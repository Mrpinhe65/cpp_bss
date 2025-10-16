/*
 流类体系及各式控制
 cin
 cout
 cerr
 clog

 streambuf
 iostream.h
*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  for (int i = 1; i <= 10; ++i) {
    for (int j = 1; j <= 10; ++j) {
      cout.width(5);
      cout.flags(ios::left);
      cout << i * j;
    }
    cout << endl;
  }
  int a = 123456789;
  cout.flags(ios::showpos);
  cout << a << endl;

  // 流操作子
  cout << "流操作子:showpos = ";
  cout << showpos << a << endl;

  cout.flags(ios::hex | ios::showbase | ios::uppercase);
  cout << a << endl;

  cout.flags(ios::oct);
  cout << a << endl;

  return 0;
}
