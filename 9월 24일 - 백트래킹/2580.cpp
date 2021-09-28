#include <iostream>

using namespace std;
const int SIZE = 9;

bool complete = false; // ������ �� ä�� �� �ִ��� �����ϴ� ����
int count = 0; // ����ִ� ĭ ���� ����
pair<int, int> blank[SIZE*SIZE]; // ����ִ� ĭ�� ��, �� ��ȣ �����ϴ� �迭
int sudoku[SIZE][SIZE]; // ������ �����ϴ� �迭

void printSudoku() { // �ϼ��� ������ ���
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            cout << sudoku[i][j] << ' ';
        cout << '\n';
    }
}

bool possible(int row, int col) {
    int row_range = 3 * (row/3), col_range = 3 * (col/3);

    for(int i = 0; i < SIZE; i++) {
        // 1. �� �˻� (�� ��ġ �ٸ��鼭 �� ���� ���)
        if(sudoku[row][i] == sudoku[row][col] && i != col) return false;
        // 2. �� �˻� (�� ��ġ �ٸ��鼭 �� ���� ���)
        if(sudoku[i][col] == sudoku[row][col] && i != row) return false;
    }

    for(int i = row_range; i < row_range+3; i++) {
        for(int j = col_range; j < col_range+3; j++) {
            // 3. 3x3 ���簢�� �˻� (��ġ �ٸ��鼭 �� ���� ���)
            if(sudoku[i][j] == sudoku[row][col] && i != row && j != col) return false;
        }
    }
    return true;
}

void backtracking(int cnt) {

    if(cnt == count) {
        printSudoku();
        complete = true;
        return;
    }

    int row = blank[cnt].first, col = blank[cnt].second;
    for(int i = 1; i <= SIZE; i++) {
        sudoku[row][col] = i;
        if(possible(row, col)) backtracking(cnt+1);
        if(complete) return;
    }
    sudoku[row][col] = 0; // ���� ����
}

int main() {

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> sudoku[i][j];
            if(!sudoku[i][j]) blank[count++] = {i, j};
        }
    }
    backtracking(0);
    return 0;
}