#include <iostream>

using namespace std;

bool isEmpty(int row, int col) { // ���� ���� ����
    if(row % 3 == 1 && col % 3 == 1) return true;
    else if(!(row / 3) || !(col / 3)) return false; // ��������
    else return isEmpty(row / 3, col / 3); // divide
}

void drawStar(int n) { // �� ���
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(isEmpty(i, j)) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    drawStar(n);
    return 0;
}