# NuklearCPP
Based on Nuklear, a signle-header ANSI C gui library, the NukllearCPP provides a C++ interface to the ANSI C functions. 
The NuklearCPP is currently under developement. There are only some functions/widgets working by now.

# Basic Idea
The basic idea was to create a easy to use C++ interface with callback function to the Nuklear GUI library. 
To implement a window you have just du extent one of the BaseWindows that run the renderer. For example you  can 
extent the NuklearBaseWindowGDI. To initialise the window just call *init();*.

```c++
class TestWindow : public NuklearBaseWindowGDI
{
public:
    TestWindow();
};
```

```c++
TestWindow::TestWindow() : NuklearBaseWindowGDI( NK_NBWB_MULTI_WINDOW )
{
    init();
}
```

## Adding widgets

First of all you need to add a new NuklearWindow by calling *addNuklearWindow();*. 
This will give you a pointer to a NuklearWindow. By calling one of the add functions you can add widgets to the
window. Attention: You need always a layout to add windgets to.

```c++
NuklearWindow * nw = this->addNuklearWindow();
nw->resize(50, 50, 200, 400);
nw->setText("Test Window");
nw->setFlags(NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|NK_WINDOW_CLOSABLE|NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE);

NuklearLayoutRowDynamic * l1 = static_cast<NuklearLayoutRowDynamic*>(nw->addLayoutRowDynamic( 30, 1 ));
l1->addLabel("Hello World!");
```

## Binging callbacks

You may bind the callback function at the creation of the object.

```c++
#include <functional>

...

l3->addButton("Test _1_", std::bind( &TestWindow::button2Clicked, this ));
```

The callback function is defined in the example below.

```c++
class TestWindow : public NuklearBaseWindowGDI
{
public:
    TestWindow();
    void button1Clicked();
};
```


# Supportet Widgets

Currently the following widgets are supportet:
- Button
- Checkbox
- Groupbox
- Label
- Layout Row Dynamic
- Layout Row Static
- Window