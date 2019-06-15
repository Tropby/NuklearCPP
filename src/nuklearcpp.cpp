
#include "nuklearcppconfig.h"
#include "nuklearcpp.h"

#define NK_IMPLEMENTATION
#include "nuklear/nuklear.h"

#ifdef NK_CPP_INCLUDE_GDI
    #define NK_GDI_IMPLEMENTATION
#endif
#ifdef NK_CPP_INCLUDE_GDI
    #include "nuklear/demo/gdi/nuklear_gdi.h"
#endif

#ifdef NK_CPP_INCLUDE_D3D9
    #define NK_D3D9_IMPLEMENTATION
#endif
#ifdef NK_CPP_INCLUDE_D3D9
    #include "nuklear/demo/d3d9/nuklear_d3d9.h"
#endif
