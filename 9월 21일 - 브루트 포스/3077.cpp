#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<string, int> answer; // ��Ȱ� ���� �����ϴ� ��
vector<string> hyun;     // ���� ��� �����ϴ� ����

int score(int n) { // ���� ����ϱ�
    int result = 0, pos1, pos2;
    for(int i = 0; i < n-1; i++) {
        for(int j = i; j < n; j++) {
            pos1 = answer[hyun[i]];
            pos2 = answer[hyun[j]];
            if(pos1 < pos2) result++; // ������ �ùٸ� ��� ���� �ο�
        }
    }
    return result;
}

int main() {
    int n;
    string input;
    cin >> n;

    for(int i = 0; i < n; i++) { // ��� �Է�
        cin >> input;
        answer[input] = i; // ���� ���� ����
    }
    hyun.assign(n, "");
    for(int i = 0; i < n; i++) // ���� ��� �Է�
        cin >> hyun[i];

    cout << score(n) << '/' << n*(n-1)/2; // ���� ���
    return 0;
}