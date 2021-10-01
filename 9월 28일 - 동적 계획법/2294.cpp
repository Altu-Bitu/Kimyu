#include <iostream>

using namespace std;
const int N = 100, K = 10000;

int coin[N+1];
int dp[K+1];  // ���� ��ġ�� �ش��ϴ� ���� ����

int countCoin(int n, int k) { // ���� �ּ� ���� ���ϱ�
    for(int i = 1; i <= k; i++) // dp �ʱ�ȭ
        dp[i] = K+1;

    for(int j = 1; j <= n; j++) { // (j: ����)
        // ���� ���� ���� ��ġ���� ���� ���
        for(int i = coin[j]; i <= k; i++)
            dp[i] = min(dp[i], dp[i-coin[j]]+1);
    }
    return (dp[k] == K+1) ? -1 : dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> coin[i];
    cout << countCoin(n, k);
    return 0;
}