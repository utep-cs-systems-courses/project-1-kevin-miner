Tokenizer
====================
# String parser:

Tokenizer recreates the function of bash of tokenizing a string of arguments.

To use run `make` in this same directory.
This will create an executable called **run**.

When runnig it will prompt for input with `> `.  
Type any string and hit enter. This will print your string parsed as tokens  
along with their position.

Memory allocation was required to acheive this.
To free this memory, uncomment `free_tokens(tokens)` and `print_tokens(tokens)`
in main.c.
This will show what is left after we free the memory.

# History:

Stores input on a linked list which can be retrieved by inputing `!#`
where `#` is the id or position of the string to retrieve.

### Notes:
- To clean unecessary files run `make clean`.
- Program will run indefinitely, to stop it use `Ctrl-c` or enter `0`.