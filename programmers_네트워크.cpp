#include <string>
#include <vector>

using namespace std;

vector<vector<int>> gComputers;
void DFS(int x) {
    for(int i = 0; i < gComputers[x].size(); i++) {
        if(gComputers[x][i] == 1) {
            gComputers[x][i] = 0;
            gComputers[i][x] = 0;
            DFS(i);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    gComputers = computers;
    for(int i = 0; i < gComputers.size(); i++) {
        for(int j = 0; j < gComputers.size(); j++) {
            if(gComputers[i][j] == 1) {
                answer++;
                gComputers[i][j] = 0;
                gComputers[j][i] = 0;
                DFS(j);
            }
        }
    }
    return answer;
}

/*
테스트 1 〉	통과 (0.01ms, 3.96MB)
테스트 2 〉	통과 (0.01ms, 3.98MB)
테스트 3 〉	통과 (0.01ms, 3.97MB)
테스트 4 〉	통과 (0.01ms, 3.97MB)
테스트 5 〉	통과 (0.01ms, 3.97MB)
테스트 6 〉	통과 (0.04ms, 3.96MB)
테스트 7 〉	통과 (0.01ms, 3.97MB)
테스트 8 〉	통과 (0.02ms, 3.97MB)
테스트 9 〉	통과 (0.02ms, 3.88MB)
테스트 10 〉	통과 (0.02ms, 3.97MB)
테스트 11 〉	통과 (0.11ms, 3.99MB)
테스트 12 〉	통과 (0.08ms, 3.97MB)
테스트 13 〉	통과 (0.04ms, 3.97MB)
*/

#include <string>
#include <vector>

using namespace std;

void DFS(int x, vector<vector<int>> &computers) {
    for(int i = 0; i < computers[x].size(); i++) {
        if(computers[x][i] == 1) {
            computers[x][i] = 0;
            computers[i][x] = 0;
            DFS(i, computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++) {
        for(int j = 0; j < computers.size(); j++) {
            if(computers[i][j] == 1) {
                answer++;
                computers[i][j] = 0;
                computers[j][i] = 0;
                DFS(j, computers);
            }
        }
    }
    return answer;
}
/* 포인터로 -> 시간 조금 짧아짐
테스트 1 〉	통과 (0.01ms, 3.96MB)
테스트 2 〉	통과 (0.01ms, 3.97MB)
테스트 3 〉	통과 (0.02ms, 3.95MB)
테스트 4 〉	통과 (0.02ms, 3.97MB)
테스트 5 〉	통과 (0.01ms, 3.94MB)
테스트 6 〉	통과 (0.03ms, 3.95MB)
테스트 7 〉	통과 (0.01ms, 3.98MB)
테스트 8 〉	통과 (0.02ms, 3.98MB)
테스트 9 〉	통과 (0.02ms, 3.96MB)
테스트 10 〉	통과 (0.02ms, 3.93MB)
테스트 11 〉	통과 (0.09ms, 4MB)
테스트 12 〉	통과 (0.07ms, 3.85MB)
테스트 13 〉	통과 (0.04ms, 3.95MB)
*/

