//
//  pa1.cpp
//  Project 1
//
//  Created by Alexandra Munoz on 2/17/16.
//  Copyright © 2016 Alexandra Munoz. All rights reserved.
//


#include <iostream>
#include <cmath>
#include "pa1.h"
using namespace std;

int main() {
    int s;
//Get size of array and check if input is an odd integer between 3 and 15
    do{
        cout << "Enter the size of a magic square: ";
        cin>>s;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }while((s%2)==0 || s<3 || s>15 || s == 0 || cin.fail());
//Create 2D dynamic array
    int **square = new int*[s];
    for(int i = 0; i < s; i++){
        square[i] = new int[s];
    }
//Fill entries of array with 0
    for(int row = 0; row < s; row++) {
        for(int col = 0; col < s; col++) {
            square[row][col] = 0;
        }
    }
//Start creating magic square by placing 1 in the top row and middle column
    int r = 0;
    int c = (s-1)/2;
    square[r][c]=1;
/*Create magic square by moving up one entry and to the right (to the entry in previous row and next column over) and placing numbers, starting with 2 since 1 is already placed, in order up to integer the user entered squared */
    for(int i = 2; i < ((pow(s,2))+1); i++){
        r--;
        c++;
/*If entry of last entered number is in the corner, then moving up and to the right means going out of the array, so the next number goes to entry in the row below and same column*/
        if(r == -1 && c == s){
            r = 1;
            c = s-1;
        }
/*If moving up one entry means going above the array (row would be -1 because row of previous entry was 0), number goes to the last row (same column) then moves to the right from there*/
        if(r == -1){
            r = s-1;
        }
/*If moving up one entry and then going to the right means going outside the array to the right, number goes to the first column */
        if(c == s){
            c = 0;
        }
/*If number in the entry that you have arrived at is not zero, which means an integer is already there, the number goes in the entry below the entry of the last entered number */
        if(square[r][c] != 0){
            r = r + 2;
            c = c-1;
        }
        square[r][c] = i;
    }
//Print out first magic square
    cout<< "Magic Square #1 is: " <<endl;
    for(int row = 0; row < s; row++) {
        for(int col = 0; col < s; col++) {
            cout<<square[row][col]<<" ";
        }
        cout<<"\n";
    }
//Print out sums of rows, columns, and diagonals
    displayRowSum(square, s);
    displayColumnSum(square, s);
    topRightDiagSum(square, s);
    topLeftDiagSum(square, s);
    
//Create 2nd array
    int **square2 = new int*[s];
    for(int i = 0; i < s; i++){
        square2[i] = new int[s];
    }
/*Second array is first array with rows and columns switched (first row of square 1 is first columnn of square 2, etc)*/
    for(int r = 0; r < s; r++){
        for(int c = 0; c < s; c++){
           square2[r][c] = square[c][r];
        }
    }
//Print out magic square 2
    cout<< "Magic Square #2 is: " <<endl;
    for(int row = 0; row < s; row++) {
        for(int col = 0; col < s; col++) {
            cout<<square2[row][col]<<" ";
        }
        cout<<"\n";
    }
    
//Print out sums of rows, columns, and diagonals
    displayRowSum(square2, s);
    displayColumnSum(square2, s);
    topRightDiagSum(square2, s);
    topLeftDiagSum(square2, s);

//Create 3rd array
    
    int **square3 = new int*[s];
    for(int i = 0; i < s; i++){
        square3[i] = new int[s];
    }
//Third array is second array flipped across a y-axis
    for(int r = 0; r < s; r++){
        for(int c = 0; c < s; c++){
            square3[r][c] = square2[r][s-1-c];
        }
    }
//Print out magic square 3
    cout<< "Magic Square #3 is: " <<endl;
    for(int row = 0; row < s; row++) {
        for(int col = 0; col < s; col++) {
            cout<<square3[row][col]<<" ";
        }
        cout<<"\n";
    }
//Print out sums of rows, columns, and diagonals
    displayRowSum(square3, s);
    displayColumnSum(square3, s);
    topRightDiagSum(square3, s);
    topLeftDiagSum(square3, s);
    
    delete [] square;
    delete [] square2;
    delete [] square3;
    
    return 0;
}

