#include <iostream>
using namespace std;

class Complex;                                       // 先声明
ostream &operator<<(ostream &out, const Complex &o); // 先声明

class Complex {
public:
  friend ostream &operator<<(ostream &out, const Complex &o); // 先声明
public:
  Complex() : m_real(0), m_imag(0) {}
  Complex(int real, int imag) : m_real(real), m_imag(imag) {}
  ~Complex() {}

  void PrintComplex() const {
    cout << "(" << m_real << "+" << m_imag << "i)" << endl;
  }

  Complex Add(const Complex &comp) {
    return Complex(m_real + comp.m_real, m_imag + comp.m_imag);
  }

public:
  // operator 运算符重载
  Complex operator+(const Complex &c) {
    /*
    Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
    return tmp;
    */

    return Complex(m_real + c.m_real, m_imag + c.m_imag);
  }

  // 复数运算 对象+整型 c3 = c1 + 10
  Complex operator+(const int i) {
    return Complex(this->m_real + i, this->m_real);
  }

private:
  int m_real;
  int m_imag;
};

class Int {
public:
  Int(int i = 0) : m_i(i) {}

  void printData() { cout << m_i << endl; }

  Int operator+(Int const &i) { return Int(m_i + i.m_i); }

  Int &operator++() { // 返回值*this不会消亡，可以用引用返回
    this->m_i++;
    return *this;
  }

  Int operator++(int) { // 返回值tmp会消亡 不能用引用返回
    Int tmp(this->m_i);
    this->m_i++;
    return tmp;
  }

private:
  int m_i;
};

// 先声明后实现
ostream &operator<<(ostream &out, const Complex &o) {
  out << "( " << o.m_real << " + " << o.m_imag << "*i)" << endl;
  return out;
}

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
  // c3=10+c4; // 加法交换原则 但重载不支持这样的交换
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
