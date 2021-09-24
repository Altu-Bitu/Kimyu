#include <iostream>

using namespace std;
const int CHANNEL = 100; // ���� ä��
const int MAX_CHANNEL = 500000;
bool breakdown[10] = {false, }; // ���峭 ��ư

bool possible(int num) { // ���������� ���� �� �ִ� ä���ΰ�
    string temp = to_string(num);
    for(char t : temp)
        if (breakdown[t - '0']) return false; // ���峭 ��ư�� ���
    return true;
}

int pushButton(int n) { // �ּ� Ŭ�� ��
    int temp, count = abs(n - CHANNEL);

    for(int i = 0; i <= 2 * MAX_CHANNEL; i++) {
        if(possible(i)) {
            // '+/-' ������ Ƚ�� + ���� ���� �Է�
            temp = abs(n-i) + to_string(i).length();
            count = min(count, temp);
        }
    }
    return count;
}

int main() {
    int n, m, temp;
    cin >> n;
    cin >> m;

    while(m--) {
        cin >> temp;
        breakdown[temp] = true;
    }
    cout << pushButton(n);
    return 0;
}