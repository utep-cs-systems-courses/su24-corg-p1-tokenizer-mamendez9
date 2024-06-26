#include <stdio.h>
#include <string.h>
#include "history.h"
#include "tokenizer.h"
#define MAX_LENGTH 100

int main(int argc, char **argv)
 {
   char input[MAX_LENGTH];
   char input_two[MAX_LENGTH];
   char *input_check;
   char *p;
   char *user_in;
   List *head_ptr = init_history();

 first_input:
   while(1)
     {
       printf("Choose an option: t = Tokenizer, h = History, e = Exit\n");
       printf("$ ");

       user_in = fgets(input, MAX_LENGTH, stdin);
       p = input;

       while (*p != '\0')
	 {
	   if (*p == '\n')
	     {
	       *p = '\0';
	       break;
	     }
	   p++;
	 }
       switch(input[0])
	 {
	 case 't':
	   printf("Enter String: ");
	   printf("$ ");
	   user_in = fgets(input, MAX_LENGTH, stdin);
	   char *p = input;
	   
	   add_history(head_ptr, p);
	   char **tokens = tokenize(p);
	   print_tokens(tokens);
	   free_tokens(tokens);
	   break;
	 case 'h':
	   goto history;
	   break;
	 case 'e':
	   printf("You have Exited!\n");
	   goto done;
	   break;
	 case '\0':
	   goto first_input;
	   break;
	 default:
	   printf("Incorrect input. Try again!\n");
	   break;
	 }
     }

 history:
   printf("Choose an option:\n");
   printf("a = Show all History\n");
   //printf("!<number> = Specific History Item\n");
   printf("c = Clear History\n");
   printf("m = Main Menu\n");
   printf("q = Quit\n");
   putchar('\n');
   printf("$ ");

   user_in = fgets(input, MAX_LENGTH, stdin);
   p = input;
   while (*p != '\0')
     {
       if (*p == '\n')
	 {
	   *p = '\0';
	   break;
	 }
       p++;
     }
   switch (input[0])
     {
     case 'a':
       if (input[1] != '\0')
	 {
	   printf("%s", get_history(head_ptr, input[1] - '0'));
	 }
       else
	 {
	   print_history(head_ptr);
	 }
       goto history;
       break;
     case 'c':
       free_history(head_ptr);
       head_ptr = init_history();
       printf("History is cleared!\n");
       goto history;
       break;
     case 'm':
       goto first_input;
       break;
     case 'q':
       goto done;
       break;
     default:
       printf("Invalid Selection. Try Again!\n");
       goto history;
       break;
       
 done:
   exit(0);
 }
}
