#include <iostream>
#include <vector>

using namespace std;

// p��ŭ �پ�� ���, �ǳ� �� �ִ°�
bool pass(vector<int> stones, int k, int p) {
    int blank = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i]-p <= 0) blank++;
        else blank = 0;
        if(blank == k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    // left : �ǳ� �� �ִ� ��� �ּڰ� / right : �ǳ� �� �ִ� ��� �ִ�
    int left = 0, right = 0;
    for(int i = 0; i < stones.size(); i++)
        right = max(right, stones[i]);

    while(left <= right) {
        int mid = (left + right) / 2;
        bool success = pass(stones, k, mid);

        if(!success) right = mid - 1; // ¡�˴ٸ� �ǳ� �� ���� -> ��� ���̱�
        else { // ¡�˴ٸ� �ǳ� �� ���� -> ��� �� �ø���
            answer = mid + 1; // (mid��ŭ �پ��� �� ��� �� �ǳ� �� ����)
            left = mid + 1;
        }
    }
    return answer;
}

int main() {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 3;

    cout << solution(stones, k);
    return 0;
}