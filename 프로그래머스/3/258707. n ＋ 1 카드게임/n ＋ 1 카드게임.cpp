#include <bits/stdc++.h>

using namespace std;


int solution(int coin, vector<int> cards) {
    int n = cards.size();
    
    vector<int> cardIndex(n + 1, -1), pairCardIndex(n + 1, -1);
    for(int i = 0; i < n; i++) {
        int card = cards[i];
        int pairCard = n + 1 - card;
        
        cardIndex[card] = i;
        
        if (cardIndex[pairCard] > -1) {
            pairCardIndex[card] = cardIndex[pairCard];
            pairCardIndex[pairCard] = i;
        }
    }
    
    int possibleRound = 1;
    for(int i = 0; i < n / 3; i++) {
        int card = cards[i];
        int pairCard = n + 1 - card;
        
        if (cardIndex[pairCard] < i) {
            possibleRound++;
        }
    }
    
    int round = 1;
    queue<int> need2CoinPair;
    for(int i = n / 3; i < n; i += 2) {
        if (round > possibleRound) {
            if (coin >= 2 and not need2CoinPair.empty()) {
                coin -= 2;
                need2CoinPair.pop();
                possibleRound++;
            }
            else {
                break;                
            }
        }
        
        int card1 = cards[i];
        int pairCard1 = n + 1 - card1;
        int card2 = cards[i + 1];
        int pairCard2 = n + 1 - card2;
        
        if (cardIndex[pairCard1] < i and coin > 0) {
            if (cardIndex[pairCard1] < n / 3) {
                possibleRound++;
                coin--;   
            }
            else {
                need2CoinPair.push(card1);
            }
        }
        if (cardIndex[pairCard2] <= i and coin > 0) {
            if (cardIndex[pairCard2] < n / 3) {
                possibleRound++;
                coin--;   
            }
            else {
                need2CoinPair.push(card2);
            }
        }
        
        round++;
    }
    
    return possibleRound;
}