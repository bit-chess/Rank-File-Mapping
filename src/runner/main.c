#include "raylib.h"
#include "../scene/background.h"
#include "../scene/mark.h"
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
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j] = 'M';
    
    Vector2 mouse_pos;

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------
        mouse_pos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) printf("(%f, %f)\n", mouse_pos.x, mouse_pos.y);
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