#include <iostream>
#include <functional>

#include "testwindow.h"

TestWindow::TestWindow() : NuklearBaseWindowGDI( NK_NBWB_MULTI_WINDOW )
{
    init();
    this->setWindowTitle("Test 123");

    this->resize(1024, 768);

    NuklearWindow * nw = this->addNuklearWindow();
    nw->resize(50, 50, 200, 400);
    nw->setText("Das ist ein Test");
    nw->setFlags(NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE);

    NuklearLayoutRowDynamic * l1 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 30, 1 ));
    l1->addButton("Test1", std::bind( &TestWindow::button1Clicked, this ));

    NuklearLayoutRowDynamic * l2 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 50, 2 ));
    l2->addButton("Test2", std::bind( &TestWindow::button2Clicked, this ))->hide();
    l2->addButton("Test3", std::bind( &TestWindow::button1Clicked, this ));

    l2->addButton("Test4", std::bind( &TestWindow::button2Clicked, this ));
    l2->addButton("Test5", std::bind( &TestWindow::button1Clicked, this ));

    l2->addCheckbox("The Build!", true);

    NuklearLayoutRowStatic * l3 = static_cast<NuklearLayoutRowStatic*>(nw->addLayoutRowStatic( 50, 100, 2 ));
    l3->addButton("Test _1_", std::bind( &TestWindow::button2Clicked, this ));
    l3->addButton("Test _2_", std::bind( &TestWindow::button1Clicked, this ));
    l3->addButton("Test _3_", std::bind( &TestWindow::button1Clicked, this ));
    l3->addLabel("Ein Label");

    NuklearLayoutRowDynamic * l4 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 200, 1 ));
    NuklearGroup * g1 = static_cast<NuklearGroup*>(l4->addGroup() );
    NuklearLayoutRowDynamic * l5 = static_cast<NuklearLayoutRowDynamic*>(g1->addLayoutRowDynamic( 50, 1 ));

    l5->addLabel("Group 1");
    l5->addLabel("Group 2");
    l5->addLabel("Group 3");
    l5->addLabel("Group 4");
    l5->addLabel("Group 5");
}

void TestWindow::button1Clicked()
{
    std::cout << (int)this << "button1Clicked" << std::endl;
    this->resize(800, 600);
}

void TestWindow::button2Clicked()
{
    std::cout << (int)this << "button2Clicked" << std::endl;
    this->resize(1024, 768);
}

