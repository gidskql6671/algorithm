#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;

int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int m, n, k;

void bfs(vector<vector<bool>> arr, vector<vector<bool>>& visited, int ix, int iy){
    queue<pair<int,int>> q;
    
    q.push(make_pair(ix, iy));
    visited[iy][ix] = true;
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n){
                if (!visited[ny][nx] && arr[ny][nx]){
                    q.push(make_pair(nx, ny));
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    while(T--){
        int count = 0;
        
        cin >> m >> n >> k;
        
        vector<vector<bool>> arr(n, vector<bool>(m, false));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            arr[y][x] = true;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (!visited[i][j] && arr[i][j]){
                    count++;
                    bfs(arr, visited, j, i);
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}