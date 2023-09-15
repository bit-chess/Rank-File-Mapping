#include "raylib.h"
#include "../scene/background.h"
#include "../scene/mark.h"
#include "../scene/match_house.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "bit-chess | Board Status");

    setup_background(screenWidth, screenHeight);
    setup_mark();

    SetTargetFPS(60);

    char board[8][8];
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j] = 'x';
    
    Vector2 mouse_pos;

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------
        mouse_pos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mapping_idx board_idx = match_board(mouse_pos.y, mouse_pos.x);
            if(board[board_idx.i][board_idx.j] == 'x') board[board_idx.i][board_idx.j] = 'M';
            else board[board_idx.i][board_idx.j] = 'x';
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();
            draw_mark(board);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();
    unload_mark();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}