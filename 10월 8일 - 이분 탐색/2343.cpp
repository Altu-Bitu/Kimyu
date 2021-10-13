#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> lecture;

// ��緹�� ���̰� len�� ��, ��緹�� ����
int divide(int len) {
    int cnt = 1, sum = lecture[0]; // ù��° ��緹�� ī��Ʈ

    for(int i = 1; i < n; i++) {
        sum += lecture[i];
        if(sum > len) { cnt++; sum = lecture[i]; }
    }
    return cnt;
}

// ��緹�� �ּ� ���� ��ȯ
int bluelay(int left, int right, int m) {
    int len = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int tmp = divide(mid); // ���̰� mid�� �� ��緹�� ����

        if(tmp > m) left = mid + 1; // ��緹�� ���� �ʰ� -> ���� �ø���
        else if(tmp <= m) { // ��緹�� ���� ���� -> ���� ���̱�
            len = mid;
            right = mid - 1;
        }
    }
    return len;
}

int main() {
    int m, long_lec = 0;
    cin >> n >> m;

    lecture.assign(n, 0);
    for(int i = 0; i < n; i++) { // ���� ���� �Է�
        cin >> lecture[i];
        long_lec = max(long_lec, lecture[i]);
    }

    // left : ��緹�� �ּ� ���� / right : ��緹�� �ִ� ����
    cout << bluelay(long_lec, long_lec * n, m);
    return 0;
}