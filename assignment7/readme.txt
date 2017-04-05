first I had to learn what pthread_create and pthread_join does

I realized I needed to use the nthreads somehow
so I made an array of pthreads

I realized the 2nd argument could be NULL for defaul
the third agument is a function pointer to the thing you are multithreading
and the fourth argument is the 1st argument to the function

pthread_join is basically putting them together
and the
firt arguments is the pthread pointer and the 2nd could be a NULL

I could use a for loop to iteratively generate the threads depending 
on nthreads

basically I needed to put the nested for loops into a function with the following format:

void* func1(void* arg)

I can only take one argument of a pointer type

basically I wanted to split the for loops by rendering 
each part in the range of a < width < b in outermost for loop 

however I could only pass in one argument into my function so 
I defined a struct

struct mystruct
{
int a, b;
};

which can specify the range


I then realized that since the threads are accessing the struct at the same time
I had to make an arry of struct of nthreads
I made an int rray that held the bounds depending of the nthreads so for example if 
nthreads = 4
then there are 4 sets of ranges:
a1 < x < b1
a2 < x < b2
a3 < x < b3
a4 < x < b4

since width was odd
I made sure b4 was equal to width

then I realized from debugging that if I leave the printing within the func1,
the rendering will not be similar, so I made a 3d float array declared globally
that stored whatever
it was printing before  and 
I just ouputed after all the pthread_create and pthread_join was finished 
so it'll be consistently rendered 

I also realized that since scene was declared in int main and the nested for loop
used it I made scene declared globally
