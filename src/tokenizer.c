#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true for any whitespace char. */
int space_char(char c) {
  if (c == ' ' || c == '\t')
    return 1;
  return 0;
}

/* Return true for any non whitespace char. */
int non_space_char(char c) {
  if (space_char(c) || c == '\0')
    return 0;
  return 1;
}

/* Return pointer to the first character of a word. */
char *word_start(char *str) {
  int i = 0;
  while (space_char(str[i]))
    i++;
  return &str[i];
}

/* Return pointer to the char at the end of word. */
char *word_terminator(char *word) {
  int i = 0;
  while (non_space_char(word[i]))
    i++;
  return &word[i];
}

/* Counts words in a sentence. */
/* BUG: returns 1 for empty string */
int count_words(char *str) {
  int c = 0;
  char *p = str;
  while (*p) {
    p = word_start(p);
    p = word_terminator(p);
    c++;
  }
  return c;
}

/* Allocates space for a string in memory. */
char *copy_str(char *inStr, short len) {
  int i = 0;
  char *p = (char *) malloc((len + 1) * sizeof(char*));
  while (i < len) {
    p[i] = inStr[i];
    i++;
  }
  p[i] = '\0';
  return p;
}

/* Tokenize a string into tokens. */
char **tokenize(char *str) {
  int i;
  short len;
  char *dummyPointer;
  char *wordPointer = word_start(str);
  short strSize = count_words(str);        /* get length of string */
  char **tokens = (char **) malloc((strSize + 1) * sizeof(char**));
  
  for (i = 0; i < strSize; i++) {
    wordPointer = word_start(wordPointer);    /* wordPointer to word start */
    dummyPointer = wordPointer;               /* dummyPointer to word start */
    wordPointer = word_terminator(wordPointer);  /* wordPointer to word end */
    len = wordPointer - dummyPointer;         /* subtract pointers to get len */
    tokens[i] = copy_str(dummyPointer, len); 
  }
  tokens[i] = '\0';
  return tokens;
}

/* Print tokenizer list. */
void print_tokens(char **tokens) {
  int i = 0;
  while (tokens[i]) {
    printf("token[%d]: %s\n", i, tokens[i]);
    i++;
  }
}

/* Free all memory */
void free_tokens(char **tokens) {
  int i = 0;
  while (tokens[i]) {
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
