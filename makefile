proj4.x: bet.o proj4_driver.o
	g++ -std=c++11 -o proj4.x proj4_driver.o bet.o
proj4_driver.o: proj4_driver.cpp
	g++ -std=c++11 -c proj4_driver.cpp
bet.o: bet.cpp
	g++ -std=c++11 -c bet.cpp
clean: 
	rm *.o proj4.x
