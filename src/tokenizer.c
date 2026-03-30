

void tokenize_line(char formatted[]) {
  char token[10][50];
  int i = 0;
  int token_counter = 0;

  while (formatted[i] == ' ' || formatted[i] == ',') {
    i++;
  }
  if (formatted[i] == '\0') {
    return;
  }
  int k = 0;
  while (formatted[i] != ' ' && formatted[i] != ',' && formatted[i] != '\0') {
    token[token_counter][k] = formatted[i];
    k++;
    i++;
  }
}
