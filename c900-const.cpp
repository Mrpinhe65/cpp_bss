#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 20;

  // const 修饰的第一种情况
  int const *p1 = &a;
  //*p1=12; // 不能改变*p1
  p1 = &b; // 可以改变p1的指向
  cout << *p1 << endl;

  // const 修饰的第二种情况
  int *const p2 = &a;
  // p2 = &b; // 不能改变p2指向
  *p2 = 11; // 可以改变*p2
  cout << *p2 << endl;

  // const 修饰的第一种情况
  // *p3 和 p3 均不能改变
  const int *const p3 = &a;
  // *p3=11; // *p3 不能改变
  // p3=&b; // p3 不能改变

  return 0;
}
