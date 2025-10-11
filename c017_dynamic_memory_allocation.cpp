#include <iostream>
using namespace std;

#define SIZE 10

class Test {
private:
  int data;

public:
  Test(int d = 0) : data(d) {
    cout << "create heap memory, this = " << this
         << ", this->data = " << this->data << endl;
  }
  ~Test() { cout << "delete heap memory, this = " << this << endl; }
};

void create_heap_memory_by_c() { // int *s = new int(10);
  cout << "\n//int *p = (int *)malloc(sizeof(int) * SIZE);" << endl;
  int *p = (int *)malloc(sizeof(int) * SIZE);
  if (p == nullptr)
    return;
  for (int i = 0; i < SIZE; ++i)
    p[i] = i + 1;

  // 释放堆区内存 free()
  cout << "//free(p);" << endl;
  free(p);
}

void create_heap_memory_by_cpp() {
  cout << "\n//int *q=new int[SIZE];" << endl;
  int *q = new int[SIZE];
  // new 可不需要判断是否成功，其自身在不成功情况下会抛出异常
  if (q == nullptr)
    return;
  for (int i = 0; i < SIZE; ++i)
    q[i] = i + 1;

  // 释放堆区内存 delete 属于数组的在指针变量前加 []
  cout << "//delete []q;" << endl;
  delete[] q;
}

int main(int argc, char *argv[]) {
  cout << "\n// c017 Dynamic Memory Allocation" << endl;
  create_heap_memory_by_c();
  create_heap_memory_by_cpp();

  cout << "\n// Test *pt=(Test*)malloc(sizeof(Test));" << endl;
  Test *pt_malloc = (Test *)malloc(sizeof(Test));
  if (pt_malloc == nullptr)
    return -1;
  free(pt_malloc);

  cout << "\n// Test *pt_new = new Test(100);" << endl;
  Test *pt_new = new Test(100);
  delete pt_new;

  cout << "\n// Test *pt_ar = new Test[10];" << endl;
  Test *pt_ar = new Test[10];
  delete[] pt_ar;

  return 0;
}
