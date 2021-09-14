#include <iostream>
#include <set>
#include <algorithm>

using namespace  std;
set<string> nonListen, result;

int main() {
    int n, m, num = 0;
    char input[21];
    cin >> n >> m;

    while(n--) { // �赵 ���� ��� �Է�
        cin >> input;
        nonListen.insert(input);
    }

    while(m--) {
        cin >> input; // ���� ���� ��� �Է�
        if(nonListen.find(input) != nonListen.end()) { // �赵 ���� ���� ��� ���ϱ�
            num++;
            result.insert(input);
        }
    }

    cout << num << '\n';
    for(const auto & iter : result) // �赵 ���� ���� ��� ���
        cout << iter << '\n';
    return 0;
}