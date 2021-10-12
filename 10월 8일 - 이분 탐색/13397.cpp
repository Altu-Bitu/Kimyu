#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

// ���� ���� �ִ��� mid�� ��, ���� ��
int divide(int mid) {
    int cnt = 1, min_num, max_num; // ù��° ���� �Ҵ�
    min_num = max_num = v[0];

    for(int i = 1; i < n; i++) {
        min_num = min(min_num, v[i]);
        max_num = max(max_num, v[i]);
        if(max_num - min_num > mid) { // ���ο� ����
            cnt++;
            min_num = max_num = v[i];
        }
    }
    return cnt;
}

int findMin(int left, int right, int m) { // ���� ���� �ִ��� �ּڰ� ���
    int min_num = 0;
    while(left <= right) {
        int mid = (left + right) / 2;
        int cnt = divide(mid);

        if(cnt > m) left = mid + 1; // ���� ���� �ʰ� -> ���� �ִ� �ø���
        else if(cnt <= m) {         // ���� ���� ���� -> ���� �ִ� ���̱�
            min_num = mid;
            right = mid - 1;
        }
    }
    return min_num;
}

int main() {
    int m, max_num = 0;
    cin >> n >> m;

    v.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        max_num = max(max_num, v[i]);
    }

    // left: ���� ���� �ִ��� �ּڰ� / right: ���� ���� �ִ��� �ִ�
    cout << findMin(0, max_num, m);
    return 0;
}