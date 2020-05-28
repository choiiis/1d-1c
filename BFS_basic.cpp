#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//show all elememts in the queue
void showAll(queue<int> q) {
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(void) {
    queue<int> q;
    bool visited[10] = { 0, };
    vector<int> v[10] = { {}, {2, 3}, {1, 3, 4, 5}, \
    {1, 2, 6, 7}, { 2, 8 }, { 2, 9 }, { 3 }, { 3 }, { 4 }, { 5 } };

    // check first node as a visited node
    visited[1] = true;

    //push first node's connected nodes
    for (auto i = v[1].begin(); i != v[1].end(); i++) {
        q.push(*i);
        visited[*i] = true;
    }
    cout << "show all elements : ";
    showAll(q);

    while (!q.empty()) {
        // print the front element(cur_node) and pop it.
        int cur_node = q.front();
        cout << "cur_node : " << q.front() << endl;
        q.pop();

        // push cur_node's connected nodes
        for (auto i = v[cur_node].begin(); i != v[cur_node].end(); i++) {
            if (visited[*i] == false) {
                q.push(*i);
                visited[*i] = true;
            }
        }
        cout << "show all elements: ";
        showAll(q);
    }

    return 0;
}