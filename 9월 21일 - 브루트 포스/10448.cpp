#include <iostream>
#include <vector>

using namespace std;
vector<int> triangular; // 1000 ���� �ﰢ�� �����ϴ� �迭

void getTriangular() { // 1000 ���� �ﰢ�� ���ϱ�
    int level = 1, t;
    while(true) {
        t = level*(level+1)/2;
        if(t > 1000) break;
        triangular.push_back(t);
        level++;
    }
}

int eureka(int num) { // �ش� �ڿ����� 3���� �ﰢ���� ������ ǥ���Ǵ°�
    int size = triangular.size();
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                if(num == triangular[i] + triangular[j] + triangular[k])
                    return 1;
            }
        }
    }
    return 0;
}

int main() {
    int k, num;
    getTriangular();

    cin >> k;
    while(k--) {
        cin >> num;
        cout << eureka(num) << '\n';
    }
    return 0;
}