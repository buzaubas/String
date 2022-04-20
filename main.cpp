#include <iostream>
#include "string.h"

int main()
{
    setlocale(LC_ALL, "Russian");

    my_string str("asdfjskdjfalskdj");
    my_string str_add("asdfjskdjfalskdj");
    std::cout << str.length() << std::endl;
    std::cout << str.at(4) << std::endl; // выведется j
    str.append(str_add);

    //str.push_back("q");



    
    return 0;
}

