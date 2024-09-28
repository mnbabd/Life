/**
 * @file Simulation.h
 * @brief 
 * 
 * @author Muneeb (mnb.abd@gmail.com)
 * Copyright (c) 2024 Muneeb - All Rights Reserved.
 */

#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdint.h>
#include <vector>
#include <atomic>

// typedef std::vector<std::atomic<uint8_t>> vector_row_t;
typedef std::vector<uint8_t> vector_row_t;
typedef std::vector<vector_row_t>    vector_2D_t;

class Simulation
{
    public:
    Simulation(uint16_t rows, uint16_t cols);

    void Init(int32_t seed = 0);

    void Tick();

    uint16_t Get_Rows();

    uint16_t Get_Cols();

    bool Get_State(int row, int col);

    void Set_State(vector_2D_t& buff, int row, int col, bool alive);

    ~Simulation();

    protected:
    uint8_t Get_Neighbours(int row, int col);

    const uint16_t m_rows;
    const uint16_t m_cols;
    vector_2D_t m_buffer;
};

#endif