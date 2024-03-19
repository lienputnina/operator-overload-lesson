#include "Masivs.h"
#include <iostream>

int main() {
  TestArrayClass mas1(5), mas2(5);

  cout << "Masiivi peec inicializaacijas" << endl;
  cout << mas1 << mas2 << endl; // tuksi
  // kad juus rakstaat "cout << mas1" kompilators aktivizee funkciju
  // "operator<<" genereejot izsaukumu operator<<(cout, mas1)

  mas1[0] = 10;
  mas1[1] = 20;
  mas1[2] = 30;
  mas1[3] = 40;
  mas1[4] = 50;
  cout << "Masiivi satur" << endl;
  cout << mas1 << mas2 << endl;
  mas2 = mas1;
  cout << "Masiivi satur (peec pieskirsanas)" << endl;
  cout << mas1 << mas2 << endl;

  system("Pause");
  return 0;
}
