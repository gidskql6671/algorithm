#include <bits/stdc++.h>
#define INF 987654321
using namespace std;
typedef long long ll;

int n;
int dist[100001];
int cost[100001];

ll solve(){
    ll result = 0;
    
    // 두번째 마을까지 가는데 필요한 돈
    ll minCost = cost[0];
    result += minCost * dist[0];
    
    for(int i = 1; i < n; i++){
        if (cost[i] < minCost){
            minCost = cost[i];
        }
        
        result += minCost * dist[i];
    }
    
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    cin >> n;
    
    for(int i = 0; i < n - 1; i++)
        cin >> dist[i];
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    
    cout << solve() << endl;
    
    return 0;
}