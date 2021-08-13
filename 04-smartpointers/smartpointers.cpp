
#include <memory>
#include <iostream>

class Test {
  public:
    Test();
    void hello();
};

Test::Test() {
}

void Test::hello() {
  std::cout << "Hello!" << std::endl;
}

int main()
{
  std::unique_ptr<int> a (new int);
  (*a) = 5;
  std::cout << *a << std::endl;

  std::unique_ptr<Test> t (new Test);
  t->hello();


  return 0;
}
