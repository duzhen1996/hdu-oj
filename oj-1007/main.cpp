//Problem Description
//Have you ever played quoit in a playground? Quoit is a game in which flat rings are pitched at some toys, with all the toys encircled awarded.
//In the field of Cyberground, the position of each toy is fixed, and the ring is carefully designed so it can only encircle one toy at a time. On the other hand, to make the game look more attractive, the ring is designed to have the largest radius. Given a configuration of the field, you are supposed to find the radius of such a ring.
//
//Assume that all the toys are points on a plane. A point is encircled by the ring if the distance between the point and the center of the ring is strictly less than the radius of the ring. If two toys are placed at the same point, the radius of the ring is considered to be 0.
//
//
//Input
//        The input consists of several test cases. For each case, the first line contains an integer N (2 <= N <= 100,000), the total number of toys in the field. Then N lines follow, each contains a pair of (x, y) which are the coordinates of a toy. The input is terminated by N = 0.
//
//
//Output
//        For each test case, print in one line the radius of the ring required by the Cyberground manager, accurate up to 2 decimal places.
//
//
//Sample Input
//2
//0 0
//1 1
//2
//1 1
//1 1
//3
//-1.5 0
//0 0
//0 1.5
//0
//
//
//Sample Output
//0.71
//0.00
//0.75

//这道题的工作说得很复杂，实际上就是找一系列点中距离最小的两点的距离的一半
//在网上


#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main() {
    while (true) {
        int pointCount = 0;

        cin >> pointCount;

        if (pointCount == 0) {
            break;
        }

        //用一个数组来存坐标
        float *x = new float[pointCount];
        float *y = new float[pointCount];

        for (int i = 0; i < pointCount; ++i) {
            cin >> x[i] >> y[i];
        }

//        for (int m = 0; m < pointCount; ++m) {
//            cout << x[m] << "," << y[m] << endl;
//        }

        //我们点两两之间算一个距离
        float l = 9999;
        float tmp = 0;
        //我们两两之间做一个组合
        for (int j = 0; j < pointCount; ++j) {
            for (int k = j + 1; k < pointCount; k++) {
                tmp = pow(x[j] - x[k], 2) + pow(y[j] - y[k], 2);
//                cout << "tmp: " << tmp << endl;
                if (tmp < l) {
                    l = tmp;
                }

            }
        }

//        cout << l << endl;

        //这里是输出格式的处理
        cout << setprecision(2) << setiosflags(ios::fixed) << (float)(pow(l, 0.5) / 2) << endl;

        delete[]x;
        delete[]y;
    }
}

