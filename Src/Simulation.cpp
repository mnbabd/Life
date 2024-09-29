/**
 * @file Simulation.cpp
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */


#include "Simulation.h"

#include <stdlib.h>
#include <time.h>
#include <assert.h>


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
    m_buffer = vector_2D_t(buffer_dim_y, vector_row_t(buffer_dim_x, 0));
}

Simulation::~Simulation()
{

}

uint8_t Simulation::Get_Neighbours(int row, int col)
{
    if(row < 0)
    {
        row = m_rows + row;
    }
    
    if(col < 0)
    {
        col = m_cols + col;
    }
    
    row = row % m_rows;
    col = col % m_cols;

    uint8_t sum = (Get_State(row - 1, col - 1) ? 1 : 0)
                + (Get_State(row - 1, col    ) ? 1 : 0)
                + (Get_State(row - 1, col + 1) ? 1 : 0)
                + (Get_State(row    , col - 1) ? 1 : 0)
                + (Get_State(row    , col + 1) ? 1 : 0)
                + (Get_State(row + 1, col - 1) ? 1 : 0)
                + (Get_State(row + 1, col    ) ? 1 : 0)
                + (Get_State(row + 1, col + 1) ? 1 : 0);

    return sum;
}

uint16_t Simulation::Get_Rows()
{
    return m_rows;
}

uint16_t Simulation::Get_Cols()
{
    return m_cols;
}

bool Simulation::Get_State(int row, int col)
{
    if(row < 0)
    {
        row = m_rows + row;
    }

    if(col < 0)
    {
        col = m_cols + col;
    }

    row = row % m_rows;
    col = col % m_cols;

    //Check if the relevant bit is set
    uint8_t octet = m_buffer[row][col/8];
    return ((octet & (1 << (col & 0b111))) != 0);
}

void Simulation::Set_State(vector_2D_t &buff, int row, int col, bool alive)
{
    assert(buff.size() == m_buffer.size());
    assert(buff[0].size() == m_buffer[0].size());

    if(row < 0)
    {
        row = m_rows + row;
    }

    if(col < 0)
    {
        col = m_cols + col;
    }

    row = row % m_rows;
    col = col % m_cols;

    //Get the relevant octet
    uint8_t octet = buff[row][col/8];

    if(alive)
    {
        //Set the bit
        octet |= (1 << (col & 0b111));
    }
    else
    {
        //Clear the bit
        octet &= (~(1 << (col & 0b111)));
    }

    //Update value
    buff[row][col/8] = octet;
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
    vector_2D_t future = vector_2D_t(m_buffer.size(),
    vector_row_t(m_buffer[0].size()));

    //Determine the future
    for(uint16_t r = 0; r < m_rows; r++)
    {
        for(uint16_t c = 0; c < m_cols; c++)
        {
            //We are determining the future of (r,c)
            uint8_t sum = Get_Neighbours(r,c);

            if(Get_State(r,c))
            {
                //Alive
                if((sum < 2) || (sum > 3))
                {
                    //No more...
                    Set_State(future, r, c, false);
                }
                else
                {
                    //Stayin' alive
                    Set_State(future, r, c, true);
                }
            }
            else
            {
                //No life here
                if(sum == 3)
                {
                    //But it finds a way
                    Set_State(future, r, c, true);
                }
                else
                {
                    //Mark it so
                    Set_State(future, r, c, false);
                }
            }
        }
    }

    //deepcopy future into present
    std::copy(future.begin(), future.end(), m_buffer.begin());
}