#include "symbol_table.h"
extern char* Opcodes[];
extern int opcodes_num;
extern char* Directives[];
extern int directives_num;

enum Type {
  NONE,
  LABEL,
  OPCODE,
  DIRECTIVE,
  OPERAND,
  INVALID
};

struct Token_Line {

  int token_count;
  char tokens[10][50];
  enum Type classification[10];
  int overflow_flag;

};

struct Token_Line tokenize_line(char formatted[]) {
  struct Token_Line a;
  a.token_count = 0;
  a.overflow_flag = 0;
  int i = 0;

  while (formatted[i] != '\0') {
    while (formatted[i] == ' ' || formatted[i] == ',') {
      i++;
    }
    if (formatted[i] == '\0') {
      break;
    }
    if (a.token_count == 10) {
      a.overflow_flag = 1;
      return a;

    }
    int k = 0;
    while (formatted[i] != ' ' && formatted[i] != ',' && formatted[i] != '\0') {
      if (k == 49) {
        a.overflow_flag = 1;
        return a;
      }
      a.tokens[a.token_count][k] = formatted[i];
      k++;
      i++;
  }
  a.tokens[a.token_count][k] = '\0';
  a.token_count++;
  }
  return a;
}

// Now that tokens are created we can classify them using tables of different parts of a line


int is_opcode(char* a) {
  for (int k = 0; k < opcodes_num; k++) {
    if (!strcmp(a, Opcodes[k])){
          return 1;
    }
  }
  return 0;
}

int is_directive(char* a) {
  for (int k = 0; k < directives_num; k++) {
    if (!strcmp(a, Directives[k])){
      return 1;
    }
  }
  return 0;
}

struct Token_Line classify_line(struct Token_Line a){
  if (a.overflow_flag) {
    return a;
  }
  for (int i = 0; i < 10; i++) {
    a.classification[i] = NONE;
  }
  if (a.token_count == 0) {
    return a;
  }
  if (is_opcode(a.tokens[0])){
    a.classification[0] = OPCODE;
    for (int i = 1; i < a.token_count; i++) {
      a.classification[i] = OPERAND;
    }
    return a;
  } else if (is_directive(a.tokens[0])) {
    a.classification[0] = DIRECTIVE;
    for (int i = 1; i < a.token_count; i++) {
      a.classification[i] = OPERAND;
    }
    return a;
  } else {
    a.classification[0] = LABEL;
   if (a.token_count < 2) {               // if index 0 then another token is required
      a.classification[0] = INVALID;
      return a;
    } else if (is_opcode(a.tokens[1])) {
      a.classification[1] = OPCODE;
      for (int i = 2; i < a.token_count; i++) {
        a.classification[i] = OPERAND;
      }
      return a;
    } else if (is_directive(a.tokens[1])) {
      a.classification[1] = DIRECTIVE;
      for (int i = 2; i < a.token_count; i++) {
        a.classification[i] = OPERAND;
      }
      return a;
    } else {
      a.classification[0] = INVALID;
      a.classification[1] = INVALID;
      return a;
    }
  }
}
