#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;

int n, k;
int board[13][13];
// x, y, dir, floor
tuple<int, int, int, int> order[11];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int gameCount = 0;

void solve(){
    
    while(gameCount <= 1000){
        gameCount++;
        
        for(int i = 1; i <= k; i++){
            int x, y, dir, floor, maxFloor = 0;
            tie(x, y, dir, floor) = order[i];
            
            // 바닥층이 아니면 이동을 못함
            if (floor != 0){
                continue;
            }
            
            // 업은 말들을 나타내는 벡터, 인덱스로 저장
            vector<int> v;
            for(int j = 1; j <= k; j++){
                if (i == j) continue;
                
                int compX, compY, tmp, compFloor;
                tie (compX, compY, tmp, compFloor) = order[j];
                
                
                if (x == compX && y == compY){
                    maxFloor = max(maxFloor, compFloor);
                    v.push_back(j);
                }
            }
            
            
            int myFloor = 0;
            int nx = x + dx[dir], ny = y + dy[dir];
            
            
            // 이동하려는 칸이 벽이거나 파랑색인경우
            if ((nx <= 0 || n < nx || ny <= 0 || n < ny) || board[ny][nx] == 2){
                // 방향을 반대로 바꾸어줌.
                dir = (dir + 2) % 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
                
                // 반대로 바꾼 후 이동하려는 곳이 파랑색이거나 맵 밖인 경우
                if ((nx <= 0 || n < nx || ny <= 0 || n < ny) || board[ny][nx] == 2){
                    // 위치를 바꾸지 않음
                    order[i] = make_tuple(x, y, dir, get<3>(order[i]));
                    for(int j = 0; j < v.size(); j++){
                        int cur = v[j];
                        
                        order[cur] = make_tuple(x, y, get<2>(order[cur]), get<3>(order[cur]));
                    }
                    
                    continue;
                }
            }
            
            // 이동하려는 칸이 흰색인 경우
            if (board[ny][nx] == 0){
                // 해당 칸에 이미 누가 있는지 체크, 있다면 위에 쌓기위해 myFloor를 업데이트
                for(int j = 1; j <= k; j++){
                    if (i == j)
                        continue;
                    
                    int compX, compY, tmp, compFloor;
                    tie (compX, compY, tmp, compFloor) = order[j];
                    
                    if (nx == compX && ny == compY){
                        myFloor = max(myFloor, compFloor + 1);
                    }
                }
                
                // order 업데이트
                order[i] = make_tuple(nx, ny, dir, get<3>(order[i]) + myFloor);
                for(int j = 0; j < v.size(); j++){
                    int cur = v[j];
                    order[cur] = make_tuple(nx, ny, get<2>(order[cur]), get<3>(order[cur]) + myFloor);
                }
                
            }
            // 이동하려는 칸이 빨간색인 경우
            else if (board[ny][nx] == 1){// 해당 칸에 이미 누가 있는지 체크, 있다면 위에 쌓기위해 myFloor를 업데이트
                for(int j = 1; j <= k; j++){
                    if (i == j)
                        continue;
                    
                    int compX, compY, tmp, compFloor;
                    tie (compX, compY, tmp, compFloor) = order[j];
                    
                    if (nx == compX && ny == compY){
                        myFloor = max(myFloor, compFloor + 1);
                    }
                }
                
                // 이동하는 말들끼리는 순서를 바꿔주면서, 기존에 있던 말들 위에 얹어줌.
                order[i] = make_tuple(nx, ny, dir, myFloor + maxFloor);
                for(int j = 0; j < v.size(); j++){
                    int cur = v[j];
                    int curX, curY, curDir, curFloor;
                    tie(curX,curY,curDir,curFloor) = order[cur];
                    
                    order[cur] = make_tuple(nx, ny, curDir, myFloor + maxFloor - curFloor);
                }
            }
           
        }
        
        for(int i = 1; i <= k; i++){
            int floor = get<3>(order[i]);
            
            if (floor >= 3){
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];
    
    for(int i = 1; i <= k; i++){
        int y, x, dir;
        cin >> y >> x >> dir;
        
        // 추후 처리를 편하게 하기 위해서 시계방향으로 순서를 매김
        if (dir == 2)
            dir = 3;
        else if (dir == 3)
            dir = 2;
        
        order[i] = make_tuple(x, y, dir - 1, 0);
    }
    
    solve();
    
    if (gameCount <= 1000){
        cout << gameCount << endl;
    }
    else{
        cout << -1 << endl;
    }
    
    return 0;
}