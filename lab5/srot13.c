#include<stdio.h>
#include<stdlib.h>

char decoder(char const * a)
{
  char f[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' ,'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' ,'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  //A is 65
  //N is 78
  //a is 97
  //n is 110
  int i = (int)(*a);
  if (i >= 65 && i <= 77)
    {
      return f[i - 26];
    }
  else if( i >= 78 && i <= 90)
    {
      return f[i - 52];
    }
  else if (i >= 97 && i <= 109)
    {
      return f[i - 84];
    }
  else if (i >= 110 && i <= 122)
    {
      return f[i - 110];
    } 
  else 
    {
      return *a;
    }
}


int cmpchar(char const *a, char const *b)
{
  if (decoder(a) > decoder(b))
    {
      return 1;
    }
  else if (decoder(a) < decoder(b))
    {
      return -1;
    }
  else 
    {
      return 0;
    }
       
}

int rot13cmp(char const *a, char const *b)
{
  int value = 1234;
  int i = 0; 
  while((a[i] != '\n' &&  b[i] != '\n'))
  {   
      value = cmpchar(&a[i],&b[i]);
      printf("%d", value);
      if (value != 0)
	{
      	printf("\n");
	return value;
	}
      i++;
    }
   printf("\n");
  if (a[i] == '\n' && b[i] != '\n')
    return -1;
  else if (a[i] != '\n' && b[i] == '\n')
    return 1;
  else 
    return 0;
}


int main(void)
      {
	/*
	char *p =(char*)malloc(sizeof(char*));
	*p = 'N';
	printf("%c", *p);
	printf("\n");
	printf("%c", decoder(p));
	printf("\n");
	free(p);
	int value = rot13cmp("\0Dhvpx23\n", "\0Whzcf!\n");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	value = rot13cmp("\0Whzcf!\n","\0Dhvpx23\n");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	printf("test1: \n");
	value = rot13cmp("\0Dhvpx23\n","\0Dhvpx23\n");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	value = rot13cmp("\0Dhv\n","\0Dhvpx23\n");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	value = rot13cmp("\0Dhvpx23\n","\0Dhvpx\n");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	*/
	
      }
