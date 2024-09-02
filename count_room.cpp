Bạn được đưa cho một bản đồ của một tòa nhà và nhiệm vụ của bạn là đếm số lượng phòng của tòa nhà đó.

Kích thước của bản đồ là n × m hình vuông và mỗi hình vuông là sàn hoặc tường. Bạn có thể đi bộ sang trái, phải, lên và xuống qua các ô sàn.

Đầu vào
Dòng nhập đầu tiên có hai số nguyên n và m: chiều cao và chiều rộng của bản đồ.

Khi đó có n dòng gồm m ký tự mô tả bản đồ. Mỗi ký tự là một trong hai ký tự '.' hoặc '#' tương ứng với sàn nhà và tường.

Giới hạn
1≤n,m≤1000

Đầu ra
In ra số nguyên duy nhất là số phòng của tòa nhà

Ví dụ :
Input 01
Copy
6 6
..###.
...#..
#..#..
.##.#.
######
.#.##.
Output 01
Copy
7

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> mp;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' || visited[x][y])
        return;

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

    int roomCount = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '.' && !visited[i][j]) {

                dfs(i, j);
                roomCount++;
            }
        }
    }

    cout << roomCount << endl;

    return 0;
}

