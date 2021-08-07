cmake_minimum_required(VERSION 3.8)
project(simgui)

set(IMGUI_ROOT_DIR ../external/imgui)
set(IMGUI_BACKENDS_DIR ../external/imgui/backends)
include_directories(${IMGUI_ROOT_DIR})
include_directories(${IMGUI_BACKENDS_DIR})
include_directories(../external/SDL/include)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        ${IMGUI_ROOT_DIR}/imgui.cpp
        ${IMGUI_ROOT_DIR}/imgui_demo.cpp
        ${IMGUI_ROOT_DIR}/imgui_draw.cpp
        ${IMGUI_ROOT_DIR}/imgui_tables.cpp
        ${IMGUI_ROOT_DIR}/imgui_widgets.cpp
        ${IMGUI_BACKENDS_DIR}/imgui_impl_sdl.cpp
		${IMGUI_BACKENDS_DIR}/imgui_impl_opengl2.cpp
        src/simgui.cpp)
		
if(WIN32)
	set(SOURCES ${SOURCES} ${IMGUI_BACKENDS_DIR}/imgui_impl_win32.cpp)
endif()	

add_library(simgui STATIC ${SOURCES})

