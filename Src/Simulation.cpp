#include "Simulation.h"
/**
 * @file Simulation.cpp
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#define CEIL_DIV(_X,_Y)  ((_X + _Y - 1)/_Y)

using namespace std;

Simulation::Simulation(uint16_t rows, uint16_t cols) :
m_rows(rows),
m_cols(cols)
{
    int buffer_dim_x = CEIL_DIV(m_cols, 8);
    int buffer_dim_y = CEIL_DIV(m_rows, 8);
    m_buffer = vector_2D_t(buffer_dim_y,
    vector_row_t(buffer_dim_x));
}

Simulation::~Simulation()
{
}
