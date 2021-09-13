#include <iostream>
#include <vector>
#include <stack>

using namespace std;
vector<int> num;
stack<double> temp;

void compute(string exp) {
    for(int i = 0; i < exp.length(); i++) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') { // �����ڰ� ���� ���
            // �ǿ����� pop
            double op2 = temp.top(); temp.pop();
            double op1 = temp.top(); temp.pop();

            switch(exp[i]) { // ���� ��� �ٽ� push
                case '+':
                    temp.push(op1 + op2);
                    break;
                case '-':
                    temp.push(op1 - op2);
                    break;
                case '*':
                    temp.push(op1 * op2);
                    break;
                case '/':
                    temp.push((double)op1/ op2);
                    break;
            }
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
    compute(exp); // ���� ǥ��� ���
    return 0;
}