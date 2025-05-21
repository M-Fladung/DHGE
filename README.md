# DHGE - Programmierung
> Aufgabenstellungen unter https://www.computerix.info/ Dozent: Klaus Kusche

Der Linker Benötigt beim kompilieren die Dateien sdlinterf.h und sdlinterf.c
Beispielhaft (C):     gcc gameoflive.c ../sdlinterf.c sdl2-config --cflags --libs -lm
Beispielhaft (C++):   g++ -Wshadow -Wall -Wextra rectan.cpp ../sdlinterf.c `sdl2-config --cflags --libs` -lm    
