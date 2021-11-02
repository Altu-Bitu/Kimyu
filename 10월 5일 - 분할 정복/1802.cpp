#include <iostream>

using namespace std;
bool result;

void divide(int left, int right, string paper) {
    if(left >= right) return; // ��������

    int l = left, r = right;
    while(l < r) {
        if(paper[l++] == paper[r--]) {
            result = false;
            return;
        }
    }
    // (������ l == r�̹Ƿ�) l�� r �� mid ��
    divide(left, l-1, paper); // left ~ mid������ �˻�
}

int main() {
    int t, mid;
    cin >> t;

    string paper;
    while(t--) {
        cin >> paper;

        result = true; // �׽�Ʈ���̽����� ���� �ʱ�ȭ
        divide(0, paper.length()-1, paper);
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}