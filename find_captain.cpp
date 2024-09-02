Trong một lớp học luôn tồn tại những nhóm học sinh, các học sinh trong nhóm này sẽ thân thiết với nhau hơn. Giả sử trong 1 nhóm, nếu bạn a chơi thân vs bạn b và bạn b chơi thân với bạn c, thì bạn a và bạn c sẽ chơi thân với nhau.

Hiện nay Tèo là lớp trưởng lớp 10A1, vì không thích việc chia bè kéo cánh trong lớp nên Tèo quyết định tìm các bạn nhóm trưởng của các nhóm để bàn việc hợp nhất các nhóm.

Tèo biết rằng trong các nhóm nhỏ, nhóm trưởng là người có nhiều quan hệ thân thiết với các thành viên khác trong nhóm nhất và là người có số thứ tự nhỏ nhất. Nếu một bạn nào đó không chơi với ai cả thì bạn đó là nhóm trưởng của chính mình.

Bạn hãy giúp tèo in ra thứ tự của các trưởng nhóm theo thứ tự từ nhỏ đến lớn nhé.

Đầu vào
Dòng đầu tiên là n và m, tương ứng với số lượng sinh viên trong lớp và số lượng tình bạn giữa các bạn trong lớp.

Các sinh viên được đánh số từ 1 tới n.

m dòng tiếp theo mỗi dòng gồm 2 số a, b thể hiện tình bạn thân thiết giữa bạn a và bạn b, a và b khác nhau.

Giới hạn
In ra thứ tự của các trưởng nhóm theo thứ tự từ nhỏ đến lớn nhé.

Đầu ra
1<=n<=1000

1<=m<=n*(n-1)/2

1<=a,b<=n

Ví dụ :
Input 01
Copy
10 6
4 3
4 1
8 5
8 6
4 2
8 2
Output 01
Copy
4 7 9 10

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a(1005);
bool visited[1005];
int cnt =0;
int nhom_truong = 0;
int bac[1005];
void dfs(int u){
    if(bac[u]>bac[nhom_truong] || bac[u]==bac[nhom_truong] && u < nhom_truong){
        nhom_truong = u;
    }
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
        bac[x]++; bac[y]++;
   }
   set<int>se;
   for(int i=1;i<=n;i++){
       if(!visited[i]){
            nhom_truong =i;
            dfs(i);
            se.insert(nhom_truong);
       }
   }
   for(auto it : se){
      cout<<it<<" ";
   }


}

