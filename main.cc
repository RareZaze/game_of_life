/**
 * @file main.cc
 * @author Zachary Long (zaze.rf.gd@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-09-23
 * 
 * 
 */

//The purpose of this program is to demonstrate the use of the game of life, a cellular automaton.
//The intention is for this program to eventually be used with a GUI, but for now it will be a simple command line program.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "game_of_life.h"

using namespace std;


int main(int argc, char* argv[]) {
    string filename;
    cout << "Welcome to the Game of Life!" << endl;
    cout << "Please enter the filename of the grid you would like to load: ";
    cin >> filename;

    string input = "";

    GameOfLife game;
    game.load_grid(filename);

    while(true){
        game.print_grid();
        //cout << "Press 'q' to quit, or any other key to continue: ";
        system("sleep 0.1");
        system("clear");
        game.update_grid();
        game.save_grid(filename);
    }

    


    return 0;
}