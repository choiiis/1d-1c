#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<int> minArr[9];
    minArr[1].push_back(N);
    if(N == number) {
        return 1;
    }
    
    for(int i = 2; i <= 8; i++) {
        cout << minArr[i-1][0] + N * pow(10, i-1) << endl;
        minArr[i].push_back(minArr[i-1][0] + N * pow(10, i-1));
        for(int j = 1; j < i; j++) {
            for(int k = 0; k < minArr[j].size(); k++) {
                for(int p = 0; p < minArr[i-j].size(); p++){
                    int val1 = minArr[j][k];
                    int val2 = minArr[i-j][p];
                    // '+'
                    minArr[i].push_back(val1 + val2);
                    // '-'
                    minArr[i].push_back(val1 - val2);
                    // '*'
                    minArr[i].push_back(val1 * val2);
                    // '/'
                    if(val2 != 0){
                        minArr[i].push_back(val1 / val2);
                    }
                }
            }
        }
        for(int q = 0; q < minArr[i].size(); q++) {
            if(minArr[i][q] == number)
                return i;
        }
    }
    
    return -1;
}