# include <stdio.h>
# include "tokenizer.h"

void clear_string(char *str)
{
  for(char *c = str; *c; c++){
    *c = '\0';
  }
}

int main()
{
  char input[255];
  //fgets(input, 255, stdin);

  char **tokens;
  puts("welcome!");

  while(1){
    printf("select an option:\n 1. input new string to tokenize\n 2. view history\n 3. quit\n> ");
    int c;
    while((c = getchar()) == '\n');
    switch(c){
    case '1':
      printf("Enter a string to tokenize: ");
      while(*fgets(input, 255, stdin) == '\n');
      //add_history(history, copy_str(input, 255));
      tokens = tokenize(input);
      print_tokens(tokens);
      clear_string(input);
      break;
    case '2':
      printf("This option is currently under construction!\n");
      break;
    case '3':
      printf("freeing resources....");
      //free_history(history);
      printf("finished, bye!\n");
      goto done;
    case '\n':
      break;
    default:
      printf("unrecognized option '%c', try again\n", c);
    }
  }

 done:
  return 0;
}
