#include <iostream>

using namespace std;
const int N = 50, P = 9;

int score = 0, turn;
int order[P+1];  // ���� ���� ����
bool check[P+1]; // ���� ���� ����
int result[N+1][P+1];

int move(bool base[4], int hit) { // ���� �̵�
    int m = 0;
    for(int i = 3; i >= 1; i--) {
        if(base[i]) { // ���� �ִ� ���
            if(i + hit >= 4) m++; // Ȩ���� ������ ���
            else base[i+hit] = base[i];
            base[i] = false;
        }
    }
    return m;
}

int baseball(int inning) { // (�̴׺� ���� ��ȯ)
    int out = 0, s = 0;
    bool base[4] = { false, }; // 1 : 1�� / 2 : 2�� / 3 : 3��

    while(out < 3) { // ���� �ƿ� ������
        int hit = result[inning][order[turn]];
        if(!hit) out++; // �ƿ�
        else {
            s += move(base, hit);  // ���� �̵�
            if(hit == 4) s++;      // Ȩ��
            else base[hit] = true; // ��Ÿ (1��Ÿ / 2��Ÿ / 3��Ÿ)
        }
        turn = turn == P ? 1 : turn+1; // Ÿ�� ����
    }
    return s;
}

void backtracking(int cnt, int n) {
    if(cnt > P) { // ���� ����: ���� ���� ���� �� ������
        turn = 1;
        int temp = 0;
        for(int i = 1; i <= n; i++) // ��� ����
            temp += baseball(i);
        score = max(score, temp);
        return;
    }

    if(cnt == 4) backtracking(cnt + 1, n); // (4�� ���� �������� ����)
    else {
        for (int i = 1; i <= P; i++) { // i: ����
            if (!check[i]) { // �������� ���� ���� -> ����
                order[cnt] = i;
                check[i] = true;
                backtracking(cnt + 1, n);
                check[i] = false;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    order[4] = 1; // 4�� Ÿ�� == 1�� ����
    check[1] = true; // (1�� ���� ���� ���� �Ϸ�)

    for(int i = 1; i <= n; i++) { // (i : �̴�)
        for(int j = 1; j <= P; j++) // (j : ����)
            cin >> result[i][j];
    }

    backtracking(1, n);
    cout << score;
    return 0;
}