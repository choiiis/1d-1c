#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int solution(string begin, string target, vector<string> words) {
    int answer = 0, count = 0, idx = 0;
    string cur, next, val1, val2;
    queue<string> q;
    int len = begin.size();
    bool check[10] = {false, };
    q.push(begin);
    
    while(!q.empty()) {
        count++;
        cur = q.front();
        for(int i = 0; i < len; i++) {
            if(cur[i] == target[i]) {
                cout << "check :: " << i << endl;
                check[i] = true;
            }
        }
        
        for(int i = 0; i < len - 1; i++) {
            if(check[i] == true)
                continue;
            val1 = cur.substr(0, i) + cur.substr(i+1, cur.size()-i-1);
            for(int j = 0; j < words.size(); j++) {
                for(int k = 0; k < len; k++) {
                    if(i == k)
                        continue;
                    if(cur[k] != words[j][k])
                        break;
                    q.push(words[j]);                    
                }
                if(i == idx)
                    continue;
                if(cur[i] == words[j][i])
                    
                val2 = words[j].substr(0, i) + words[j].substr(i+1, words[j].size()-i-1);
                if(val1 == val2) {
                    if(target == words[j])
                        return answer;
                    else {
                        cout << "push :: " << words[j] << endl;
                        q.push(words[j]);
                    }
                }
            }
        }
        q.pop();
    }
    return 0;
}

/* 테스트케이스 1번 틀림 */