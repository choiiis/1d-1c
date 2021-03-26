#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int next_weight, idx = 0;
    int cur_weight = truck_weights[0];
    q.push(truck_weights[0]);
    idx += 1;
    answer += 1;

    while(!q.empty()) {
        // time count
        answer++;        
        // if all truck passed
        if(idx >= truck_weights.size()) {
            answer += bridge_length - 1;
            break;
        }

        next_weight = truck_weights[idx];
        // if bridge is enough to add next truck
        if(cur_weight + next_weight <= weight) {
            q.push(next_weight);
            cur_weight += next_weight;
            idx++;
        }
        // if bridge cannot handle next truck
        else {
            q.push(0);
        }
        // bridge length full -> pop front
        if(q.size() >= bridge_length){
            cur_weight -= q.front();
            q.pop();
        }
    }

    return answer;
}