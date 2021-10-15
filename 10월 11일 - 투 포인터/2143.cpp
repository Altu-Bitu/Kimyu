#include <iostream>
#include <vector>

using namespace std;

vector<int> a, b;

int arrSum(int n, int m, int t) { // �� �迭 �� ���� ���
    int cnt = 0;
    int a_left = 0, a_right = 1;

    while(a_left < a_right && a_right <= n) {
        int a_sum = a[a_right] - a[a_left];
        if(a_sum >= t) { // a �ι迭 ���� t���� ũ�ų� ������ �� �迭 �� �Ұ���
            a_left++;
            if(a_left == a_right) a_right++;
            continue;
        }

        int b_left = 0, b_right = 1;
        while (b_left < b_right && b_right <= m) {
            int b_sum = b[b_right] - b[b_left];

            if (a_sum + b_sum == t) { cnt++; b_left++; } // �� �迭 �� �߰�
            else if (a_sum + b_sum >= t) {               // b �迭 ���� ���̱�
                b_left++;
                if(b_left == b_right) b_right++;
            }
            else b_right++;                              // b �迭 ���� �ø���
        }

        if(a_right - a_left > 1) a_left++; // a �迭 ���� ���̱�
        else a_right++;                    // ���̻� a �迭 ���� ���� �� ���� -> a �迭 ���� �ø���
    }
    return cnt;
}

int main() {
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