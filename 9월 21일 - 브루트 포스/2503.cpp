#include <iostream>
#include <vector>

using namespace std;
bool suppose[1000];

vector<int> digit(int q) { // �ڸ��� ���ϱ�
    vector<int> temp;
    temp.assign(3, 0);
    for(int i = 2; i >= 0; i--) {
        temp[i] = q % 10;
        q /= 10;
    }
    return temp;
}

void setInvalid() { // �Ұ����� �� ����
    for(int i = 0; i < 123; i++) suppose[i] = false; // 1. �� �ڸ��� �Ұ���
    for(int i = 123; i <= 987; i++) {
        vector<int> check = digit(i);
        if(check[0] == 0 || check[1] == 0 || check[2] == 0) { // 2. 0 �Ұ���
            suppose[i] = false;
            continue;
        }
        else if(check[0] == check[1] || check[0] == check[2] || check[1] == check[2]) { // 3. ���� ���� �Ұ���
            suppose[i] = false;
            continue;
        }
        suppose[i] = true;
    }
    for(int i = 988; i < 1000; i++) suppose[i] = false; // 4. �ִ� ���� ����� ���
}

void baseballGame(int q, int strike, int ball) { // ���� �߱�
    vector<int> num = digit(q);

    for(int i = 123; i <= 987; i++) { // ���� ���� ���� ����Ʈ
        int strike_cnt = 0, ball_cnt = 0;

        if(suppose[i]) {
            vector<int> cmp = digit(i); // �� ���
            for(int j = 0; j < 3; j++) {
                for(int k = 0; k < 3; k++) {
                    if(j == k && num[j] == cmp[k]) strike_cnt++;    // ��Ʈ����ũ
                    else if(j != k && num[j] == cmp[k]) ball_cnt++; // ��
                }
            }
            if(strike != strike_cnt || ball != ball_cnt) suppose[i] = false; // ���� ���� ����Ʈ���� ����
        }
    }
}

int countAnswer() { // ���� ���� ���� ����
    int sum = 0;
    for(int i = 123; i <= 987; i++)
        sum += suppose[i];
    return sum;
}

int main() {
    int n, q, strike, ball;
    cin >> n;

    setInvalid(); // �Ұ����� ���� ����
    while(n--) {
       cin >> q >> strike >> ball;
        baseballGame(q, strike, ball);
    }

    cout << countAnswer();
    return 0;
}