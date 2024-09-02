Một đồ thị n đỉnh là một cây, nếu như nó có đúng n -1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.

Cho một đồ thị vô hướng n đỉnh và m cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra 1 nếu đồ thị đã cho là cây, ngược lại in ra 0.

Ví dụ :
Input 01
Copy
6 5
4 3
2 1
6 5
5 4
3 2
Output 01
Copy
1

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a(1005);
bool visited[1005];
int cnt =0;
void dfs(int u){
    cnt++;
    visited[u] = true;
    for(auto v : a[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
int main(){
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
   }
   dfs(1);
   if((cnt==n) && (n == m+1)){
    cout<<"1"<<endl;
   }
   else{
      cout<<"0"<<endl;
   }


}

