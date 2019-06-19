#include <iostream>
#include "tabtenn.h"
#include "brass.h"

int main() {
    // TableTennisPlayer player("Yongwu", "Han", false);
    // player.playerName();

    RatedPlayer player_1("Yongwu", "Han", 8);
    player_1.playerName();

    // 使用基类指针指向派生类对象
    TableTennisPlayer *ptr = &player_1;
    // 使用基类引用引用派生类对象
    TableTennisPlayer &rt = player_1;

    // 基类的指针或引用，只能调用基类的方法；
    ptr->playerName();
    rt.playerName();

    Brass dom("HH", 11224, 4183.45);
    BrassPlus dot("HH", 11228, 2592.00);
    dom.viewAcct();
    dot.viewAcct();


    return 0;
}
