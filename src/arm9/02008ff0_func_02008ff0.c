/* Decompiled C draft; module arm9; ROM address 02008ff0. No matching claim. */
#include "types.h"
#include "deps/02008ff0_func_02008ff0.h"

void func_02008ff0(uint param_1,code *param_2)

{
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  piVar2 = piRam02009080;
  iVar4 = *piRam02009080;
  iVar5 = iVar4 + 0x10 + iRam02009084 * param_1;
  if ((((*(int *)(iVar5 + iRam02009088) == *(int *)(iVar5 + iRam0200908c)) &&
       (*(int *)(iVar5 + iRam02009088) != 0)) && (*(short *)(iVar5 + iRam02009090) != 0)) &&
     (*(short *)(iVar5 + iRam02009094) == *(short *)(iVar5 + iRam02009090))) {
    uVar3 = 1 << (param_1 & 0xff);
    if ((*(ushort *)(iVar4 + 4) & uVar3) == 0) {
      uVar1 = (ushort)uVar3;
      *(ushort *)(iVar4 + 4) = *(ushort *)(iVar4 + 4) | uVar1;
      *(ushort *)(*piVar2 + 2) = *(ushort *)(*piVar2 + 2) | uVar1;
      func_02008a14();
      if (param_2 != (code *)0x0) {
        (*param_2)(1,iVar5,param_1);
        return;
      }
    }
  }
  else {
    uVar3 = 1 << (param_1 & 0xff);
    if (((*(ushort *)(iVar4 + 4) & uVar3) != 0) &&
       (*(ushort *)(iVar4 + 4) = *(ushort *)(iVar4 + 4) ^ (ushort)uVar3, param_2 != (code *)0x0)) {
      (*param_2)(2,iVar5,param_1);
    }
  }
  return;
}

