/**
 * FileName:   helloworld.cpp
 * Author:     Chen Yanfei
 * @contact:   fasionchan@gmail.com
 * @version:   $Id$
 *
 * Description:
 *
 * Changelog:
 *
 * Q&A:
 *
 * How to compile a C++ program?
 *   In a Linux system, you can use g++:
 *   $ g++ -o helloworld helloworld.cpp
 *
 * 如何编译一个C++程序？
 *   在Linux系统下，采用g++命令来编译：
 *   $ g++ -o helloworld helloworld.cpp
 **/

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    cout << "Hello world" << endl;
    return 0;
}
