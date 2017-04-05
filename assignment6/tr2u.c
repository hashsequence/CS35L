#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
  if (argc <= 2 || argc > 3)
    {
      fprintf(stderr, "need two arguments\n");
      exit(1);
    }
  int i = 0;
  int j = 0;
  while (argv[1][i] != '\0')
    {
      i++;
    }  
  while (argv[2][j] != '\0')
    {
      j++;
    }  
  if ( i != j)
    {
      fprintf(stderr, "the two arguments are of unequal size \n");
      exit(1);
    }

  i=0;
  j=0;

  for (i = 0; argv[1][i] != '\0'; i++)
    {
      for (j = 0; argv[1][j] != '\0'; j++)
        {
          if (argv[1][i] == argv[1][j] && i != j)
            {
              fprintf(stderr, "cannot have duplicates in string1 or the from string\n");
              exit(1);
            }
        }
    }
  i=0;
  j=0;

  int c;
  while (read(0,&c, sizeof(char)) > 0)
    {
      i=0;
      j=0;
       
      while (argv[1][i] != '\0')
	{
	  //applying bit mask to extract only the least significant bytes
	  c &= 0xff;
	  /*
	  printf("this is c: ");
	  printf("%d\n", c);
	  printf("this is argv[1][i]: ");
	  printf("%d\n", argv[1][i]);
	  */
	  if (c == argv[1][i])
	    {
	      c = argv[2][i];
	      //	      printf("\nI see this\n");
	      write(1,&c, sizeof(char));
	      j = 1;
	      break;
	    }
	    i++;
	}
       if (j == 0)
	 write(1, &c, sizeof(char)); 
      //      printf("%d\n", flag);
    }
return 0;
}
