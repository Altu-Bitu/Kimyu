#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, bool>> a; // ������, �κ� ����

int countZero(int n) { // ������ 0�� ĭ ����
    int cnt = 0;
    for(int i = 1; i <= 2 * n; i++)
        if(a[i].first == 0) cnt++;
    return cnt;
}

void rotate(int &lift_pos, int &drop_pos, int n) { // 1. �� ĭ ȸ��
    lift_pos = lift_pos <= 1 ? 2 * n : lift_pos - 1;
    drop_pos = drop_pos <= 1 ? 2 * n : drop_pos - 1;
    a[drop_pos].second = false; // ������ (�κ� ����)
}

void move(int lift_pos, int drop_pos, int n) { // 2. �̵�
    int pre = 0, now = drop_pos;
    while(pre != lift_pos) {
        pre = now <= 1 ? 2 * n : now - 1;
        // �κ� �̵� : �κ� ���� && ������ �������� && ���� ĭ �κ� ����
        if(!a[now].second && a[now].first && a[pre].second) {
            a[now].second = true;
            a[pre].second = false;
            a[now].first--; // ������ ����
        }
        now = now <= 1 ? 2 * n : now - 1;
    }
    a[drop_pos].second = false; // ������ (�κ� ����)
}

void lift(int lift_pos) { // 3. �ø���
    if(a[lift_pos].first) {
        a[lift_pos].second = true;
        a[lift_pos].first--;
    }
}

int belt(int n, int k) {
    int level = 0, lift_pos = 1, drop_pos = n;
    while(countZero(n) < k) {
        level++;
        rotate(lift_pos, drop_pos, n); // 1. �� ĭ ȸ��
        move(lift_pos, drop_pos, n); // 2. �̵�
        lift(lift_pos); // 3. �ø���
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