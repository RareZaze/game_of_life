/**
 * @file game_of_life.h
 * @author Zachary Long (zaze.rf.gd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-23
 * 
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

class GameOfLife {
    public:
        GameOfLife();
        GameOfLife(int size);

        void load_grid(std::string filename);
        void save_grid(std::string filename);

        void print_grid();

        void update_grid();
    private:
        std::vector<std::vector<bool>> grid;
};

#endif // GAME_OF_LIFE_H