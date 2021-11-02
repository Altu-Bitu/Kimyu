#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 100;

vector<pair<int, int>> cable; // (A ������ ��ȣ, B ������ ��ȣ)
int dp[SIZE+1]; // (�ش� �ε������� ���� ���� ���� ����)

int removeCable(int n) { // ���־� �ϴ� ������ �ּ� ���� ���ϱ�
    int inc = 1; // ���� ���� �ִ� ���� �����ϴ� ����

    dp[1] = 1;
    for(int i = 2; i <= n; i++) { // ���̺��� ���� ���� ã��
        int temp = 1;
        for(int j = 1; j < i; j++)
            if(cable[j].second < cable[i].second) temp = max(temp, dp[j] + 1);
        dp[i] = temp;
        inc = max(inc, dp[i]);
    }
    return n - inc;
}

int main() {
    int n;
    cin >> n;

    cable.assign(n+1, {0, 0});
    for(int i = 1; i <= n; i++)
        cin >> cable[i].first >> cable[i].second;
    sort(cable.begin()+1, cable.end());

    cout << removeCable(n);
    return 0;
}