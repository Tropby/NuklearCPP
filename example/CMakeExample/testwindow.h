#ifndef TESTAPPLICATION_H
#define TESTAPPLICATION_H

#include "nuklearcpp.h"
using namespace nkcpp;

class TestWindow : public NuklearBaseWindowGDI
{
public:
    TestWindow();

    void button1Clicked();
    void button2Clicked();
};

#endif // TESTAPPLICATION_H