//1002
//Problem Description
//I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
//
//
//Input
//        The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
//
//
//Output
//        For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.
//
//
//Sample Input
//2
//1 2
//112233445566778899 998877665544332211
//
//
//Sample Output
//Case 1:
//1 + 2 = 3
//
//Case 2:
//112233445566778899 + 998877665544332211 = 1111111111111111110
//                                          1111111111111111110
#include <iostream>
#include <string>

using namespace std;


//在字符串头部加入东西,第二个形参为数组有效位的大小
void addFirst(char *inputCharArr, int size, char insertChar) {
    for (int i = size - 1; i >= 0; --i) {
        inputCharArr[i + 1] = inputCharArr[i];
    }

    inputCharArr[0] = insertChar;
}

//这里我们使用的是超大数的相加
//输入为string，输出为string
char *add(string num1, string num2) {
    //看第一位是正数还是负数
    if (num1[0] != '-' && num2[0] != '-') {
        //这里判断的是如果两个都不是负数的情况
        //进位
        int up = 0;
        //结果字符串
        char *result = new char[1001];
        //让比较大的位数的数作为result的暂时位数
        //这个会比实际有内容的索引多一位
        int valid_size = num1.size();
        if (num2.size() > valid_size) {
            valid_size = num2.size();
        }

//    cout << "valid_size: " << valid_size << endl;

        for (int i = 0; i < num1.size() || i < num2.size(); ++i) {
            //从最后一位开始
            //如果进入第一个说明现在只有num2有效位了
            if (i >= num1.size()) {
                int tempResult = up + num2[num2.size() - i - 1] - '0';
                //看看进位
                result[valid_size - i - 1] = (tempResult % 10) + '0';
                up = tempResult / 10;
            } else if (i >= num2.size()) {
                int tempResult = up + num1[num1.size() - i - 1] - '0';
                //看看进位
                result[valid_size - i - 1] = (tempResult % 10) + '0';
                up = tempResult / 10;
            } else {
                //两个大数的有效位都没有走完

//            cout << "up:" << up << endl;
//            cout << "num1[num1.size() - i - 1]:" << num1[num1.size() - i - 1] << endl;
//            cout << "num2[num2.size() - i - 1]:" << num2[num2.size() - i - 1] << endl;

                int tempResult = up + num1[num1.size() - i - 1] - '0' + num2[num2.size() - i - 1] - '0';

//            cout << "tempResult:" << tempResult << endl;
                //看看进位
                result[valid_size - i - 1] = (tempResult % 10) + '0';
                up = tempResult / 10;
            }
        }

        //这个时候看看up里面有没有东西
        if (up != 0) {
            //这个时候存结果的有效位就需要多一位
            addFirst(result, valid_size, up + '0');
            valid_size++;
        }
//
//    cout << "result: ";
//
//    for (int k = 0; k <= valid_size; ++k) {
//        cout << result[k];
//    }
//
//    cout << endl;

        //将结果进行裁剪
        char *realResult = new char[valid_size + 1];

        for (int j = 0; j <= valid_size; ++j) {
            realResult[j] = result[j];
        }


        //这个地方在之前的编程中出现了重大的错误，原本valid的位置写的是valid+1，而重构之后的数组大小又是valid+2，实际上validsize实际上已经就是有效位个数了
        //并不是有效索引。注意区分，有效位数和有效索引。
        realResult[valid_size] = '\0';

        return realResult;
    }

}


int main() {
    //获取用例个数
    int caseCount = 0;

    cin >> caseCount;
    int now = 1;
    while (now <= caseCount) {
        //    cout << "caseCount = " << caseCount << endl;
        //第一个加数数组
        string num1 = "";

        string num2 = "";

        cin >> num1 >> num2;

        //不计算，在打印的时候计算
//    for (int i = 0; i < caseCount; ++i) {
//        num1Arr[i] = num1Arr[i] + num2Arr[i];
//    }

        //打印

        cout << "Case " << now << ":" << endl;
        cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;

        if (now != caseCount){
            cout << endl;
        }
        now++;
    }


//    string num1 = "10000";
//    string num2 = "9000";
//
//    string result = add(num1, num2);
//
//    cout << "result:" << result << endl;


}

