#g++ or direct path to it
CC = g++

main.exe : main.o 
	$(CC) -std=c++11 -Wl,-s -o main.exe main.o  -L"C:/boost_1_82_0/libs" -static-libgcc -static-libstdc++
			
main.o : main.cpp
	$(CC) -c main.cpp -I"C:/boost_1_82_0"
	
clean:
	del *.o
	del *.exe
