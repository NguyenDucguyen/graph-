Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy đếm số thành phần liên thông của đồ thị.

Gợi ý : Số thành phần liên thông của đồ thị tương ứng với số lần gọi DFS (BFS) để đi thăm hết mọi đỉnh của đồ thị

Copy
int dem = 0;
for(int i = 1; i <= n; i++){
    if(!visited[i]){
        DFS(i);
        ++dem;
    }
}


Đầu vào
Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra số thành phần liên thông của đồ thị

Ví dụ :
Input 01
Copy
5 4
4 1
2 1
3 2
4 3
Output 01
Copy
2

#include <bits/stdc++.h>
using namespace std;

bool visited[1005];
vector<vector<int>> a(1005);

void dfs(int u) {
    visited[u] = true;
    sort(a[u].begin(), a[u].end());
    for (int v : a[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            dem++;
        }
    }
    cout << dem << endl;
    return 0;
}


