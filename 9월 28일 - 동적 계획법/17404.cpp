#include <iostream>

using namespace std;
const int N = 1000;

int cost[N+1][3];
int dp[N+1][3];

int minCost(int n) {
    int min_cost = N*N+1;

    for(int i = 0; i < 3; i++) { // i: 1�� �� ����
        for(int j = 0; j < 3; j++) {
            if(j == i) dp[1][j] = cost[1][j];
            else dp[1][j] = N*N+1;
        }
        // ���� ���� ���޾� ������ �ʵ���
        for(int j = 2; j <= n; j++) {
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + cost[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + cost[j][1];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + cost[j][2];
        }
        // n��° ��
        for(int j = 0; j < 3; j++)
            if(j != i) min_cost = min(min_cost, dp[n][j]); // 1�� �� ����� ��ġ�� �ʴ� ���
    }
    return min_cost;
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    cout << minCost(n);
    return 0;
}