/* Decompiled C draft; module arm9; ROM address 020d6df0. No matching claim. */
#include "types.h"
#include "deps/020d6df0_func_020d6df0.h"

void func_020d6df0(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_48 [40];
  uint uVar8;
  
  uVar8 = param_1 + 4 & 3;
  uVar6 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  uVar8 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  uVar4 = (ulonglong)uRam020d6f18;
  uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar5 = (ulonglong)uRam020d6f18;
  iVar2 = ((int)uVar6 >> 0x1f) * uRam020d6f18;
  iVar3 = ((int)uVar8 >> 0x1f) * uRam020d6f18;
  iVar1 = (int)((((int)uVar7 >> 0x1f) * uRam020d6f18 +
                 uVar7 * 0xb6 + (int)((ulonglong)uRam020d6f18 * (ulonglong)uVar7 >> 0x20) + 0x800) *
                0x10 >> 0x10) >> 4;
  MTX_RotX33__from_thumb
            ((undefined4 *)(uintptr_t)(param_2),(int)*(short *)(iRam020d6f1c + iVar1 * 4),
             (int)*(short *)(iRam020d6f1c + (iVar1 * 2 + 1) * 2));
  iVar1 = (int)((iVar2 + uVar6 * 0xb6 + (int)(uVar4 * uVar6 >> 0x20) + 0x800) * 0x10 >> 0x10) >> 4;
  MTX_RotY33__from_thumb
            ((undefined4 *)(void *)(auStack_48),(int)*(short *)(iRam020d6f1c + iVar1 * 4),
             (int)*(short *)(iRam020d6f1c + (iVar1 * 2 + 1) * 2));
  MTX_Concat33(param_2,(uint *)(void *)(auStack_48),(uint *)(uintptr_t)(param_2));
  iVar1 = (int)((iVar3 + uVar8 * 0xb6 + (int)(uVar5 * uVar8 >> 0x20) + 0x800) * 0x10 >> 0x10) >> 4;
  MTX_RotZ33__from_thumb
            ((undefined4 *)(void *)(auStack_48),(int)*(short *)(iRam020d6f1c + iVar1 * 4),
             (int)*(short *)(iRam020d6f1c + (iVar1 * 2 + 1) * 2));
  MTX_Concat33(param_2,(uint *)(void *)(auStack_48),(uint *)(uintptr_t)(param_2));
  return;
}

