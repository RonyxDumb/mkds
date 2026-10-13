/* Decompiled C draft; module arm9; ROM address 0214a194. No matching claim. */
#include "types.h"
#include "deps/0214a194_func_0214a194.h"

int func_0214a194(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (*DAT_0214a210 & 0x1f00) >> 8;
  switch((*(uint *)(DAT_0214a20c & 0xfffffffc) >> (DAT_0214a20c & 3) * 8 |
         *(uint *)(DAT_0214a20c & 0xfffffffc) << (DAT_0214a20c & 3) * -8 + 0x20) & 7) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    if ((*DAT_0214a210 & 0x80) == 0) {
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

