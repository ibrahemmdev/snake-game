#include <iostream>
#include <raylib.h>
#include "utils.h"
#include "variables.h"

using namespace std;

class Food {
    private:
        pair<int, int> position;
        Texture2D texture;
    public:
        Food (deque<pair<int, int>> dq) {
            position = generateRandomePosition(dq);
            Image img = LoadImage("images/food.png");
            texture = LoadTextureFromImage(img);
            UnloadImage(img);
        }

        ~Food () {
            UnloadTexture(texture);
        }

        void DrawFood() {
            auto [x, y] = position;
            DrawTexture(texture, OFFSET + x * CELL_SIZE, OFFSET + y * CELL_SIZE, WHITE);
        }

        pair<int, int> getFoodPosition(){
            return position;
        }

        pair<int, int> generateRandomePosition(deque<pair<int, int>> dq){
            int x = GetRandomValue(0, CELL_COUNT - 1);
            int y = GetRandomValue(0, CELL_COUNT - 1);
            
            while(elementInDeque(pair<int,int>{x, y}, dq)) {
                generateRandomePosition(dq);
            }
            
            return {x, y};
        }

        void updatePosition(deque<pair<int, int>> dq){
            position = generateRandomePosition(dq);
        }
};