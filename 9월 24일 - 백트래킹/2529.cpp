#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 9;

int k;
char sign[SIZE];    // �ε�ȣ �����ϴ� �迭
int num [SIZE + 1]; // ���� �����ϴ� �迭
bool check[SIZE + 1];
vector<string> result; // �ε�ȣ ������ �����ϴ� ���� �����ϴ� ����

void backtracking(int cnt, int start, int end) {
    if(cnt == k+1) { // ���� ���� : �ε�ȣ ������ k�� -> ���ڴ� k+1��
        string temp = "";
        for(int i = 0; i < cnt; i++)
            temp += to_string(num[i]);
        result.push_back(temp);
        return;
    }

    for(int i = start; i <= end; i++) {
        if(!check[i]) {
            num[cnt] = i;
            check[i] = true;
            if(sign[cnt] == '<') backtracking(cnt+1, i+1, SIZE); // �ε�ȣ�� < �� ���: ū ���ڸ� Ž��
            else backtracking(cnt+1, 0, i-1);               // �ε�ȣ�� >�� ���: ���� ���ڸ� Ž��
            check[i] = false; // ���� ����
        }
    }
}

int main() {
    cin >> k;
    for(int i = 0; i < k; i++)
        cin >> sign[i];

    backtracking(0, 0, SIZE);
    cout << result[result.size()-1] << '\n';
    cout << result[0];
    return 0;
}