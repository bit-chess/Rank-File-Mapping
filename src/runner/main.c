#include "raylib.h"
#include "../scene/background.h"
#include "../scene/mark.h"
#include "../scene/match_house.h"
#include "../bitboard/bit.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight + 100, "bit-chess | Board Status");

    setup_background(screenWidth, screenHeight);
    setup_mark();

    SetTargetFPS(60);

    char board[8][8];
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j] = 'x';
    
    Vector2 mouse_pos;

    int clicked = 0;

    while (!WindowShouldClose()){
        // Update
        //----------------------------------------------------------------------------------
        mouse_pos = GetMousePosition();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && mouse_pos.x <= screenWidth && mouse_pos.y <= screenHeight) {
            mapping_idx board_idx = match_board(mouse_pos.y, mouse_pos.x);
            if(board_idx.i != 8 && board_idx.j != 8){
                if(board[board_idx.i][board_idx.j] == 'x') board[board_idx.i][board_idx.j] = 'M';
                else board[board_idx.i][board_idx.j] = 'x';
            }
        }

        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)  && mouse_pos.y > screenHeight){
            clicked = 1;
            read_bitboard(board);
        }else {
            clicked = 0;
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            draw_background();
            draw_mark(board);

            if(!clicked){
                DrawRectangle(0, screenHeight, screenWidth, screenHeight + 100, Fade(ORANGE, 0.5f));
                DrawRectangleLines(0, screenHeight, screenWidth, screenHeight + 100, ORANGE);
            }else{
                DrawRectangle(0, screenHeight, screenWidth, screenHeight + 100, Fade(MAROON, 0.5f));
                DrawRectangleLines(0, screenHeight, screenWidth, screenHeight + 100, MAROON);
            }
            DrawText("BITBOARD", screenWidth / 2 - 40, screenHeight + 30, 20, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    unload_background();
    unload_mark();

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}