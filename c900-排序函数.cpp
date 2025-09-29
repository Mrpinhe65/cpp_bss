#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 排序函数
bool myCompare(int v1, int v2) {
  return v1 > v2;  // 降序
}

int main(int argc, char* argv[]) {
  vector<int> v;
  v.push_back(10);
  v.push_back(30);
  v.push_back(20);
  v.push_back(50);
  v.push_back(40);

  // 默认升序
  sort(v.begin(), v.end());
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // 降序
  sort(v.begin(), v.end(), myCompare);
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}