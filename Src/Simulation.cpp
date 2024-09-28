#include "Simulation.h"
/**
 * @file Simulation.cpp
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#include <stdlib.h>
#include <time.h>


#define CEIL_DIV(_X,_Y)  ((_X + _Y - 1)/_Y)
using namespace std;

Simulation::Simulation(uint16_t rows, uint16_t cols) :
m_rows(rows),
m_cols(cols)
{
    int buffer_dim_x = CEIL_DIV(m_cols, 8);
    int buffer_dim_y = m_rows;

    //m_buffer[r][c]
    //m_buffer[y][x]
    m_buffer = vector_2D_t(buffer_dim_y,
    vector_row_t(buffer_dim_x));
}

Simulation::~Simulation()
{

}

uint16_t Simulation::Get_Rows()
{
    return m_rows;
}

uint16_t Simulation::Get_Cols()
{
    return m_cols;
}

bool Simulation::Get_State(uint16_t row, uint16_t col)
{
    //Check if the relevant bit is set
    uint8_t octet = m_buffer[row][col/8];
    return ((octet & (1 << (col & 0b111))) != 0);
}

void Simulation::Init(int32_t seed)
{
    if(seed)
    {
        srand(seed);
    }
    else
    {
        srand(time(NULL));
    }

    for(auto& row : m_buffer)
    {
        for(auto& octet : row)
        {
            int rnd = rand();

            //Should roughly be half populated cells overall
            octet = ((uint8_t*)&rnd)[0] & ((uint8_t*)&rnd)[1];
        }
    }
}


void Simulation::Tick()
{
    //For a tick is to be tocked, so all tocks shall tick.
}