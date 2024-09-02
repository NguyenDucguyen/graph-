Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy tìm đường đi theo thuật toán BFS từ đỉnh s tới đỉnh t.

Trong qúa trình mở rộng của thuật toán BFS, luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn. Nếu không tồn tại đường đi thì in ra -1.

Đầu vào
Dòng đầu tiên là 4 số n, m, s, t, tương ứng với số lượng đỉnh, cạnh của đồ thị, đỉnh bắt đầu và đỉnh kết thúc.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s,t<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra đường đi từ s tới t nếu có đường đi, trường hợp không tồn tại đường đi thì in ra -1.

Ví dụ :
Input 01
Copy
5 10 2 3
5 1
4 5
3 5
4 3
2 1
3 2
5 3
2 5
1 3
5 2
Output 01
Copy
2 1 3

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<int> parent(1005, -1);
bool bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) return true;

        sort(adj[u].begin(), adj[u].end());
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}

void printPath(int t) {
    vector<int> path;
    for (int v = t; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);

    }

    if (bfs(s, t)) {
        printPath(t);
    } else {
        cout << -1 << endl;
    }

    return 0;
}


