
#include <stdio.h>

namespace amigo1 {
void ola() {
  printf("Ola, sou o amigo 1\n");
}
}

namespace amigo2 {
void ola() {
  printf("Ola, sou o amigo 2\n");
  }
}

int main()
{
  printf("Ola, mundo!\n");
  amigo1::ola();
  amigo2::ola();

  return 0;
}
