#include <bits/stdc++.h>
using namespace std;


string board[51][51];
pair<int, int> group[51][51];
int groupSize[51][51];

pair<int, int> root(pair<int, int> cur) {
    while(cur != group[cur.first][cur.second]) {
        cur = group[cur.first][cur.second];
    }
    
    return cur;
}

void unionGroup(pair<int, int> a, pair<int, int> b) {
    pair<int, int> aRoot = root(a);
    pair<int, int> bRoot = root(b);
    
    if (aRoot == bRoot) {
        return;
    }
    
    if (groupSize[aRoot.first][aRoot.second] < groupSize[bRoot.first][bRoot.second]) {
        groupSize[bRoot.first][bRoot.second] += groupSize[aRoot.first][aRoot.second];
        group[aRoot.first][aRoot.second] = bRoot;
    }
    else {
        groupSize[aRoot.first][aRoot.second] += groupSize[bRoot.first][bRoot.second];
        group[bRoot.first][bRoot.second] = aRoot;
    }
}

bool isSameGroup(pair<int, int> a, pair<int, int> b) {
    return root(a) == root(b);
}

vector<string> split(string input, char delimiter) {
    istringstream iss(input);
    string buffer;
    
    vector<string> result;
    
    while(getline(iss, buffer, delimiter)) {
        result.push_back(buffer);
    }
    
    return result;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i = 1; i <= 50; i++) {
        for(int j = 1; j <= 50; j++) {
            group[i][j] = make_pair(i, j);
            groupSize[i][j] = 1;
        }
    }
    
    for(string command : commands) {
        vector<string> cmd = split(command, ' ');
        
        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                int r = stoi(cmd[1]), c = stoi(cmd[2]);
                
                pair<int, int> sell = root({r, c});
                
                board[sell.first][sell.second] = cmd[3];
            }
            else {
                for(int i = 1; i <= 50; i++) {
                    for(int j = 1; j <= 50; j++) {
                        pair<int, int> sell = root({i, j});
                        
                        if (board[sell.first][sell.second] == cmd[1]) {
                            board[sell.first][sell.second] = cmd[2];
                        }
                    }
                }
            }
        }
        else if (cmd[0] == "MERGE") {
            int r1 = stoi(cmd[1]), c1 = stoi(cmd[2]);
            int r2 = stoi(cmd[3]), c2 = stoi(cmd[4]);
            
            pair<int, int> sell1 = root({r1, c1});
            pair<int, int> sell2 = root({r2, c2});
            
            string prevData = "";
            if (board[sell1.first][sell1.second].size() > 0 and board[sell2.first][sell2.second].size() > 0) {
                prevData = board[sell1.first][sell1.second];
            }
            else if (board[sell1.first][sell1.second].size() > 0) {
                prevData = board[sell1.first][sell1.second];
            }
            else if (board[sell2.first][sell2.second].size() > 0) {
                prevData = board[sell2.first][sell2.second];
            }
            
            unionGroup(sell1, sell2);
 
            pair<int, int> newRoot = root(sell1);
            
            board[sell1.first][sell1.second] = "";
            board[sell2.first][sell2.second] = "";
            board[newRoot.first][newRoot.second] = prevData;
        }
        else if (cmd[0] == "UNMERGE") {
            int r = stoi(cmd[1]), c = stoi(cmd[2]);
            
            pair<int, int> rootSell = root({r, c});
            string rootData = board[rootSell.first][rootSell.second];
            
            vector<pair<int, int>> targets;
            for(int i = 1; i <= 50; i++) {
                for(int j = 1; j <= 50; j++) {
                    pair<int, int> sell = root({i, j});

                    if (rootSell == sell) {
                        targets.push_back({i, j});
                    }
                }
            }
            
            for(pair<int, int> sell : targets) {
                board[sell.first][sell.second] = "";
                group[sell.first][sell.second] = sell;
                groupSize[sell.first][sell.second] = 1;
            }
            
            board[r][c] = rootData;
        }
        else {
            pair<int, int> sell = root(make_pair(stoi(cmd[1]), stoi(cmd[2])));
            
            if (board[sell.first][sell.second].size() > 0) {
                answer.push_back(board[sell.first][sell.second]);                
            }
            else {
                answer.push_back("EMPTY");
            }
        }
    }
    
    return answer;
}