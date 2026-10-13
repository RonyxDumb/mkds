/* Decompiled C draft; module arm9; ROM address 020b7fd8. No matching claim. */
#include "types.h"
#include "deps/020b7fd8_GetRacerCharacterIdAndUnk.h"

void GetRacerCharacterIdAndUnk(int param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 * 0x30 +
          (*(uint *)(DAT_020b80a0 & 0xfffffffc) >> (DAT_020b80a0 & 3) * 8 |
          *(uint *)(DAT_020b80a0 & 0xfffffffc) << (DAT_020b80a0 & 3) * -8 + 0x20) + 0x68;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *param_2 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  switch(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
         *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_020b8040;
  case 2:
    break;
  case 3:
    goto LAB_020b8040;
  case 4:
    goto LAB_020b804c;
  case 5:
LAB_020b804c:
    *param_3 = 9;
    return;
  case 6:
    goto LAB_020b8058;
  case 7:
LAB_020b8058:
    *param_3 = 10;
    return;
  case 8:
    break;
  case 9:
LAB_020b8040:
    *param_3 = 8;
    return;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
    uVar3 = (*(uint *)(DAT_020b80a4 & 0xfffffffc) >> (DAT_020b80a4 & 3) * 8 |
            *(uint *)(DAT_020b80a4 & 0xfffffffc) << (DAT_020b80a4 & 3) * -8 + 0x20) + param_1 * 4 +
            0x10c;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    iVar2 = (int)uVar3 >> 0x1f;
    *param_2 = ((uVar3 * 0x40000000 + iVar2 >> 0x1e | iVar2 << 2) - iVar2) + 0xc;
    if ((int)uVar3 < 4) {
      *param_3 = 5;
    }
    else {
      *param_3 = 6;
    }
    return;
  default:
    return;
  }
  *param_3 = 7;
  return;
}

