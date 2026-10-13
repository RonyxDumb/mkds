/* Decompiled C draft; module arm9; ROM address 02124140. No matching claim. */
#include "types.h"
#include "deps/02124140_func_02124140.h"

void func_02124140(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  
  uVar2 = uRam02124188;
  uVar1 = uRam02124184;
  puVar4 = *(ushort **)
            (*(int *)((uint)*(ushort *)(param_5 + 6) * 0x40 + param_4 + param_1 * 0x40 + 0x3c) +
            0x44);
  puVar3 = *(ushort **)(puVar4 + 2);
  iVar5 = 0;
  if (*puVar4 != 0) {
    do {
      *puVar3 = *puVar3 & (ushort)uVar2;
      if (param_2 != 0) {
        *puVar3 = *puVar3 | (ushort)uVar1;
      }
      puVar3 = puVar3 + 3;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*puVar4);
  }
  return;
}

