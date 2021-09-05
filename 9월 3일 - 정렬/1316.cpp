#include <iostream>
#include <vector>

using namespace std;
vector<string> word;
vector<bool> alphabet;

int isGroup(string word) { // �׷� ���� Ȯ��
    alphabet.assign(26, false);

    char pre = word[0];
    alphabet[pre-97] = true;
    for(int i = 1; i < word.length(); i++) {
        char tmp = word[i];
        if(tmp != pre) {
            if(alphabet[tmp-97]) return 0;
            else {
                alphabet[tmp-97] = true;
                pre = tmp;
            }
        }
    }
    return 1;
}

int main() {
    int n, result = 0;
    cin >> n;

    word.assign(n, "");
    for(int i = 0; i < n; i++)
        cin >> word[i];

    for(int i = 0; i < n; i++) // �׷� ���� Ȯ��
        result += isGroup(word[i]);
    cout << result;
    return 0;
}