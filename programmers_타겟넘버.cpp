#include <string>
#include <vector>
#include <iostream>

using namespace std;

int val = 0;
int answer = 0;
int ops[2] = {1, -1};
vector<int> gNumbers;
int gTarget;

void DFS(int i) {
    for(int j = 0; j < 2; j++) {
        val += ops[j] * gNumbers[i];
        if(i < (gNumbers.size() - 1))
            DFS(i+1);
        
        else {
            if(val == gTarget)
                answer++;   
        }
        val -= ops[j] * gNumbers[i];
    }    
}

int solution(vector<int> numbers, int target) {
    gNumbers = numbers;
    gTarget = target;
    DFS(0);
    return answer;
}

/*
전역변수로 설정) 메모리 큰 차이 없음, 시간 짧아짐
테스트 1 〉	통과 (4.29ms, 3.95MB)
테스트 2 〉	통과 (4.24ms, 3.89MB)
테스트 3 〉	통과 (0.01ms, 3.98MB)
테스트 4 〉	통과 (0.02ms, 3.96MB)
테스트 5 〉	통과 (0.15ms, 3.9MB)
테스트 6 〉	통과 (0.02ms, 3.97MB)
테스트 7 〉	통과 (0.01ms, 3.73MB)
테스트 8 〉	통과 (0.04ms, 3.98MB)
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int val = 0;
int answer = 0;
int ops[2] = {1, -1};

void DFS(int i, vector<int> numbers, int target) {
    for(int j = 0; j < 2; j++) {
        val += ops[j] * numbers[i];
        if(i < (numbers.size() - 1))
            DFS(i+1, numbers, target);
        
        else {
            if(val == target)
                answer++;   
        }
        val -= ops[j] * numbers[i];
    }    
}

int solution(vector<int> numbers, int target) {
    DFS(0, numbers, target);
    return answer;
}
/*
테스트 1 〉	통과 (35.93ms, 3.75MB)
테스트 2 〉	통과 (36.21ms, 3.97MB)
테스트 3 〉	통과 (0.04ms, 3.95MB)
테스트 4 〉	통과 (0.16ms, 3.96MB)
테스트 5 〉	통과 (1.26ms, 3.98MB)
테스트 6 〉	통과 (0.09ms, 3.94MB)
테스트 7 〉	통과 (0.04ms, 3.97MB)
테스트 8 〉	통과 (0.32ms, 3.92MB)
*/