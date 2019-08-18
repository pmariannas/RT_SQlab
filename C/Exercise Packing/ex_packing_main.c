#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex_packing.h"

int main()
{
    union un UnionMy;
    int value=0;
    char str[16] = "abcb";
    value = compressWithout(str);
    printf("compressWithout - strlen: %d\n", value);

    value = compressUn(UnionMy,str);
    printf("with bit field option -strlen : %d\n", value);
    
    return 0;
}