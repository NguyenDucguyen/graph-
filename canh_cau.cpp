Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Hãy đếm số lượng cạnh cầu của đồ thị.

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
10 1
5 2
10 5
10 6
5 3
10 4
Output 01
Copy
6

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a(1005);
bool visited[1005];
vector<pair<int,int>> dscanh;
int n,m;

void nhap(){
    cin>>n>>m;
    for(int i= 1; i<=m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        dscanh.push_back({x,y});
    }

}
void dfs(int u){
    visited[u] = true;
    for(auto v : a[u]){
        if(!visited[v] ){
            dfs(v);
        }
    }
}

void dfs2( int u ,int s ,int t){
    visited[u] = true;
    for(auto v : a[u]){
        if((u ==s && v == t) || (u==t && v == s)) continue;
        if(!visited[v]) dfs2(v,s,t);


    }
}

void canhcau (){
    int ans =0;
    int tplt =0;
    memset(visited, false , sizeof(visited));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            tplt++;
            dfs(i);
        }
    }

    for(auto it : dscanh){
        int x = it.first , y =it.second;
        int dem =0;
        memset(visited , false , sizeof(visited));
        for(int j=1;j<=n;j++){
            if(!visited[j])
            dem++;
            dfs2(j,x,y);
        }
        if(dem > tplt) ans++;
    }
    cout<<ans<<endl;

}
int main(){
    nhap();
    canhcau();


}

