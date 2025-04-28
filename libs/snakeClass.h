#include <iostream>
#include <raylib.h>
#include <deque>
#include "variables.h"

using namespace std;

class Snake {
    private:
        deque<pair<int, int>> body = { pair<int, int>{6,9}, pair<int, int>{5,9}, pair<int, int>{4,9} };
        pair<int, int> direaction = {1, 0};
        bool addSegment = false;
        bool running = true;
        Sound eatSound;
        Sound wallSound;
    public:

        Snake(){
            InitAudioDevice();
            eatSound = LoadSound("sounds/Sounds_eat.mp3");
            wallSound = LoadSound("sounds/wall.mp3");
        }

        ~Snake() {
            UnloadSound(eatSound);
            UnloadSound(wallSound);
            CloseAudioDevice();
        }

        void DrawSnake() {
            for(unsigned int i = 0; i < body.size(); i++){
                auto [x, y] = body[i];
                Rectangle segment = Rectangle{ OFFSET + x * CELL_SIZE, OFFSET + y * CELL_SIZE, (float)CELL_SIZE, (float)CELL_SIZE };
                DrawRectangleRounded(segment, 0.5, 0.6, i == 0 ? RED : darkGreen);
            }
        }

        bool UpdateDireaction (pair<int, int> foodPosition) {
            if(addSegment){
                pair<int, int> newPos = { body[0].first + direaction.first, body[0].second + direaction.second };
                body.push_front(newPos);
                addSegment = false;
            } else {
                body.pop_back();
                pair<int, int> newPos = { body[0].first + direaction.first, body[0].second + direaction.second };
                body.push_front(newPos);
            }
            return checkCollection(foodPosition);
        }

        void remakeDireactions(pair<int, int> dir) {
            direaction = dir;
        }

        pair<int, int> getDirection(){
            return direaction;
        }

        deque<pair<int, int>> getBody() {
            return body;
        }

        bool checkCollection(pair<int, int> foodPosition){
            
            if(body[0].first == foodPosition.first && body[0].second == foodPosition.second){
                addSegment = true;
                PlaySound(eatSound);
                return true;
            }
            return false;
        }

        void checkHitEdges() {
            if(body[0].first == CELL_COUNT || body[0].first == -1) {
                gameOver();
            }
            if(body[0].second == CELL_COUNT || body[0].second == -1){
                gameOver();
            }
        }

        void checkHitTail() {
            deque<pair<int, int>> headless = body;
            headless.pop_front();
            if(elementInDeque(body[0], headless)){
                gameOver();
            }
        }

        void reset() {
            body = { pair<int, int>{6,9}, pair<int, int>{5,9}, pair<int, int>{4,9} };
            direaction = {1, 0};
        }

        void gameOver() {
            reset();
            running = false;
            PlaySound(wallSound);
        }

        bool getRunning(){
            return running;
        }

        void updateRunning(bool r){
            running = r;
        }
};