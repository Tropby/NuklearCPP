TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../../src/

SOURCES += \
    main.cpp \
    testwindow.cpp \
    ../../src/nuklearcpp.cpp \
    ../../src/widgets/nuklearelement.cpp \
    ../../src/widgets/nuklearbutton.cpp \
    ../../src/widgets/nuklearwindow.cpp \
    ../../src/widgets/nuklearlayoutrowdynamic.cpp \
    ../../src/widgets/nuklearlayoutrowstatic.cpp \
    ../../src/widgets/nuklearlabel.cpp \
    ../../src/widgets/nuklearcheckbox.cpp \
    ../../src/widgets/nukleargroup.cpp \
    ../../src/nuklearguiparser.cpp \
    ../../src/images/nuklearbitmap.cpp \
    ../../src/nuklearcppapplication.cpp \
    ../../src/platforms/nuklearbasewindow.cpp \
    ../../src/platforms/win32/d3d9/nuklearbasewindowd3d9.cpp \
    ../../src/platforms/win32/gdi/nuklearbasewindowgdi.cpp \
    ../../src/platforms/win32/gdi/nukleargdiinput.cpp \
    ../../src/platforms/win32/nuklearbasewindowwin32.cpp

HEADERS += \
    testwindow.h \
    ../../src/nuklearcpp.h \
    ../../src/nuklear/nuklear.h \
    ../../src/nuklear/demo/gdi/nuklear_gdi.h \
    ../../src/nuklear/demo/d3d9/nuklear_d3d9.h \
    ../../src/widgets/nuklearelement.h \
    ../../src/widgets/nuklearbutton.h \
    ../../src/widgets/nuklearwindow.h \
    ../../src/widgets/nuklearlayoutrowdynamic.h \
    ../../src/widgets/nuklearlayoutrowstatic.h \
    ../../src/widgets/nuklearlabel.h \
    ../../src/widgets/nuklearcheckbox.h \
    ../../src/widgets/nukleargroup.h \
    ../../src/nuklearguiparser.h \
    ../../src/images/nuklearbitmap.h \
    ../../src/nuklearcppconfig.h \
    ../../src/nuklearcppapplication.h \
    ../../src/platforms/nuklearbasewindow.h \
    ../../src/platforms/win32/d3d9/nuklearbasewindowd3d9.h \
    ../../src/platforms/win32/gdi/nukleargdiinput.h \
    ../../src/platforms/win32/gdi/nuklearbasewindowgdi.h \
    ../../src/platforms/win32/nuklearbasewindowwin32.h

LIBS += -luser32 -lgdi32 -lMsimg32 -ld3d9
