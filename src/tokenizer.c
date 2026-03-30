

void tokenize_line(char formatted[]) {
  char tokens[10][50];
  int i = 0;
  int token_counter = 0;

  while (formatted[i] != '\0') {
    while (formatted[i] == ' ' || formatted[i] == ',') {
      i++;
    }
    if (formatted[i] == '\0') {
      break;
    }
    int k = 0;
    while (formatted[i] != ' ' && formatted[i] != ',' && formatted[i] != '\0') {
      tokens[token_counter][k] = formatted[i];
      k++;
      i++;
  }
  tokens[token_counter][k] = '\0';
  token_counter++;
  }
}

