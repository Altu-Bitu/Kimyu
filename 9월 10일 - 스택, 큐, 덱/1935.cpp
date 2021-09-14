#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> num;

double compute(double op1, double op2, char op) { // ���� ��� ��ȯ
    switch(op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return (double)op1 / op2;
    }
    return -1;
}

void postfix(string exp) {
    stack<double> temp;

    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { // �����ڰ� ���� ���
            // �ǿ����� pop
            double op2 = temp.top(); temp.pop();
            double op1 = temp.top(); temp.pop();
            temp.push(compute(op1, op2, exp[i])); // ���� ��� push
        }
        else temp.push(num[exp[i]-'A']); // �����ڰ� �ƴ� ���
    }
    printf("%.2f", temp.top()); // �Ҽ� ��°�ڸ����� ���
}

int main() {
    int n;
    string exp;

    cin >> n;
    cin >> exp;
    num.assign(n, 0);
    for(int i = 0; i < n; i++) // �ǿ����� �Է¹ޱ�
        cin >> num[i];
    postfix(exp); // ���� ǥ��� ���
    return 0;
}