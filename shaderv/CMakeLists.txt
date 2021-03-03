cmake_minimum_required(VERSION 3.10)
project(shaderv)

add_subdirectory(../auxiliary auxiliary)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

option(DOCK_USE_ADVANCED "Dock window: Use advanced docking system" ON)
if(DOCK_USE_ADVANCED)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build/dependency/qtads/include)
  link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build/dependency/qtads/lib)
  add_definitions(-DDOCK_USE_ADVANCED)
endif()
option(DOCK_ALLOW_FLOATING "Dock window: Allow floating dock window" ON)
if(DOCK_ALLOW_FLOATING)
  add_definitions(-DDOCK_ALLOW_FLOATING)
endif()

find_package(NodeEditor)

option(SHADERV_USE_CONSOLE "Showing console" OFF)
if(NOT SHADERV_USE_CONSOLE)
  if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /subsystem:windows /entry:mainCRTStartup")
  else()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--subsystem,windows")
  endif()
endif()

file(GLOB_RECURSE GUI *.ui)
file(GLOB_RECURSE RES *.qrc)

file(GLOB_RECURSE CORE core/*.cpp  core/*.hpp  core/*.h)
file(GLOB_RECURSE UI     ui/*.cpp    ui/*.hpp    ui/*.h)

add_executable(shaderv ${GUI} ${RES} ${CORE} ${UI})
target_link_libraries(shaderv Qt5::Core Qt5::Gui Qt5::Widgets)
target_link_libraries(shaderv qtadvanceddocking NodeEditor::nodes)
target_link_libraries(shaderv dfx)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
  target_precompile_headers(shaderv PRIVATE graph/QtHeaders.hpp)
  target_precompile_headers(shaderv PRIVATE graph/QtAdsHeaders.hpp)
  target_precompile_headers(shaderv PRIVATE graph/NodesHeaders.hpp)
  target_precompile_headers(shaderv PRIVATE Auxiliary.hpp)
endif()
