#include <iostream>
using namespace std;

// 1. 构造对象
// 2. 初始化对象
// 3. 类型转换

class Test {
 public:
  explicit Test(int d = 0) {
    // Test(int d = 0) {
    cout << "Create Test Object: " << this << endl;
    this->data = d;
    cout << "t = 100 赋值语句触发隐形转换【int 100->类This->data = "
         << this->data << endl;
  }

  ~Test() { cout << "Free Test Object:" << this << endl; }

  // int 运算符重载
  operator int() { return this->data; }

 private:
  int data;
};

int main(int argc, char *argv[]) {
  Test t;
  // t = 100; // 先构造一个Test的临时对象，再赋值给t
  // 前提是需要有对应的构造函数
  t = (Test)100;  // 先构造一个Test的临时对象，再赋值给t
  // 如构造函数加explicit显式 需在转换时加（Test）

  int value = t;  // 需要运算符 int 重载进行转换
  cout << "int 运算符重载: value = [operator int(){return this->data;}]"
       << value << endl;
  return 0;
}
