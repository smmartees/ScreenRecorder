cmake_minimum_required(VERSION 3.16)

project(ScreenRecorderApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(Qt6 REQUIRED COMPONENTS Quick)
# find_package(Qt6Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Quick Qml)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appScreenRecorderApp
    main.cpp
)

qt_add_qml_module(appScreenRecorderApp
    URI ScreenRecorderApp
    QML_FILES
        Main.qml
        SOURCES appManager.cpp
        SOURCES videoRecorder.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appScreenRecorderApp PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appScreenRecorderApp
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appScreenRecorderApp
    PRIVATE 
	Qt6::Quick
	Qt6::Gui
	Qt6::Widgets
	Qt6::Quick
	Qt6::Qml
)

include(GNUInstallDirs)
install(TARGETS appScreenRecorderApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
