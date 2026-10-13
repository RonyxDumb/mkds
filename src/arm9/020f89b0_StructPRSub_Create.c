/* Decompiled C draft; module arm9; ROM address 020f89b0. No matching claim. */
#include "types.h"
#include "deps/020f89b0_StructPRSub_Create.h"

void StructPRSub_Create(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  param_1[6] = param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[3] = 0x13;
  param_1[4] = 0x13;
  param_1[5] = 0x13;
  param_1[8] = 0;
  uVar2 = (uint)*(ushort *)(param_2 + 0x1f8) * 0x30 +
          (*(uint *)(uRam020f8a00 & 0xfffffffc) >> (uRam020f8a00 & 3) * 8 |
          *(uint *)(uRam020f8a00 & 0xfffffffc) << (uRam020f8a00 & 3) * -8 + 0x20) + 0x70;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  param_1[9] = (uint)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3);
  return;
}

