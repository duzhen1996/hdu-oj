//Problem Description
//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
//
//
//Input
//        The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
//
//
//Output
//        For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
//
//
//Sample Input
//2
//5 6 -1 5 4 -7
//7 0 6 -1 1 -6 7 -5
//
//
//Sample Output
//Case 1:
//14 1 4
//
//Case 2:
//7 1 6
//


#include <iostream>
#include <string>

using namespace std;


int main() {
    //获取用例个数
    int caseCount = 0;

    cin >> caseCount;
    int now = 1;
    while (now <= caseCount) {

        //使用动态规划的思路，我们使用一个数组来存储以索引i为结尾的最大子串的和，对于这个数组来说，如果之前一个元素是大于0的，那么
        //我们就是用之前的元素加上条件序列对应位的元素，如果之前一个元素是小于0，那就从条件序列的当前位开始计算。
        //动态规划就是把问题分成一小个一小个部分，善用之前计算的结果为下一次服务。

        //获取输入数据，第一位为输入序列的长度
        int length = 0;
        cin >> length;
//        cout << "输入" << length << endl;
        //获取输出序列
        int *inputArr = new int[length];
        for (int i = 0; i < length; ++i) {
            cin >> inputArr[i];
        }
//
//        for (int m = 0; m < length; ++m) {
//            cout << inputArr[m] << endl;
//        }

        //创建一个数组，使用这个数组存以i索引为结尾的最大子串的和。
        int *max = new int[length];

        max[0] = inputArr[0];

        for (int j = 1; j < length; ++j) {
            //这里是动态规划的核心部分
            if (max[j - 1] > 0) {
                max[j] = max[j - 1] + inputArr[j];
            } else {
                max[j] = inputArr[j];
            }
        }

//        for (int m = 0; m < length; ++m) {
//            cout << max[m] << endl;
//        }

        //找出最大子串
        int maxIndex = 0;
        for (int k = 1; k < length; ++k) {
            if (max[maxIndex] < max[k]) {
                maxIndex = k;
            }
        }

//        cout << maxIndex << endl;

        //k存着最大子串的尾部，向前找到最大子串的头部
        int maxTop = maxIndex;

        //对负数列单独处理
        if (max[maxIndex] < 0) {
            maxTop = maxIndex;
        } else {
            while (maxTop >= 0) {

                if (max[maxTop] < 0) {

                    break;
                }


                maxTop--;
            }

            maxTop++;

        }

        //maxTop是子列头部的索引


        cout << "Case " << now << ":" << endl;

        cout << max[maxIndex] << " " << maxTop + 1 << " " << maxIndex + 1 << endl;

//        cout << endl;


        if (now != caseCount) {
            cout << endl;
        }
        now++;

        delete[]max;
        delete[]inputArr;
    }


}

