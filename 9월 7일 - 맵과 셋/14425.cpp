#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
set<string> s;

int main() {
    int n, m, result = 0;
    char input[501];
    cin >> n >> m;

    while(n--) { // ���տ� ���ڿ� ����
        cin >> input;
        s.insert(input);
    }

    while(m--) { // ���ڿ� �˻�
        cin >> input;
        if(s.find(input) != s.end()) result++;
    }
    cout << result;
    return 0;
}
