/* This file serves as a stack ADT client 
 * Program 4.2
 * stack holds numbers 
 * for example 235
 * first push 0 to the stack
 * pop 0 * 10 + '2' - '0' = 2 push 2
 * pop 2 * 10 + '3' - '0' = 23 push 23
 * pop 23 * 10 + '5' - '0' = 235 push 235
 * the 0 setup is important for computing the number based on single bit
 */

/* usage : ./a.out 5 9 8 + 4 6 \* \* 7 + \* */
/* simbol '*' must be escapted otherwise    */
/* it will be recognized as wildcast '*'    */
/* in turn it returns file names            */ 
/* $ ./a.out *                              */
/* argv[0] = ./a.out                        */
/* argv[1] = a.out                          */
/* argv[2] = infix-to-postfix.c ...         */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QC_STACK.h"
//#include "Item.h"

int main(int argc, char **argv)
{
  int i = 0; int N = 0;
  
  while (argv[i]!=NULL)  i++;
  
  N = i - 1;			/* substract argv[0] (command) */

  STACKinit(N);

  for(i = 1; i <= N; i++) { 
    if (!strcmp(argv[i],"+")) { 
	STACKpush(STACKpop() + STACKpop());  
	continue;
      } 
    if (!strcmp(argv[i], "*")) { 
      STACKpush(STACKpop() * STACKpop()); 
      continue;
    }  
    
    STACKpush(atoi(argv[i]));

    /* if (argv[i] >= "0" && argv[i] <= "9")  */
    /*   { STACKpush(0); }		/\* setup stack for the following while loop *\/  */
    /* while(argv[i] >= "0" && argv[i] <= "9")   */
    /*   { STACKpush(STACKpop()*10 + argv[i++]-'0'); }   */
  } 
  printf("result = %d\n", STACKpop()); 
  
}
