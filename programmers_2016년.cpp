#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    // 0: SUN, 1: MON, 2: TUE, 3: WED, 4: THU, 5: FRI, 6: SAT
    int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int val = 5;
    
    for(int i = 1; i <= 12; i++) {
        for(int j = 1; j <= days[i-1]; j++) {
            if(i == a && j == b) {
                switch(val) {
                    case 0: 
                        return "SUN";
                    case 1:
                        return "MON";
                    case 2:
                        return "TUE";
                    case 3:
                        return "WED";
                    case 4:
                        return "THU";
                    case 5:
                        return "FRI";
                    case 6:
                        return "SAT";
                }
            }
            
            if(val == 6)
                val -= 6;
            else
                val++;
        }
    }
}