#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<int> l;

// �� ���� ��� ȥ�հ��� 0�� ��������
vector<int> threeLiquid(int n) {
    vector<int> liquid(3, 0);
    ll min_diff = 3 * 1e9 + 1; // �� ���� ��� ȥ�հ� �ּڰ� �����ϴ� ����

    for(int i = 0; i < n; i++) { // i��° -> ������ ���
        int left = i+1, right = n-1;

        while(left < right && min_diff) { // (min_diff�� 0�̸� stop)
            ll mix = (ll) l[left] + l[i] + l[right];

            if(abs(mix) < min_diff) {
                min_diff = abs(mix);
                liquid[0] = l[i];
                liquid[1] = l[left];
                liquid[2] = l[right];
            }

            if(mix > 0) right--;     // �� ���� �� �����
            else if(mix < 0) left++; // �� ū �� �����
        }
    }
    return liquid;
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

    vector<int> liquid = threeLiquid(n);
    cout << liquid[0] << ' ' << liquid[1] << ' ' << liquid[2];
    return 0;
}