#include <stdio.h>
#include "tokenizer.h"

void main(void) {
  char in[100];
  
  while (1) {
    printf("%s", "> ");
    fgets(in, 101, stdin);
    //printf("%s", in);

    char **tokens = tokenize(in);    
    print_tokens(tokens);
    free_tokens(tokens);
    print_tokens(tokens);
  }
}
