/* Decompiled C draft; module arm9; ROM address 02046648. No matching claim. */
#include "types.h"
#include "deps/02046648_HasSomeSecretFlag.h"

undefined4 HasSomeSecretFlag(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(DAT_02046738 & 0xfffffffc) >> (DAT_02046738 & 3) * 8 |
          *(uint *)(DAT_02046738 & 0xfffffffc) << (DAT_02046738 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 0x1f8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xff;
  if (*(char *)(uVar3 + 0x23f) != '\0') {
    uVar4 = 3;
  }
  switch(param_1) {
  case 0:
    return 1;
  case 1:
    return 1;
  case 2:
    iVar2 = CheckSecretFlag(uVar4);
    if (iVar2 != 0) {
      return 1;
    }
    break;
  case 3:
    iVar2 = CheckSecretFlag(uVar4 + 4);
    if (iVar2 != 0) {
      return 1;
    }
    break;
  case 4:
    return 1;
  case 5:
    return 1;
  case 6:
    iVar2 = CheckSecretFlag(uVar4 + 8);
    if (iVar2 != 0) {
      return 1;
    }
    break;
  case 7:
    iVar2 = CheckSecretFlag(uVar4 + 0xc);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}

