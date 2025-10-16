#include <iostream>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
  list<int> myList;
  for (int i = 0; i < 10; ++i)
    myList.push_back(i);

  list<int>::iterator it = myList.begin();
  while (it != myList.end()) {
    cout << *it << "-->";
    it++;
  }
  cout << "nil" << endl;

  return 0;
}
