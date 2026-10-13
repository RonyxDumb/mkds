/* Decompiled C draft; module arm9; ROM address 020be950. No matching claim. */
#include "types.h"
#include "deps/020be950_OamBuffer_SomeFn_0.h"

void OamBuffer_SomeFn_0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = func_020b1dbc();
  uVar1 = DAT_020be9d0;
  switch(uVar2) {
  case 0:
    OamBuffer_SomeFn_1(param_1);
    return;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    goto switchD_020be960_default;
  }
  iVar6 = 0;
  uVar4 = *(uint *)(DAT_020be9d0 & 0xfffffffc) >> (DAT_020be9d0 & 3) * 8 |
          *(uint *)(DAT_020be9d0 & 0xfffffffc) << (DAT_020be9d0 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 0xc & 3;
  uVar3 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  if ((int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) < 1) {
    return;
  }
  do {
    uVar5 = uVar4 + iVar6 * 4 + 0x198;
    uVar3 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    (*(code *)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20))(param_1);
    uVar5 = uVar1 & 3;
    uVar3 = *(uint *)(uVar1 & 0xfffffffc);
    uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
    iVar6 = iVar6 + 1;
    uVar5 = uVar4 + 0xc & 3;
    uVar3 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  } while (iVar6 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20));
switchD_020be960_default:
  return;
}

