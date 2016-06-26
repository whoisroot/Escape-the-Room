all: *.cpp
	g++ -o EscapeTheRoom Fila.cpp ListaCadastral.cpp Main.cpp -I. `allegro-config --cflags --libs` 
