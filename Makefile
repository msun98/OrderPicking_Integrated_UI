#############################################################################
# Makefile for building: OrderPicking_Integrated_UI
# Generated by qmake (3.1) (Qt 5.12.8)
# Project:  OrderPicking_Integrated_UI.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile OrderPicking_Integrated_UI.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

EQ            = =

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_WEBSOCKETS_LIB -DQT_NETWORK_LIB -DQT_SERIALPORT_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -g -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/opencv4 -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtWebSockets -isystem /usr/include/x86_64-linux-gnu/qt5/QtNetwork -isystem /usr/include/x86_64-linux-gnu/qt5/QtSerialPort -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = OrderPicking_Integrated_UI1.0.0
DISTDIR = /home/rainbow/OrderPicking_Integrated_UI/.tmp/OrderPicking_Integrated_UI1.0.0
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -lboost_chrono -lboost_date_time -lboost_regex -lboost_system -lboost_thread -L/usr/local/lib/ -lopencv_core -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_calib3d -lopencv_features2d -lopencv_flann -lopencv_objdetect -lopencv_photo -lopencv_video -lopencv_videoio /usr/lib/x86_64-linux-gnu/libQt5Widgets.so /usr/lib/x86_64-linux-gnu/libQt5Gui.so /usr/lib/x86_64-linux-gnu/libQt5WebSockets.so /usr/lib/x86_64-linux-gnu/libQt5Network.so /usr/lib/x86_64-linux-gnu/libQt5SerialPort.so /usr/lib/x86_64-linux-gnu/libQt5Core.so /usr/lib/x86_64-linux-gnu/libGL.so -lpthread   
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = cobot.cpp \
		impl/AsioTelnetClient.cpp \
		keti_vision.cpp \
		kitech_gripper.cpp \
		lift.cpp \
		lift_serialcmd.cpp \
		log_writer.cpp \
		main.cpp \
		mainwindow.cpp \
		networkthread.cpp \
		omron.cpp \
		option_writer.cpp \
		telnetclient.cpp \
		websocket.cpp \
		cv_to_qt.cpp \
		qmylabel.cpp qrc_resource.cpp \
		moc_cobot.cpp \
		moc_keti_vision.cpp \
		moc_kitech_gripper.cpp \
		moc_lift.cpp \
		moc_mainwindow.cpp \
		moc_networkthread.cpp \
		moc_omron.cpp \
		moc_telnetclient.cpp \
		moc_websocket.cpp \
		moc_qmylabel.cpp
OBJECTS       = cobot.o \
		AsioTelnetClient.o \
		keti_vision.o \
		kitech_gripper.o \
		lift.o \
		lift_serialcmd.o \
		log_writer.o \
		main.o \
		mainwindow.o \
		networkthread.o \
		omron.o \
		option_writer.o \
		telnetclient.o \
		websocket.o \
		cv_to_qt.o \
		qmylabel.o \
		qrc_resource.o \
		moc_cobot.o \
		moc_keti_vision.o \
		moc_kitech_gripper.o \
		moc_lift.o \
		moc_mainwindow.o \
		moc_networkthread.o \
		moc_omron.o \
		moc_telnetclient.o \
		moc_websocket.o \
		moc_qmylabel.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_websockets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		OrderPicking_Integrated_UI.pro Common_header.h \
		cobot.h \
		impl/AsioTelnetClient.h \
		impl/TelnetProtocol.h \
		keti_vision.h \
		kitech_gripper.h \
		lift.h \
		lift_serialcmd.h \
		log_writer.h \
		mainwindow.h \
		networkthread.h \
		omron.h \
		option_writer.h \
		telnetclient.h \
		websocket.h \
		cv_to_qt.h \
		qmylabel.h cobot.cpp \
		impl/AsioTelnetClient.cpp \
		keti_vision.cpp \
		kitech_gripper.cpp \
		lift.cpp \
		lift_serialcmd.cpp \
		log_writer.cpp \
		main.cpp \
		mainwindow.cpp \
		networkthread.cpp \
		omron.cpp \
		option_writer.cpp \
		telnetclient.cpp \
		websocket.cpp \
		cv_to_qt.cpp \
		qmylabel.cpp
QMAKE_TARGET  = OrderPicking_Integrated_UI
DESTDIR       = 
TARGET        = OrderPicking_Integrated_UI


first: all
####### Build rules

OrderPicking_Integrated_UI: ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: OrderPicking_Integrated_UI.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_websockets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_x11extras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		OrderPicking_Integrated_UI.pro \
		resource.qrc
	$(QMAKE) -o Makefile OrderPicking_Integrated_UI.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_edid_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_serialport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_vulkan_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_websockets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_x11extras.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
OrderPicking_Integrated_UI.pro:
resource.qrc:
qmake: FORCE
	@$(QMAKE) -o Makefile OrderPicking_Integrated_UI.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug

qmake_all: FORCE


all: Makefile OrderPicking_Integrated_UI

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents resource.qrc $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents Common_header.h cobot.h impl/AsioTelnetClient.h impl/TelnetProtocol.h keti_vision.h kitech_gripper.h lift.h lift_serialcmd.h log_writer.h mainwindow.h networkthread.h omron.h option_writer.h telnetclient.h websocket.h cv_to_qt.h qmylabel.h $(DISTDIR)/
	$(COPY_FILE) --parents cobot.cpp impl/AsioTelnetClient.cpp keti_vision.cpp kitech_gripper.cpp lift.cpp lift_serialcmd.cpp log_writer.cpp main.cpp mainwindow.cpp networkthread.cpp omron.cpp option_writer.cpp telnetclient.cpp websocket.cpp cv_to_qt.cpp qmylabel.cpp $(DISTDIR)/
	$(COPY_FILE) --parents mainwindow.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_objc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_objc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all: qrc_resource.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resource.cpp
qrc_resource.cpp: resource.qrc \
		/usr/lib/qt5/bin/rcc \
		icon/cpature-selected.jpg \
		icon/lock-normal.jpg \
		icon/setting-selected.jpg \
		icon/unlock-normal.jpg \
		icon/lidar-over.jpg \
		icon/debug-over.jpg \
		icon/orderpicking.jpg \
		icon/lidar-selected.jpg \
		icon/lock-over.jpg \
		icon/background2.jpg \
		icon/unlock-over.jpg \
		icon/debug-selected.jpg \
		icon/debug-normal.jpg \
		icon/lidar-normal.jpg \
		icon/capture-over.jpg \
		icon/setting-over.jpg \
		icon/save-over.jpg \
		icon/capture-normal.jpg \
		icon/save-normal.jpg \
		icon/setting-normal.jpg \
		icon/background.jpg
	/usr/lib/qt5/bin/rcc -name resource resource.qrc -o qrc_resource.cpp

compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -g -std=gnu++11 -Wall -W -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_cobot.cpp moc_keti_vision.cpp moc_kitech_gripper.cpp moc_lift.cpp moc_mainwindow.cpp moc_networkthread.cpp moc_omron.cpp moc_telnetclient.cpp moc_websocket.cpp moc_qmylabel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_cobot.cpp moc_keti_vision.cpp moc_kitech_gripper.cpp moc_lift.cpp moc_mainwindow.cpp moc_networkthread.cpp moc_omron.cpp moc_telnetclient.cpp moc_websocket.cpp moc_qmylabel.cpp
moc_cobot.cpp: cobot.h \
		Common_header.h \
		option_writer.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include cobot.h -o moc_cobot.cpp

moc_keti_vision.cpp: keti_vision.h \
		Common_header.h \
		option_writer.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include keti_vision.h -o moc_keti_vision.cpp

moc_kitech_gripper.cpp: kitech_gripper.h \
		Common_header.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include kitech_gripper.h -o moc_kitech_gripper.cpp

moc_lift.cpp: lift.h \
		Common_header.h \
		lift_serialcmd.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include lift.h -o moc_lift.cpp

moc_mainwindow.cpp: mainwindow.h \
		cobot.h \
		Common_header.h \
		option_writer.h \
		lift.h \
		lift_serialcmd.h \
		keti_vision.h \
		kitech_gripper.h \
		log_writer.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h \
		omron.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include mainwindow.h -o moc_mainwindow.cpp

moc_networkthread.cpp: networkthread.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include networkthread.h -o moc_networkthread.cpp

moc_omron.cpp: omron.h \
		Common_header.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include omron.h -o moc_omron.cpp

moc_telnetclient.cpp: telnetclient.h \
		impl/AsioTelnetClient.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include telnetclient.h -o moc_telnetclient.cpp

moc_websocket.cpp: websocket.h \
		Common_header.h \
		omron.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include websocket.h -o moc_websocket.cpp

moc_qmylabel.cpp: qmylabel.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include /home/rainbow/OrderPicking_Integrated_UI/moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/rainbow/OrderPicking_Integrated_UI -I/usr/include/opencv4 -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtWebSockets -I/usr/include/x86_64-linux-gnu/qt5/QtNetwork -I/usr/include/x86_64-linux-gnu/qt5/QtSerialPort -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/8 -I/usr/include/x86_64-linux-gnu/c++/8 -I/usr/include/c++/8/backward -I/usr/lib/gcc/x86_64-linux-gnu/8/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/8/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include qmylabel.h -o moc_qmylabel.cpp

compiler_moc_objc_header_make_all:
compiler_moc_objc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui \
		/usr/lib/qt5/bin/uic \
		qmylabel.h
	/usr/lib/qt5/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_rcc_clean compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

cobot.o: cobot.cpp cobot.h \
		Common_header.h \
		option_writer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cobot.o cobot.cpp

AsioTelnetClient.o: impl/AsioTelnetClient.cpp impl/AsioTelnetClient.h \
		impl/TelnetProtocol.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AsioTelnetClient.o impl/AsioTelnetClient.cpp

keti_vision.o: keti_vision.cpp keti_vision.h \
		Common_header.h \
		option_writer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o keti_vision.o keti_vision.cpp

kitech_gripper.o: kitech_gripper.cpp kitech_gripper.h \
		Common_header.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o kitech_gripper.o kitech_gripper.cpp

lift.o: lift.cpp lift.h \
		Common_header.h \
		lift_serialcmd.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lift.o lift.cpp

lift_serialcmd.o: lift_serialcmd.cpp lift_serialcmd.h \
		Common_header.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lift_serialcmd.o lift_serialcmd.cpp

log_writer.o: log_writer.cpp log_writer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o log_writer.o log_writer.cpp

main.o: main.cpp mainwindow.h \
		cobot.h \
		Common_header.h \
		option_writer.h \
		lift.h \
		lift_serialcmd.h \
		keti_vision.h \
		kitech_gripper.h \
		log_writer.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h \
		omron.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		cobot.h \
		Common_header.h \
		option_writer.h \
		lift.h \
		lift_serialcmd.h \
		keti_vision.h \
		kitech_gripper.h \
		log_writer.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h \
		omron.h \
		ui_mainwindow.h \
		qmylabel.h \
		cv_to_qt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

networkthread.o: networkthread.cpp networkthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o networkthread.o networkthread.cpp

omron.o: omron.cpp omron.h \
		Common_header.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o omron.o omron.cpp

option_writer.o: option_writer.cpp option_writer.h \
		Common_header.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o option_writer.o option_writer.cpp

telnetclient.o: telnetclient.cpp telnetclient.h \
		impl/AsioTelnetClient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o telnetclient.o telnetclient.cpp

websocket.o: websocket.cpp websocket.h \
		Common_header.h \
		omron.h \
		telnetclient.h \
		impl/AsioTelnetClient.h \
		networkthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o websocket.o websocket.cpp

cv_to_qt.o: cv_to_qt.cpp cv_to_qt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cv_to_qt.o cv_to_qt.cpp

qmylabel.o: qmylabel.cpp qmylabel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qmylabel.o qmylabel.cpp

qrc_resource.o: qrc_resource.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resource.o qrc_resource.cpp

moc_cobot.o: moc_cobot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cobot.o moc_cobot.cpp

moc_keti_vision.o: moc_keti_vision.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_keti_vision.o moc_keti_vision.cpp

moc_kitech_gripper.o: moc_kitech_gripper.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_kitech_gripper.o moc_kitech_gripper.cpp

moc_lift.o: moc_lift.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_lift.o moc_lift.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_networkthread.o: moc_networkthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_networkthread.o moc_networkthread.cpp

moc_omron.o: moc_omron.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_omron.o moc_omron.cpp

moc_telnetclient.o: moc_telnetclient.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_telnetclient.o moc_telnetclient.cpp

moc_websocket.o: moc_websocket.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_websocket.o moc_websocket.cpp

moc_qmylabel.o: moc_qmylabel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qmylabel.o moc_qmylabel.cpp

####### Install

install_target: first FORCE
	@test -d $(INSTALL_ROOT)/opt/OrderPicking_Integrated_UI/bin || mkdir -p $(INSTALL_ROOT)/opt/OrderPicking_Integrated_UI/bin
	-$(QINSTALL_PROGRAM) $(QMAKE_TARGET) $(INSTALL_ROOT)/opt/OrderPicking_Integrated_UI/bin/$(QMAKE_TARGET)

uninstall_target: FORCE
	-$(DEL_FILE) $(INSTALL_ROOT)/opt/OrderPicking_Integrated_UI/bin/$(QMAKE_TARGET)
	-$(DEL_DIR) $(INSTALL_ROOT)/opt/OrderPicking_Integrated_UI/bin/ 


install: install_target  FORCE

uninstall: uninstall_target  FORCE

FORCE:

