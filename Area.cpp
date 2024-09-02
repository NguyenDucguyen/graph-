Bạn được cung cấp một lưới 2D. Dấu '#' đại diện cho chướng ngại vật và dấu '.' đại diện cho không gian trống.

Bạn cần tìm các khu vực của các thành phần bị ngắt kết nối.

Các ô (i + 1, j), (i, j + 1), (i-1, j), (i, j-1) là các ô liền kề với ô (i, j).

Đầu vào
Dòng đầu tiên là n và m, tương ứng với số dòng và số cột của lưới 2D.

n dòng tiếp theo, mỗi dòng là m kí tự '#' hoặc '.'.

Giới hạn
1<=N,M<=1000

Đầu ra
In ra diện tích các vùng không gian trống liền kề trên 1 dòng.

Ví dụ :
Input 01
Copy
10 10
###.#.#..#
.######...
###..##.#.
.##...###.
##....#..#
.#..###...
..####.##.
...##.....
..#...####
.#..##.##.
Output 01
Copy
1 1 8 1 11 1 17 9 1 1

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> mp;
vector<vector<bool>> visited;
int cnt =0;
void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' || visited[x][y])
        return;
    cnt++;
    visited[x][y] = true;


    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() {
    cin >> n >> m;
    mp.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }


    vector<int>result;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '.' && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    for(auto it : result ){
        cout<<it<<" ";
    }

    return 0;
}


