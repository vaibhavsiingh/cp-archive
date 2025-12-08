#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;


int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y] && grid[x][y] > 0;
}


int dfs(int x, int y) {
    visited[x][y] = true;
    int coins = grid[x][y];
    
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (isValid(nx, ny)) {
            coins = max(coins, grid[x][y] + dfs(nx, ny));
        }
    }
    
    visited[x][y] = false; 
    return coins;
}

int main() {
    cin >> N;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N, false));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int maxCoins = 0;
    
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if ((i + j) % 2 == 1 && grid[i][j] > 0) { 
                maxCoins = max(maxCoins, dfs(i, j));
            }
        }
    }
    
    cout << maxCoins << endl;
    return 0;
}