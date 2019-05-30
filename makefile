main.x: bet.o driver.o
	g++ -std=c++11 -o proj4.x proj4_driver.o bet.o
driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp
bet.o: bet.cpp
	g++ -std=c++11 -c bet.cpp
clean: 
	rm *.o 
	rm *.x
