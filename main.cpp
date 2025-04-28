#include <iostream>
#include <raylib.h>
#include "libs/foodClass.h"
#include "libs/snakeClass.h"
#include "libs/utils.h"
#include "libs/variables.h"

using namespace std;

int main () {
    InitWindow(2* OFFSET + SCREEN_WIDTH, 2* OFFSET + SCREEN_HEIGHT, SCREEN_TITLE);
    SetTargetFPS(FRAME_PER_SEC);

    Snake snake = Snake();
    Food food = Food(snake.getBody());
    int score = 0;

    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(green);
        DrawRectangleLinesEx(Rectangle{OFFSET - 5, OFFSET - 5, CELL_SIZE * CELL_COUNT + 10, CELL_SIZE * CELL_COUNT + 10 }, 5, darkGreen);
        DrawText("Snake Game", OFFSET - 5, 20, 40, darkGreen);
        DrawText(TextFormat("%i", score), OFFSET - 5, OFFSET + CELL_SIZE * CELL_COUNT + 10, 40,darkGreen);

        food.DrawFood();
        snake.DrawSnake();

        if(eventTriggered(0.2)){
            if(snake.getRunning() == true){
                snake.checkHitEdges();
                snake.checkHitTail();
                if(snake.UpdateDireaction(food.getFoodPosition())){
                    food.updatePosition(snake.getBody());
                    score++;
                };
            } else {
                score = 0;
            }
        }
        
        if(IsKeyPressed(KEY_UP) && snake.getDirection().second != 1){
            snake.remakeDireactions({0, -1});
            snake.updateRunning(true);
        } else if(IsKeyPressed(KEY_DOWN) && snake.getDirection().second != -1){
            snake.remakeDireactions({0, 1});
            snake.updateRunning(true);
        } else if(IsKeyPressed(KEY_RIGHT) && snake.getDirection().first != -1){
            snake.remakeDireactions({1, 0});
            snake.updateRunning(true);
        } else if(IsKeyPressed(KEY_LEFT) && snake.getDirection().first != 1){
            snake.remakeDireactions({-1, 0});
            snake.updateRunning(true);
        }

        EndDrawing();
    }

    CloseWindow();
}