/* Decompiled C draft; module arm9; ROM address 020b4520. No matching claim. */
#include "types.h"
#include "deps/020b4520_func_020b4520.h"

void func_020b4520(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (param_5 < 1) {
    return;
  }
  do {
    iVar2 = 0;
    if (0 < param_4) {
      do {
        *(undefined2 *)(param_6 + (param_7 + iVar2 + (param_8 + iVar1) * 0x20) * 2) =
             *(undefined2 *)(param_1 + (param_2 + iVar2 + (param_3 + iVar1) * 0x20) * 2);
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_4);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < param_5);
  return;
}

