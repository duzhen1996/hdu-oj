//Problem Description
//FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
//The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
//
//
//Input
//        The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
//
//
//Output
//        For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
//
//
//Sample Input
//5 3
//7 2
//4 3
//5 2
//20 3
//25 18
//24 15
//15 10
//-1 -1
//
//
//Sample Output
//13.333
//31.500
//


//我们将每个房间根据性价比使用快排排个序，然后让老鼠优先选性价比最高的房间


//我做的这个方案内存超了，但是思路是没有问题的。实际上我们可以就申请两个数组，分别是F和J，快排的时候我们将F和J都传进去，直接在F和J上做排序。美滋滋。



#include <iostream>
#include <iomanip>

using namespace std;


//快速排序
void quick_sort(short start, short end, float *inputArr, short *roomNo) {

//    cout << start << " " << end << endl;

//    for (int j = start; j <= end; ++j) {
//        cout << inputArr[j] << " ";
//    }

//    cout << endl;

    //递归结束
    if (start == end) {
        return;
    }

    //将尾部作为桩，将index作为比桩大的和比桩小的分界线，index所指向的是比桩小的
    short index = start - 1;
    //用一个指针遍历所有的元素，比桩大的就要被0-index这个范围包含
    //从大到小排序
    //最后index桩就在index的位置上
    for (short i = start; i <= end; ++i) {
        float temp;

        if (inputArr[i] >= inputArr[end]) {
            index++;
            //将i位置和index位置的元素进行交换
            float temp = inputArr[i];
            inputArr[i] = inputArr[index];
            inputArr[index] = temp;

            //roomNo数组也要做响应的替换
            temp = roomNo[i];
            roomNo[i] = roomNo[index];
            roomNo[index] = temp;
        }
    }

    //左边和右边递归快排
    //如果桩在最左或者最右就不用管了

    if (index != start) {
        quick_sort(start, index - 1, inputArr, roomNo);
    }

    if (index != end) {
        quick_sort(index + 1, end, inputArr, roomNo);
    }
}

int main() {
    while (true) {
        //控制输入，前两个输入一个是老鼠食物的数量，还有一个是房间的数量
        short catFood = 0;
        short roomCount = 0;

        cin >> catFood >> roomCount;

        if (catFood == -1 && roomCount == -1) {
            break;
        }


        //两个数组，一个用来放房间里面的JavaBean数量，一个是得到所有JavaBean需要的Food的数量
        short *J = new short[roomCount];
        short *F = new short[roomCount];

        //使用一个数组算出所有房间的性价比
        float *fittest = new float[roomCount];

        //和性价比一起的房间号
        short *roomNo = new short[roomCount];

        for (int j = 0; j < roomCount; ++j) {
            roomNo[j] = j;
        }

        //获取所有的房间输入
        for (short i = 0; i < roomCount; ++i) {
            cin >> J[i] >> F[i];

            fittest[i] = (float) J[i] / F[i];
        }

        quick_sort(0, roomCount - 1, fittest, roomNo);

//        for (int l = 0; l < roomCount; ++l) {
//            cout << fittest[l] << " ";
//        }
//
//        cout << endl;

        float resultJava = 0;

        //然后我们进行交易
        //从性价比高的到低的进行交易
        //这个负责整个房间整个房间地买
        //剩下的房间记录一下
        int roomNoEnd = 0;
        for (short k = 0; k < roomCount && catFood >= F[roomNo[k]]; ++k) {
            //一口气买整个房间的食物
            resultJava = resultJava + J[roomNo[k]];

            catFood = catFood - F[roomNo[k]];

            roomNoEnd = k;
        }

        //看看是不是还剩下
        if (catFood > 0 && roomNoEnd < roomCount - 1) {
            //这里就是还剩下一个房间
            resultJava = resultJava + catFood * ((float) J[roomNo[roomNoEnd + 1]] / F[roomNo[roomNoEnd + 1]]);
        }

        //打印
        cout << setprecision(3) << setiosflags(ios::fixed) << resultJava << endl;


        delete[]J;
        delete[]F;
        delete[]fittest;
        delete[]roomNo;
    }
}

