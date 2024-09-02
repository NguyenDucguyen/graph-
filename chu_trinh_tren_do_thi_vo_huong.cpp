Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy xác định xem đồ thị có tồn tại chu trình hay không? Bài này các bạn cài đặt bằng 3 phương pháp : DFS, BFS và DSU.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra 1 nếu đồ thị tồn tại chu trình, ngược lại in ra 0.

Ví dụ :
Input 01
Copy
10 11
10 5
10 4
10 1
10 3
5 2
5 4
10 8
5 3
5 1
10 6
10 9
Output 01
Copy
1

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1005);
bool visited[1005];
int n, m;

void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

bool dfs(int u, int parent) {
    visited[u] = true;
    for (auto v : a[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    nhap();
    bool check = false;
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            if (dfs(u, -1)) {
                check = true;
                break;
            }
        }
    }
    if (check) cout << "1";
    else cout << "0";
}

