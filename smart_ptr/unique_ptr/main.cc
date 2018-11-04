#include <string>

#include "unique_ptr.h"
#define CHECKPOINT(x) cout << "\nCHECKPOINT " << x << "\n"
using std::cout;
using std::endl;
using std::string;

class my_datatype {
  int data_;
  string str_;

public:
  my_datatype(int data, string str) : data_(data), str_(str) {
    cout << "Data constructed for \"" << str_ << "\"\n";
  }
  int data() { return data_; }
  string str() { return str_; }
  ~my_datatype() { cout << "Data desctructed for \"" << str_ << "\"\n"; }
};

int main(int argc, char **argv) {
  CHECKPOINT(1);
  unique_ptr<my_datatype> ptr1(
      new my_datatype(1, "first")); // not expection-safe.

  CHECKPOINT(2);
  unique_ptr<my_datatype> ptr2(
      new my_datatype(2, "second")); // not expection-safe.
  // unique_ptr<my_datatype> ptr = ptr1;         // copy not-allowed.
  CHECKPOINT(3);
  unique_ptr<my_datatype> ptr3 = ptr1.release(); // release

  CHECKPOINT(4);
  ptr2 = std::move(ptr3);
}
