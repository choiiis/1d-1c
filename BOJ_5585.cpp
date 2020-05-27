#include <iostream>

using namespace std;
int main(void) {
    int cost;
    int coin_num = 0; // the total number of coin
    cin >> cost;

    int change = 1000 - cost;
    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    
    for(int i = 0; i < 6; i++){
        int tmp = 0;
        
        // no more change. finish
        if (change == 0) {
            break;
        }

        if (change >= coin[i]) {
            // tmp : the number of coin[i]
            tmp = change / coin[i];
            coin_num += tmp;
            change -= tmp * coin[i];

        }
    }

    cout << coin_num << endl;

    return 0;
}