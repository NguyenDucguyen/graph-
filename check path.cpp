Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s,t<=n<=1000

1<=m<=n*(n-1)/2

1<=Q<=10000

Đầu ra
Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1.

Ví dụ :
Input 01
Copy
5 3
5 4
4 1
4 3
3
4 5
4 2
3 4
Output 01
Copy
1
-1
1


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a(1005);
bool visited[1005];
int cnt =0;
int lt[1005];
void dfs(int u){
    lt[u] =cnt;
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
   for(int i=1;i<=n;i++){
      if(!visited[i]){
          cnt++;
          dfs(i);
      }
   }
   int q;
   cin>>q;
   while(q--){
    int x,y;
    cin>>x>>y;
    if(lt[x]==lt[y]){
        cout<<"1"<<endl;
    }
    else cout<<"-1"<<endl;
   }




}

