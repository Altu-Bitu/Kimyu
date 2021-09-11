#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<int> result;

int fashionCheck(map<string, int> &kinds) {
    int day = 1;
    for(auto & kind : kinds)
        day *= (kind.second + 1); // (�ش� �ǻ� ������ + �ش� �ǻ��� �� �Դ� ���)
    return day - 1; // (-1 : �ƹ��͵� ���� �ʴ� ���)
}

int main() {
    int t, n;
    string kind, cloth; // �ǻ� ����, �ǻ� �̸�
    cin >> t;

    result.assign(t, 0);
    for(int i = 0; i < t; i++) {
        cin >> n;

        map<string, int> kinds; // (�ǻ� ����, �ش� �ǻ� ���� ����)
        for(int j = 0; j < n; j++) {
            cin >> cloth >> kind;
            if(kinds.find(kind) == kinds.end()) kinds.insert({kind, 1});
            else kinds[kind]++;
        }
        result[i] = fashionCheck(kinds);
    }

    for(int i = 0; i < t; i++) // ��� ���
        cout << result[i] << '\n';
    return 0;
}