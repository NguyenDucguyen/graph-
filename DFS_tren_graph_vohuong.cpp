Cho đồ thị vô hướng G = <V, E> được biểu diễn dưới dạng danh sách cạnh.

Hãy thực hiện in ra danh sách các đỉnh được duyệt theo thuật toán DFS bắt đầu từ đỉnh nguồn s

Trong quá trình mở rộng của thuật toán DFS luôn ưu tiên mở rộng đỉnh có số thứ tự nhỏ hơn trước

Đầu vào
Dòng đầu tiên là 2 số n và m và s, tương ứng với số lượng đỉnh, cạnh của đồ thị và đỉnh bắt đầu duyệt.

Các đỉnh của đồ thị được đánh số từ 1 tới n.

m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra các đỉnh được duyệt theo thuật toán DFS(s).

Chú ý trong quá trình mở rộng các đỉnh của thuật toán DFS luôn lựa chọn duyệt các đỉnh có thứ tự nhỏ hơn trước.

Ví dụ :
Input 01
Copy
5 5 3
5 2
3 2
5 4
5 3
5 1
Output 01
Copy
3 2 5 1 4

#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<vector<int>>a(1005);
void dfs(int u){
    cout<<u<<" ";
    visited[u] = true;
    sort(a[u].begin(),a[u].end());
    for(int v : a[u]){
        if(!visited[v]) dfs(v);
    }

}
int main(){
    int n,m,u;
    cin>>n>>m>>u;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(u);

}

