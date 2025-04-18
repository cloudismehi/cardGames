#include <iostream>
#include <raylib.h>
#include <vector>

int main(){
    InitWindow(1000, 1000, "half man with the body of a shark"); 
    SetTargetFPS(60); 

    Rectangle rec = {100.f, 100.f, 200.f, 200.f}; 
    Color col[] = {BLACK, WHITE}; 
    std::vector<Vector2> circles; 

    int _index = 0; 
    while(!WindowShouldClose()){
        BeginDrawing(); 
        ClearBackground(WHITE); 
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mousePos = {(float)GetMouseX(), (float)GetMouseY()}; 
            if (CheckCollisionPointRec(mousePos, rec)){
                if (++_index >= 2) _index = 0; 
            }
            else circles.push_back(mousePos); 
        }
        for (auto val : circles){
            DrawCircleV(val, 5, BLACK); 
        }
        DrawRectangleRec(rec, col[_index]); 
        EndDrawing(); 
    }
    CloseWindow(); 
    return 0; 
}