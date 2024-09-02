Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

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
4 4
1 2
2 3
3 1
1 4
Output 01
Copy
1

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1005);
enum State { UNVISITED, VISITING, VISITED };
State state[1005];
int n, m;

void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

bool dfs(int u) {
    state[u] = VISITING;
    for (auto v : a[u]) {
        if (state[v] == UNVISITED) {
            if (dfs(v)) return true;
        } else if (state[v] == VISITING) {
            return true;
        }
    }
    state[u] = VISITED;
    return false;
}

int main() {
    nhap();
    bool check = false;
    for (int u = 1; u <= n; u++) {
        if (state[u] == UNVISITED) {
            if (dfs(u)) {
                check = true;
                break;
            }
        }
    }
    if (check) cout << "1";
    else cout << "0";
    return 0;
}

