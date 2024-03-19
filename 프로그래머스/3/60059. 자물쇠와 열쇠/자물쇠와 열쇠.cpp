#include <string>
#include <vector>

using namespace std;

void rotateArr(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<vector<int>> tmp(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp[j][n - 1 - i] = arr[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}

bool isInside(int y, int x, int n) {
    return 0 <= y and y < n and 0 <= x and x < n;
}

bool isFit(vector<vector<int>> &key, vector<vector<int>> &lock, int sy, int sx) {
    int m = key.size(), n = lock.size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int keyY = sy + i, keyX = sx + j;
            if (isInside(keyY, keyX, m)) {
                if (not (key[keyY][keyX] ^ lock[i][j])) {
                    return false;
                }
            }
            else {
                if (lock[i][j] == 0) {
                    return false;
                }
            }
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size(), n = lock.size();
    
    for(int k = 0; k < 4; k++) {
        rotateArr(key);
        
        for(int i = m - 1; i > -n; i--) {
            for(int j = m - 1; j > -n; j--) {
                if (isFit(key, lock, i, j)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}