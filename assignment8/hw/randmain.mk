randlibhw.so: randlibhw.c
	gcc $(CFLAGS) -fPIC randlibhw.c -shared -o randlibhw.so 
randlibsw.so: randlibsw.c
	gcc $(CFLAGS) -fPIC randlibsw.c -shared -o randlibsw.so 
randmain: randcpuid.o randmain.o
	gcc $(CFLAGS) randcpuid.o randmain.o -ldl -Wl,-rpath=$PWD -o randmain
