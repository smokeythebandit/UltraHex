cmake_minimum_required(VERSION 3.16)

project(UltraHex VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appUltraHex
    main.cpp
    Application/Core/Bootstrapper.h Application/Core/Bootstrapper.cpp
    Application/Files/FileHandle.h Application/Files/FileHandle.cpp
    Application/Files/FileManager.h Application/Files/FileManager.cpp
    Application/Files/FileReader.h Application/Files/FileReader.cpp
    Application/Files/FileModel.h Application/Files/FileModel.cpp
    Application/Files/FileModelRow.h Application/Files/FileModelRow.cpp
    Application/Checksum/AbstractChecksumCalculator.h Application/Checksum/AbstractChecksumCalculator.cpp
)

qt_add_qml_module(appUltraHex
    URI UltraHex
    VERSION 1.0
    QML_FILES
    Application/Core/FileOperations.qml
    Application/Core/SearchOperations.qml
    GUI/Core/Main.qml
    GUI/Core/MainMenu/MainMenu.qml
    GUI/Core/MainMenu/FileMenu.qml
    GUI/Core/MainMenu/SearchMenu.qml
    GUI/Core/MainToolBar/MainToolBar.qml
    GUI/Controls/HexView/HexView.qml
    GUI/Controls/HexView/HexViewRow.qml
    GUI/Controls/HexView/HexViewSettings.qml
    GUI/Controls/TabView/TabView.qml
    GUI/Dialogs/FindDialog.qml
    GUI/Controls/TabView/TabViewItem.qml
    GUI/Tabs/HexViewTab.qml
)

qt_add_resources(appUltraHex "Icons"
    PREFIX "/Icons"
    FILES
        GUI/Icons/Close.svg
        GUI/Icons/Draft.svg
        GUI/Icons/Folder.svg
        GUI/Icons/Save.svg
        GUI/Icons/FillWidth.svg
        GUI/Icons/Hexadecimal.svg
)

set_target_properties(appUltraHex PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER ultrahex.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(
    appUltraHex
    PRIVATE Qt6::Quick
)

target_include_directories(
    appUltraHex
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Application/Files
)

install(TARGETS appUltraHex
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


