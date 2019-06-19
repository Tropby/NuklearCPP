#ifndef NUKLEARSTRINGHELPER_H
#define NUKLEARSTRINGHELPER_H


#include <string>

namespace nkcpp
{

    class NuklearStringHelper
    {
    public:
        NuklearStringHelper();


        static void ltrim(std::string &s);

        // trim from end (in place)
        static void rtrim(std::string &s);

        // trim from both ends (in place)
        static void trim(std::string &s);

        // trim from start (copying)
        static std::string ltrim_copy(std::string s);

        // trim from end (copying)
        static std::string rtrim_copy(std::string s);

        // trim from both ends (copying)
        static std::string trim_copy(std::string s);
    };

}

#endif // NUKLEARSTRINGHELPER_H
