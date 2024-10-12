cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(Life CXX C)

add_subdirectory(Src)


option(ENABLE_ADDRESS_SANITIZER "Address Sanitisation with libasan" OFF)
option(ENABLE_PROFILING "gprof based profiling" ON)
option(PROFILING_LINE_BY_LINE "Higher level of profiling detail" OFF)
option(PROFILING_BLOCK_COUNTING "Count branch/block executions" OFF)

if(ENABLE_ADDRESS_SANITIZER)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif(ENABLE_ADDRESS_SANITIZER)


if(ENABLE_PROFILING)
    if (UNIX)
        #This is for unix-like systems e.g. linux.
        add_compile_options(-pg)
        add_link_options(-pg)
        if(PROFILING_LINE_BY_LINE)
            add_compile_options(-g)
            add_link_options(-g)
        endif(PROFILING_LINE_BY_LINE)
        if(PROFILING_LINE_BY_LINE)
            add_compile_options(-a)
            add_link_options(-a)
        endif(PROFILING_LINE_BY_LINE)
    else()
        message("If you're on Windows. Try using profiling tools built into VSCommunity instead. Or something else based on preference.")
    endif (UNIX)
endif(ENABLE_PROFILING)


#Setting up Logging levels [todo] extract to different file (autogenerate in the future)
set(Debug_Levels 
"Verbose"
"Debug"
"Info"
"Warning"
"Critical"
"Fatal")

option(OVERRIDE_LOG_LEVEL "Override log levels of all modules" OFF)

if(OVERRIDE_LOG_LEVEL)
    set(OVERRIDEN_LOG_LEVEL "Info"
    CACHE STRING "Overriden log level of all Modules")
    set_property(CACHE OVERRIDEN_LOG_LEVEL PROPERTY STRINGS ${Debug_Levels})
    list(FIND Debug_Levels ${OVERRIDEN_LOG_LEVEL} ALL_LOG_LEVEL_IDX)
    add_compile_definitions(LOG_LEVEL_ALL=${ALL_LOG_LEVEL_IDX})
else()
    #Add options for all the modules using logging module
    set(LOG_LEVEL_MAIN "Info"
    CACHE STRING "Main.cpp log level")
    set_property(CACHE LOG_LEVEL_MAIN PROPERTY STRINGS ${Debug_Levels})
    list(FIND Debug_Levels ${LOG_LEVEL_MAIN} MAIN_LOG_LEVEL_IDX)
    add_compile_definitions(MAIN_LOG_LEVEL=${MAIN_LOG_LEVEL_IDX})

    set(LOG_LEVEL_VISUALISE "Info"
    CACHE STRING "Visualise module log level")
    set_property(CACHE LOG_LEVEL_VISUALISE PROPERTY STRINGS ${Debug_Levels})
    list(FIND Debug_Levels ${LOG_LEVEL_VISUALISE} VISUALISE_LOG_LEVEL_IDX)
    add_compile_definitions(VISUALISE_LOG_LEVEL=${VISUALISE_LOG_LEVEL_IDX})
endif()


add_executable(life ${Life_Includes} ${Life_Sources})

if(MSVC)
#-DGLUT_INCLUDE_DIR=${projectDir}\freeglut\include -DGLUT_glut_LIBRARY=${projectDir}\freeglut\lib
set(GLUT_INCLUDE_DIR "${GLUT_DIR}/include")
set(GLUT_glut_LIBRARY "${GLUT_DIR}/lib/x64")
#set(OPENGL_LIBRARY_DIR ${GLUT_DIR}/bin)
else()
find_package(GLUT REQUIRED)
endif()


if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
    set(GLUT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/freeglut" CACHE STRING "Location of freeGLUT")
endif(NOT GLUT_FOUND)

message("GLUT_INCLUDE_DIR = ${GLUT_INCLUDE_DIR}")
include_directories(${GLUT_INCLUDE_DIR})

file(GLOB SRC_FILES ${GLUT_INCLUDE_DIR}/*)
target_sources(life PUBLIC ${SRC_FILES})

if(MSVC)
target_link_libraries(life 
freeglut)
else()
target_link_libraries(life 
GLU GL glut)
endif()