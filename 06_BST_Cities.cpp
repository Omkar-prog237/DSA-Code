#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int adj_mat[50][50] = {0};
int visited[50] = {0};
int n;
string cities[40];

void dfs(int v) {
    stack<int> s;
    s.push(v);
    visited[v] = 1;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << cities[node] << " ";

        for (int i = 0; i < n; i++) {
            if (adj_mat[node][i] != 0 && !visited[i]) {
                s.push(i);
                visited[i] = 1;
            }
        }
    }
}

bool isConnected() {
    fill(visited, visited + 50, 0);  // Reset visited array
    dfs(0);  // Start DFS from city 0
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "Enter the number of cities: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter city " << i + 1 << ": ";
        cin >> cities[i];
    }

    cout << "Enter the distance between cities:\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << ": ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];  // Because the graph is undirected
        }
    }

    cout << "\nAdjacency Matrix:\n\t";
    for (int i = 0; i < n; i++) {
        cout << cities[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << cities[i] << "\t";
        for (int j = 0; j < n; j++) {
            cout << adj_mat[i][j] << "\t";
        }
        cout << endl;
    }

    if (isConnected()) {
        cout << "\n\nThe graph (cities) is connected." << endl;
    } else {
        cout << "\n\nThe graph (cities) is not connected." << endl;
    }

    return 0;
}
