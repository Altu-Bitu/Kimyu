#include <iostream>
#include <vector>

using namespace std;
int alpha[26];
vector<string> word;

bool checkConfiguration(int cmp[26]) { // �� ���� ���� ���ϱ�
    // idx : (�ʱ� ���� : -1) �� ���� ������ �ٸ� ��� �ش� ���ĺ� ��ȣ ����
    int different = 0, idx = -1;

    for(int i = 0; i < 26; i++) {
        if(alpha[i] == cmp[i]) continue;

        // ���� ���� ->  1. �� ���� ���ϰų� ����  2. �� ���� �ٸ� ���ڷ� �ٲٱ�
        different += abs(alpha[i] - cmp[i]);
        if(different > 2) return false;

        // idx != -1 : ������ �� ���� ������ �ٸ� ��찡 �־���
        // alpha[idx] + alpha[i] != cmp[idx] + cmp[i] : ������ �޶��� ���ڸ� �̹� ���ڷ� �ٲ� �� ����
        if(idx != -1 && alpha[idx] + alpha[i] != cmp[idx] + cmp[i]) return false; // 2�� ����
        idx = i;
    }
    return true;
}

void setAlphabet(int a[26], string w) { // �ܾ� ���� �����ϱ�
    for(int i = 0; i < w.length(); i++)
        a[w[i] - 'A']++;
}

int isSimilar(int n) {
    int cnt = 0;
    setAlphabet(alpha, word[0]); // ù��° ���ĺ� ���� ����

    for(int i = 1; i < n; i++) {
        int cmp[26] = {0, };
        setAlphabet(cmp, word[i]); // ���� ���ĺ� ���� ����
        if(checkConfiguration(cmp)) cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    word.assign(n, "");
    for(int i = 0; i < n; i++)
        cin >> word[i];

    cout << isSimilar(n);
    return 0;
}