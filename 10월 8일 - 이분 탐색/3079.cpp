#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
int n;
vector<int> t;

// �ɻ� �ð��� mid�� ��, �ɻ���� �� �ִ� ��� ��
ll pass(int mid) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(mid < t[i]) return cnt;
        cnt += (mid / t[i]);
    }
    return cnt;
}

ll minTime(ll left, ll right, int m) { // �ּ� �ɻ� �ð� ��ȯ
    ll sec = right;

    while(left <= right) {
        ll mid = (left + right) / 2;
        ll cnt = pass(mid);

        if(cnt < m) left = mid + 1; // ��� ��� ������� ���� -> �ɻ� �ð� �ø���
        else if(cnt >= m) {         // ��� ��� ��� -> �ɻ� �ð� ���̱�
            sec = mid;
            right = mid - 1;
        }
    }
    return sec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> n >> m;

    t.assign(n, 0);
    for(int i = 0 ; i < n; i++)
        cin >> t[i];
    sort(t.begin(), t.end());

    // left : �ɻ� �ҿ� �ð� �ּڰ� / right : �ɻ� �ҿ� �ð� �ִ�
    cout << minTime(t[0], t[n-1] * m, m);
    return 0;
}