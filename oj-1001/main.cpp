//1001
#include <iostream>

using namespace std;

int main() {
    //处理输入
    int *inputArr = new int[10000];
    //包括索引
    int index = -1;
    int input;

    while (cin >> input) {
        index++;
        inputArr[index] = input;
    }

    int end = 0;

    //处理所有的数据
    for (int j = 0; j <= index; ++j) {
        end = inputArr[j];
        inputArr[j] = 0;
        for (int i = 1; i <= end; ++i) {
            inputArr[j] = i + inputArr[j];
        }
    }

    //输出
    for (int i = 0; i <= index; ++i) {
        cout << inputArr[i] << endl << endl;
    }

    delete[]inputArr;
}