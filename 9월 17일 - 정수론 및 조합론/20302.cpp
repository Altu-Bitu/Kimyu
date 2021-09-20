#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
const int SIZE = 100000;
vector<int> prime;
map<int, int> result; // �ذ� ���� �����ϴ� ��

void isPrime() { // �Ҽ� �����ϱ�
    prime.assign(SIZE+1, 0);
    for(int i = 2; i <= SIZE; i++) prime[i] = i;

    for(int i = 2; i <= sqrt(SIZE); i++) {
        if(prime[i] != i) continue;
        for(int j = i*i; j <= SIZE; j+=i)
            if(prime[j] == j) prime[j] = i;
    }
}

// (���� ���θ� �Ǵ��ϹǷ� ��ȣ ����)
void multi_fact(int num) { // ���ϱ�
    num = abs(num);
    while(num > 1) {
        result[prime[num]]++;
        num /= prime[num];
    }
}

void divide_fact(int num) { // ������
    num = abs(num);
    while(num > 1) {
        result[prime[num]]--;
        num /= prime[num];
    }
}

string isMintChoco() { // ��Ʈ ���� ���� �Ǻ��ϱ�
    for(auto iter = result.begin(); iter != result.end(); iter++)
        if(iter->second < 0) return "toothpaste"; // �������� ���
    return "mint chocolate"; // ������ ���
}

int main() {
    int n, num;
    char op;
    cin >> n;

    isPrime(); // �Ҽ� �����ϱ�

    // ù��° ���� �Է��ϱ� (����)
    cin >> num;
    multi_fact(num);
    cin.ignore();
    n--;

    while(n--) { // ������ ���� �Է��ϱ�
        cin >> op >> num;
        switch(op) {
            case '*': // ���� (����)
                multi_fact(num);
                break;
            case '/': // ������ (�и�)
                divide_fact(num);
                break;
        }
        cin.ignore();
    }
    cout << isMintChoco(); // ��Ʈ ���� ���� ���
    return 0;
}