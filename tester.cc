#include "easy_event.h"

int main() {
    std::function<int(int)>f;
  Event<int(int,int)> event;

  event.SetHandler([](int a, int b)->int{
    return a+b;
  });

  int i = event.Emit(2,3);
  printf("i:%d\n",i);
}