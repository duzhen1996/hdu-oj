//Problem Description
//The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.
//
//For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.
//
//
//Input
//        There are multiple test cases. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100. A test case with N = 0 denotes the end of input. This test case is not to be processed.
//
//
//Output
//        Print the total time on a single line for each test case.
//
//
//Sample Input
//1 2
//3 2 3 1
//0
//
//
//Sample Output
//17
//41



#include <iostream>

using namespace std;


int main() {
    while (true) {
        int count = 0;
        cin >> count;
        if (count == 0) {
            break;
        }

        int *floorNo = new int[count];

        for (int i = 0; i < count; ++i) {
            cin >> floorNo[i];
        }

        //用一个变量存储当前楼层
        int now = 0;
        int temp;
        int time = 0;

        for (int j = 0; j < count; ++j) {
            temp = floorNo[j] - now;

            //如果大，就向上走
            if (temp > 0) {
                time = time + 6 * temp + 5;
            }

            if (temp == 0) {
                time = time + 5;
            }

            //如果小，就向下走
            if (temp < 0) {
                temp = 0 - temp;
//                cout << "这里" << endl;
                time = time + 4 * temp + 5;
            }

            now = floorNo[j];
//            cout << time << endl;
        }

        //打印时间
        cout << time << endl;

        delete[]floorNo;
    }
}

