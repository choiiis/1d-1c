#include <string>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// (x1, y1), (x2, y2)
struct Pos {
    int x1;
    int y1;
    int x2;
    int y2;
};

int solution(string dirs) {
    int answer = 0;
    bool isExist = false; // route in vector or not
    vector<struct Pos> pArr; // routes vector
    pair<int, int> cur = make_pair(0, 0); // current node
    pair<int, int> next; // next node
    
    // if "LULLD" do 5 times (length of string)
    for(int i = 0; i < dirs.length(); i++) {
        isExist = false;
        if(dirs[i] == 'U') {
            next.first = cur.first;
            next.second = cur.second + 1;
        }
        else if(dirs[i] == 'L') {
            next.first = cur.first - 1;
            next.second = cur.second;
        }
        else if(dirs[i] == 'R') {
            next.first = cur.first + 1;
            next.second = cur.second;
        }
        else if(dirs[i] == 'D') {
            next.first = cur.first;
            next.second = cur.second - 1;
        }
        
        // if pos out of the map
        if(next.first < -5 || next.first > 5 || next.second < -5 || next.second > 5)
            continue;

        // if pos already in the routes vector
        for(int j = 0; j < pArr.size(); j++) {
                if(pArr[j].x1 == cur.first && pArr[j].y1 == cur.second 
                   && pArr[j].x2 == next.first && pArr[j].y2 == next.second){
                    isExist = true;
                }
        }
        
        // if pos no in the routes vector
        if(isExist == false) {
            pArr.push_back({cur.first, cur.second, next.first, next.second});
            pArr.push_back({next.first, next.second, cur.first, cur.second});
            answer++;
        }
        
        //next node become the current node
        cur.first = next.first;
        cur.second = next.second;
    }
    
    return answer;
}