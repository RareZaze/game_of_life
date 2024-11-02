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
    //int size = 100;
    //Default shall be 100x100 grid for now
    for(int i = 0; i < size; i++){
        vector<bool> row;
        for(int j = 0; j < size; j++){
            row.push_back(false);
        }
        grid.push_back(row);
    }
}

/*GameOfLife::GameOfLife(int a){ //constructor with size parameter
    size = a;
    //Not sure if going to keep but added constructor that sets up a grid of size x size
    for(int i = 0; i < size; i++){
        vector<bool> row;
        for(int j = 0; j < size; j++){
            row.push_back(false);
        }
        grid.push_back(row);
    }
}*/


void GameOfLife::load_grid(std::string filename){ //loads a grid from a file
    // I want to eventually load from a binary file or bitmap but for now it will just be a dat file with asscii 1s and 0s
    ifstream input(filename);
    char c;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){          
            input >> c; 
            switch(c){
                case '0':
                    grid[i][j] = false;
                    break;
                case '1':
                    grid[i][j] = true;
                    break;
                /*case '\n':
                    end = true;
                    break;*/
                default:
                    cout << "Invalid character in file" << endl;
                    return;
                    break;
            }
        }
    }

    input.close();
        
}

void GameOfLife::save_grid(std::string filename){ //saves the grid to a file
    ofstream output(filename);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid[i][j]){
                output << '1';
            } else {
                output << '0';
            }
        }
        output << '\n';
    }
    output.close();
}

void GameOfLife::print_grid(){ //prints grid to the console
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(grid[i][j]){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

}

void GameOfLife::update_grid(){ //updates the grid based on the rules of the game of life
    vector<vector<bool>> new_grid;
    for(int i = 0; i < size; i++){
        vector<bool> row;
        for(int j = 0; j < size; j++){
            row.push_back(false);
        }
        new_grid.push_back(row);
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int count = 0;
            for(int k = -1; k < 2; k++){
                for(int l = -1; l < 2; l++){
                    if(k == 0 && l == 0){
                        continue;
                    }
                    if(i + k < 0 || i + k >= size || j + l < 0 || j + l >= size){
                        continue;
                    }
                    if(grid[i + k][j + l]){
                        count++;
                    }
                }
            }
            if(grid[i][j]){
                if(count < 2 || count > 3){
                    new_grid[i][j] = false;
                } else {
                    new_grid[i][j] = true;
                }
            } else {
                if(count == 3){
                    new_grid[i][j] = true;
                } else {
                    new_grid[i][j] = false;
                }
            }
        }
    }
    grid = new_grid;

}