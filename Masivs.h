#ifndef MASIVS_H
#define MASIVS_H

#include <iostream>

using namespace std;

class TestArrayClass {
  friend ostream &operator<<(ostream &, const TestArrayClass &);

private:
  int size;
  int *ptr;

public:
  TestArrayClass(int = 10);

  TestArrayClass(const TestArrayClass &object);

  ~TestArrayClass();

  /*
  "operator" - indicates that this method is an overload of the specific
  operator.
  TestArrayClass & - returning a reference to the class instance
  */
  const TestArrayClass &operator=(const TestArrayClass &);

  int &operator[](int);

  /*
  "const" at the end of these - guarantees not to modify any member variables of
  the object on which it is called.
  */
  bool operator==(const TestArrayClass &otherArray) const;
  bool operator!=(const TestArrayClass &otherArray) const;

  /*
   For increment (++) and decrement (--) operators it is common to return the
   object itself (by reference) to allow chaining. Need to ensure that both the
   declaration and the definition have matching return type
  */
  TestArrayClass &operator++();
  TestArrayClass &operator--();

  TestArrayClass &operator+(int) const;
  TestArrayClass &operator-(int) const;

  bool operator>(const TestArrayClass &);
  bool operator<(const TestArrayClass &);

  bool operator>=(const TestArrayClass &);
  bool operator<=(const TestArrayClass &);
};

#endif