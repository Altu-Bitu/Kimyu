#include <iostream>
#include <vector>

using namespace std;

// ������ �������� �ʰ� m���� ���� ���� ��� �� (�����̵� ������)
int steal(vector<int> house, int n, int m, int k) {
    int cnt =0, money = 0;

    for(int i = 0; i < m; i++)
        money += house[i];
    if(money < k) cnt++;

    if(n == m) return cnt; // (�ٸ� ��� ����)

    for(int i = 1; i < n; i++) {
        money -= house[i-1];
        money += house[(i-1+m) % n];
        if(money < k) cnt++;
    }
    return cnt;
}

int main() {
    int t, n, m, k;
    cin >> t;

    while(t--) {
        cin >> n >> m >> k;

        vector<int> house (n, 0);
        for(int i = 0; i < n; i++)
            cin >> house[i];
        cout << steal(house, n, m, k) << '\n';
    }
    return 0;
}