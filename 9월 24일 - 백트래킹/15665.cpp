#include <iostream>
#include <set>

using namespace std;
const int SIZE = 7;

int n, m;
set<int> temp; // ����� ���� �Է°� �����ϴ� ��
int num[SIZE]; // ���� �����ϴ� �迭

void backtracking(int cnt) { // cnt: ���� ����
    if(cnt == m) { // ���� ����
        for(int i = 0; i < m; i++)
            cout << num[i] << ' ';
        cout << '\n';
        return;
    }

    for(auto iter = temp.begin(); iter != temp.end(); iter++) {
        num[cnt] = *iter;
        backtracking(cnt+1); // (�ߺ� ���)
    }
}

int main() {
    int input;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> input;
        temp.insert(input);
    }

    backtracking(0);
    return 0;
}