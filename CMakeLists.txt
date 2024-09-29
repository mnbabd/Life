cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Life CXX C)

add_subdirectory(Src)


option(ENABLE_ADDRESS_SANITIZER "Address Sanitisation with libasan" OFF)

if(ENABLE_ADDRESS_SANITIZER)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
endif(ENABLE_ADDRESS_SANITIZER)

#Setting up Logging levels [todo] extract to different file (autogenerate in the future)
set(Debug_Levels 
"Log_Verbose"
"Log_Debug"
"Log_Info"
"Log_Warning"
"Log_Critical"
"Log_Fatal")

#Add options for all the modules using logging module
set(LOG_LEVEL_MAIN "Log_Info"
CACHE STRING "main.cpp log level")
set_property(CACHE LOG_LEVEL_MAIN PROPERTY STRINGS ${Debug_Levels})
list(FIND Debug_Levels ${LOG_LEVEL_MAIN} MAIN_LOG_LEVEL_IDX)
add_compile_definitions(MAIN_LOG_LEVEL=${MAIN_LOG_LEVEL_IDX})

set(LOG_LEVEL_VISUALISE "Log_Info"
CACHE STRING "Visualise module log level")
set_property(CACHE LOG_LEVEL_VISUALISE PROPERTY STRINGS ${Debug_Levels})
list(FIND Debug_Levels ${LOG_LEVEL_VISUALISE} VISUALISE_LOG_LEVEL_IDX)
add_compile_definitions(VISUALISE_LOG_LEVEL=${VISUALISE_LOG_LEVEL_IDX})


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