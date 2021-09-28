#include <iostream>

using namespace std;
const int SIZE = 10;

// ���� ����, ������, �ּҺ�� �����ϴ� ����
int n, start_pos = 0, min_cost = 10000000;
int w[SIZE+1][SIZE+1]; // ����ġ �����ϴ� �迭
bool check[SIZE+1];

void backtracking(int cnt, int start, int sum) {
    if(cnt == n-1) { // ���� ����: ��� ���� ��ȸ
        int last = w[start][start_pos]; // ���������� �ǵ��ư��� ���
        if(last == 0) return;
        sum += last;
        min_cost = min(min_cost, sum);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!check[i] && w[start][i]) {
            check[i] = true;
            backtracking(cnt + 1, i, sum + w[start][i]);
            check[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cin >> w[i][j];
    }

    for(int i = 1; i <= n; i++) {
        start_pos = i;
        check[i] = true;
        backtracking(0, i, 0);
        check[i] = false;
    }
    cout << min_cost;
    return 0;
}