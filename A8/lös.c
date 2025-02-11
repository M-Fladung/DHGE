// Verkettete Listen: Gib Textfiles sortiert nach Zeilenlänge aus
//
// Aufruf: lensort file1 file2 ...
//
// Klaus Kusche, 2020

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

// Maximale Zeilenlänge
#define MAX_LINELEN 256

// Typ für 1 Element der verketteten Liste = 1 Zeile
typedef struct line {
  const char *file_name;  // File, aus dem die Zeile ist
  int line_nr;            // ursprüngliche Zeilennummer im File
  const char *text;       // Text der Zeile
  struct line *next;      // Verkettung zur nächsten Zeile gleicher Länge
} line_t;

// Typ für 1 Liste als Ganzes
// Da wir *hinten* an die Listen anhängen,
// brauchen wir nicht nur einen Head-Pointer, sondern auch einen Tail-Pointer!
typedef struct list {
  line_t *head;          // Kopf = Pointer auf das erste Element
  line_t *tail;          // Schwanz = Pointer auf das letzte Element
} list_t;

// Programmname (argv[0]), für Fehlermeldungen
const char *prog_name;

void save_line(list_t lines[], const char *file_name, int line_nr,
               const char *text);
void read_file(list_t lines[], const char *file_name);
void write_lines(list_t lines[]);

// Hänge die Zeile "text" (Zeile Nummer line_nr aus File file_name)
// an die entsprechende Liste in lines an
void save_line(list_t lines[], const char *file_name, int line_nr,
               const char *text)
{
  // neuen Listenknoten für die Zeile anlegen
  line_t *p = (line_t *) (malloc(sizeof (line_t)));
  if (p == NULL) {
    fprintf(stderr, "%s: Out of memory: %s\n", prog_name, strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Dynamische Kopie des Zeilentextes anlegen
  // und als text im Listenelement eintragen
  p->text = strdup(text);
  if (p->text == NULL) {
    fprintf(stderr, "%s: Out of memory: %s\n", prog_name, strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Rest des Listenelementes befüllen
  p->file_name = file_name;
  p->line_nr = line_nr;
  // Das neue Element wird immer letztes Element der Liste ==> kein Nachfolger!
  p->next = NULL;

  // Länge der Zeile ist Nummer der Liste, in die sie gehört
  size_t len = strlen(text);
  assert(len < MAX_LINELEN);
  // Element hinten an Liste Nummer len anhängen
  if (lines[len].head == NULL) {
    // Liste war bisher leer ==> neues Element ist erstes Element
    lines[len].head = p;
  } else {
    // Liste hat schon Elemente
    // ==> neues Element wird Nachfolger des bisher letzten Elementes
    lines[len].tail->next = p;
  }
  // in beiden Fallen wird das neue Element neues letztes Element der Liste
  lines[len].tail = p;
}

// Lies den File file_name und speichere seine Zeilen in lines
void read_file(list_t lines[], const char *file_name)
{
  FILE *f;
  char line[MAX_LINELEN];

  if ((f = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "%s: Can't open %s: %s\n", prog_name, file_name,
            strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Schleife pro Zeile (fgets liefert am Fileende NULL = false)
  for (int line_nr = 1; fgets(line, sizeof (line), f); ++line_nr) {
    // Wurde die Zeile komplett incl. \n gelesen, oder fehlt das hinteren Ende?
    if (strchr(line, '\n') == NULL) {
      fprintf(stderr, "%s: Line too long (%s:%d)\n",
              prog_name, file_name, line_nr);
      exit(EXIT_FAILURE);
    }
    save_line(lines, file_name, line_nr, line);
  }

  // Endete die Lese-Schleife wegen Dateiende oder wegen Lesefehler?
  if (ferror(f)) {
    fprintf(stderr, "%s: Can't read %s: %s\n", prog_name, file_name,
            strerror(errno));
    exit(EXIT_FAILURE);
  }

  // Bei nur-Lese-Files gibt es bei close normalerweise keine Fehler...
  fclose(f);
}

// Gib alle Zeilen in lines in aufsteigender Längen-Reihenfolge aus
void write_lines(list_t lines[])
{
  // Alle Listen der Reihe nach ausgeben
  for (int len = 0; len < MAX_LINELEN; ++len) {
    // Alle Elemente einer Liste der Reihe nach ausgeben
    for (line_t *p = lines[len].head; p != NULL; p = p->next) {
      if (printf("%s:%d: %s", p->file_name, p->line_nr, p->text) < 0) {
        fprintf(stderr, "%s: Can't write stdout: %s\n",
                prog_name, strerror(errno));
        exit(EXIT_FAILURE);
      }
    }
  }
}

int main(int argc, const char *argv[])
{
  // Pro möglicher Zeilenlänge eine eigene Liste
  list_t lines[MAX_LINELEN];

  prog_name = argv[0];

  if (argc == 1) {
    fprintf(stderr, "Usage: %s file ...\n", prog_name);
    exit(EXIT_FAILURE);
  }

  // Alle Listen auf "leer" initialisieren
  for (int i = 0; i < MAX_LINELEN; ++i) {
    lines[i].head = lines[i].tail = NULL;
  }

  for (int i = 1; i < argc; ++i) {
    read_file(lines, argv[i]);
  }

  write_lines(lines);
  
  exit(EXIT_SUCCESS);
}