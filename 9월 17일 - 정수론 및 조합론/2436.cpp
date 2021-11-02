#include <iostream>
#include <cmath>

using namespace std;

int gcdRecursion(int a, int b) { // �ִ� ����� ���ϱ�
    if(b == 0) return a;
    return gcdRecursion(b, a%b);
}

string naturalNumberPair(int gcd, int lcm) { // �� �ڿ��� ã��
    int multi = lcm / gcd, a = gcd, b = gcd;

    for(int i = sqrt(multi); i >= 1; i--) {
        // 1. i�� multi�� ���
        // 2. i�� multi/is�� ���μ�
        if(multi % i == 0 && gcdRecursion(i, multi/i) == 1) {
            a *= i; b *= multi/i;
            break;
        }
    }
    return to_string(a) + ' ' + to_string(b);
}

int main() {
    int gcd, lcm, multi, a, b;
    cin >> gcd >> lcm;
    cout << naturalNumberPair(gcd, lcm); // �� �ڿ��� ����ϱ�
    return 0;
}