//
// Created by tfraisse on 17/12/23.
//
#include "victory.hpp"
int find_left(int matrix[7][6],int line,int column,int value){
    if(matrix[column][line]==value && column <7 && line >= 0 && line <6){
        return 1+ find_left(matrix,line-1,column+1,value);
    }else{
        return 0;
    }
}
int find_right(int matrix[7][6],int line,int column,int value){
    if(matrix[column][line]==value && column <7 && line >= 0 && line <6 ){
        return 1+ find_right(matrix,line+1,column+1,value);
    }else{
        return 0;
    }
}
int find_middle(int matrix[7][6],int line,int column,int value){
    if(matrix[column][line]==value && column <7 && line >= 0 && line <6){
        return 1+ find_middle(matrix,line,column+1,value);
    }else{
        return 0;
    }
}
int find_bottom(int matrix[7][6],int line,int column,int value){
    if(matrix[column][line]==value && column <7 && line >= 0 && line <6){
        return 1+ find_bottom(matrix,line+1,column,value);
    }else{
        return 0;
    }
}
int victory(int matrix[7][6],int value){
    int aligned_piece;
    for( int i=0; i<7; i++){
        for(int k=0; k<6; k++){
            aligned_piece= find_left(matrix,k,i,value);
            if(aligned_piece==4){
                return value;
            }else {
                aligned_piece = find_middle(matrix, k, i, value);
                if (aligned_piece == 4) {
                    return value;
                } else {
                    aligned_piece = find_right(matrix, k, i, value);
                    if (aligned_piece == 4) {
                        return value;
                    }else{
                        aligned_piece = find_bottom(matrix,k,i,value);
                        if(aligned_piece == 4){
                            return value;
                        }
                    }
                }
            }
        }
    }
    return 0;
}