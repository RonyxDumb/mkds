/* Decompiled C draft; module arm9; ROM address 02110e58. No matching claim. */
#include "types.h"
#include "deps/02110e58_func_02110e58.h"

uint func_02110e58(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar3;
  
  uVar5 = *(uint *)(DAT_02110fb0 & 0xfffffffc) >> (DAT_02110fb0 & 3) * 8 |
          *(uint *)(DAT_02110fb0 & 0xfffffffc) << (DAT_02110fb0 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 8 & 3;
  uVar1 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  uVar2 = 0xffffffff;
  switch(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) {
  case 0:
    goto LAB_02110e90;
  case 1:
    uVar3 = DAT_02110fb4 + 0xcU & 3;
    uVar2 = *(uint *)(DAT_02110fb4 + 0xcU & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
    uVar3 = func_020c7108();
    if (uVar2 == uVar3) {
      uVar2 = 0;
    }
    break;
  case 2:
    uVar3 = DAT_02110fb4 + 0xcU & 3;
    uVar2 = *(uint *)(DAT_02110fb4 + 0xcU & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
    break;
  case 3:
    uVar3 = uVar5 + 0x1c & 3;
    uVar2 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
    if ((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) == 1) {
      uVar3 = DAT_02110fb4 + 0xcU & 3;
      uVar2 = *(uint *)(DAT_02110fb4 + 0xcU & 0xfffffffc);
      if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 2;
      }
    }
    else {
      uVar3 = DAT_02110fb4 + 0xcU & 3;
      uVar2 = *(uint *)(DAT_02110fb4 + 0xcU & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if (uVar3 == 0) {
        iVar4 = GetDriverPlace((short)*(char *)(uVar5 + 0x62));
        uVar2 = (uint)(iVar4 != 1);
      }
      else if ((uVar3 == 1) || (uVar2 = param_3, uVar3 == 2)) {
        uVar2 = 2;
      }
    }
    break;
  case 4:
    uVar3 = DAT_02110fb4 + 0xcU & 3;
    uVar2 = *(uint *)(DAT_02110fb4 + 0xcU & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 2;
    }
    break;
  case 5:
LAB_02110e90:
    uVar3 = DAT_02110fb4 + 0xcU & 3;
    uVar2 = *(uint *)(DAT_02110fb4 + 0xcU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      iVar4 = GetDriverPlace((short)*(char *)(uVar5 + 0x62));
      uVar2 = (uint)(iVar4 != 1);
    }
    else if ((uVar3 == 1) || (uVar2 = param_3, uVar3 == 2)) {
      uVar2 = 2;
    }
  }
  return uVar2;
}

