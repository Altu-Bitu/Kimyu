#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> star;

void top(int size, int row, int col){ // ��
    for(int i = 0; i < 4*size-3; i++)
        star[row][col+i] = '*';
}

void bottom(int n, int size, int row, int col) { // �Ʒ�
    for(int i = 0; i < 4*size-3; i++)
        star[4*(n-1)-row][col+i] = '*';
}

void left(int size, int row, int col) { // ����
    for(int i = 0; i < 4*size-3; i++)
        star[row+i][col] = '*';
}

void right(int n, int size, int row, int col) { // ������
    for(int i = 0; i < 4*size-3; i++)
        star[row+i][4*(n-1)-row] = '*';
}

void makeStar(int n, int size, int row, int col) { // �� ���
    top(size, row, col);
    left(size, row, col);
    right(n, size, row, col);
    bottom(n, size, row, col);
}

int main() {
    int n, size;
    cin >> n;

    star.assign(4*n-3, vector<char>(4*n-3, ' '));
    for(int i = 0; i < n; i++)
        makeStar(n, n-i, 2*i, 2*i);

    for(int i = 0; i < 4*n-3; i++){ // �� ���
        for(int j = 0; j < 4*n-3; j++)
            cout << star[i][j];
        cout << '\n';
    }
    return 0;
}