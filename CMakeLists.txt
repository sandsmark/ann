project(ann)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(ann_SRCS ann.cpp main.cpp)
qt4_automoc(${ann_SRCS})
add_executable(ann ${ann_SRCS})
target_link_libraries(ann ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS ann RUNTIME DESTINATION bin)
