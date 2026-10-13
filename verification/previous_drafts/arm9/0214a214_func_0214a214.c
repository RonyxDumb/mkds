/* Decompiled C draft; module arm9; ROM address 0214a214. No matching claim. */
#include "types.h"
#include "deps/0214a214_func_0214a214.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int func_0214a214(void)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = ((_DAT_04000000 & 0x38000000) >> 0x1b) * 0x10000;
  uVar1 = (*DAT_0214a29c & 0x1f00) >> 8;
  switch(_DAT_04000000 & 7) {
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
    if ((*DAT_0214a29c & 0x80) == 0) {
      iVar2 = iVar2 + 0x6000000 + uVar1 * 0x800;
    }
    else {
      iVar2 = uVar1 * 0x4000 + 0x6000000;
    }
    return iVar2;
  case 6:
    return 0x6000000;
  default:
    return 0;
  }
  return iVar2 + 0x6000000 + uVar1 * 0x800;
}

