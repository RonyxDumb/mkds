/* Decompiled C draft; module arm9; ROM address 0200c858. No matching claim. */
#include "types.h"
#include "deps/0200c858_func_0200c858.h"

void func_0200c858(int param_1,char *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_3 + -1) {
    do {
      *(char *)(param_1 + iVar1) = *param_2;
      iVar1 = iVar1 + 1;
      if (*param_2 != '\0') {
        param_2 = param_2 + 1;
      }
    } while (iVar1 < param_3 + -1);
  }
  *(undefined1 *)(param_1 + iVar1) = 0;
  return;
}

