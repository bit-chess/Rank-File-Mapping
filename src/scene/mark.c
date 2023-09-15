#include "mark.h"
#include "raylib.h"

Texture2D  mark_piece;

Vector2 allof_pos[8][8];

void setup_mark(void){
    mark_piece = LoadTexture("../assets/mark_house.png");

    for(int i = 0 ; i < 8; i++) {
        for(int j = 0 ; j < 8; j++) {
            allof_pos[i][j] = (Vector2){(float)(POS_X_INITAL + j * DISTANCE_PIECE), (float)(POS_Y_INITAL + (i * DISTANCE_PIECE))};
        } 
    }
}

void draw_mark(char board[8][8]){
    for(int i = 0 ; i < 8; i++) {
        for(int j = 0 ; j < 8; j++) {
            switch (board[i][j]){
                case 'M':
                    DrawTextureRec(mark_piece, (Rectangle){0, 0, 40, 50}, allof_pos[i][j], WHITE);
                    break;

                default:
                    break;
            }
        } 
    }
}

void unload_mark(void){
    UnloadTexture(mark_piece);
}