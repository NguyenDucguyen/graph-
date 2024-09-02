Trong một lớp học luôn tồn tại những nhóm học sinh, các học sinh trong nhóm này sẽ thân thiết với nhau hơn.

Giả sử trong 1 nhóm, nếu bạn a chơi thân vs bạn b và bạn b chơi thân với bạn c, thì bạn a và bạn c sẽ chơi thân với nhau.

Hiện nay Tèo là lớp trưởng lớp 10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm ra nhóm có số bạn chơi thân với nhau nhất trong nhóm để đưa các thành viên của các nhóm khác vào trong nhóm có số lượng thành viên cao nhất này.

Bạn hãy giúp Tèo tìm ra số lượng thành viên lớn nhất của 1 nhóm chơi thân bất kỳ trong lớp nhé !

Đầu vào
Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn trong lớp.

Các sinh viên được đánh số từ 1 tới n.

m dòng tiếp theo mỗi dòng gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn a và bạn b, a và b khác nhau.

Giới hạn
In ra nhóm có số lượng bạn lớn nhất

Đầu ra
1<=n<=1000

1<=m<=n*(n-1)/2

1<=a,b<=n

Ví dụ :
Input 01
Copy
10 6
8 2
4 1
8 6
8 7
8 1
8 5
Output 01
Copy
7


#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a(1005);
bool visited[1005];
int cnt =0;
int nhom_truong = 0;
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
   vector<int>v;
    int max_cnt =0;
   for(int i=1;i<=n;i++){
       if(!visited[i]){
            cnt = 0;
           dfs(i);
            max_cnt = max(max_cnt, cnt);
       }
   }
   cout<<max_cnt;

}
