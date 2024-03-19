#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;


int n, m;
int arr[1001][1001];
int visited[1001][1001];
pair<int,int> Count[1001][1001];
int result[1001][1001];

int section = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool check(int x, int y){
    if (0 <= x && x < m && 0 <= y && y < n)
        return true;
    return false;
}

// 한 공간에 몇개의 칸이 있는지 Count에 기록함
void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    queue<pair<int, int>> nq;
    q.emplace(sx, sy);
    
    section++;
    visited[sy][sx] = 1;
    int count = 1;
    
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        nq.emplace(x, y);
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            
            if (check(nx, ny) && !visited[ny][nx] && arr[ny][nx] == 0){
                visited[ny][nx] = 1;
                q.emplace(nx, ny);
                count++;
            }
        }
    }
    
    while(!nq.empty()){
        int x = nq.front().first, y = nq.front().second;
        nq.pop();
        
        Count[y][x] = make_pair(section, count);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        
        for(int j = 0; j < m; j++)
            arr[i][j] = str[j] - '0';
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (arr[i][j] == 0 && !visited[i][j]){
                bfs(j, i);
                result[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if (arr[i][j] == 1){
                int count = 1; // 자기자신도 포함되기에 시작은 1
                
                // 상하좌우의 빈 공간들의 총 개수를 더해줌
                vector<int> checkSection;
                for(int k = 0; k < 4; k++){
                    int nx = j + dx[k], ny = i + dy[k];
                    
                    if (check(nx, ny)){
                        
                        // 이미 계산한 구획이면 continue
                        bool flag = false;
                        for(int l = 0; l < checkSection.size(); l++)
                            if (Count[ny][nx].first == checkSection[l])
                                flag = true;
                        if (flag)
                            continue;
                        
                        count += Count[ny][nx].second;
                        checkSection.push_back(Count[ny][nx].first);
                    }
                }
                result[i][j] = count % 10;
            }
        }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << result[i][j];
        cout << "\n";
    }
    
    return 0;
}