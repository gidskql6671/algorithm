#include <bits/stdc++.h>

using namespace std;

int maxBuyEmoPlusCount = 0;
int maxBuyEmoPrice = 0;

void calculateSells(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &percents) {
    int buyEmoPlusCount = 0;
    int totalBuyEmoPrice = 0;

    for(int i = 0; i < users.size(); i++) {
        int buyEmosPrice = 0;
        for(int j = 0; j < emoticons.size(); j++) {
            if (users[i][0] <= percents[j]) {
                buyEmosPrice += emoticons[j] * (100 - percents[j]) / 100;
            }
        }
        if (buyEmosPrice >= users[i][1]) {
            buyEmoPlusCount++;
        }
        else {
            totalBuyEmoPrice += buyEmosPrice;
        }
    }

    if (maxBuyEmoPlusCount < buyEmoPlusCount) {
        maxBuyEmoPlusCount = buyEmoPlusCount;
        maxBuyEmoPrice = totalBuyEmoPrice;
    }
    else if (maxBuyEmoPlusCount == buyEmoPlusCount and maxBuyEmoPrice < totalBuyEmoPrice) {
        maxBuyEmoPrice = totalBuyEmoPrice;
    }
}

void recur(vector<vector<int>> &users, vector<int> &emoticons, vector<int> &percents, int cur) {
    if (cur == emoticons.size()) {
        calculateSells(users, emoticons, percents);
        return;
    }
    
    for(int i = 1; i <= 4; i++) {
        percents[cur] = i * 10;
        recur(users, emoticons, percents, cur + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> percents = vector<int>(emoticons.size(), 10);
    
    recur(users, emoticons, percents, 0);
    
    answer.push_back(maxBuyEmoPlusCount);
    answer.push_back(maxBuyEmoPrice);
    return answer;
}