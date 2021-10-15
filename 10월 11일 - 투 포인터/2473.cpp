#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef struct liquid {
    int l[3];
}liquid;
vector<int> l;

// �� ���� ��� ȥ�հ��� 0�� ��������
liquid threeLiquid(int n) {
    liquid result;
    ll min_diff = 3 * 1e9 + 1; // �� ���� ��� ȥ�հ� �ּڰ� �����ϴ� ����

    for(int i = 0; i < n; i++) { // i��° -> ������ ���
        int left = 0, right = n-1;

        while(left < right && min_diff) { // (min_diff�� 0�̸� stop)
            if(left == i) { left++; continue; }
            if(right == i) { right--; continue; }

            ll mix = (ll) l[left] + l[i] + l[right];
            if(abs(mix) < min_diff) {
                min_diff = abs(mix);
                result.l[0] = l[left];
                result.l[1] = l[i];
                result.l[2] = l[right];
            }

            if(mix > 0) right--;     // �� ���� �� �����
            else if(mix < 0) left++; // �� ū �� �����
        }
    }
    sort(result.l, result.l+3); // �� ��� �������� ����
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    l.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> l[i];
    sort(l.begin(), l.end());

    liquid result = threeLiquid(n);
    cout << result.l[0] << ' ' << result.l[1] << ' ' << result.l[2];
    return 0;
}