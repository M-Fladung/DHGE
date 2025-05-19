# DHGE Einführung in die Programmierung (C)
> Aufgabenstellungen unter https://www.computerix.info/
> Dozent: Klaus Kusche

> Für die Funktionalität der SDL integrierenden Dateien muss SDL installiert sein (Ordner SDL). Leider ist SDL zu groß um es direkt zu pushen. Und LFS läuft noch nicht

**Zum Kompilieren von SDL Dateien**
- Der Linker Benötigt beim kompilieren die Dateien sdlinterf.h und sdlinterf.c 
- **Beispielhaft:**  gcc gameoflive.c ../sdlinterf.c `sdl2-config --cflags --libs -lm` 