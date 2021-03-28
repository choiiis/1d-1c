/* 
처음에 2중 for문으로 풀었는데 효율성 검사 통과 못함
질문게시판 보고 해결) 
sort를 하고 나면 i번째 원소가 i+1번째 원소에 포함되지 않는다면
그 뒤로는 다 안됨 --> for문 하나로 해결 가능 
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++) {
        if(phone_book[i+1].find(phone_book[i]) == 0)
            return false;   
    }
    return true;
}