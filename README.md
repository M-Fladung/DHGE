# DHGE

> Für die Funktionalität der SDL integrierenden Dateien muss SDL installiert sein (Ordner SDL). Leider ist SDL zu groß um es direkt zu pushen. Und LFS läuft noch nicht

**Zum Kompilieren von SDL Dateien**
- Der Linker Benötigt beim kompilieren die Dateien sdlinterf.h und sdlinterf.c in SDL_usage
- **Beispielhaft:**  gcc sort.c sdlinterf.c `sdl2-config --cflags --libs -lm` 