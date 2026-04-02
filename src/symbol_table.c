// pointer to  Array containing all LC3 opcodes
char* Opcodes[] = {
                   "ADD", "AND", "NOT", "BR", "JMP", "JSR",
                   "JSRR", "LD", "LEA", "ST", "STI", "STR",
                   "TRAP", "RET", "RTI"
                  };

// total bytes reserved divided by an  element's reserved bytes
opcodes_num = sizeof(Opcodes) / sizeof(Opcodes[0]);

// pointer to  Array containing all LC3 Directives

char* Directives[] = {".ORIG", ".END", ".BLKW", ".FILL", ".STRINGZ"};

directives_num = sizeof(Directives) / sizeof(Directives[0]);
