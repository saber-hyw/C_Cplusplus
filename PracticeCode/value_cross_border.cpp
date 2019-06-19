
#include <iostream>

using namespace std;

int main() 
{
    // short range: [-32768, 32767]; unsigned range[0,65535]
    short value{};   // the default value is 0, when undefined;
    unsigned short ug_value = {0};  // okay if variable value already define;

    // 分别给与最大值，然后+1
    value = 32767;
    ug_value = 32767;
    value = value + 1;
    ug_value = ug_value + 1;
    cout << "value + 1 = " << value << endl;
    cout << "ug_value + 1 = " << ug_value << endl;

    // 分别给与最小值，然后-1
    value = 0;
    ug_value = 0;
    value = value - 1;
    ug_value = ug_value - 1;
    cout << "value - 1 = " << value << endl;
    cout << "ug_value - 1 = " << ug_value << endl;

    return 0;
}