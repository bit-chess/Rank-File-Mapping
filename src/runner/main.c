#include "raylib.h"
#include "../scene/background.h"
#include "../scene/piece.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {


    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess | Board Status");

    setup_background(screenWidth, screenHeight);
    setup_pieces();

    SetTargetFPS(60);

    char board[8][8];
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j] = 'x';
    int turn = 1;

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();
            draw_pieces(board);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();
    unload_pieces();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}