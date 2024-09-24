/**
 * @file game_of_life.cc
 * @author Zachary Long (zaze.rf.gd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-23
 * 
 * 
 */

#include "game_of_life.h"
#include <iostream>
#include <fstream>


using namespace std;

GameOfLife::GameOfLife(){ //default constructor
    int size = 100;
    //Default shall be 100x100 grid for now
    for(int i = 0; i < size; i++){
        vector<bool> row;
        for(int j = 0; j < size; j++){
            row.push_back(false);
        }
        grid.push_back(row);
    }
}

GameOfLife::GameOfLife(int a){ //constructor with size parameter
    size = a;
    //Not sure if going to keep but added constructor that sets up a grid of size x size
    for(int i = 0; i < size; i++){
        vector<bool> row;
        for(int j = 0; j < size; j++){
            row.push_back(false);
        }
        grid.push_back(row);
    }
}


void GameOfLife::load_grid(std::string filename){ //loads a grid from a file
    // I want to eventually load from a binary file or bitmap but for now it will just be a dat file with asscii 1s and 0s
    ifstream input(filename);
    bool end = false;
    char c;
    for(int i = 0; i < size; i++){
        end = false;
        while(!end){           
            input >> c;
            switch(c){
                case '0':
                    grid[i].push_back(false);
                    break;
                case '1':
                    grid[i].push_back(true);
                    break;
                case '\n':
                    end = true;
                    break;
                default:
                    cout << "Invalid character in file" << endl;
                    return;
                    break;
            }
        }
    }
        
}

void GameOfLife::save_grid(std::string filename){

}

void GameOfLife::print_grid(){

}

void GameOfLife::update_grid(){

}