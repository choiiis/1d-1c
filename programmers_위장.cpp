#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> ctg;
    
    for(int i = 0; i < clothes.size(); i++) {
        ctg[clothes[i][1]]++;
    }
    
    for(auto i = ctg.begin(); i != ctg.end(); i++) {
        answer *= (i -> second + 1);
    }
        
    return answer-1;
}

/*
공부할거
for(auto item : clothes)
    myclothes[item[1]]++;
for(auto tmp : myclothes)
    answer *= (tmp.second+1);
*/ 