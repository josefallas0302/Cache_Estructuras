prueba1: prueba1.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp
	g++ prueba1.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp -o prueba1.o
	./prueba1.o > Reporte_prueba1.txt
	gedit Reporte_prueba1.txt

clean:
	rm *.o
