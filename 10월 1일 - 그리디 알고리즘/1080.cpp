#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> matrix; // (0 : A ��� / 1 : B ���)

bool change(int row, int col, int n, int m) { // ��� �ٲ� �� �ִ°�
    if(row >= n-2 || col >= m-2) return false;
    // ��� �ٲٱ�
    for(int i = row; i < row+3; i++) {
        for(int j = col; j < col+3; j++)
            matrix[0][i][j] = !matrix[0][i][j]; // ���� ������
    }
    return true;
}

int countChange(int n, int m) { // ��� �ٲٴ� Ƚ�� ����
    int result = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[0][i][j] != matrix[1][i][j]) {
                if(!change(i, j, n, m)) return -1; // B�� ������ �� ���� ���
                result++;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    string input;
    cin >> n >> m;

    matrix.assign(2, vector<vector<int>> (n, vector<int> (m, 0)));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input;
            for(int k = 0; k < m; k++)
                matrix[i][j][k] = input[k]-'0';
        }
    }

    cout << countChange(n, m);
    return 0;
}