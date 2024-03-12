#include <bits/stdc++.h>

using namespace std;


int getGrade(int sameCount) {
    switch(sameCount) {
        case 6: return 1;
        case 5: return 2;
        case 4: return 3;
        case 3: return 4;
        case 2: return 5;
        default: return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> winNums) {
    vector<int> answer;
    
    sort(lottos.begin(), lottos.end());
    sort(winNums.begin(), winNums.end());
    
    int sameCount = 0, zeroCount = 0;
    int i = 0, j = 0;
    while(i < lottos.size() and j < winNums.size()) {
        if (lottos[i] == 0) {
            zeroCount++;
        }
        
        if (lottos[i] == winNums[j]) {
            sameCount++;
            i++; j++;
        }
        else if (lottos[i] < winNums[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    
    answer.push_back(getGrade(sameCount + zeroCount));
    answer.push_back(getGrade(sameCount));
    
    
    return answer;
}