/* Decompiled C draft; module arm9; ROM address 0214e258. No matching claim. */
#include "types.h"
#include "deps/0214e258_Rtc_Time_GetSeconds.h"

int Rtc_Time_GetSeconds(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 4 & 3;
  uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar2 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  return ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 0x3c +
         (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) * 0x3c +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
}

