/* Decompiled C draft; module arm9; ROM address 0207a948. No matching claim. */
#include "types.h"
#include "deps/0207a948_GetDriverMaybeSfxPosition.h"

void GetDriverMaybeSfxPosition(undefined4 *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar3;
  
  uVar2 = param_2 * iRam0207a970 +
          (*(uint *)(uRam0207a96c & 0xfffffffc) >> (uRam0207a96c & 3) * 8 |
          *(uint *)(uRam0207a96c & 0xfffffffc) << (uRam0207a96c & 3) * -8 + 0x20) + 0x508;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar3 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar4 = puVar3[1];
  uVar5 = puVar3[2];
  *param_1 = *puVar3;
  param_1[1] = uVar4;
  param_1[2] = uVar5;
  return;
}

