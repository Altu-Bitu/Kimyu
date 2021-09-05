#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> testNum, passNum; // �׽�Ʈ ���̽� ��, �׽�Ʈ ���̽��� �հ��� ��
struct grade { // ���� ����ü
    int document;
    int interview;
};
vector<grade> test;

bool cmp(const grade &t1, const grade &t2) { // ���� ���� ��������
    return t1.document < t2.document;
}

void findPass(int index) { // �հ��� ã��
    int pass = 1; // ���� ���� 1�� ������ �հ�
    int cmp = test[0].interview;
    for(int i = 1 ; i < testNum[index]; i++) {
        if(cmp > test[i].interview) {
            pass += 1;
            cmp = test[i].interview;
        }
    }
    passNum[index] = pass;
}

int main() {
    int t;
    cin >> t;

    testNum.assign(t , 0);
    passNum.assign(t , 0);
    for(int i = 0; i < t; i++) {
        cin >> testNum[i];
        test.assign(testNum[i], {0,0});
        for(int j = 0; j < testNum[i]; j++)
            cin >> test[j].document >> test[j].interview;

        sort(test.begin(), test.end(), cmp); // ���� ���� ��������
        findPass(i); // �հ��� ã�� 
    }
    for(int i = 0; i < t; i++) // �׽�Ʈ ���̽��� �հ��� �� ���
        cout << passNum[i] << '\n';
    return 0;
}