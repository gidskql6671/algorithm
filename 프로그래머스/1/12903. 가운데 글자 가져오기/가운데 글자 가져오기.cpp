#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n = s.size();
    if (n % 2 == 0) {
        return s.substr(n / 2 - 1, 2);
    }
    
    return s.substr(n / 2, 1);
}