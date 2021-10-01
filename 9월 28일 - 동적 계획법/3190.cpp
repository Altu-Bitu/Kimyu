#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 100;

int n;
bool apple[SIZE+1][SIZE+1], body[SIZE+1][SIZE+1];
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0}; // (�� �� �� ��)
char change[SIZE*SIZE+1];
queue<pair<int, int>> snake;

int changeDirection(int time, int dir) {
    if(change[time] == 'L') return (dir+1) % 4;
    if(change[time] == 'D') return (dir-1 < 0 ? 3 : dir-1) % 4;
    return dir;
}

int dummyGame() {
    int time = 0, row, col, dir = 3;

    snake.push({1, 1}); // �ʱ� ��ġ
    while(true) {
        time++;

        // ��(back)
        row = snake.back().first + dy[dir];
        col = snake.back().second + dx[dir];
        if(row < 1 || row > n || col < 1 || col > n || body[row][col]) break; // ���̳� �ڱ� �ڽ��� ���� �ε����� ���
        snake.push({row, col}); // �� PUSH
        body[row][col] = true;
        dir = changeDirection(time, dir); // ���� ��ȯ

        // ���� (front)
        if(apple[row][col]) apple[row][col] = false; // ��� �߰� -> ���� �״�� & ��� �Ա�
        else { // ��� ���� -> ���� ���̱�
            body[snake.front().first][snake.front().second] = false;
            snake.pop();
        }
    }
    return time;
}

int main() {
    int k, l, row, col, x;
    char c;

    cin >> n;
    cin >> k;

    while(k--) { // ��� ��ġ �Է�
        cin >> row >> col;
        apple[row][col] = true;
    }

    cin >> l;
    while(l--) { // ���� ��ȯ ���� �Է�
        cin >> x >> c;
        change[x] = c;
    }

    cout << dummyGame();
    return 0;
}