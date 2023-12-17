#include <iostream>
#include "Window.hpp"
#include "mouse_verif.hpp"
int main() {
    Window play_area;
    if(!play_area.setup_window()){
        return -1;
    }
    play_area.load_background();
    //init Victory matrix
    short matrix_pion[7][6]={0};

    //init position variable of the grid
    short first_circle_x=23,first_circle_y=115;
    //spacing between two circle
    short spacing_y=14,spacing_x=14,circle_area=71;
    // mouse position variable
    int mouse_position_x=0,mouse_position_y=0;
    int compteur=0,column,line;
    bool quit=false;
    while(!quit){
        bool show=true;
        SDL_Event game_event;
        while(SDL_PollEvent(&game_event) != 0) {
            line = -1;
            column = -1;
            switch (game_event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    //obtain the column
                    if (game_event.button.x >= 32 && game_event.button.x <= 102) {
                        column = 0;
                    }
                    if (game_event.button.x >= (32 + (spacing_x + circle_area) * 1) &&
                        game_event.button.x <= (102 + (spacing_x + circle_area) * 1)) {
                        column = 1;
                    }
                    if (game_event.button.x >= (32 + (spacing_x + circle_area) * 2) &&
                        game_event.button.x <= (102 + (spacing_x + circle_area) * 2)) {
                        column = 2;
                    }
                    if (game_event.button.x >= (32 + (spacing_x + circle_area) * 3) &&
                        game_event.button.x <= (102 + (spacing_x + circle_area) * 3)) {
                        column = 3;
                    }
                    if (game_event.button.x >= (32 + (spacing_x + circle_area) * 4) &&
                        game_event.button.x <= (102 + (spacing_x + circle_area) * 4)) {
                        column = 4;
                    }
                    if (game_event.button.x >= (32 + (spacing_x + circle_area) * 5) &&
                        game_event.button.x <= (102 + (spacing_x + circle_area) * 5)) {
                        column = 5;
                    }
                    if (game_event.button.x >= (32 + (spacing_x + circle_area) * 6) &&
                        game_event.button.x <= (102 + (spacing_x + circle_area) * 6)) {
                        column = 6;
                    }
                    if (matrix_pion[column][5] == 0) {
                        line = 5;
                    } else {
                        if (matrix_pion[column][4] == 0) {
                            line = 4;
                        } else {
                            if (matrix_pion[column][3] == 0) {
                                line = 3;
                            } else {
                                if (matrix_pion[column][2] == 0) {
                                    line = 2;
                                } else {
                                    if (matrix_pion[column][1] == 0) {
                                        line = 1;
                                    } else {
                                        if (matrix_pion[column][0] == 0) {
                                            line = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (line >= 0 && column >= 0) {
                        if (!(compteur % 2)) {
                            play_area.load_pion("./image/pion_jaune.png",
                                                (first_circle_x + (circle_area + spacing_x) * column),
                                                (first_circle_y + (circle_area + spacing_y) * line));
                            matrix_pion[column][line] = 2;
                        } else {
                            play_area.load_pion("./image/pion_rouge.png",
                                                (first_circle_x + (circle_area + spacing_x) * column),
                                                (first_circle_y + (circle_area + spacing_y) * line));
                            matrix_pion[column][line] = 1;
                        }
                        ++compteur;
                    }
                    break;
            }
        }
        SDL_Delay(100);
    }
    return 0;
}
