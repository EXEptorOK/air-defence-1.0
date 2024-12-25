cmake_minimum_required(VERSION 3.1)

#comment

project(airdefence)

set(GLUT_ROOT ${PROJECT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

find_package(GLUT REQUIRED)
if(GLUT_FOUND)
    message("GLUT is found here:")
    message("\tInclude dir ${GLUT_INCLUDE_DIR}")
    message("\tLibraries   ${GLUT_LIBRARIES}")
endif()
target_include_directories(${GLUT_INCLUDE_DIR})


find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    message("OpenGL is found here:")
    message("\tInclude dir ${OpenGL_INCLUDE_DIRS}")
    message("\tLibraries   ${OPENGL_LIBRARIES}")
endif()
include_directories(${OpenGL_INCLUDE_DIRS})

target_include_directories(include)
find_library(PTHREAD_LIBRARY pthread)
find_library(PCRE_LIBRARY pcre)

add_executable(main src/main.cpp 
		    include/Base.h
		    src/Base.cpp 
		    include/network.h 
		    src/network.cpp 
		    include/Missile.h 
		    src/Missile.cpp
		    include/AirDefenceSystem.h
		    src/AirDefenceSystem.cpp
		    src/consolePreparation.cpp
		    include/Constants.h
		    src/Constants.cpp
		    src/render.cpp
		    src/renderThread.cpp)


target_link_libraries(main ${PTHREAD_LIBRARY} ${PCRE_LIBRARY})
		    