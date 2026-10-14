/* Decompiled C draft; module arm9; ROM address 02023244. No matching claim. */
#include "types.h"
#include "deps/02023244_func_02023244.h"

void func_02023244(ushort *param_1,int param_2,int param_3,int param_4,ushort param_5,int param_6)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (param_3 < 1) {
    return;
  }
  do {
    puVar2 = param_1;
    iVar4 = 0;
    if (0 < param_2) {
      do {
        uVar1 = (ushort)((uint)(param_6 << 0x1c) >> 0x10) | param_5;
        iVar4 = iVar4 + 1;
        param_5 = param_5 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
      } while (iVar4 < param_2);
    }
    iVar3 = iVar3 + 1;
    param_1 = param_1 + param_4;
  } while (iVar3 < param_3);
  return;
}

