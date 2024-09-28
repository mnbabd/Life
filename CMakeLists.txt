cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Life CXX)



set(Life_Sources
${Life_Sources} 
${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(Life_Includes
${Life_Includes}
${CMAKE_CURRENT_SOURCE_DIR}/logging.h
)

add_executable(life ${Life_Includes} ${Life_Sources})


# find_package(OpenGL REQUIRED)
# if (OpenGL_FOUND)
#     target_include_directories(opengl-template PRIVATE ${OPENGL_INCLDUE_DIRS})
#     target_link_libraries(opengl-template PRIVATE ${OPENGL_LIBRARIES})
# else()
#     message(FATAL_ERROR "OpenGL was not found on the system")
# endif()

# # Handle the optional libraries
# if (${ENABLE_ASSIMP})
#     include(${CMAKE_DIR}/LinkASSIMP.cmake)
#     LinkASSIMP(opengl-template PRIVATE)
# endif()
