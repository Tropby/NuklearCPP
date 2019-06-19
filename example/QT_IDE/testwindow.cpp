#include <iostream>
#include <functional>

#include "testwindow.h"

TestWindow::TestWindow() : NuklearBaseWindowGDI( NK_NBWB_MULTI_WINDOW )
{
    init();

    this->setWindowTitle("Nuklear");

    this->resize(1024, 768);

   // gui.load("gui", this);

    NuklearWindow * nw = this->addNuklearWindow();
    nw->resize(50, 50, 200, 400);
    nw->setText("Nuklear");
    nw->setFlags(NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE);

    NuklearLayoutRowDynamic * lnc1 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 300, 1 ));
    NuklearChart * nc1 = static_cast<NuklearChart*>(lnc1->addChart(NK_CHART_LINES));
    nc1->addValue(rand()*100);
    nc1->addValue(rand()*100);
    nc1->addValue(rand()*100);
    nc1->addValue(rand()*100);
    nc1->addValue(rand()*100);
    nc1->addValue(rand()*100);

    NuklearLayoutRowDynamic * l1 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 30, 1 ));
    NuklearButton * b1 = static_cast<NuklearButton*>(l1->addButton("Test1"));
    b1->setOnClick(NK_CPP_BIND(TestWindow, button1Clicked, this));

    NuklearLayoutRowDynamic * l2 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 50, 2 ));
    NuklearButton * b2 = static_cast<NuklearButton*>(l2->addButton("Test1"));
    b2->setOnClick(NK_CPP_BIND(TestWindow, button2Clicked, this));

    NuklearLayoutRowDynamic * l3 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 30, 2 ));
    l3->addButton("Test4");
    l3->addButton("Test5");
    NuklearProgressBar * pb1 = static_cast<NuklearProgressBar*>(l3->addProgressBar(80, 100, true));
    pb1->setOnChange(NK_CPP_BIND(TestWindow, progressChanged, this));


    testCheckbox = static_cast<NuklearCheckbox*>(l2->addCheckbox("The Build!", false));
    testCheckbox->setOnChanged(NK_CPP_BIND(TestWindow, checkboxChanged, this ));

    l2->addSlider(0, 50, 200, 5);
    testTextEdit = static_cast<NuklearTextEditLine*>(l2->addTextEdit("Change ME!"));
    testTextEdit->setOnChange(NK_CPP_BIND(TestWindow, texteditChanged, this ) );

    NuklearLayoutRowStatic * l4 = static_cast<NuklearLayoutRowStatic*>(nw->addLayoutRowStatic( 50, 100, 2 ));
    l4->addButton("Test _1_");
    l4->addButton("Test _2_");
    l4->addButton("Test _3_");
    testLabel = static_cast<NuklearLabel*>(l3->addLabel("Ein Label"));
    testSelectable = static_cast<NuklearSelectable*>(l3->addSelectable("Click ME", true));
    testSelectable->setOnChanged( NK_CPP_BIND(TestWindow, selectableChanged, this) );

    NuklearLayoutRowDynamic * l6 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 200, 1 ));
    NuklearGroup * g1 = static_cast<NuklearGroup*>(l6->addGroup() );
    NuklearLayoutRowDynamic * l5 = static_cast<NuklearLayoutRowDynamic*>(g1->addLayoutRowDynamic( 50, 1 ));

    l5->addLabel("Group 1");
    l5->addLabel("Group 2");
    l5->addLabel("Group 3");
    l5->addLabel("Group 4");
    l5->addLabel("Group 5");

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

