#include <iostream>

using namespace std;

bool isJava(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. �ҹ���, �빮�� �ܿ� �ٸ� ���� �Ұ�
    if(!islower(arg[0])) return false;     // (1��)
    if(arg.find('_') != string::npos) return false; // (2��)
    for(int i = 1; i < arg.length(); i++) {
        if (!isupper(arg[i]) && !islower(arg[i])) // (2��)
            return false;
    }
    return true;
}

bool isCpp(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. ������ ���� _ �Ұ�
    // 3. �������� _ �Ұ�
    if(!islower(arg[0])) return false;      // (1��)
    if(arg[arg.length()-1] == '_') return false;        // (2��)
    if(arg.find("__") != string::npos) return false; // (3��)
    for(int i = 1; i < arg.length(); i++) {
        if (!islower(arg[i]) && arg[i] != '_')
            return false;
    }
    return true;
}

string java(string &arg) { // �ڹ� ������ �����
    string temp = "";
    for(int i = 0; i < arg.length(); i++) {
        if(arg[i] == '_') {
            temp += toupper(arg[i+1]);
            i++;
            continue;
        }
        temp += arg[i];
    }
    return temp;
}

string cpp(string &arg) { // c++ ������ �����
    string temp = "";
    for(char ch : arg) {
        if(ch >= 'A' && ch <= 'Z') {
            temp += '_';
            temp += tolower(ch);
            continue;
        }
        temp += ch;
    }
    return temp;
}

string makeIdentifier(string &arg) { // ������ �����
    bool is_java = isJava(arg);
    bool is_cpp = isCpp(arg);

    if(!is_java && !is_cpp) return "Error!";
    if(is_java) return cpp(arg); // �ڹ� -> ���ܻ�
    else return java(arg);      // ���ܻ� -> �ڹ�
}

int main() {
    string argument;
    cin >> argument;

    cout << makeIdentifier(argument);
    return 0;
}