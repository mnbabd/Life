

set(Life_Sources
${CMAKE_CURRENT_SOURCE_DIR}/logging.c
${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Visualise.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Simulation.cpp
PARENT_SCOPE)


set(Life_Includes
    ${CMAKE_CURRENT_SOURCE_DIR}/logging.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Visualise.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Simulation.h
PARENT_SCOPE)
