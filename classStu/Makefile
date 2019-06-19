# main：a.o b.o
# gcc -o main a.o b.o 
# a.o:a.c
#  gcc -c a.c -o a.o 
# b.o:b.c
#  gcc -c b.c -o b.o

exec : tabtenn.o  main.o brass.o
	g++ tabtenn.o brass.o main.o -o exec

tabtenn.o : tabtenn.cpp
	g++ tabtenn.cpp -c

main.o : main.cpp
	g++ main.cpp -c

brass.o : brass.cpp
	g++ brass.cpp -c

clean :
	rm exec main.o tabtenn.o brass.o

# g++ tabtenn.cpp -c tabtenn.o
# g++ main.cpp -c main.o
# g++ main.o tabtenn.o -o main