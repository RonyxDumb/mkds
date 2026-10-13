/* Decompiled C draft; module arm9; ROM address 02016638. No matching claim. */
#include "types.h"
#include "deps/02016638_StructTEQSub_HandleTEQSub.h"

void StructTEQSub_HandleTEQSub(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar2 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = param_1 + 0xc & 3;
  uVar6 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar1 = iRam02016678 +
          (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 4;
  uVar4 = uVar1 & 3;
  uVar8 = *(uint *)(uVar1 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,
                 uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
  uVar1 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = param_1 + 0xc & 3;
  uVar7 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  (*(code *)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20))
            (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,
             uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20,
             uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20);
  return;
}

