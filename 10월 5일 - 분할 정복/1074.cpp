#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int idx = 0; // ���� �����ϴ� ����
vector<vector<int>> arr;

void order(int row, int col, int size) { // ���� ���ϱ�
    if(size == 2) { // conquer
        for(int i = row; i < row + 2; i++) {
            for(int j = col; j < col + 2; j++) {
                arr[i][j] = idx++;
            }
        }
        return;
    }

    // divide (z��� �������)
    order(row, col, size/2);
    order(row, col + size/2, size/2);
    order(row + size/2, col, size/2);
    order(row + size/2, col + size/2, size/2);
}

int main() {
    int n, r, c;
    cin >> n >> r >> c;

    int size = pow(2, n);
    arr.assign(size, vector<int>(size, 0));
    order(0, 0, size); // ���� ���ϱ�

    cout << arr[r][c]; // �ش� ĭ�� ���� ����ϱ�
    return 0;
}