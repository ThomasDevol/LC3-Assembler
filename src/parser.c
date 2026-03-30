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
    char formatted[256];
    int out_line = 0;
    int last_space = 0;
    int i = 0; // tracks the index within the line
    int j = 0; // tracks index for the formatted text

    while (line[i] == ' ' || line[i] == '\t') {
      i++;
    } // skip the rest if it is null or the termination char is found

    if (line[i] == '\0' || line[i] == ';' || line[i] == '\n') {
      continue;
    }
    while (line[i] != '\0' && line[i] != ';' && line[i] != '\n') {

      if (line[i] == '\t') {
        i++;
        continue;
      }

      if (line[i] == ' '  || line[i] == '\t') {
        if (!last_space) {
          formatted[j] = ' ';
          last_space = 1;
          j++;
        }
        i++;
      } else {
        formatted[j] = line[i];
        out_line = 1;
        last_space = 0;
        i++;
        j++;
      }
    }
    if (out_line == 1) {
      if (j >0 && formatted[j-1] == ' '){ //remove trailing whitespace at the end
        j--;
      }
      formatted[j] = '\0';
    }

  }
  fclose(file_pointer);
}
