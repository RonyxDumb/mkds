/* Decompiled C draft; module arm9; ROM address 020ff97c. No matching claim. */
#include "types.h"
#include "deps/020ff97c_func_020ff97c.h"

void func_020ff97c(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  puVar5 = (undefined4 *)(param_1 + 0x28);
  puVar4 = (undefined4 *)(param_1 + 0xa0);
  iVar3 = 4;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar4 = *puVar5;
  *(undefined4 *)(param_1 + iRam020ffa68) = 0;
  *(undefined4 *)(param_1 + iRam020ffa6c) = 0;
  *(undefined4 *)(param_1 + iRam020ffa70) = 0;
  *(undefined4 *)(param_1 + iRam020ffa74) = 0;
  uVar6 = Multiply64(*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x1c) >> 0x1f,uRam020ffa78);
  *(uint *)(param_1 + iRam020ffa7c) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x20) >> 0x1f,uRam020ffa80,0);
  *(int *)(param_1 + iRam020ffa84) =
       (int)((uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14) >> 1;
  uVar6 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020ffa88,0);
  *(uint *)(param_1 + iRam020ffa8c) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  uVar6 = Multiply64(*(int *)(param_1 + 0x24),*(int *)(param_1 + 0x24) >> 0x1f,uRam020ffa88,0);
  *(uint *)(param_1 + iRam020ffa90) = (uint)uVar6 >> 0xc | (int)((ulonglong)uVar6 >> 0x20) << 0x14;
  *(undefined4 *)(param_1 + iRam020ffa94) = 0;
  *(undefined4 *)(param_1 + iRam020ffa98) = 1;
  *(undefined4 *)(param_1 + iRam020ffa9c) = 0;
  *(undefined4 *)(param_1 + iRam020ffaa0) = 0;
  *(undefined4 *)(param_1 + iRam020ffaa8) = uRam020ffaa4;
  *(undefined4 *)(param_1 + 0xe8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xec) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  VecFx32_AddScale1(-*(int *)(param_1 + iRam020ffa84),param_1 + 0x34,param_1 + 4,(int *)(uintptr_t)(param_1 + 0xf4));
  *(undefined4 *)(param_1 + iRam020ffaac) = 0;
  *(undefined4 *)(param_1 + iRam020ffab0) = 0;
  *(undefined4 *)(param_1 + iRam020ffab4) = 1;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020ffab8;
  return;
}

