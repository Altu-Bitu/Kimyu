#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 100;

vector<pair<int, int>> cable; // (A ������ ��ȣ, B ������ ��ȣ)
int dp[SIZE+1]; // ���� ���� �����ϴ� �迭

int removeCable(int n) { // ���־� �ϴ� ������ �ּ� ���� ���ϱ�
    int result = 0, start = cable[1].second; // (start: start ������ B ������ ��ȣ)
    dp[1] = 1;

    for(int i = 2; i <= n; i++) { // ���̺��� ���� ���� ã��
        // ���� ���̺��� ���� ���
        if(cable[i].second < cable[i-1].second && start < cable[i].second) dp[i] = dp[i-1]; // start ������ �����ٴ� ū ���
        else if(cable[i].second < cable[i-1].second && start > cable[i].second) { // start ������ ������ ���� ���
            dp[i] = 1;
            start = cable[i].second;
        }
        // ���� ���̺��� ū ���
        else dp[i] = dp[i-1] + 1;
        result = max(result, dp[i]);
    }
    return n - result;
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