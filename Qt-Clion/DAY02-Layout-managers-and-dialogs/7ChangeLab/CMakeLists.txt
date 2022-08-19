cmake_minimum_required(VERSION 3.5)

project(untitled LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.14.2/5.14.2/mingw73_64/lib/cmake/Qt5")

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

if (ANDROID)
    add_library(untitled SHARED
            main.cpp
            mainwindow.cpp
            mainwindow.h
            mainwindow.ui
            changelab.h
            changelab.cpp
            )

else ()
    add_executable(untitled
            main.cpp
            mainwindow.cpp
            mainwindow.h
            mainwindow.ui
            changelab.h
            changelab.cpp
            )
endif ()

target_link_libraries(untitled PRIVATE Qt5::Widgets)
target_include_directories(untitled PRIVATE "${CMAKE_BINARY_DIR}/Test_autogen/include")#Test_autogen文件夹名字注意，Test要改成项目名！！
