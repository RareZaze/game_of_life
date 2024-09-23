/**
 * @file game_of_life.h
 * @author Zachary Long (zaze.rf.gd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-23
 * 
 * 
 */
#include <vector>
#include <string>

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

class GameOfLife {
    public:
        GameOfLife();
        GameOfLife(int size);

        void print_grid();

        void update_grid();
    private:
        std::vector<std::vector<bool>> grid;
        void load_grid(std::string filename);
        void save_grid(std::string filename);
};

#endif // GAME_OF_LIFE_H