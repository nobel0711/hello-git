//test1.c
#include <stdio.h>
#include "test2.h"

#define FOO 3

int main()
{
  int a=5;
  printf("a=%d a*a=%d\n", a, square(a));
  foo=FOO; 
  printf("foo=%d foo*foo=%d\n", foo, square(foo));
  return 0;
}

