#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> side;

int biggestTriangle(int n) { // �� ���� ������ ���� �ִ� ���ϱ�
    for(int i = 0; i < n-2; i++) {
        if(side[i] < side[i+1] + side[i+2])
            return side[i] + side[i+1] + side[i+2];
    }
    return -1; // �ﰢ�� ���� �� ���� ���
}

int main() {
    int n;
    cin >> n;

    side.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> side[i];
    sort(side.begin(), side.end(), greater<>()); // ���� �������� ����

    cout << biggestTriangle(n);
    return 0;
}