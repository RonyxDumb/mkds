/* Decompiled C draft; module arm9; ROM address 02135048. No matching claim. */
#include "types.h"
#include "deps/02135048__snprintf.h"

int _snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  iVar1 = SomeSnprintfImpl(__s,__maxlen,__format,&uStack_4);
  return iVar1;
}

