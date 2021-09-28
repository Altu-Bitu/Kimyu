#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 15;

int l, c;
char cipher[SIZE];
char alphabet[SIZE+1];

void backtracking(int cnt, int start, int vowel) {
    if(cnt == l) { // ���� ����: �ܾ� ���� l�� ��
        if(vowel >= 1 && l-vowel >= 2) {
            // 1. �ּ� �� ���� ����
            // 2. �ּ� �� ���� ����
            for (int i = 0; i < cnt; i++) // ������ ��ȣ ���
                cout << cipher[i];
            cout << '\n';
        }
        return;
    }

    for(int i = start; i <= c; i++) {
        cipher[cnt] = alphabet[i];
        // (i+1: ��������)
        if(alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' || alphabet[i] == 'u') backtracking(cnt+1, i+1, vowel+1);
        else backtracking(cnt+1, i+1, vowel);
    }
}

int main() {
    cin >> l >> c;

    for(int i = 1; i <= c; i++)
        cin >> alphabet[i];
    sort(alphabet+1, alphabet+c+1); // �Է��� ���ڵ� ����

    backtracking(0, 1, 0);
    return 0;
}