#include <iostream>
#include <stack>

using namespace std;

int pri(char ch) { // ������ �켱����
    switch(ch) {
        case '(': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

void make_postfix(string &exp) { // ���� ǥ��� �����
    stack<char> temp; // ������ �����ϴ� ����

    for(int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        switch(ch) {
            case '(':
                temp.push(ch); break; // ���� ��ȣ PUSH
            case '+': case '-': case '*': case '/': // ������ PUSH
                while(!temp.empty() && pri(temp.top()) >= pri(ch)) {
                    cout << temp.top();
                    temp.pop();
                }
                temp.push(ch);
                break;
            case ')': // �ݴ� ��ȣ ���� ��� : ���ÿ� �ִ� ������ ��� & POP
                while(temp.top() != '(') {
                    cout << temp.top();
                    temp.pop();
                }
                if(temp.top() == '(') temp.pop(); // ���� ��ȣ POP
                break;
            default: cout << ch; // �ǿ����� ���
        }
    }
    while(!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
}

int main() {
    string exp;
    cin >> exp;

    make_postfix(exp);
    return 0;
}