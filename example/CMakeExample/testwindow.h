#ifndef TESTAPPLICATION_H
#define TESTAPPLICATION_H

#include "nuklearcpp.h"
using namespace nkcpp;

class TestWindow : public NuklearBaseWindowGDI
{
public:
    TestWindow();

    void button1Clicked(NuklearElement * sender);
    void button2Clicked(NuklearElement * sender);

    void texteditChanged(NuklearElement * sender);
    void checkboxChanged(NuklearElement * sender);
    void selectableChanged(NuklearElement * sender);

private:
    NuklearLabel * testLabel;
    NuklearTextEditLine * testTextEdit;
    NuklearCheckbox * testCheckbox;
    NuklearSelectable * testSelectable;
};

#endif // TESTAPPLICATION_H
