#include <bits/stdc++.h>
#define INF 987654321
typedef long long ll;
using namespace std;

int k;
vector<pair<int, int>> orders;
vector<vector<int>> wheels(4, vector<int>(8, 0));

void rotateWheel(vector<pair<int, int>> targetWheels){
    for(int i = 0; i < targetWheels.size(); i++){
        int num = targetWheels[i].first;
        int dir = targetWheels[i].second;
        
        // 시계방향 회전
        if (dir == 1){
            wheels[num].insert(wheels[num].begin(), wheels[num].back());
            wheels[num].pop_back();
        }
        // 반시계방향 회전
        else{
            wheels[num].push_back(wheels[num].front());
            wheels[num].erase(wheels[num].begin());
        }
    }
}

vector<pair<int, int>> findCanRotateWheel(int num, int dir){
    // 2랑 6을 체크해야함.
    vector<pair<int, int>> targetWheels;
    
    targetWheels.push_back(make_pair(num, dir));
    
    int nDir = dir * -1;
    // 돌릴 바퀴 오른쪽을 체크함
    for(int i = num + 1; i < 4; i++){
        if (wheels[i - 1][2] != wheels[i][6]){
            targetWheels.push_back(make_pair(i, nDir));
            nDir *= -1;
        }
        else
            break;
    }
    nDir = dir * -1;
    // 돌릴 바퀴 왼쪽을 체크함
    for(int i = num - 1; i >= 0; i--){
        if (wheels[i][2] != wheels[i + 1][6]){
            targetWheels.push_back(make_pair(i, nDir));
            nDir *= -1;
        }
        else
            break;
    }
    
    return targetWheels;
}

int calcScore(){
    return wheels[0][0] + wheels[1][0] * 2 + wheels[2][0] * 4 + wheels[3][0] * 8;
}

int simulation(){
    for(int i = 0; i < k; i++){
        int number = orders[i].first;
        int dir = orders[i].second;
        
        vector<pair<int, int>> targetWheels = findCanRotateWheel(number, dir);
        rotateWheel(targetWheels);
    }
    
    return calcScore();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    for(int i = 0; i < 4; i++){
        string str;
        cin >> str;
        
        for(int j = 0; j < 8; j++){
            wheels[i][j] = str[j] - '0';
        }
    }
    
    cin >> k;
    for(int i = 0; i < k; i++){
        int number, dir;
        cin >> number >> dir;
        orders.push_back(make_pair(number - 1, dir));
    }
    
    cout << simulation() << endl;
    
    return 0;
}