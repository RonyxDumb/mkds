/* Decompiled C draft; module arm9; ROM address 0208823c. No matching claim. */
#include "types.h"
#include "deps/0208823c_Animation_CreateFrom.h"

void Animation_CreateFrom(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_4 != 0) && (uVar4 = 0, param_5 != 0)) {
    uVar2 = Mem_AllocateHeap(param_5,param_4 << 2);
    *(undefined4 *)(param_2 + 0x1c) = uVar2;
    uVar2 = Mem_AllocateHeap(param_5,param_4 << 2);
    *(undefined4 *)(param_2 + 0x20) = uVar2;
    if (param_4 != 0) {
      do {
        uVar1 = param_2 + 0x1cU & 3;
        uVar3 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
        *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar4 * 4) = 0;
        uVar1 = param_2 + 0x20U & 3;
        uVar3 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
        *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar4 * 4) = 0;
        uVar4 = uVar4 + 1 & 0xffff;
      } while (uVar4 < param_4);
    }
  }
  Animation_InitializeImpl(param_2,0);
  *(undefined4 *)(param_3 + 0x58) = 0;
  *(int *)(param_2 + 0x14) = param_3;
  *(short *)(param_2 + 0x18) = (short)param_4;
  *(undefined2 *)(param_2 + 0x1a) = 0;
  *(undefined4 *)(param_2 + 0x28) = param_1;
  uVar2 = uRam020882f8;
  *(undefined4 *)(param_2 + 0x2c) = 0;
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  *(undefined4 *)(param_2 + 0x34) = 0;
  return;
}

