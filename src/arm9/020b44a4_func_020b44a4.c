/* Decompiled C draft; module arm9; ROM address 020b44a4. No matching claim. */
#include "types.h"
#include "deps/020b44a4_func_020b44a4.h"

void func_020b44a4(int param_1,int param_2,int param_3,int param_4,int param_5,short param_6)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  
  param_5 = param_3 + param_5;
  if (param_3 < param_5) {
    iVar3 = param_3 << 5;
    uVar2 = (ushort)uRam020b451c;
    do {
      iVar4 = param_2;
      if (param_2 < param_2 + param_4) {
        do {
          iVar1 = (iVar4 + iVar3) * 2;
          iVar4 = iVar4 + 1;
          *(ushort *)(param_1 + iVar1) = param_6 << 0xc | uVar2 & *(ushort *)(param_1 + iVar1);
        } while (iVar4 < param_2 + param_4);
      }
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 0x20;
    } while (param_3 < param_5);
    return;
  }
  return;
}

