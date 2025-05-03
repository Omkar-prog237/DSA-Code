#include <iostream>
#include <string>
using namespace std;

int cost[20][20] = {0};  // Initialize with 0
string offices[20];

void create(int &v) {
    cout << "\nEnter total number of offices: ";
    cin >> v;
    for (int i = 1; i <= v; i++) {
        cout << "Enter name of office " << i << ": ";
        cin >> offices[i];
    }
    for (int i = 1; i <= v; i++) {
        for (int j = i + 1; j <= v; j++) {
            cout << "\nProvide cost if edge between " << offices[i] << " and " << offices[j] << ": ";
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }
}

void display(int v) {
    cout << "\nAdjacency Matrix (Cost Matrix) is:" << endl;
    for (int i = 1; i <= v; i++) {
        cout << "\n";
        for (int j = 1; j <= v; j++) {
            cout << "\t" << cost[i][j];
        }
    }
    cout << endl;
}

void prims(int v) {
    int pos = 1, mincost = 0, min = 9999, row = 0, col = 0;
    int visit[20] = {0};
    int path[20] = {0};
    visit[1] = 1;
    path[pos++] = 1;

    for (int k = 1; k <= v - 1; k++) {
        min = 9999;
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (visit[i] == 1 && visit[j] == 0 && cost[i][j] != 0 && min > cost[i][j]) {
                    min = cost[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        mincost += min;
        visit[col] = 1;
        path[pos++] = col;
        cost[row][col] = cost[col][row] = 0;
    }

    cout << "\nTotal minimum cost: " << mincost << endl;
    cout << "\nShortest Path is: ";
    for (int i = 1; i < pos; i++) {
        cout << offices[path[i]];
        if (i < pos - 1) cout << " --> ";
    }
    cout << endl;
}

int main() {
    int v;
    create(v);
    display(v);
    prims(v);
    return 0;
}
