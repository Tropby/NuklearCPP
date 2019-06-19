
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>


#include "nuklearguiparser.h"
#include "nuklearstringhelper.h"

namespace nkcpp
{
    NuklearGUIParser::NuklearGUIParser()
    {
    }

    void NuklearGUIParser::load( std::string filename, NuklearBaseWindow * baseWindow, NuklearContainer * baseContainer )
    {
        std::ifstream input;
        std::vector<NuklearElement*> elements;

        input.open( filename );

        if (input.is_open())
        {
            std::string line;
            while ( getline (input, line, '\n') )
            {
                // Layer berechnen
                unsigned int layer = 0;
                while( line[layer] == '\t' )
                    layer++;

                if( baseContainer != nullptr )
                {
                    if(elements.empty())
                        elements.push_back(baseContainer);
                    layer++;
                }

                // trim the input line
                line = NuklearStringHelper::trim_copy(line);


                std::istringstream f(line);
                std::string s;
                std::vector<std::string> strings;
                std::string entry;
                bool isString = false;

                // explode the strings
                while (getline(f, s, ' '))
                {
                        if( s[s.length()-1] == '"' )
                        {
                            entry += " " + s.substr(0, s.length()-1);
                            isString = false;
                        }
                        else if( s[0] == '"' )
                        {
                            entry += s.substr(1, s.length()-1);
                            isString = true;
                        }
                        else
                        {
                            if( isString )
                                entry += " ";
                            entry += s;
                        }

                        if( !isString )
                        {
                            std::string e = entry;
                            strings.push_back(e);
                            entry = "";
                        }
                }

                while( elements.size() > layer )
                    elements.pop_back();

                if( strings[0].compare( "NK_CPP_WINDOW" ) == 0 )
                {
                    if( baseWindow != nullptr )
                    {
                        NuklearWindow * nw = baseWindow->addNuklearWindow();
                        nw->resize(std::atoi(strings[2].c_str()), std::atoi(strings[3].c_str()), std::atoi(strings[4].c_str()), std::atoi(strings[5].c_str()));
                        nw->setName( strings[1] );
                        elements.push_back(nw);
                    }
                    else
                    {
                        MessageBoxA(nullptr, std::string( std::string("Can not load GUI! Base window not defined!\n\n") + strings[0] ).c_str(), "GUI LOAD ERROR", MB_ICONERROR);
                        return;
                    }
                }
                else if( strings[0].compare( "NK_CPP_ROW_LAYOUT_DYNAMIC" ) == 0 )
                {
                    NuklearContainer * nc = static_cast<NuklearContainer*>(elements[layer-1]);
                    NuklearContainer * nlrd = nc->addLayoutRowDynamic( std::atoi(strings[2].c_str()), std::atoi(strings[3].c_str()) );
                    nlrd->setName( strings[1] );
                    elements.push_back(nlrd);
                }
                else if( strings[0].compare( "NK_CPP_LABEL" ) == 0 )
                {
                    NuklearContainer * nc = static_cast<NuklearContainer*>(elements[layer-1]);
                    NuklearLabel * nl = static_cast<NuklearLabel*>(nc->addLabel(strings[2]));
                    nl->setName( strings[1] );
                    elements.push_back(nl);
                }
                else if( strings[0].compare( "NK_CPP_BUTTON" ) == 0 )
                {
                    NuklearContainer * nc = static_cast<NuklearContainer*>(elements[layer-1]);
                    NuklearButton * nb = static_cast<NuklearButton*>(nc->addButton(strings[2]));
                    nb->setName( strings[1] );
                    elements.push_back(nb);
                }
                else if( strings[0].compare( "NK_CPP_INCLUDE" ) == 0 )
                {
                    NuklearContainer * nc = static_cast<NuklearContainer*>(elements[layer-1]);
                    this->load( strings[1], nullptr, nc );
                }
                else
                {
                    MessageBoxA(nullptr, std::string( std::string("Can not load GUI!\n\nUnknown Widget: ") + strings[0] ).c_str(), "GUI LOAD ERROR", MB_ICONERROR);
                    return;
                }
            }
            input.close();
        }
    }
}
