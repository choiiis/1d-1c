#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> v[10] = { {}, {2, 3}, {1, 3, 4, 5},
    {1, 2, 6, 7}, { 2, 8 }, { 2, 9 }, { 3 }, { 3 }, { 4 }, { 5 } };
bool isVisited[9];
bool isPushed[9];

int main(void) {
    stack<int> s;

    isVisited[1] = true;
    isPushed[1] = true;
    cout << "push 1" << endl;
    cout << "cur_node(pop) : " << 1 << endl;
    for (auto i = v[1].begin(); i != v[1].end(); i++) {
        cout << "push " << *i << endl;
        s.push(*i);
        isPushed[*i] = true;
    }

    while (!s.empty()) {
        int cur_node = s.top();
        cout << "cur_node(pop) : " << cur_node << endl;
        isVisited[cur_node] = true;
        s.pop();
        for (auto i = v[cur_node].begin(); i != v[cur_node].end(); i++) {
            if (!isPushed[*i]) {
                cout << "push " << *i << endl;
                s.push(*i);
                isPushed[*i] = true;
            }
        }
    }
}