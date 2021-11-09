#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> event;

void setRelation(int n) { // (�÷��̵�-���� �˰��� �̿��Ͽ� ���� ����)
    for(int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(event[i][k] == -1 && event[k][j] == -1) { // i -> k -> j
                    event[i][j] = -1; // �ռ���
                    event[j][i] = 1;  // �޼���
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, s, pre, next;
    cin >> n >> k;

    event.assign(n+1, vector<int> (n+1, 0)); // ���� �Ұ� ���·� �ʱ�ȭ
    while(k--) { // ��� ���� �Է�
        cin >> pre >> next;
        event[pre][next] = -1; // �ռ���
        event[next][pre] = 1;  // �޼���
    }
    setRelation(n);

    cin >> s;
    while(s--) {
        cin >> pre >> next;
        cout << event[pre][next] << '\n';
    }
    return 0;
}