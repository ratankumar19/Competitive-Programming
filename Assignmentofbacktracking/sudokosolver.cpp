#include<iostream>
using namespace std;
#define size 9
bool getMeEmpty(int **sudoku,int &row,int &col){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(sudoku[i][j]==0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool isSafeCol(int **sudoko,int col,int element){
    for(int i=0;i<size;i++){
        if(sudoko[i][col]==element)
            return false;
    }
    return true;
}
bool isSafeRow(int **sudoko,int row,int element){
    for(int i=0;i<size;i++){
        if(sudoko[row][i]==element)
            return false;
    }
    return true;
}
bool isSafeBox(int **sudoko,int row,int col,int element){
    int rX = row - (row%3);
    int cX = col - (col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoko[i+rX][j+cX]==element)
                return false;
        }
    }
    return true;
}
bool isSafeToInsert(int **sudoku,int row,int col,int toInsert){
    if(isSafeCol(sudoku,col,toInsert) && isSafeRow(sudoku,row,toInsert) && isSafeBox(sudoku,row,col,toInsert))
        return true;
    return false;
}
bool solveSudoku(int **sudoku){
    int row,col;
    if(!getMeEmpty(sudoku,row,col)){
        return true;
    }

    for(int i=1;i<=size;i++){
        if(isSafeToInsert(sudoku,row,col,i)){
            sudoku[row][col] = i;
            if(solveSudoku(sudoku)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}
bool sudokuSolver(int sudoku[][9]){
    int **temp = new int*[size];
    for(int i=0;i<size;i++){
        temp[i] = new int[size];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            temp[i][j] = sudoku[i][j];
        }
    }
    if(solveSudoku(temp))
        return true;
    return false;
}
