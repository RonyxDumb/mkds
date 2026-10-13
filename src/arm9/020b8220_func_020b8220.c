/* Decompiled C draft; module arm9; ROM address 020b8220. No matching claim. */
#include "types.h"
#include "deps/020b8220_func_020b8220.h"

uint func_020b8220(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  switch(param_2) {
  case 0:
    return 0x1b;
  case 1:
    return 0x14;
  case 2:
    return 0x22;
  case 3:
    return 0x17;
  case 4:
    return 0x11;
  case 5:
    break;
  case 6:
    return 0x1f;
  case 7:
    return 0x20;
  case 8:
    return 0x21;
  case 9:
    return 0x1c;
  case 10:
    return 0x23;
  case 0xb:
    return 0x15;
  case 0xc:
    return 0x19;
  case 0xd:
    return 0x18;
  case 0xe:
    return 0x1d;
  case 0xf:
    return 0x1a;
  case 0x10:
    return 0x1e;
  case 0x11:
    return 0x16;
  default:
    return param_1;
  }
  iVar3 = (param_1 & 0xffff) * 0x210 +
          (*(uint *)(DAT_020b8374 & 0xfffffffc) >> (DAT_020b8374 & 3) * 8 |
          *(uint *)(DAT_020b8374 & 0xfffffffc) << (DAT_020b8374 & 3) * -8 + 0x20);
  uVar2 = iVar3 + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x1c +
          (*(uint *)(DAT_020b8378 & 0xfffffffc) >> (DAT_020b8378 & 3) * 8 |
          *(uint *)(DAT_020b8378 & 0xfffffffc) << (DAT_020b8378 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 3) {
    uVar2 = iVar3 + 0x38;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffff;
  }
  else {
    uVar2 = 0;
  }
  switch(uVar2) {
  case 0:
    break;
  case 1:
    return 0x11;
  case 2:
    return 0x12;
  case 3:
    break;
  default:
    return param_1;
  }
  return 0x13;
}

