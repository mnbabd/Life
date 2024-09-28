cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Life CXX)

add_subdirectory(Src)

find_package(GLUT REQUIRED)
    message(${GLUT_INCLUDE_DIR})
    include_directories(${GLUT_INCLUDE_DIR})
    if(NOT GLUT_FOUND)
        message(ERROR "GLUT not found!")
    endif(NOT GLUT_FOUND)


add_executable(life ${Life_Includes} ${Life_Sources} ${GLUT_INCLUDE_DIR})
target_link_libraries(life 

#openGL
GLU GL glut
)