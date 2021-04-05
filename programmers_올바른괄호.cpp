#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int index = 0;
    stack<char> st;
  
    while(index < s.length()) {
        char cur = s[index];
        if(cur == ')') {
            if(st.empty())
                return false;
            
            else {
                if(st.top() == '(')
                    st.pop();
                else
                    st.push(cur);
            }   
        }
        else
            st.push(cur);
        index++;
    }
    if(!st.empty())
        return false;
    
    return answer;
}