//
//  pa1.h
//  Project 1
//
//  Created by Alexandra Munoz on 2/18/16.
//  Copyright © 2016 Alexandra Munoz. All rights reserved.
//

#ifndef pa1_h
#define pa1_h

#include <iostream>
using namespace std;

//Method to find sums of rows
void displayRowSum(int **square, int s){
    cout<<"Checking the sums of every row: ";
    for(int r = 0; r < s; r++){
        int sumRow = 0;
        for(int c = 0; c < s; c++){
            sumRow += square[r][c];
        }
        cout<<sumRow <<" ";
    }
    cout<<endl;
}

//Method to find sums of columns
void displayColumnSum(int **square, int s){
    cout<<"Checking the sums of every column: ";
    for(int r = 0; r < s; r++){
        int sumColumn = 0;
        for(int c = 0; c < s; c++){
            sumColumn += square[c][r];
            
        }
        cout<<sumColumn <<" ";
    }
    cout<<endl;
}

//Method to find sum of diagonal that starts at top right
void topRightDiagSum(int **square, int s){
    cout<<"Checking the sums of every diagonal: ";
        int sumDiag = 0;
        int c = s-1;
        for(int r = 0; r < s; r++){
            sumDiag += square[r][c];
            c--;
        }
        cout<<sumDiag <<" ";
}

//Method to find sum of diagonal that starts at top left
void topLeftDiagSum(int **square, int s){
    int sumDiag = 0;
    for(int r = 0; r < s; r++){
        sumDiag += square[r][r];
    }
    cout<<sumDiag <<" ";
    cout<<endl;
}
#endif /* pa1_h */
