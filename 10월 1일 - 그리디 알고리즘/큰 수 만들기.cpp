#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length()-k, idx = 0; // ���ڿ� ����, Ž�� ������ ��ġ

    for(int i = 0; i < len; i++) {
        char max_num = 0;
        int max_idx = idx;
        for(int j = idx; j <= k+i; j++) { // (Ž��) ���� ū �� ã��
            if(max_num < number[j]) {
                max_num = number[j];
                max_idx = j;
            }
        }
        idx = max_idx + 1;
        answer += number[max_idx]; // ���� ū �� ���信 �߰�
    }
    return answer;
}

int main() {
    string number = "1231234";
    int k = 3;

    cout << solution(number, k);
    return 0;
}