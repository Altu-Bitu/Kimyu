#include <iostream>

using namespace std;
const int SIZE = 1500000;

typedef struct consult{
    int time, pay; // �ð�, �޿�
}consult;
consult c[SIZE+1];
long long dp[SIZE+51];

long long maxProfit(int n) { // �ִ� ���� ���ϱ�
    int day;
    for(int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i]); // (���ϱ����� ������ ���������� ���ͺ��� Ŀ�� ��)
        day = i-1 + c[i].time;
        dp[day] = max(dp[day], dp[i-1] + c[i].pay);
    }
    return dp[n]; // n�ϱ����� �ִ� ���� ��ȯ
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> c[i].time >> c[i].pay;

    cout << maxProfit(n);
    return 0;
}