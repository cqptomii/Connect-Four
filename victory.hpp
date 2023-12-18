//
// Created by tfraisse on 17/12/23.
//

#ifndef CONNECT_FOUR_VICTORY_HPP
#define CONNECT_FOUR_VICTORY_HPP
#include "Window.hpp"
int victory(int matrix[7][6],int valeur);
int find_bottom(int matrix[7][6],int line,int column,int value);
int find_left(int matrix[7][6],int line,int column,int value);
int find_right(int matrix[7][6],int line,int column,int value);
int find_middle(int matrix[7][6],int line,int column,int value);
#endif //CONNECT_FOUR_VICTORY_HPP
