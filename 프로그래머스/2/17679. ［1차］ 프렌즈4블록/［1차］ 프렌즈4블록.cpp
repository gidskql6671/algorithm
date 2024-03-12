#include <bits/stdc++.h>

using namespace std;

int eraseBlock(int n, int m, vector<string> &board) {
    vector<vector<bool>> isErased = vector<vector<bool>>(n, vector<bool>(m, false));
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            
            if (board[i][j] == board[i][j + 1] and
               board[i][j] == board[i + 1][j] and
               board[i][j] == board[i + 1][j + 1]) {
                isErased[i][j] = true;
                isErased[i][j + 1] = true;
                isErased[i + 1][j] = true;
                isErased[i + 1][j + 1] = true;
            }
        }
    }
    
    int erasedCount = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (isErased[i][j]) {
                erasedCount++;
                board[i][j] = 0;
            }
        }
    }
    
    return erasedCount;
}

void applyGravity(int n, int m, vector<string> &board) {
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if (board[i][j] != 0) {
                continue;
            }
            
            for(int k = i; k > 0; k--) {
                board[k][j] = board[k - 1][j];
                board[k - 1][j] = 0;
            }
        }
    }
}

int solution(int n, int m, vector<string> board) {
    int answer = 0;
    
    while(true) {
        int erasedBlockCount = eraseBlock(n, m, board);
        if (erasedBlockCount == 0) {
            break;
        }
        answer += erasedBlockCount;
        cout << answer << endl;
        
        applyGravity(n, m, board);
    }
    
    return answer;
}