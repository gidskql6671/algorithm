#include <bits/stdc++.h>

using namespace std;

struct node{
    node* prev;
    node* next;
    int num;
};

node* cur;
stack<node*> deletedStack;

string solution(int n, int k, vector<string> cmds) {
    cur = (node*)malloc(sizeof(node));
    cur->num = 0;
    cur->prev = NULL;
    cur->next = NULL;
    
    node* prev = cur;
    for(int i = 1; i < n; i++) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->num = i;
        newNode->prev = prev;
        newNode->next = NULL;
        
        prev->next = newNode;
        prev = newNode;
        
        if (k == i) {
            cur = newNode;
        }
    }
    
    for (string cmd : cmds) {
        if (cmd[0] == 'D') {
            int moveCount = stoi(cmd.substr(2));
            
            for(int i = 0; i < moveCount; i++) {
                cur = cur->next;
            }
        }
        else if (cmd[0] == 'U') {
            int moveCount = stoi(cmd.substr(2));
            
            for(int i = 0; i < moveCount; i++) {
                cur = cur->prev;
            }
        }
        else if (cmd[0] == 'C') {
            node* deletedNode = cur;
            
            if (cur->next == NULL) {
                cur = cur->prev;
            }
            else {
                cur = cur->next;
            }
            
            deletedStack.push(deletedNode);
            if (deletedNode->prev != NULL) {
                deletedNode->prev->next = deletedNode->next;
            }
            if (deletedNode->next != NULL) {
                deletedNode->next->prev = deletedNode->prev;                
            }
        }
        else {
            node* restoredNode = deletedStack.top();
            deletedStack.pop();
            
            if (restoredNode->prev != NULL) {
                restoredNode->prev->next = restoredNode;                
            }
            if (restoredNode->next != NULL) {
                restoredNode->next->prev = restoredNode;                
            }
        }
    }
    
    string answer = string(n, 'X');
    while(cur->prev != NULL) {
        cur = cur->prev;
    }
    while(cur != NULL) {
        answer[cur->num] = 'O';
        cur = cur->next;
    }
    
    
    return answer;
}