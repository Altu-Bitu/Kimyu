#include <iostream>
#include <vector>

using namespace std;
const int N = 30000;

bool sushi[N+1];
vector<int> belt;

int countSushi(int n, int k, int c) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        int kind = 0;
        // i���� k�� �˻�
        for(int j = i; j < i + k; j++) {
            if(sushi[belt[j % n]]) continue;
            // ���� ī��Ʈ
            sushi[belt[j % n]] = true; kind++;
        }
        if(!sushi[c]) kind++; // ������ ���� ���ð� ���Ե��� ���� ��� ���� ���
        s = max(s, kind);

        // ���� �ʱ�ȭ
        for(int j = i; j < i + k; j++)
            sushi[belt[j % n]] = false;
    }
    return s;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    belt.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> belt[i];

    cout << countSushi(n, k, c);
    return 0;
}