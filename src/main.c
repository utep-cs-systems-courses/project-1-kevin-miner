#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int toInt(char c);

void main(void) {
  char in[100];
  char **tokens;
  int index;
  List *list = init_history();
  
  while (in[0] != '0') {
    printf("%s", "> ");
    fgets(in, 50, stdin);
    
    if (in[0] == '!') {
      index = toInt(in[1]);
      get_history(list, index);
    }
    else {
      
      tokens = tokenize(in);    
      print_tokens(tokens);
      free_tokens(tokens);
      print_tokens(tokens);
      
      
      //add_history(list, in);

      /*
      add_history(list, "hello\n");
      add_history(list, "world\n");
      add_history(list, "computer\n");
      add_history(list, "science\n");
      print_history(list);
      */
      
      //free_history(list);
      //print_history(list);
      
    }
  }
  //print_history(list);
}

int toInt(char c) {
  return c - '0';
}
