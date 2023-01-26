#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr list;

    list.push_back("775");
    list.push_front("122");
    list.push_back("7");
    list.push_back("7315");
    list.push_front("122");
    list.push_front("12552");
    list.push_front("122");
    list.push_front("122");
    list.push_front("122");
    list.push_front("122");
    list.push_back("775");
    list.push_back("775");


    


    std::cout << "front" << list.front() << std::endl;
    std::cout << "back" << list.back() << std::endl;

    // list.pop_back();
    list.pop_front();

    // std::cout << "" << list.front() << std::endl;
    

}

