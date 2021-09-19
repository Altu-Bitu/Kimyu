#include <iostream>
#include <stack>

using namespace std;
stack<int> melody[7]; // ��Ÿ ���� ���� ����

int flick(int line, int flat) { // �հ��� ƨ���
    melody[line].push(flat);
    return 1;
}

long long checkPreFlat(int line, int flat) {
    long long count = 0;

    bool push = false; // ���� �� push ���� ǥ��
    while(!melody[line].empty()) {
        if(melody[line].top() == flat) { // ���� ������ ��� stop
            push = true;
            break;
        }
        else if(melody[line].top() < flat) {  // �� ���� ������ ���
            count += flick(line, flat); // �հ��� ƨ���
            push = true;
            break;
        }
        melody[line].pop(); count++; // �հ��� ����
    }
    if(!push) count += flick(line, flat); // ���� �� push ���� ���� ���
    return count;
}

int main() {
    int n, p;
    long long count = 0;
    pair<int, int> temp;
    cin >> n >> p;

    while(n--) {
        cin >> temp.first >> temp.second;
        if(melody[temp.first].empty()) count += flick(temp.first, temp.second); // ������ ����ִ� ���
        else if(melody[temp.first].top() < temp.second) count += flick(temp.first, temp.second); // �� ���� ������ ���
        else count += checkPreFlat(temp.first, temp.second); // ���ų� ���� ������ ���
    }
    cout << count;
    return 0;
}