#include <bits/stdc++.h>

using namespace std;

vector<int> tree;

void fillMax(int cur) {
    if (tree[cur] > 0 or cur >= tree.size()) {
        return;
    }
    
    fillMax(cur * 2);
    fillMax(cur * 2 + 1);
    
    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}

void makeTree(vector<int> &stones) {
    int leafCount = 1;
    while(leafCount < stones.size()) {
        leafCount *= 2;
    }
    tree = vector<int>(leafCount * 2 + 1, 0);
    
    for(int i = leafCount; i < leafCount + stones.size(); i++) {
        tree[i] = stones[i - leafCount];
    }
    
    fillMax(1);
}

int findMaxVal(int fLeft, int fRight, int left, int right, int cur) {
    if (fRight <= left or right <= fLeft) {
        return -1;
    } 
    
    if (fLeft <= left and right <= fRight) {
        return tree[cur];
    }
    
    int m1 = findMaxVal(fLeft, fRight, left, (left + right) / 2, cur * 2);
    int m2 = findMaxVal(fLeft, fRight, (left + right) / 2, right, cur * 2 + 1);

    return max(m1, m2);
}

int solution(vector<int> stones, int k) {
    makeTree(stones);
    
    int leafCount = 1;
    while(leafCount < stones.size()) {
        leafCount *= 2;
    }
    int answer = 987654321;
    for(int i = 0; i < stones.size() - k + 1; i++) {
        int maxVal = findMaxVal(i, i + k, 0, leafCount, 1);
        answer = min(answer, maxVal);
    }
    
    return answer;
}