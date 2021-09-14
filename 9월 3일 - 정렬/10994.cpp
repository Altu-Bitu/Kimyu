#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> star;

void top(int size, int pos){ // ��
    for(int i = 0; i < 4*size-3; i++)
        star[pos][pos+i] = '*';
}

void bottom(int n, int size, int pos) { // �Ʒ�
    for(int i = 0; i < 4*size-3; i++)
        star[4*(n-1)-pos][pos+i] = '*';
}

void left(int size, int pos) { // ����
    for(int i = 0; i < 4*size-3; i++)
        star[pos+i][pos] = '*';
}

void right(int n, int size, int pos) { // ������
    for(int i = 0; i < 4*size-3; i++)
        star[pos+i][4*(n-1)-pos] = '*';
}

void makeStar(int n, int size, int pos) { // �� ���
    if(size > 0) {
        top(size, pos);
        left(size, pos);
        right(n, size, pos);
        bottom(n, size, pos);
        makeStar(n, size-1, pos+2);
    }
}

int main() {
    int n, size;
    cin >> n;

    star.assign(4*n-3, vector<char>(4*n-3, ' '));
    makeStar(n, n, 0); // �� ���

    for(int i = 0; i < 4*n-3; i++){ // �� ���
        for(int j = 0; j < 4*n-3; j++)
            cout << star[i][j];
        cout << '\n';
    }
    return 0;
}