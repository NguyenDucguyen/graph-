Cho đồ thị có hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy kiểm tra đồ thị có liên thông mạnh hay không? Bài này các bạn thử cài đặt bằng 3 cách là : brute force, thuật toán Tarjan, thuật toán Kosaraju.

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra 1 nếu đồ thị liên thông mạnh, ngược lại in ra 0.

Ví dụ :
Input 01
Copy
6 14
3 4
3 1
2 5
2 6
4 6
2 3
5 6
1 5
1 2
3 5
4 5
6 3
4 2
1 4
Output 01
Copy
1

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a(1005);
bool visited[1005];
int n, m;
int low[1005], num[1005], cnt;

void nhap() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

bool tarjan(int u) {
    bool hasCycle = false;
    num[u] = low[u] = cnt++;


    for (auto v : a[u]) {
        if (num[v] == 0) {
            if (tarjan(v)) hasCycle = true;
            low[u] = min(low[u], low[v]);
        } else if (visited[v]) {
            low[u] = min(low[u], num[v]);
        }

        if (low[u] == num[u] && low[v] == num[v]) hasCycle = true;
    }


    return hasCycle;
}

int main() {
    nhap();
    bool check = false;


    for (int u = 1; u <= n; u++) {
        if (num[u] == 0) {
            if (tarjan(u)) {
                check = true;
                break;
            }
        }
    }

    if (check) cout << "1";
    else cout << "0";

    return 0;
}

