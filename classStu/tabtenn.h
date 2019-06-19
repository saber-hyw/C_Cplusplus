#ifndef TABTENN_H_
#define TABTENN_H_

#include "defs.h"

class TableTennisPlayer {
public:
    // 以下这两种构造函数的重载写法，会引起歧义，编译器编译不过；
    // 究其原因是：C++不支持参数缺省； 编译器没办法知道调用哪个构造函数；
    // 解决的方法是：去掉默认值，不要起成为全缺省或是半缺省参数；
    // TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);
    TableTennisPlayer(const string &fn, const string &ln, bool ht);
    // TableTennisPlayer(const string &fn = "none", const string &ln = "none");
    // 因此改为：去掉参数的默认值
    TableTennisPlayer(const string &fn, const string &ln);
    ~TableTennisPlayer();
    void playerName() const;
    bool tableAvailable() const;
    void resetTable(bool v);

private:
    void privateFunc();

private:
    string firstName;
    string lastName;
    bool hasTable;
};

// 继承基类
class RatedPlayer : public TableTennisPlayer {
public:
    // 派生类的构造函数，新增参数r,去掉参数ht
    RatedPlayer(const string &fn, const string &ln, unsigned int r);
    ~RatedPlayer();

    void showRating();
private:
    unsigned int rating;
    int leavel;
};

#endif