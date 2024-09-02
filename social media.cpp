Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử.

Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.

Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không? Nếu có hãy in ra YES, NO trong trường hợp ngược lại.

Đầu vào
Dòng 1 gồm 2 số nguyên N và M.

M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u # v) cho biết u và v là kết bạn với nhau trên mạng xã hội của Tý.

Giới hạn
1<= N, M ≤ 100 000

Đầu ra
In ra kết quả của bài toán

Ví dụ :
Input 01
Copy
4 3
1 3
3 4
1 4
Output 01
Copy
YES

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a(1005);
bool visited[1005];
int cnt = 0;
void dfs(int u) {
     cnt++;
     visited[u] = true;
     for(auto v : a[u]){
        if(visited[v] == false){
           dfs(v);
        }
     }

}
int main(){
    int n,m;
    cin >>n>>m;
    for(int i =1; i<=m;i++){
        int x ,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);

    }
    int res =0 ;
    for(int i=1;i<=n;i++){
        cnt=0;
        dfs(i);
        res+= (cnt *(cnt-1))/2;

    }
    if(res  == m ) cout<<"YES";
    else cout << "NO" ;

}

