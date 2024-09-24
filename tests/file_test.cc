/**
 * @file file_test.cc
 * @author Zachary Long (zl877220@ohio.edu)
 * @brief This program is designed to test the file stream functionality of c++, specifically when reading and writing bitstreams;
 * @version 0.1
 * @date 2024-09-23
 * 
 * 
 */

#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ofstream output("test");

    for(int i = 0; i < 256; i++){
        output << ((i%2) == 0);
    }

    output.close();

    return 0;
}