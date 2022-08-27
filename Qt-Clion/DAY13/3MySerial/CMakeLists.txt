cmake_minimum_required(VERSION 3.5)
### 编译不过去有点小难
project(mytest LANGUAGES CXX)

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
### 编译不过去有点小难 2002-8-27-21:17
#find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets SerialPort REQUIRED)

if (ANDROID)
    add_library(mytest SHARED
            main.cpp
            myserial.ui
            myserial.h
            myserial.cpp
            )
else ()
    add_executable(mytest
            main.cpp
            myserial.ui
            myserial.h
            myserial.cpp
            )
endif ()

target_link_libraries(mytest PRIVATE Qt5::Widgets)
