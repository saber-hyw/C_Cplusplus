#include "tabtenn.h"

// const string &fn, const string &ln, bool ht; 是头文件中定义的构造函数的参数
// 使用初始化列表的方法
// firstName, lastName, hasTable 是类TableTennisPlayer的成员变量，
// 在初始化类对象的时候，同时赋值并初始化成员变量的值；
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht)
    :firstName(fn), lastName(ln), hasTable(ht) {
        cout<< "this is constructor of TableTennisPlayer" << endl;
}

// 函数重载：使用构造函数内初始化的方法
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln) {
    cout<< "this is constructor of TableTennisPlayer" << endl;
    cout<< "Init data in constructor" << endl;
    firstName = fn;
    lastName = ln;
    hasTable = false;
}

TableTennisPlayer::~TableTennisPlayer() {
}

void TableTennisPlayer::playerName() const {
    cout<< lastName << ", " << firstName << endl;
}

bool TableTennisPlayer::tableAvailable() const {
    return hasTable;
}

void TableTennisPlayer::resetTable(bool v) {
    hasTable = v;
}

void TableTennisPlayer::privateFunc() {
    cout<< "privateFunc" << endl;
}

// below is RatePlayer class
RatedPlayer::RatedPlayer(const string &fn, const string &ln, unsigned int r)
:TableTennisPlayer(fn,ln), 
rating(r),
leavel(10) {
    cout << "the constructor of RatePlayer" << endl;
    cout << "Init data of r = " << r << endl;
    cout << "Init data of leavel = " << leavel << endl;
}
// rating 是初始化对象时一并初始化的值；leavel 是成员变量在构造函数时，初始化；

RatedPlayer::~RatedPlayer() {
}

void RatedPlayer::showRating() {
    cout << "rating = " << rating << endl;
}