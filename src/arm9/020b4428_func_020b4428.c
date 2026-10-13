/* Decompiled C draft; module arm9; ROM address 020b4428. No matching claim. */
#include "types.h"
#include "deps/020b4428_func_020b4428.h"

void func_020b4428(int param_1,int param_2,int param_3,int param_4,int param_5,ushort param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  param_5 = param_3 + param_5;
  if (param_3 < param_5) {
    iVar2 = param_3 << 5;
    do {
      iVar3 = param_2;
      if (param_2 < param_2 + param_4) {
        do {
          iVar1 = (iVar3 + iVar2) * 2;
          iVar3 = iVar3 + 1;
          *(ushort *)(param_1 + iVar1) = param_6 | *(ushort *)(param_1 + iVar1) & 0xfc00;
        } while (iVar3 < param_2 + param_4);
      }
      param_3 = param_3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (param_3 < param_5);
    return;
  }
  return;
}

