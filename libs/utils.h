#pragma once

#include <iostream>
#include <deque>
#include <raylib.h>

using namespace std;

double lastUpdateTime = 0;

inline bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }

    return false;
}

inline bool elementInDeque(pair<int, int> el, deque<pair<int, int>> dq) {
    for(unsigned int i = 0; i < dq.size(); i++){
        if(dq[i].first == el.first && dq[i].second == el.second){
            return true;
        }
    }
    return false;
}
