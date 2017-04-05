#include<stdio.h>
#include<stdlib.h>

char decoder(char const * a)
{
  return (*a)^(42);
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

int frobcmp(void const *a1, void const *b1)
{
  
  char const **a2 = (char const**)a1;
  char const **b2 = (char const**)b1;
  char const *a = *a2;
  char const *b = *b2;
  
  int value = 1234;
  int i = 0; 
  int j = 0;
  while((a[i] != ' ' &&  b[j] != ' '))
  {  
    /*
    	  printf("@");
	  printf("%c", a[i]);
	  printf("#");
	  printf("%c", b[j]);
    */
      value = cmpchar(&a[i],&b[j]);
      /*
      printf(" %d", value);
      printf("\n");
      */
      if (value != 0)
	{	  
	return value;
	}
      i++;
      j++;
    }
   
  //   printf("out of loop");
  //printf("\n");
  if (a[i] == ' ' && b[j] != ' ')
    return -1;
  else if (a[i] != ' ' && b[j] == ' ')
    return 1;
  else 
    return 0;
}
/*
void test(void)
{
	
	char *p =(char*)malloc(sizeof(char));
	*p = 'N';
	printf("%c", *p);
	printf("\n");
	printf("%c", decoder(p));
	printf("\n");
	free(p);
	int value = frobcmp("*{_CIA\030\031 ", "*`_GZY\v ");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	value = frobcmp( "*`_GZY\v ", "*{_CIA\030\031 ");
	printf("value is ");
	printf("%d", value);
	printf("\n");

	printf("test1: \n");	
	value = frobcmp("*{_CIA\030\031 ", "*{_CIA\030\031 ");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	value = frobcmp("*{_CIA\03 ", "*{_CIA\030\031 ");
	printf("value is ");
	printf("%d", value);
	printf("\n");
 	value = frobcmp("*{_CIA\030\031 ", "*{_CIA\030\0312 ");
	printf("value is ");
	printf("%d", value);
	printf("\n");
	value = frobcmp("*{_CIA\030\031 ", "*{_CIA\030\0 ");
	printf("value is ");
	printf("%d", value);
	printf("\n");

}
*/
int main()
{
  //  test();
  /*allocate a char array for the input*/
  int MAXLINES = 1000;
  int nitems = 0;
  char* inarr = (char*)malloc(sizeof(char)*MAXLINES);
  if( inarr == NULL)
    {
      fprintf(stderr, "Error allocating memory\n");
      exit(1);
    }

  char c;
  int c1 = 0;
  int i = 0;
  /*read the input until the end of file, getchar() reads the 
   next character of the input, returns either EOF or a char*/
  int emptycounter = 0;
do
 {

   /* I had to cast c1 an int to input into the array correctly but
      I need c1 as a stopping condition since it is the original value */
   c1 = getchar();
   c = (char)c1;
  
   //return if empty file
if ( c == EOF &&  emptycounter == 0)
     {
       return 0;
     }
   if (emptycounter == 0)
     {
       emptycounter = 1;
     }
   if (c1 == EOF)
     {
       break;
     }
   //printf("%c", c);
   inarr[i]=c;
   i++;
   if (i == MAXLINES)
     {
       //    printf("reallocating\n");
       MAXLINES*=2;
       inarr = realloc(inarr, sizeof(char)*MAXLINES);
     }
     if( inarr == NULL)
    {
      fprintf(stderr, "Error allocating memory\n");
      exit(1);
    }

 }
 while(c1 != EOF);
// printf("size of inarr is: ");
//printf("%c", i);
// printf("%c",inarr[i-1]);
// printf("\n");
//If the inarry does not end with a space, add a space
 if (inarr[i-1] != ' ')
   {
     inarr[i]=' ';
     i++;
   }
 int j = 0;
 int  max_string_length = 0;
 int string_length = 0;

 //this loop counts the number of elements by counting the spaces
 //and it also counts the maximum stringlength plus one for the 
 //trailing space
 for(j = 0; j < i; j++)
   {
     string_length++;
     if (inarr[j] == ' ')
       {
	 nitems++;
	 if(string_length >=  max_string_length)
	   {
	     max_string_length = string_length;
	   }
	 string_length = 0;
       }

  
   }
 /*
 printf("nitems: ");
 printf("%d", nitems);
 printf("\n");
 printf("max string length: ");
 printf("%d", max_string_length);
 printf("\n");
 */

 /*the tricky part was making a 2d array of char since you
have to allocate the heap for each of the *strarr after allocating
the number of rows for **strarr*/
char **strarr = (char**)malloc(sizeof(char*)*nitems); 
int m = 0;
     if( strarr == NULL)
    {
      fprintf(stderr, "Error allocating memory\n");
      exit(1);
    }

 for (m = 0; m < nitems; m++)
   {
     strarr[m]= (char*)malloc(sizeof(char)*max_string_length);
     if( strarr[m] == NULL)
    {
      fprintf(stderr, "Error allocating memory\n");
      exit(1);
    }

   }
 
 int k = 0;
 int inarrcounter = 0;
 int h = 0;
 while(h < nitems || inarrcounter < i) 
   {
     k = 0;
     while (inarr[inarrcounter] != ' ')
       {
	 strarr[h][k] = inarr[inarrcounter];
	 inarrcounter++;
	 k++;
       }
     
     if(inarr[inarrcounter] == ' ')
       {
	 strarr[h][k] = inarr[inarrcounter];
	 inarrcounter++;
	 k++;
       }
     h++;
   }
 k = 0;
  qsort(strarr,nitems,sizeof(char*),frobcmp);
  int r = 0;
  int t = 0;	
 
for(r = 0; r < nitems; r++)
  {    
    t = 0;
    while(strarr[r][t] != ' ')
      {
	printf("%c", strarr[r][t]);
	t++;
      }
    printf("%c", strarr[r][t]);
  }

//freeing memory
for(r = 0; r < nitems; r++)
  {    
    free(strarr[r]);
  }
    free(strarr);
    free(inarr);
    return 0;
}
