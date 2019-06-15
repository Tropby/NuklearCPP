#ifndef NUKLEARCPP_H
#define NUKLEARCPP_H

#include "nuklearcppconfig.h"

#ifdef NK_CPP_INCLUDE_GDI
    #define NK_INCLUDE_FIXED_TYPES
    #define NK_INCLUDE_STANDARD_IO
    #define NK_INCLUDE_STANDARD_VARARGS
    #define NK_INCLUDE_DEFAULT_ALLOCATOR
#endif

#ifdef NK_CPP_INCLUDE_D3D9
    #define NK_INCLUDE_FIXED_TYPES
    #define NK_INCLUDE_STANDARD_IO
    #define NK_INCLUDE_STANDARD_VARARGS
    #define NK_INCLUDE_DEFAULT_ALLOCATOR
    #define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
    #define NK_INCLUDE_FONT_BAKING
    #define NK_INCLUDE_DEFAULT_FONT
    #define NK_ASSERT
#endif

#include "nuklear/nuklear.h"

#ifdef NK_CPP_INCLUDE_GDI
    #include "nuklear/demo/gdi/nuklear_gdi.h"
    #include "platforms/win32/gdi/nuklearbasewindowgdi.h"
    #include "platforms/win32/gdi/nukleargdiinput.h"
#endif

#ifdef NK_CPP_INCLUDE_D3D9
    #include "nuklear/demo/d3d9/nuklear_d3d9.h"
    #include "platforms/win32/d3d9/nuklearbasewindowd3d9.h"
#endif

#include "nuklearcppapplication.h"

#include "widgets/nuklearwindow.h"
#include "widgets/nuklearbutton.h"
#include "widgets/nuklearlayoutrowdynamic.h"
#include "widgets/nuklearlayoutrowstatic.h"
#include "widgets/nuklearlabel.h"
#include "widgets/nuklearcheckbox.h"
#include "widgets/nukleargroup.h"
#include "widgets/nuklearselectable.h"
#include "widgets/nuklearslider.h"
#include "widgets/nukleartextedit.h"

#include "nuklearguiparser.h"

#endif // NUKLEARCPP_H
