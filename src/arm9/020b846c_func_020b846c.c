/* Decompiled C draft; module arm9; ROM address 020b846c. No matching claim. */
#include "types.h"
#include "deps/020b846c_func_020b846c.h"

undefined4 func_020b846c(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0xb;
  switch(param_1) {
  case 0:
    uVar4 = 0x12;
    break;
  case 1:
    uVar4 = 0x10;
    break;
  case 2:
    uVar4 = 0x17;
    break;
  case 3:
    uVar4 = 0x14;
    break;
  case 4:
    uVar4 = 0xd;
    break;
  case 5:
    iVar2 = GetCurrentPlayerRacerId();
    iVar2 = iVar2 * 0x210 +
            (*(uint *)(DAT_020b85d4 & 0xfffffffc) >> (DAT_020b85d4 & 3) * 8 |
            *(uint *)(DAT_020b85d4 & 0xfffffffc) << (DAT_020b85d4 & 3) * -8 + 0x20);
    uVar3 = iVar2 + 0x30;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * 0x1c +
            (*(uint *)(DAT_020b85d8 & 0xfffffffc) >> (DAT_020b85d8 & 3) * 8 |
            *(uint *)(DAT_020b85d8 & 0xfffffffc) << (DAT_020b85d8 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 3) {
      uVar3 = iVar2 + 0x38;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffff;
    }
    else {
      uVar3 = 0;
    }
    switch(uVar3) {
    case 0:
      goto LAB_020b8564;
    case 1:
      uVar4 = 0xd;
      break;
    case 2:
      uVar4 = 0xe;
      break;
    case 3:
LAB_020b8564:
      uVar4 = 0xf;
    }
    break;
  case 6:
    uVar4 = 0x16;
    break;
  case 7:
    uVar4 = 0x1b;
    break;
  case 8:
    uVar4 = 0x19;
    break;
  case 9:
    uVar4 = 0x13;
    break;
  case 10:
    uVar4 = 0x18;
    break;
  case 0xb:
    uVar4 = 0x11;
    break;
  case 0xc:
    uVar4 = 0x1a;
    break;
  case 0xd:
    uVar4 = 0x1e;
    break;
  case 0xe:
    uVar4 = 0x1c;
    break;
  case 0xf:
    uVar4 = 0x1d;
    break;
  case 0x10:
    uVar4 = 0x15;
    break;
  case 0x11:
    uVar4 = 0x1f;
    break;
  case 0x12:
    break;
  case 0x13:
  }
  return uVar4;
}

