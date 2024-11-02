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
        GameOfLife(); //default constructor
        //GameOfLife(int a); //constructor with size parameter

        void print_grid(); //prints the grid to the console
        void load_grid(std::string filename); //loads a grid from a file
        void save_grid(std::string filename); //saves the grid to a file

        void update_grid(); //updates the grid based on the rules of the game of life
    private:
        const int size = 50; //size of the grid (size x size) to be used for referencing borders
        std::vector<std::vector<bool>> grid;
        
};

#endif // GAME_OF_LIFE_H