/* Decompiled C draft; module arm9; ROM address 0214a088. No matching claim. */
#include "types.h"
#include "deps/0214a088_func_0214a088.h"

int func_0214a088(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (*DAT_0214a104 & 0x1f00) >> 8;
  switch((*(uint *)(DAT_0214a100 & 0xfffffffc) >> (DAT_0214a100 & 3) * 8 |
         *(uint *)(DAT_0214a100 & 0xfffffffc) << (DAT_0214a100 & 3) * -8 + 0x20) & 7) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_0214a0d8;
  case 4:
    goto LAB_0214a0d8;
  case 5:
LAB_0214a0d8:
    if ((*DAT_0214a104 & 0x80) == 0) {
      iVar1 = uVar2 * 0x800;
    }
    else {
      iVar1 = uVar2 * 0x4000;
    }
    return iVar1 + 0x6200000;
  case 6:
    return 0;
  default:
    return 0;
  }
  return uVar2 * 0x800 + 0x6200000;
}

