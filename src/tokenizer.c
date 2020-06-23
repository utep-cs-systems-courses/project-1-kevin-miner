#include <stdlib.h>
#include "tokenizer.h"
#include <stdio.h>

// Return true for any whitespace char.
int space_char(char c) {
  if (c == ' ' || c == '\t')
    return 1;
  return 0;
}

// Return true for any non whitespace char.
int non_space_char(char c) {
  if (space_char(c) || c == '\0')
    return 0;
  return 1;
}

// Return pointer to the first character of a word.
char *word_start(char *str) {
  int i = 0;
  while (space_char(str[i]))
    i++;
  return &str[i];
}

// Return the char after end of word.
// Will return an extra byte
char *word_terminator(char *word) {
  int i = 0;
  while (non_space_char(word[i]))
    i++;
  return &word[i];
}

// Counts words in a sentence.
// Will return 1 if empty or whitespace at ending
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

// Allocates a word in memory.
char *copy_str(char *inStr, short len) {
  int i = 0;
  char *p = (char *) malloc((len + 1) * sizeof(char));
  while (p[i] = inStr[i])
    i++;
  return p;
}

// Store words on an array of pointers.
char **tokenize(char *str) {
  int i;
  short len;
  char *dummyPointer;
  char *wordPointer = word_start(str);
  short strSize = count_words(str);           //get length of input
  char **tokens = (char **) malloc((strSize + 1) * sizeof(char *));
  for (i = 0; i < strSize; i++) {
    wordPointer = word_start(wordPointer);    //wordPointer to word start
    dummyPointer = wordPointer;               //dummyPointer is at the start 
    wordPointer = word_terminator(wordPointer);  //wordPointer is at the end
    len = wordPointer - dummyPointer;

    tokens[i] = copy_str(dummyPointer, len);
    printf("%s", (**tokens)++);
  }
  tokens[i+1] = copy_str('\0', 1);
  return tokens;
}

void print_tokens(char **tokens) {
  int i = 0;
  while (i<2) {
    printf("%s", *tokens[i]);
    //tokens++;
    i++;
  }
}
