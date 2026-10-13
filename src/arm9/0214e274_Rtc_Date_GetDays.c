/* Decompiled C draft; module arm9; ROM address 0214e274. No matching claim. */
#include "types.h"
#include "deps/0214e274_Rtc_Date_GetDays.h"

int Rtc_Date_GetDays(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  uint uVar6;
  uint uVar4;
  
  uVar6 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (((((uVar6 < 100) &&
        (uVar4 = param_1 + 4 & 3, uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc),
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20, uVar4 != 0)) && (uVar4 < 0xd)) &&
      ((uVar3 = param_1 + 8 & 3, uVar2 = *(uint *)(param_1 + 8 & 0xfffffffc),
       uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20, uVar3 != 0 && (uVar3 < 0x20)))) &&
     ((uVar2 = param_1 + 0xc & 3, uVar1 = *(uint *)(param_1 + 0xc & 0xfffffffc),
      (int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 7 && ((uVar4 != 0 && (uVar4 < 0xd))))
     )) {
    uVar2 = iRam0214e300 + uVar4 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    iVar5 = (uVar3 - 1) + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    if ((2 < uVar4) && ((uVar6 & 3) == 0)) {
      iVar5 = iVar5 + 1;
    }
    return uVar6 * iRam0214e304 + iVar5 + (uVar6 + 3 >> 2);
  }
  return -1;
}

