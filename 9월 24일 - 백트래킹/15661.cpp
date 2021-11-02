#include <iostream>

using namespace std;
const int SIZE = 20;

int n, difference = 40000; // �ο� ��, �ɷ�ġ ���� �����ϴ� ����
bool check[SIZE+1];    // ��ŸƮ�� ���� ���� �����ϴ� �迭
int s[SIZE+1][SIZE+1]; // �ɷ�ġ �����ϴ� �迭

int computeSkillScore() { // �ɷ�ġ ���
    int start_skill = 0, link_skill = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(check[i] && check[j]) start_skill += s[i][j];
            else if(!check[i] && !check[j]) link_skill += s[i][j];
        }
    }
    return abs(start_skill - link_skill); // �ɷ�ġ ���� �缳��
}

void backtracking(int idx) {
    if(idx == n) { // ���� ����: idx ������ ���� ����
        difference = min(difference, computeSkillScore());
        return;
    }

    for(int i = idx; i <= n; i++) { // �� ����
        if(!check[i]) {
            check[i] = true;
            backtracking(i);
            check[i] = false; // ���� ����
        }
    }
}

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) { // �ɷ�ġ �Է�
        for(int j = 1; j <= n; j++)
            cin >> s[i][j];
    }

    backtracking(1);
    cout << difference;
    return 0;
}