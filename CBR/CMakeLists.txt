cmake_minimum_required(VERSION 3.5)

project(CBR LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})

find_package(Libraries)
#option --quazip
find_package(QuaZip-Qt5)
#option --opencv
find_package(OpenCV REQUIRED)
MESSAGE("OpenCV version : ${OpenCV_VERSION}")
include_directories( ${OpenCV_INCLUDE_DIRS} )


if(ANDROID)
  add_library(CBR SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    archivemanager.cpp
    archivemanager.h
    imgmanager.cpp
    imgmanager.h
    browsermanager.cpp
    browsermanager.h
    mylistwidgetdelegate.cpp
    mylistwidgetdelegate.h
  )
else()
  add_executable(CBR
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    archivemanager.cpp
    archivemanager.h
    imgmanager.cpp
    imgmanager.h
    browsermanager.cpp
    browsermanager.h
    mylistwidgetdelegate.cpp
    mylistwidgetdelegate.h
  )
endif()

target_link_libraries(CBR PRIVATE Qt5::Widgets QuaZip::QuaZip ${OpenCV_LIBS} ${ImageMagick_LIBRARIES})
