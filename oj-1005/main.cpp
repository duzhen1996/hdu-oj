//Problem Description
//A number sequence is defined as follows:
//
//        f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.
//
//Given A, B, and n, you are to calculate the value of f(n).
//
//
//Input
//        The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
//
//
//Output
//        For each test case, print the value of f(n) on a single line.
//
//
//Sample Input
//1 1 3
//1 2 10
//0 0 0
//
//
//Sample Output
//2
//5
//



#include <iostream>
#include <string>

using namespace std;


int main() {
//暴力计算的方法会带来比较长的时间。我们要勇于算出循环。
//    while (true) {
//        //获取三个玩意
//        int a, b;
//        long n, temp1, temp2;
//        temp1 = 1;
//        temp2 = 1;
//        cin >> a >> b >> n;
//
//        //如果三个都是0，那就退出
//        if (a == 0 && b == 0 && n == 0) {
//            break;
//        }
//
//        //循环次数
//        int result = 0;
//        for (int i = 0; i < n - 2; ++i) {
//            result = (a * temp2 + b * temp1) % 7;
//            temp1 = temp2;
//            temp2 = result;
//        }
//
//        if (n == 1 || n == 2) {
//            cout << 1 << endl;
//        } else {
//            cout << result << endl;
//        }
//    }

//计算的方法比较简单因为7个数字有49种组合，所以在第50对开始的时候一定就会出现循环，所以我们就计算到f(50)。在这个之前一定是出现循环的。
//在f(50)之后一定全是循环。
//循环我们要知道的是循环的开始位置和循环的周期大小。我们记录f(50)、f(51)两位，看看之前的值有没有和f(50)以及f(51)分别对应相等的。
//这样子周期的大小就知道了，而之前两个和f(50)、f(51)分别对应的就是周期的开始。

    while (true) {
        int a, b;
        long n;

        cin >> a >> b >> n;

        //如果三个都是0，那就退出
        if (a == 0 && b == 0 && n == 0) {
            break;
        }

        int *result = new int[51];
        result[1] = 1;
        result[2] = 1;
        for (int i = 3; i <= 51; ++i) {
            result[i] = (a * result[i - 1] + b * result[i - 2]) % 7;
        }

//    for (int j = 1; j <= 51; ++j) {
//        cout << result[j] << " ";
//    }

        //如果n比较小就直接找出结果就好了
        if (n <= 51) {

            cout << result[n] << endl;

        } else {
            //这段代码是用来找周期的
            int temp1 = 49;
            int temp2 = 50;

            while (!(result[temp1] == result[50] && result[temp2] == result[51])) {
                temp1--;
                temp2--;
            }

            int T = 50 - temp1;
//        cout << endl << "结束：" << 50 - temp1 << endl;

            //我们假设temp1就是周期开始的位置之一
            int realIndex = temp1 + (n - temp1) % T;

            cout << result[realIndex] << endl;
        }

    }
}

