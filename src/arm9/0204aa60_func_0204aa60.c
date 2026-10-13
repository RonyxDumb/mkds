/* Decompiled C draft; module arm9; ROM address 0204aa60. No matching claim. */
#include "types.h"
#include "deps/0204aa60_func_0204aa60.h"

int func_0204aa60(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0204aaa8 & 0xfffffffc) >> (DAT_0204aaa8 & 3) * 8 |
          *(uint *)(DAT_0204aaa8 & 0xfffffffc) << (DAT_0204aaa8 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  switch(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_0204aa94;
  case 2:
LAB_0204aa94:
    return (*(uint *)(DAT_0204aaac & 0xfffffffc) >> (DAT_0204aaac & 3) * 8 |
           *(uint *)(DAT_0204aaac & 0xfffffffc) << (DAT_0204aaac & 3) * -8 + 0x20) + DAT_0204aab0;
  case 3:
    break;
  default:
    return 0;
  }
  return uVar3 + 0x60;
}

