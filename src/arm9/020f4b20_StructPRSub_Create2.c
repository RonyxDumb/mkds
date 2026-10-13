/* Decompiled C draft; module arm9; ROM address 020f4b20. No matching claim. */
#include "types.h"
#include "deps/020f4b20_StructPRSub_Create2.h"

void StructPRSub_Create2(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  param_1[1] = param_2;
  *param_1 = 0x13;
  param_1[2] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 0;
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    param_1[iVar3 + 5] = 0;
    iVar3 = iVar4;
  } while (iVar4 < 3);
  uVar2 = (uint)*(ushort *)(param_2 + 0x1f8) * 0x30 +
          (*(uint *)(uRam020f4b88 & 0xfffffffc) >> (uRam020f4b88 & 3) * 8 |
          *(uint *)(uRam020f4b88 & 0xfffffffc) << (uRam020f4b88 & 3) * -8 + 0x20) + 0x70;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  param_1[9] = (uint)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3);
  return;
}

