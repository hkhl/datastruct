#include <iostream>
#include <vector>
using namespace std;

//注意: 初始化的区间是闭合区间 还是左闭右开区间
//需要对用的迭代就行判断
//如果是闭合区间  left <= right    l = mid + 1  r = mid - 1;
//如果是左闭右开区间 left < right   l = mid + 1  r = mid;


/*
 *溢出
 *前面解决了边界选择时可能出现的问题, 下面来解决另一个问题,其实这个问题严格的说不属于算法问题,不过我注意到很多地方都没有提到,我觉得还是提一下比较好.
 *在循环体内,计算中间位置的时候,使用的是这个表达式:
 *middle = (left + right) / 2;
 *
 *假如,left与right之和超过了所在类型的表示范围的话,那么middle就不会得到正确的值.
 *所以,更稳妥的做法应该是这样的:
 *middle = left + (right - left) / 2;
 */
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end)   //用小于等与,vector为空发生段错误
    {                     //如果是闭合区间, 用 < 将无法查核到最后一个元素
        //找找区间中点
        Ran mid = begin + (end - begin) / 2;

        if (x < *mid)
            end = mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);

    bool s = binary_search(v.begin(), v.end(), 1);
    cout << s << endl;
    s = binary_search(v.begin(), v.end(), 3);
    cout << s << endl;
    s = binary_search(v.begin(), v.end(), 5);
    cout << s << endl;

    s = binary_search(v.begin(), v.end(), 9);
    cout << s << endl;
    s = binary_search(v.begin(), v.end(),-1);
    cout << s << endl;
    return 0;
}




//[a,b]
int search2(int array[], int n, int v)
{
    int left, right, middle;

    left = 0, right = n - 1;

    while (left <= right)
    {
        middle = (left + right) / 2;
        if (array[middle] > v)
        {
            right = middle - 1;
        }
        else if (array[middle] < v)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}


//[a,b)
int search3(int array[], int n, int v)
{
    int left, right, middle;

    left = 0, right = n;

    while (left < right)
    {
        middle = (left + right) / 2;

        if (array[middle] > v)
        {
            right = middle;
        }
        else if (array[middle] < v)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}
