#include <stdio.h>

void parse_source_file(const char *filename) {
  // create pointer to file imported
  FILE *file_pointer = fopen(filename, "r");

  // NULL protection
  if (file_pointer == NULL) {
    printf("Error: Invalid, unable to open file %s\n", filename);
    return;
  }

  // declare buffer
  char line[256];
  while (fgets(line, sizeof(line), file_pointer) != NULL) {
    int out_line = 0;
    int last_space = 0;
    int i = 0; // tracks the index within the line

    while (line[i] == ' ' || line[i] == '\t') {
      i++;
    } // skip the rest if it is null or the termination char is found

    if (line[i] == '\0' || line[i] == ';') {
      continue;
    }
    while (line[i] != '\0' && line[i] != ';') {

      if (line[i] == '\t') {
        i++;
        continue;
      }

      if (line[i] == ' ') {
        if (last_space) {
          i++;
          continue;
        }
        last_space = 1;
        printf("%c", line[i]);
        out_line = 1;
        i++;
      } else {
        last_space = 0;
        printf("%c", line[i]);
        out_line = 1;
        i++;
      }
    }
    if (out_line == 1) {
      putchar('\n');
    }
  }
  fclose(file_pointer);
}
