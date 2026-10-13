/* Decompiled C draft; module arm9; ROM address 020aa300. No matching claim. */
#include "types.h"
#include "deps/020aa300_func_020aa300.h"

void func_020aa300(int param_1)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = *(byte **)(param_1 + 0x44);
  if (pbVar3 == (byte *)0x0) {
    *(uint *)(param_1 + 0x44) =
         **(int **)(param_1 + 0x2c) + (uint)*(ushort *)(*(int **)(param_1 + 0x2c) + 3) * 8;
    return;
  }
  if (*(ushort *)(pbVar3 + 6) < 0x100) {
    iVar1 = _s32_div_f((uint)*pbVar3 * 2 + (uint)pbVar3[2],2);
    iVar1 = *piRam020aa398 + iVar1;
    iVar2 = _s32_div_f((uint)pbVar3[1] * 2 + (uint)pbVar3[3],2);
    iVar2 = *piRam020aa39c + iVar2;
  }
  else {
    iVar1 = _s32_div_f((uint)*pbVar3 * 2 + (uint)pbVar3[2],2);
    iVar2 = _s32_div_f((uint)pbVar3[1] * 2 + (uint)pbVar3[3],2);
  }
  iVar1 = func_020aaea0(param_1,iVar1 + 3,iVar2 + -3);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x44) = iVar1;
    return;
  }
  *(uint *)(param_1 + 0x44) =
       **(int **)(param_1 + 0x2c) + (uint)*(ushort *)(*(int **)(param_1 + 0x2c) + 3) * 8;
  return;
}

