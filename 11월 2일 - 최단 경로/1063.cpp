#include <iostream>
#include <vector>

using namespace std;

int r_king, c_king, r_stone, c_stone;
// R L B T RT LT RB LB
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1}, dy[8] = {0, 0, 1, -1, -1, -1, 1, 1};

// ü������ ����°�
bool isOut(int row, int col) { return (row < 0 || row >= 8 || col < 0 || col >= 8); }
// ü���� ��ġ ����
void renewPosition(int &row, int &col, int new_row, int new_col) { row = new_row; col = new_col; }

void move(string direction) {
    int dir = 0;
    if(direction == "L") dir = 1;
    else if(direction == "B") dir = 2;
    else if(direction == "T") dir = 3;
    else if(direction == "RT") dir = 4;
    else if(direction == "LT") dir = 5;
    else if(direction == "RB") dir = 6;
    else if(direction == "LB") dir = 7;

    int new_r_king = r_king + dy[dir];
    int new_c_king = c_king + dx[dir];
    if(isOut(new_r_king, new_c_king)) return; // ü���� ����� ���

    if(new_r_king == r_stone && new_c_king == c_stone) { // ���� ���� ���� ��ġ�ϴ� ���
        int new_r_stone = r_stone + dy[dir];
        int new_c_stone = c_stone + dx[dir];
        if(isOut(new_r_stone, new_c_stone)) return; // ü���� ����� ���
        renewPosition(r_stone, c_stone, new_r_stone, new_c_stone);
    }
    renewPosition(r_king, c_king, new_r_king, new_c_king);
}

int main() {
    string king, stone, direction;
    int n;

    cin >> king >> stone >> n;
    c_king = king[0] - 'A'; r_king = '8' - king[1];
    c_stone = stone[0] - 'A'; r_stone = '8' - stone[1];

    for(int i = 0; i < n; i++) {
        cin >> direction;
        move(direction);
    }
    cout << (char)(c_king + 'A') << 8 - r_king << '\n';
    cout << (char) (c_stone + 'A') << 8 - r_stone;
    return 0;
}