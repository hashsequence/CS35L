#include<stdio.h>
#include<stdlib.h>


int main()
{
  int emptyfile == 0;
  int c; 
do
  {
    c = getchar();
    if(c == EOF && emptyfile == 0)
      {
	return 0;
      }
    if (emptyfile == 0)
      {
	emptyfile = 1;
      }
    putchar(c);

  }while (c == EOF);
}
