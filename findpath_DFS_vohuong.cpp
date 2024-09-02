Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy tìm đường đi theo thuật toán DFS từ đỉnh s tới đỉnh t.

Trong qúa trình mở rộng của thuật toán DFS, luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn. Nếu không tồn tại đường đi thì in ra -1.

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
5 3 4 3
4 2
2 1
3 1
Output 01
Copy
4 2 1 3

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<int> path;
bool dfs(int u, int t) {
    visited[u] = true;
    path.push_back(u);
    if (u == t) return true;

    sort(adj[u].begin(), adj[u].end());
     for(int v : adj[u]){
        if (!visited[v]) {
            if (dfs(v, t)) return true;
        }
     }

    path.pop_back();
    return false;
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (dfs(s, t)) {
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

