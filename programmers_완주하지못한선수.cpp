#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < completion.size(); i++) {
        if(participant[i] != completion[i])
            return participant[i];
    }
    // if not found, last participant is the answer
    return participant[participant.size() - 1];
}