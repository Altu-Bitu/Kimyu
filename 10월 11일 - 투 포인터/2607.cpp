#include <iostream>
#include <vector>

using namespace std;
int alpha[26];
vector<string> word;

bool checkConfiguration(int cmp[26]) { // �� ���� ���� ���ϱ�
    int different = 0;

    int left = 0, right = 25;
    while(left < right) {
        while(left < right) { // �ٸ� ���� ���� ������ �ݺ�
            if(alpha[left] != cmp[left]) break;
            left++;
        }
        different += abs(alpha[left] - cmp[left]);
        if(different > 2) return false;
        if(left == right) break;

        while(left < right) { // �ٸ� ���� ���� ������ �ݺ�
            if(alpha[right] != cmp[right]) break;
            right--;
        }
        different += abs(alpha[right] - cmp[right]);
        if(different > 2) return false;
        if(left == right) break;

        // �ϳ��� ���ڸ� �ٸ� ���ڷ� �ٲ� �� �ִ� ���
        if((alpha[left] + alpha[right]) != (cmp[left] + cmp[right])) return false;
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