//Problem Description
//Contest time again! How excited it is to see balloons floating around. But to tell you a secret, the judges' favorite time is guessing the most popular problem. When the contest is over, they will count the balloons of each color and find the result.
//
//This year, they decide to leave this lovely job to you.
//
//
//Input
//        Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) -- the total number of balloons distributed. The next N lines contain one color each. The color of a balloon is a string of up to 15 lower-case letters.
//
//A test case with N = 0 terminates the input and this test case is not to be processed.
//
//
//Output
//        For each case, print the color of balloon for the most popular problem on a single line. It is guaranteed that there is a unique solution for each test case.
//
//
//Sample Input
//5
//green
//        red
//blue
//        red
//red
//3
//pink
//        orange
//pink
//0
//
//
//Sample Output
//red
//        pink
//



#include <iostream>
#include <string>

using namespace std;


int main() {

    while (true) {
        //获取用例个数
        int caseCount = 0;
        cin >> caseCount;

        //创建动态数组
        if (caseCount == 0) {
            break;
        }

        string *colorArr = new string[caseCount];
        //一个用来计数的数组
        int *colorCount = new int[caseCount];
        //数组有效位
        int valid = -1;

        for (int j = 0; j < caseCount; ++j) {
            colorCount[j] = 0;
            colorArr[j] = "";
        }

        //每次输入都要和历史输入的进行比较

        string temp = "";
        //判断是不是已经比较过了
        bool judge = false;
        for (int i = 0; i < caseCount; ++i) {
            cin >> temp;
            judge = false;
            for (int j = 0; j <= valid; ++j) {
                //这里要注意一下，c_str返回一个指向以空字符终止的数组，是一个string向char数组的转换
                //strcmp比较两个字符串，第一个比较大就是正，小就是负，相等就是0；
                if (strcmp(temp.c_str(), colorArr[j].c_str()) == 0) {
                    //如果找到相等的
                    judge = true;
                    colorCount[j]++;
                    break;
                }
            }

            if (!judge) {
                //没有找到相同的那就追加在数组后面
                valid++;
                colorArr[valid] = temp;
                colorCount[valid]++;
            }

            //如果已经找到就不用管
        }

        //这里已经完成计数
        //找出最大值
        int max = 0;
        int maxIndex = -1;
        for (int k = 0; k <= valid; ++k) {
            if (max < colorCount[k]) {
                max = colorCount[k];
                maxIndex = k;
            }
        }

        //打印最大值对应的颜色
        cout << colorArr[maxIndex] << endl;

        delete[]colorArr;
        delete[]colorCount;
    }
}

