#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> v[10] = { {}, {2, 3}, {1, 3, 4, 5},
    {1, 2, 6, 7}, { 2, 8 }, { 2, 9 }, { 3 }, { 3 }, { 4 }, { 5 } };
bool isVisited[9];

int main(void) {
    stack<int> s;

    cout << "** node" << 1 << " visited! **" << endl;
    cout << "push 1" << endl;

    s.push(1);
    isVisited[1] = true;

    while (!s.empty()) {
        // if the node has (unvisited) connected node(s)
        bool isConnected = false;
        int cur_node = s.top();
   
        // search all connected nodes
        for (auto i = v[cur_node].begin(); i != v[cur_node].end(); i++) {
            // if the node has a unvisited & connected node(s)
            if (!isVisited[*i]) {
                isConnected = true;

                cout << "** node" << *i << " visited! **" << endl;
                cout << "push " << *i << endl;

                s.push(*i);
                isVisited[*i] = true;
                break;
            }
        }
        // no more unvisited & connected node
        if (!isConnected) {
            s.pop();
            cout << "pop" << cur_node << endl;
        }
    }
    return 0;
}