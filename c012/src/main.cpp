#include "c012_operator.hpp"

int main(int argc, char *argv[]) {
  cout << "// 运算符重载 operator " << endl;
  Complex c;
  Complex c1(1, 2);
  Complex c2(3, 4);

  cout << "\n// 类内成员函数实现复数相加 c = c1.Add(c2);" << endl;
  c = c1.Add(c2);   // 类内成员函数实现加法
  c.PrintComplex(); // 类内成员函数实现打印

  cout << "\n// 重载运算符+ ，对象和对象相加 c = c1 + c2;" << endl;
  c = c1 + c2;      // 需要重载运算符+ ，否则对象和对象无法相加
  c.PrintComplex(); // 类内成员函数实现打印

  cout << "\n// 重载运算符+ ，对象和对象相加的原本模式 c = c1.operator+(c2);"
       << endl;
  c = c1.operator+(c2);
  c.PrintComplex(); // 类内成员函数实现打印
  cout << "\n// 重载运算符<< (属于 opstream 类)，实现对象的直接输出语句 "
          "cout<<c1<<endl;"
       << endl;
  cout << c1 << endl; // <<的函数重载，打印对象

  cout << "\n// 复数运算 对象+整型 c3 = c1 + 10: (100+100i)+10" << endl;
  Complex c3;
  Complex c4(100, 100);
  c3 = c4 + 10;      // 重载运算符+
  c3.PrintComplex(); // 类内成员函数实现打印

  cout << "\n// 友元函数friend Complex operator+(int i,const Complex&c);实现 "
          "c3 = 10 + c4"
       << endl;
  c3 = 10 + c4;      // 加法交换原则 但重载不支持这样的交换 可用友元函数实现
  c3.PrintComplex(); // 类内成员函数实现打印

  Int x;
  Int y(3);
  Int z(7);

  cout << "\n// x = y + z;" << endl;
  x = y + z;
  x.printData();

  cout << "\n // 前置++：x = ++a;" << endl;
  Int a(5);
  x = ++a;
  x.printData();

  cout << "\n // 后置++：x = a++;" << endl;
  a = 5;
  x = a++;
  cout << "\n // x.printData();" << endl;
  x.printData();
  cout << "\n // a.printData();" << endl;
  a.printData();

  return 0;
}
