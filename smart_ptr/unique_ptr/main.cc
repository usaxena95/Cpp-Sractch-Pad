#include <string>

#include "unique_ptr.h"
using std::cout;
using std::endl;
using std::string;

class my_datatype {
  int data_;
  string str_;

public:
  my_datatype(int data, string str) : data_(data), str_(str) {
    cout << "Data constructed.\n";
  }
  int data() { return data_; }
  string str() { return str_; }
  ~my_datatype() { cout << "Data desctructed.\n"; }
};

int main(int argc, char **argv) {
  unique_ptr<my_datatype> ptr(
      new my_datatype(123, "hello world")); // not expection-safe.
  cout << ptr->data() << " " << ptr->str() << endl;
  // unique_ptr<my_datatype> ptr1 = ptr;           // copy not-allowed.
  unique_ptr<my_datatype> ptr1 = ptr.release(); // release
  unique_ptr<my_datatype> ptr2 = std::move(ptr1);
  ptr2 = std::move(ptr2);
}
