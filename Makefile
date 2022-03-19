APP=sort
__start__: obj ./${APP}
	rm -f core.* core; ./${APP}

obj:
	mkdir obj

./${APP}: obj/main.o obj/arrays.o
	g++ -o ./${APP} obj/main.o obj/arrays.o

obj/main.o: src/main.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/main.o src/main.cpp

obj/arrays.o: src/main.cpp
	g++ -Iinc -W -Wall -pedantic -c -o obj/arrays.o src/arrays.cpp


clean:
	rm -f obj/* ./${APP} core.* core