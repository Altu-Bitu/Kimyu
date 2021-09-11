#include <iostream>
#include <string>
#include <stack>

using namespace std;

void addLargeNum(const string &a, const string &b) { // ���ϱ�
    stack<int> result;
    int tmp, remain; // (tmp: �����, remain �ø���)
    int p1 = a.length()-1, p2 = b.length()-1; // (���� �ڸ����� ����ϱ� ����)

    bool flag = false; // �ø� ���� ǥ��
    while(p1 >= 0 && p2 >= 0) {
        tmp = a[p1]-'0' + b[p2]-'0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        p1--; p2--;
    }

    while(p1>=0) { // a�� ���� ���ڰ� �� �����ִ� ���
        tmp = a[p1] - '0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        p1--;
    }

    while(p2>=0) { // b�� ���� ���ڰ� �� �����ִ� ���
        tmp = b[p2] - '0';
        if(flag) {
            tmp += remain;
            flag = false;
            remain = 0;
        }
        if(tmp/10) {
            flag = true;
            remain = (int) tmp/10;
        }
        result.push(tmp%10);
        p2--;
    }
    if(flag) result.push(remain);

    while(!result.empty()) { // ���� ��� ���
        cout << result.top();
        result.pop();
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    addLargeNum(a,b);
    return 0;
}