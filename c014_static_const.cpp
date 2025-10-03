#include <iostream>
using namespace std;

class Test {
public:
  friend void Fun(Test &);
  Test(int d = 0) : data(d) { count++; }
  ~Test() { count--; }
  void FunInClass() {
    cout << "\nFunInClass 成员函数" << endl;
    cout << "data = " << data << endl;
    cout << "count = " << count << endl;
  }
  static void Show() {
    cout
        << "\n静态 static Show()成员函数,只能访问静态变量，不能访问成员普通变量"
        << endl;
    cout << "普通方法可以调用静态方法，反之则不可以" << endl;
    cout << "原因是静态方法没有指针This" << endl;
    // cout << "data = " << data << endl;
    cout << "static count = " << count << endl;
  }
  // const 的重载问题
  // 普通方法/函数
  void List() { // void List(Test * const this )
    cout << "This is List() // 相当于 void List(Test * const this )" << endl;
    data = 0; // 可以改变成员变量的值
    int abc = 2;
  }
  // 常方法/函数
  void List() const { // 相当于 void(const Test * const this)
    cout << "This is List()const 相当于 void(const Test * const this)" << endl;
    // data=0; // 常方法/函数中 不能改变成员变量的值
    int abc = 2;
  }

private:
  int data;
  static int count;
};
// Init count 要求类外初始化
int Test::count = 0;

void Fun(Test &t) {
  cout << "t.data = " << t.data << endl;
  cout << "Object count = " << Test::count << endl;
}
int main(int argc, char *argv[]) {
  cout << "\n// c014_static_const.cpp" << endl;

  Test t(100);
  Fun(t);
  Test t1(200);
  Fun(t1);
  Test t2(300);
  Fun(t2);
  // 成员函数
  t.FunInClass();
  // 成员函数
  t.Show();

  return 0;
}
