#include "Masivs.h"
#include <assert.h>
#include <iostream>

using namespace std;

TestArrayClass::TestArrayClass(int arraySize) {
  size = arraySize;
  ptr = new int[size];
  assert(ptr != 0); // beidzam ja atmina nav izdaliita
  for (int i = 0; i < size; i++)
    ptr[i] = 0;
}

TestArrayClass::TestArrayClass(const TestArrayClass &object) {
  // Copy size
  size = object.size;

  // Allocate new memory for the copy
  ptr = new int[size];

  // Copy the contents
  for (int i = 0; i < size; ++i) {
    ptr[i] = object.ptr[i];
  }
};

TestArrayClass::~TestArrayClass() { delete[] ptr; }

ostream &operator<<(ostream &output, const TestArrayClass &a) {
  int i;
  for (i = 0; i < a.size; i++) {
    output << a.ptr[i] << ' ';
    if ((i + 1) % 10 == 0)
      output << endl;
  }
  if (i % 10 != 0)
    output << endl;
  return output;
};

int &TestArrayClass::operator[](int index) {
  assert(0 <= index && index < size);
  return ptr[index];
}

const TestArrayClass &TestArrayClass::operator=(const TestArrayClass &right) {
  if (&right != this) // paarbauda vai nav tas pats masiivs, ja ir tas pats
                      // nekas nav jaadara
  {
    delete[] ptr;
    size = right.size;
    ptr = new int[size]; // atminas izdalisana masiiva koppijai
    assert(ptr != 0);

    for (int i = 0; i < size; i++)
      ptr[i] = right.ptr[i];

    return *this; // lauj x = y = z
  }
  return *this; // lauj x = y = z
}

bool TestArrayClass::operator==(const TestArrayClass &otherArray) const {
  // First, compare the sizes of the two arrays
  if (this->size != otherArray.size)
    return false;

  // Next, compare each element in the arrays
  for (int i = 0; i < this->size; i++) {
    if (this->ptr[i] != otherArray.ptr[i])
      return false;
  }

  // If we reach here, the arrays are the same size and have the same elements
  return true;
};

bool TestArrayClass::operator!=(const TestArrayClass &otherArray) const {
    // some code
};

TestArrayClass &TestArrayClass::operator++(){
    // some code
};
TestArrayClass &TestArrayClass::operator--(){
    // some code
};

TestArrayClass &TestArrayClass::operator+(int) const {
    // some code
};
TestArrayClass &TestArrayClass::operator-(int) const {
    // some code
};

bool TestArrayClass::operator>(const TestArrayClass &){
    // some code
};
bool TestArrayClass::operator<(const TestArrayClass &){
    // some code
};

bool TestArrayClass::operator>=(const TestArrayClass &){
    // some code
};
bool TestArrayClass::operator<=(const TestArrayClass &){
    // some code
};
