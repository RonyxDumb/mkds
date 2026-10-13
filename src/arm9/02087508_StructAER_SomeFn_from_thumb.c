/* Decompiled C draft; module arm9; ROM address 02087508. No matching claim. */
#include "types.h"
#include "deps/02087508_StructAER_SomeFn_from_thumb.h"

void StructAER_SomeFn_from_thumb(undefined4 *param_1,undefined2 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = Mem_AllocateHeap(param_3,0x90);
  param_1[7] = uVar1;
  uVar1 = puRam0208759c[1];
  puVar4 = puRam0208759c + 2;
  *param_1 = *puRam0208759c;
  param_1[1] = uVar1;
  param_1[2] = *puVar4;
  *(undefined2 *)(param_1 + 3) = param_2;
  puVar5 = (undefined4 *)param_1[7];
  iVar3 = 4;
  puVar4 = puRam020875a0;
  do {
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    puVar4 = puVar4 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = *puVar4;
  puVar5 = (undefined4 *)(param_1[7] + 0x24);
  iVar3 = 4;
  puVar4 = puRam020875a4;
  do {
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    puVar4 = puVar4 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = *puVar4;
  puVar5 = (undefined4 *)(param_1[7] + 0x48);
  iVar3 = 4;
  puVar4 = puRam020875a8;
  do {
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    puVar4 = puVar4 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = *puVar4;
  puVar5 = (undefined4 *)(param_1[7] + 0x6c);
  iVar3 = 4;
  puVar4 = puRam020875ac;
  do {
    uVar1 = *puVar4;
    uVar2 = puVar4[1];
    puVar4 = puVar4 + 2;
    *puVar5 = uVar1;
    puVar5[1] = uVar2;
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *puVar5 = *puVar4;
  param_1[4] = 1;
  param_1[5] = 0;
  param_1[6] = 1;
  *(undefined2 *)(param_1 + 9) = 0;
  *(short *)((int)param_1 + 0x26) = (short)uRam020875b0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  return;
}

