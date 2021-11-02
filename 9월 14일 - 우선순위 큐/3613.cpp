#include <iostream>

using namespace std;

<<<<<<< HEAD
bool isJava(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. �ҹ���, �빮�� �ܿ� �ٸ� ���� �Ұ�
    if(!islower(arg[0])) return false;     // (1��)
    if(arg.find('_') != string::npos) return false; // (2��)
    for(int i = 1; i < arg.length(); i++) {
        if (!isupper(arg[i]) && !islower(arg[i])) // (2��)
=======
bool is_java(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. �ҹ���, �빮�� �ܿ� �ٸ� ���� �Ұ�
    if(arg[0] < 'a' || arg[0] > 'z') return false;     // (1��)
    if(arg.find('_') != string::npos) return false; // (2��)
    for(int i = 1; i < arg.length(); i++) {
        if ((arg[i] < 'A' || arg[i] > 'Z') && (arg[i] < 'a' || arg[i] > 'z')) // (2��)
>>>>>>> main
            return false;
    }
    return true;
}

<<<<<<< HEAD
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
=======
bool is_cpp(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. ������ ���� _ �Ұ�
    // 3. �������� _ �Ұ�
    if(arg[0] < 'a' || arg[0] > 'z') return false;      // (1��)
    if(arg[arg.length()-1] == '_') return false;        // (2��)
    if(arg.find("__") != string::npos) return false; // (3��)
    for(int i = 1; i < arg.length(); i++) {
        if ((arg[i] < 'a' || arg[i] > 'z') && arg[i] != '_') return false;
>>>>>>> main
    }
    return true;
}

string java(string &arg) { // �ڹ� ������ �����
    string temp = "";
    for(int i = 0; i < arg.length(); i++) {
        if(arg[i] == '_') {
<<<<<<< HEAD
            temp += toupper(arg[i+1]);
=======
            temp += arg[i+1] - 'a' + 'A';
>>>>>>> main
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
<<<<<<< HEAD
            temp += tolower(ch);
=======
            temp += ch - 'A' + 'a';
>>>>>>> main
            continue;
        }
        temp += ch;
    }
    return temp;
}

<<<<<<< HEAD
string makeIdentifier(string &arg) { // ������ �����
    bool is_java = isJava(arg);
    bool is_cpp = isCpp(arg);

    if(!is_java && !is_cpp) return "Error!";
    if(is_java) return cpp(arg); // �ڹ� -> ���ܻ�
=======
string make_identifier(string &arg) { // ������ �����
    bool isJava = is_java(arg);
    bool isCpp = is_cpp(arg);

    if(!isJava && !isCpp) return "Error!";
    if(isJava) return cpp(arg); // �ڹ� -> ���ܻ�
>>>>>>> main
    else return java(arg);      // ���ܻ� -> �ڹ�
}

int main() {
    string argument;
    cin >> argument;

<<<<<<< HEAD
    cout << makeIdentifier(argument);
=======
    cout << make_identifier(argument);
>>>>>>> main
    return 0;
}