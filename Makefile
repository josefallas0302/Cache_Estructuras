prueba1: prueba1.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp
	g++ prueba1.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp -o prueba1.o
	./prueba1.o > Reporte_prueba1.txt
	gedit Reporte_prueba1.txt

prueba2: prueba2.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp
	g++ prueba2.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp -o prueba2.o
	./prueba2.o > Reporte_prueba2.txt
	gedit Reporte_prueba2.txt

prueba3: prueba3.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp
	g++ prueba3.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp -o prueba3.o
	./prueba3.o > Reporte_prueba3.txt
	gedit Reporte_prueba3.txt

todo: todo.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp
	g++ todo.cpp block.cpp cache_dir.cpp mem.cpp cache.cpp line.cpp -o todo.o
	./todo.o > Reporte_todo.txt
	gedit Reporte_todo.txt

clean:
	rm *.o
