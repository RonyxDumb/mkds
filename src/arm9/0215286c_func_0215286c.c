/* Decompiled C draft; module arm9; ROM address 0215286c. No matching claim. */
#include "types.h"
#include "deps/0215286c_func_0215286c.h"

void func_0215286c(uint param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _s32_div_f(param_3 + 4,5);
  iVar1 = iRam021528b8;
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      *(undefined1 *)((param_4 + iVar2 + -1) - iVar3) = *(undefined1 *)(iVar1 + (param_1 & 0x1f));
      param_1 = param_1 >> 5 | param_2 << 0x1b;
      param_2 = param_2 >> 5;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  *(undefined1 *)(param_4 + iVar2) = 0;
  return;
}

