#include <bits/stdc++.h>

using namespace std;

bool isUnique(vector<vector<string>> &relation, vector<bool> &chooses) {
    set<string> s;
    
    for(vector<string> tuple : relation) {
        string tupleValue = "";
        for(int i = 0; i < chooses.size(); i++) {
            if (chooses[i]) {
                tupleValue += tuple[i];
            }
        }
        
        s.insert(tupleValue);
    }
    
    return s.size() == relation.size();
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int columnCount = relation[0].size();
    vector<bool> chooses(columnCount);
    int countCase = pow(2, columnCount);
    
    vector<int> candidateKeys;
    for (int choose = 1; choose < countCase; choose++) {
        int tmp = choose;
        
        bool alreadyIncluded = false;
        for(int candidateKey : candidateKeys) {
            if ((candidateKey & choose) == candidateKey) {
                alreadyIncluded = true;
                break;
            }
        }
        if (alreadyIncluded) {
            continue;
        }
        
        for(int i = 0; i < chooses.size(); i++) {
            chooses[i] = tmp % 2;
            
            tmp /= 2;
        }
        
        if (isUnique(relation, chooses)) {
            answer++;
            candidateKeys.push_back(choose);
        }
    }
    
    
    return answer;
}