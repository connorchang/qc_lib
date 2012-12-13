/* This file converts infix to postfix
 * Program 4.3 page 143
 * stack holds singel operators
 */

#include <stdio.h>
#include <stdlib.h>
#include "QC_STACK.h"
/* Item is defined to char */
#include "Item.h"


int main(int argc, char **argv)
{
  char *in = argv[1]; int i = 0; int N = strlen(in);
  
  STACKinit(N);

  for(i = 0; i < N; i++) {
    if (in[i] == '+' || in[i] == '*')
      { STACKpush(in[i]); }
    if (in[i] == ')')
      { printf("%c ", STACKpop(); }
    if (in[i] >= '0' && in[i] <= '9')
      { printf("%c ", in[i]); }		/* setup stack for the following while loop */
  }
  
}
