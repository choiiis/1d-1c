#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long solution(int w,int h) {
    int nw, nh;   
    long long answer = 1;
    vector<long long> yval[2];
    double y, roundy;
    bool isExist, isDone;
    
    // W > H
    if(w < h) {
        nw = h;
        nh = w;
    }
    else {
        nw = w;
        nh = h;
    }
    
    yval[0].push_back(1);

    for(int i = 1; i < nw; i++) {
        isExist = false;
        y = double(nh) / nw * i;
        roundy = round(y);
        if(y < roundy) {
            // (x, round(y))
            for(int j = 0; j < yval[0].size(); j++) {
                if(yval[0][j] == roundy){
                    isExist = true;
                    break;
                }
            }
            if (isExist == false) {
                answer++;
            }
            // (x+1, round(y))
            yval[1].push_back(roundy);
            answer++;
        }
        
        else if(y == roundy) {
            // (x, y+1)
            for(int j = 0; j < yval[0].size(); j++) {
                if(yval[0][j] == roundy){
                    isExist = true;
                    break;
                }
            }
            if (isExist == false) {
                answer++;
            }
            // (x+1, y+1)
            yval[1].push_back(roundy + 1);
            answer++;
        }
        
        else if(y > roundy) {
            // (x, y)
            for(int j = 0; j < yval[0].size(); j++) {
                if(yval[0][j] == roundy + 1) {
                    isExist = true;
                    break;
                }
            }
            if (isExist == false) {
                answer++;
            }
            
            // (x+1, y+1)
            yval[1].push_back(roundy + 1);
            answer++;
        }
        else {}
        yval[0].clear();
        for(int i = 0; i < yval[1].size(); i++) {
            yval[0].push_back(yval[1][i]);
        }
        yval[1].clear();
    }
    
    answer = (long)w * h - answer;
    return answer;
}