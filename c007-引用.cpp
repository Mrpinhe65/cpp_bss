#include <iostream>

using namespace std;

void fun(int x, int y) {
  x = 100;
  y = 200;
}

// c的传地址方式
void swap_c(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

// c++引用方式
void swap_cpp(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 20;

  fun(a, b);

  cout << "a = %d, b = %d" << endl;

  // c的传地址方式
  cout << "\nc的传址方式" << endl;
  swap_c(&a, &b);
  cout << "a = " << a << ", b = " << b << endl;

  // c++引用方式
  cout << "\nc++引用方式" << endl;
  swap_cpp(a, b);

  cout << "a = " << a << ", b = " << b << endl;

  // 对指针的引用
  cout << "\n 对指针p的引用 int *&q=p; " << endl;
  {
    int *p = &a;
    int *&q = p;
    cout << "p" << p << endl;
    cout << "q" << q << endl;
  }
  // 对数组的引用
  cout << "\n对数组的ar[5]引用 int (&br)[5] = ar; " << endl;
  {
    int ar[] = {1, 2, 3, 4, 5};
    int const n = sizeof(ar) / sizeof(ar[0]);
    int (&br)[n] = ar;
  }

  // const 对数组的引用
  {
    cout << "\nconst int a =10; 引用也必须是:const int &b = a;" << endl;
    const int a = 100;
    const int &b = a;
    cout << "也可以用const引用变量：int c =10; const int &d = c;" << endl;
    int c = 10;
    const int &d = c;
  }

  // const引用过程有类型转换的情况，地址不一样，
  // 主要原因：引用的是转换的临时变量地址
  cout << "\nconst double a=12.34; const int &b=a; "
          "a和b地址不一样【转换时的临时变量造成】"
       << endl;
  {
    const double a = 12.34;
    const int &b = a;
    cout << "&a = " << &a << ", &b =" << &b << endl;
  }

  return 0;
}
