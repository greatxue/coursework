cmake_minimum_required(VERSION 3.14)

project(Problem1_qt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(Problem1_qt
    Combinatorics.cpp
    Combinatorics.h


)
target_link_libraries(Problem1_qt Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS Problem1_qt
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
