Tokenizer
====================
# Tokenizer:

Tokenizer recreates the function of bash of tokenizing a string of arguments.

To use run **make** in this same directory.
This will create an executable **run**.

When runnig it will prompt for input with `> `.
Type any string and hit <return>. This will print your string parsed as tokens
along with their position.

Program will run indefenitly, to stop use **Ctrl-c**

Memory allocation was required to acheive this.
To free this memory, uncomment `free_tokens(tokens)` and `print_tokens(tokens)`
in main.c.
This will show what is left after we free the memory.

To clean unecessary files run **make clean**