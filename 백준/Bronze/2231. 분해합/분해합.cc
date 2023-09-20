#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    for(int i = 1; i < n; i++){
        int sum, number;
        sum = number = i;
        
        while(number > 0){
            sum += number % 10;
            
            number /= 10;
        }
        
        if (sum == n){
            cout << i << "\n";
            return 0;
        }
    }
    
    cout << 0 << "\n";
    
    return 0;
}