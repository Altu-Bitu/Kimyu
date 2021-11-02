#include <iostream>

using namespace std;
const int N = 100000, MAX = 1000000000;

int dis[N], cost[N]; // �Ÿ�, �ֿ�� ���� �����ϴ� �迭

long long minCost(int n) { // �ּ� ��� ���ϱ�
    long long result = 0, min_cost = MAX;
    for(int i = 0; i < n-1; i++) {
        if(cost[i] < min_cost) min_cost = cost[i];
        result += (long long) dis[i] * min_cost;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++)
        cin >> dis[i];
    for(int i = 0; i < n; i++)
        cin >> cost[i];

    cout << minCost(n);
    return 0;
}