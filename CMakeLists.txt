cmake_minimum_required(VERSION 3.16)

project(Qt_MachineDistributrice VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver Qt avec Widgets et Charts, pour Qt5 et Qt6
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    boisson.cpp
    Cases.cpp
    CSVParser.cpp
    fproduit1.cpp
    nourriture.cpp
    MachineDistributrice.cpp
    produit.cpp
    admin.cpp
    fonction.cpp

    boisson.h
    Cases.h
    CSVParser.h
    fproduit1.h
    nourriture.h
    mainwindow.h
    MachineDistributrice.h
    produit.h
    admin.h
    fonction.h
    Parser.h

    fproduit1.ui
    admin.ui
    ressources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Qt_MachineDistributrice
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Qt_MachineDistributrice SHARED ${PROJECT_SOURCES})
    else()
        add_executable(Qt_MachineDistributrice ${PROJECT_SOURCES})
    endif()
endif()

target_link_libraries(Qt_MachineDistributrice PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Charts
)

if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Qt_MachineDistributrice)
endif()

set_target_properties(Qt_MachineDistributrice PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Qt_MachineDistributrice
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Qt_MachineDistributrice)
endif()
