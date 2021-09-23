#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, bool>> a; // ������, �κ� ����

int countZero(int n) { // ������ 0�� ĭ ����
    int cnt = 0;
    for(int i = 1; i <= 2*n; i++)
        if(a[i].first == 0) cnt++;
    return cnt;
}

void rotate(int n) { // 1. �� ĭ ȸ��
    a[0] = a[2*n];
    for(int i = 2*n-1; i >= 1; i--) // �� ĭ�� �̵�
        a[i+1] = a[i];
    a[1] = a[0];
    a[n].second = false; // ������ (�κ� ����)
}

void move(int n) { // 2. �̵�
    for(int i = n; i >= 2; i--) {
        // �κ� ���� && ������ �������� && ���� ĭ �κ� ����
        if(!a[i].second && a[i].first && a[i-1].second) {
            // �κ� �̵�
            a[i].second = true;
            a[i-1].second = false;
            a[i].first--; // ������ ����
        }
    }
    a[n].second = false; // ������ (�κ� ����)
}

void lift() { // 3. �ø���
    if(a[1].first) {
        a[1].second = true;
        a[1].first--;
    }
}

int belt(int n, int k) {
    int level = 0;

    while(countZero(n) < k) {
        level++;
        rotate(n); // 1. �� ĭ ȸ��
        move(n); // 2. �̵�
        lift(); // 3. �ø���
    }
    return level;
}

int main() {
    int n, k;
    cin >> n >> k;

    a.assign(2*n+1, {0, false});
    for(int i = 1; i <= 2*n; i++)
        cin >> a[i].first;
    cout << belt(n, k); // �ܰ� ���
    return 0;
}