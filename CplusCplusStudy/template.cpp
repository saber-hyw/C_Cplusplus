/**
 * By Yongwu Han
 * 2019-08-02
 * 
 * 展示template<> 模板的所有用法
 * (1) 最简单的template用法；
 */

#include <iostream>

using namespace std;

template<class T>
T GetMax(T a, T b) {
    T result;
    result = a > b ? a : b;
    return result;
}

int main() {
    int res = GetMax(34,3);
    cout << "GetMax() = " << res <<endl;

    return 0;
}