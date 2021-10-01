#include <iostream>

using namespace std;
const int MAX = 100, Q = 1000000000;

int dp[MAX+1][10];

long long countStairs(int n) { // ��� �� ���� ����
    long long count = 0;
    dp[1][0] = 0; // 0���� �����ϴ� ���� ��� �� �ƴ�

    // i: �ڸ��� / j: �ش� �ڸ��� ����
    for(int j = 1; j <= 9; j++)
        dp[1][j] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) dp[i][j] = dp[i-1][j+1] % Q;
            else if(j == 9) dp[i][j] = dp[i-1][j-1] % Q;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % Q;
        }
    }

    for(int j = 0; j <= 9; j++) // n�ڸ����� count
        count += dp[n][j];
    return count % Q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << countStairs(n);
    return 0;
}