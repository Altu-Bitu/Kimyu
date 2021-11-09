#include <iostream>
#include <vector>

using namespace std;
const int MAX_SIZE = 100;

int x, y;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1}; // ����
bool board[MAX_SIZE+1][MAX_SIZE+1];

// 0���� : 0
// 1���� : 0 1                (0 -> 1)
// 2���� : 0 1 2 1            (1 -> 2, 0 -> 1)
// 3���� : 0 1 2 1 2 3 2 1    (1 -> 2, 2 -> 3, 0 -> 1)
void dragonCurve(vector<int> &dir) { // g���� �巡�� Ŀ�� �׸���
    int curve_size = dir.size();
    for(int i = curve_size-1; i >= 0; i--) {
        int d = (dir[i] + 1) % 4;
        x += dx[d];
        y += dy[d];
        board[y][x] = true;
        dir.push_back(d);
    }
}

int countDragonCurve() { // ���簢���� �� �������� ��� �巡�� Ŀ���� �Ϻ��� ���簢�� ���� ���ϱ�
    int count = 0;
    for(int i = 0; i <= MAX_SIZE; i++) {
        for(int j = 0; j <= MAX_SIZE; j++) {
            if(board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1])
                count++;
        }
    }
    return count;
}

int main() {
    int n, d, g;
    cin >> n;

    while(n--) {
        // ������, ���� ����, ����
        cin >> x >> y >> d >> g;

        // 0���� �巡�� Ŀ�� (����)
        board[y][x] = true;
        x += dx[d];
        y += dy[d];
        board[y][x] = true;

        vector<int> dir;
        dir.push_back(d);

        // 1~g���� �巡�� Ŀ�� �׸���
        while(g--) dragonCurve(dir);
    }

    cout << countDragonCurve();
    return 0;
}