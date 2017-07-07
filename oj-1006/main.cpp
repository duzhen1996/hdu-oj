//Problem Description
//The three hands of the clock are rotating every second and meeting each other many times everyday. Finally, they get bored of this and each of them would like to stay away from the other two. A hand is happy if it is at least D degrees from any of the rest. You are to calculate how much time in a day that all the hands are happy.
//
//
//Input
//        The input contains many test cases. Each of them has a single line with a real number D between 0 and 120, inclusively. The input is terminated with a D of -1.
//
//
//Output
//        For each D, print in a single line the percentage of time in a day that all of the hands are happy, accurate up to 3 decimal places.
//
//
//Sample Input
//0
//120
//90
//-1
//
//
//Sample Output
//100.000
//0.000
//6.251
//

//因为是无极的，所以应该函数求交点的方式解决问题，应该是三个分段函数求之间求值距离的问题。这个实现已经无限细分了720000份，时间已经很久了，但是最后一位还是有误差。
//http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=27348&messageid=1&deep=0。这道题的解答这里有
//这道题的思路就是老老实实使用double

#include <iostream>
#include <string>
#include <math.h>

using namespace std;


int main() {


    //我们需要使用time在重头走到尾，使用暴力的方法，time代表一秒
    //一天的秒数

    //这个钟的指针应该是无极的，秒针6度一秒，分针是1/10度，时针是1/120度
    //我们将1/720度作为角度的最小度量单位
    //相对速度，时针是6，分针72，秒针360

    //D是以度为单位，所以要看秒针每次走一度的时候各自的变化。所以我们每1/6秒看一次，这个是时间的最小度量单位
    //每1/6秒,时针走1，分针走12，秒针走60

    int daySecond = 12 * 3600 * 6 * 1000;
//    cout << daySecond << endl;
    //happy的时间
    float happyTime = 0;

    long D = 0;

    cin >> D;

    D = D * 720 * 1000;

    //秒的度数
    long second = 0;
    long min = 0;
    long hour = 0;

    //两两之间的角度距离
    long second2min = 0;
    long second2hour = 0;
    long min2hour = 0;

    for (int i = 1; i <= daySecond; ++i) {

        //秒针的角度
        second = (second + 60) % (360 * 720 * 1000);

        //分针的角度
        min = (min + 12) % (360 * 720 * 1000);

        //时针的角度
        hour = (hour + 1) % (360 * 720 * 1000);

        //看分秒之间角度差
        second2min = abs(second - min);
        if (second2min > 180 * 720 * 1000) {
            second2min = 360 * 720 * 1000 - second2min;
        }

        //看秒时只差
        second2hour = abs(second - hour);
        if (second2hour > 180 * 720 * 1000) {
            second2hour = 360 * 720 * 1000 - second2hour;
        }

        //分时只差
        min2hour = abs(min - hour);
        if (min2hour > 180 * 720 * 1000) {
            min2hour = 360 * 720 * 1000 - min2hour;
        }

        //看happy
        if (second2hour >= D && second2min >= D && min2hour >= D) {
            happyTime++;
        }
    }

    //看比例
//    cout << happyTime << endl;
    cout << happyTime * 100 / daySecond;


}

