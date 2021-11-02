#include <iostream>
#include <queue>

using namespace std;
queue<int> idx;

void findK(string num) { // K ��ġ ã��
    for(int i = 0; i < num.length(); i++)
        if(num[i] == 'K') idx.push(i);
}

string maxNumber(string num) { // �ִ� : �������� k�̸� �����ֱ�
    string answer = "";

    if(idx.empty()) { // K�� �ϳ��� ���� ��� -> ��� 1
        for(int i = 0; i < num.length(); i++) answer += '1';
    }
    else { // K�� �ϳ��� �ִ� ���
        int m = 0, k;
        while(!idx.empty()) {
            answer += '5';
            k = idx.front(); idx.pop();
            for(int i = m; i < k; i++) answer += '0';
            m = k + 1;
        }
        for(int i = k + 1; i < num.length(); i++) answer += '1';
    }
    return answer;
}

string minNumber(string num) { // �ּڰ� : k���� �����ֱ�
    string answer = "";

    if(idx.empty()) { // K�� �ϳ��� ���� ��� -> ù�ڸ��� 1
        answer += '1';
        for(int i = 0; i < num.length()-1; i++) answer += '0';
    }
    else { // K�� �ϳ��� �ִ� ���
        int m = 0, k;
        while(!idx.empty()) {
            k = idx.front(); idx.pop();
            if(k-m) answer += '1';
            for(int i = m + 1; i < k; i++) answer += '0';
            answer += '5';
            m = k + 1;
        }
        if(m < num.length()) {
            answer += '1';
            for(int i = m + 1; i < num.length(); i++) answer += '0';
        }
    }
    return answer;
}

int main() {
    string num;
    cin >> num;

    findK(num);
    cout << maxNumber(num) << '\n';
    findK(num);
    cout << minNumber(num);
    return 0;
}