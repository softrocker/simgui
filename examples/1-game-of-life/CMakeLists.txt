cmake_minimum_required(VERSION 3.10)

# set the project name
project(GameOfLife)

set(CMAKE_CONFIGURATION_TYPES Debug Release)

set(IMGUI_ROOT_DIR ../../../external/imgui-master)
include_directories(${IMGUI_ROOT_DIR})

set(IMGUI_BACKENDS_DIR ../../../external/imgui-master/backends)
include_directories(${IMGUI_BACKENDS_DIR})

set(SDL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/../../../external/SDL2/include)
include_directories(${SDL_INCLUDE_DIR})

set(SDL_LIB_DIR ${CMAKE_SOURCE_DIR}/../../../external/SDL2/build/Debug)
link_directories(${SDL_LIB_DIR})

set(SIMGUI_DIR ${CMAKE_SOURCE_DIR}/../../)
include_directories(${SIMGUI_DIR})

set(ADDITIONAL_SOURCES ${IMGUI_ROOT_DIR}/imgui.cpp
${IMGUI_ROOT_DIR}/imgui_demo.cpp
${IMGUI_ROOT_DIR}/imgui_draw.cpp
${IMGUI_ROOT_DIR}/imgui_tables.cpp
${IMGUI_ROOT_DIR}/imgui_widgets.cpp

${IMGUI_BACKENDS_DIR}/imgui_impl_opengl2.cpp
${IMGUI_BACKENDS_DIR}/imgui_impl_sdl.cpp

${SIMGUI_DIR}/simgui.cpp)
# add the executable
if(WIN32)
	set( ADDITIONAL_SOURCES ${ADDITIONAL_SOURCES}
	${IMGUI_BACKENDS_DIR}/imgui_impl_win32.cpp)
endif()

add_executable(GameOfLife main.cpp GameOfLife.cpp GameOfLife.h
	${ADDITIONAL_SOURCES}
)

set(ADDITIONAL_LIBS)
if(WIN32)
	set( ADDITIONAL_LIBS ${ADDIDIONAL_LIBS}
	opengl32.lib 

	kernel32.lib
	user32.lib

	gdi32.lib
	winspool.lib
	comdlg32.lib
	advapi32.lib
	shell32.lib
	ole32.lib
	oleaut32.lib
	uuid.lib
	odbc32.lib
	odbccp32.lib
	version.lib

	winmm.lib
	dbghelp.lib
	shlwapi.lib
	Setupapi.lib)
endif()

set(STATIC_LIB_SUFFIX .a)
if(WIN32)
	set(STATIC_LIB_SUFFIX .lib)
endif()

target_link_libraries(GameOfLife ${SDL_LIB_DIR}/SDL2-staticd${STATIC_LIB_SUFFIX} 
	${ADDITIONAL_LIBS}
)