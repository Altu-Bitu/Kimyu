#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> a, b;

long long arrSum(int n, int m, int t) { // �� �迭 �� ���� ���
    long long cnt = 0;
    // ���� a�� �ι迭, b�� �ι迭 �����ϴ� ��
    map<int, int> partial_a, partial_b; // (first: �� �迭 �� / second: �ش� �� �迭 �� ����)

    for(int a_right = n; a_right > 0; a_right--) { // a�� ��� �� �迭 ���ϱ�
        for (int a_left = 0; a_left < a_right; a_left++) {
            int a_sum = a[a_right] - a[a_left];
            partial_a[a_sum]++;
        }
    }
    for(int b_right = m; b_right > 0; b_right--) { // b�� ��� �� �迭 ���ϱ�
        for(int b_left = 0; b_left < b_right; b_left++) {
            int b_sum = b[b_right] - b[b_left];
            partial_b[b_sum]++;
        }
    }

    // (a �� �迭�� ��������)
    for(auto iter = partial_a.begin(); iter != partial_a.end(); iter++)
        cnt += (long long) iter->second * partial_b[t - iter->first]; // (�ش� �ι迭 �� ����) * ((t - a �ι迭 ��) ����)
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, m, num;
    cin >> t;

    cin >> n;
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> num;
        a[i] = a[i-1] + num;
    }

    cin >> m;
    b.assign(m+1, 0);
    for(int i = 1; i <= m; i++) {
        cin >> num;
        b[i] = b[i-1] + num;
    }

    cout << arrSum(n, m, t);
    return 0;
}