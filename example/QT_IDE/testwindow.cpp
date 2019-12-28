#include <iostream>
#include <functional>

#include "testwindow.h"

TestWindow::TestWindow() : NuklearBaseWindowGDI( NK_NBWB_SINGLE_WINDOW )
{
    init();

    this->setWindowTitle("Nuklear");

   // gui.load("gui", this);

    NuklearWindow * nw = this->addNuklearWindow();
    nw->setText("Nuklear");

    this->resize(1024, 768);

    //nw->setFlags(NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE);

    NuklearLayoutRowDynamic * nl1 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 30, {0.2f, 0.6f, 0.0f} ));
    {
        NuklearButton * b1 = static_cast<NuklearButton*>(nl1->addButton("1"));
        nl1->addButton("2");
        nl1->addButton("3");
    }

    NuklearTree *t = static_cast<NuklearTree*>(nw->addTree("Test Tree"));
    t->addLabel("Test1");
    t->addLabel("Test2");
    NuklearTree *t2 = static_cast<NuklearTree*>(t->addTree("Test Tree"));
    t2->addLabel("T2Test1");
    t2->addLabel("T2Test2");

    NuklearLayoutRowDynamic * nl2 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic(30, {0.5f, 0.0f}));
    {
        NuklearLabel * l1 = static_cast<NuklearLabel*>(nl2->addLabel("L1"));
        NuklearLabel * l2 = static_cast<NuklearLabel*>(nl2->addLabel("L2"));
        l1->setHorizontalAlignment(NK_TEXT_ALIGN_RIGHT);
        l1->setVerticalAlignment(NK_TEXT_ALIGN_BOTTOM);
    }


}

void TestWindow::button1Clicked(NuklearElement * sender)
{
    auto button = static_cast<NuklearButton*>(sender);
    button->setText("clicked!");
    this->resize(800, 600);
}

void TestWindow::button2Clicked(NuklearElement * sender)
{
    this->resize(1024, 768);
}

void TestWindow::progressChanged(NuklearElement *sender)
{
    NuklearProgressBar * pb = static_cast<NuklearProgressBar*>(sender);
    testLabel->setText(std::string("ProgressBar value changed: ") + std::to_string(pb->getValue()));
}

void TestWindow::texteditChanged(NuklearElement * sender)
{
    testLabel->setText(testTextEdit->getText());
}

void TestWindow::checkboxChanged(NuklearElement * sender)
{
    testTextEdit->setReadonly(testCheckbox->isActive());
    testSelectable->setActive( !testCheckbox->isActive() );
}

void TestWindow::selectableChanged(NuklearElement * sender)
{
    testCheckbox->setActive( !testSelectable->isActive() );
}

