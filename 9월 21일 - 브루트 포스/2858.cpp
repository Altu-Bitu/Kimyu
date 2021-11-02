#include <iostream>

using namespace std;

int getRoomSize(int total, int red, int brown) { // �� �� ���� ���� ���ϱ�
    for(int i = 2; i < total/2; i++) {
        if(i * (total/i) == total) {
            int check = 2*(i + total/i)-4;
            if(check == red || check == brown) return i;
        }
    }
    return 0;
}

int main() {
    int r, b, total, l, w, temp;
    cin >> r >> b;

    total = r + b; // �� Ÿ�� ����
    temp = getRoomSize(total, r, b); // �� �� ���� ����

    l = max(temp, total/temp);
    w = min(temp, total/temp);
    cout << l << ' ' << w;
    return 0;
}