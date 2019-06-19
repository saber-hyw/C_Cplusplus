/////////////////////////////////////////////////////////////////
/// @file map_practice.cpp
/// @brief defines map practice
/// @version 1.0
/// @author Yongwu Han
/// @date 2019-03-29
/////////////////////////////////////////////////////////////////
/// Edit history                                               \n
/// -----------------------------------------------------------\n
/// DATE               NAME              DESCRIPTION           \n
/// 2019-03-29         Yongwu Han        Create.               \n
/////////////////////////////////////////////////////////////////

#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <map>

using namespace std;

int main () {
    // 关于size_t: typedef unsigned int size_t; 全局定义在 crtdefs.h 文件中;  
    // 为了使自己的程序有很好的移植性，c++程序员应该尽量使用size_t和size_type而不是int, unsigned

    /**单词计数
    * key: 单词
    * value: 单词的次数
    */
    map<string, size_t> word_count;  // word_count map的对象
    string word;
    while(cin >> word) {
        if ("quit" == word)
            break;
        ++word_count[word];    
    }
    for (const auto &w : word_count)
        cout <<"input key: " << w.first
        << "; value: " << w.second
        << ((w.second > 1) ? " times " : " time ") << endl;
    

}





