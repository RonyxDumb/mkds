/* Decompiled C draft; module arm9; ROM address 02124100. No matching claim. */
#include "types.h"
#include "deps/02124100_func_02124100.h"

void func_02124100(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  
  uVar1 = uRam0212413c;
  puVar3 = *(ushort **)
            (*(int *)((uint)*(ushort *)(param_5 + 6) * 0x40 + param_4 + param_1 * 0x40 + 0x3c) +
            0x44);
  iVar2 = *(int *)(puVar3 + 2);
  iVar4 = 0;
  if (*puVar3 != 0) {
    do {
      *(ushort *)(iVar2 + 4) = *(ushort *)(iVar2 + 4) & (ushort)uVar1;
      *(ushort *)(iVar2 + 4) = *(ushort *)(iVar2 + 4) | (ushort)(param_2 << 0xc);
      iVar2 = iVar2 + 6;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*puVar3);
  }
  return;
}

