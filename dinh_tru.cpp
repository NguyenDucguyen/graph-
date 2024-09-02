Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy đếm số lượng đỉnh trụ của đồ thị.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1=<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra số lượng đỉnh trụ của đồ thị

Ví dụ :
Input 01
Copy
10 6
5 4
5 2
10 2
10 7
5 3
10 1
Output 01
Copy
3

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
bool visited[1005];

void dfs(int u) {
    visited[u] = true;
    for (auto v : adjList[u]) {
        if (!visited[v]) dfs(v);
    }
}

void countCriticalNodes(int n) {
    int connectedComponents = 0;
    memset(visited, false, sizeof(visited));

    // Count initial number of connected components
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            connectedComponents++;
            dfs(i);
        }
    }

    int criticalNodes = 0;

    // Check each node if it is a critical node
    for (int i = 1; i <= n; ++i) {
        memset(visited, false, sizeof(visited));
        visited[i] = true; // Temporarily remove node i

        int newComponents = 0;
        for (int j = 1; j <= n; ++j) {
            if (!visited[j]) {
                newComponents++;
                dfs(j);
            }
        }

        if (newComponents > connectedComponents) {
            criticalNodes++;
        }
    }

    cout << criticalNodes << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    adjList.resize(n + 1); // Resize adjList to hold n nodes

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    countCriticalNodes(n);

    return 0;
}

