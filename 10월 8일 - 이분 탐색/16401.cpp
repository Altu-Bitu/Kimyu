#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> l;

// ���� ���̰� len�� ��, ������ �� �ִ� ��ī ��
int divide(int len) {
    int nephew = 0;
    for(int i = 0; i < n; i++) {
        if(l[i] < len) return nephew; // ����� �� ���� ����
        nephew += (l[i] / len);
    }
    return nephew;
}

// ���� ���� �ִ� ���� ��ȯ
int cookie(int left, int right, int m) {
    int len = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int nephew = divide(mid); // ���� ���̰� mid ������ �� �ִ� ��ī ��

        if(nephew < m) right = mid - 1; // ��� ��ī���� ������ �� ���� -> ���� ���� ���̱�
        else if(nephew >= m) { // ��� ��ī���� ������ �� ���� -> ���� �ø���
            len = mid;
            left = mid + 1;
        }
    }
    return len;
}

int main() {
    int m;
    cin >> m >> n;

    l.assign(n, 0);
    for(int i = 0; i <n; i++)
        cin >> l[i];
    sort(l.begin(), l.end(), greater<>()); // �������� ����

    // left : ��Ű �ּ� ���� / right: ��Ű �ְ� ����
    cout << cookie(1, l[0], m);
    return 0;
}