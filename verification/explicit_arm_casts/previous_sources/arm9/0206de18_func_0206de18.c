/* Decompiled C draft; module arm9; ROM address 0206de18. No matching claim. */
#include "types.h"
#include "deps/0206de18_func_0206de18.h"

undefined4 func_0206de18(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  bool bVar5;
  uint uVar6;
  uint uVar4;
  
  uVar4 = param_2 + 0x4cU & 3;
  uVar3 = *(uint *)(param_2 + 0x4cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x400000) == 0) {
    uVar3 = param_2 + 0x7cU & 3;
    uVar6 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
    if (((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0x200) == 0) {
      bVar1 = true;
      if (((uVar4 & DAT_0206dfcc) == 0) &&
         (uVar4 = param_2 + 0x48U & 3, uVar3 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
         ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x1800) == 0)) {
        uVar4 = param_2 + 0x180U & 3;
        uVar3 = *(uint *)(param_2 + 0x180U & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        bVar5 = false;
        if ((uVar4 != 0) && ((uVar4 != 1 && (uVar4 != 2)))) {
          bVar5 = true;
        }
        if (!bVar5) {
          bVar1 = false;
        }
      }
      if (bVar1) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
    else {
      uVar3 = param_2 + 0x180U & 3;
      uVar6 = *(uint *)(param_2 + 0x180U & 0xfffffffc);
      if (((uVar6 >> uVar3 * 8 == 0 && uVar6 << uVar3 * -8 + 0x20 == 0) &&
          (uVar3 = param_2 + 0x48U & 3, uVar6 = *(uint *)(param_2 + 0x48U & 0xfffffffc),
          ((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar4 & DAT_0206dfcc) == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return 0;
  }
  StructMQRacerEntry_SomeFn_59(param_2,param_3,1);
  DriverContext_MaybeQueuePlaySfx(param_2,0xe8,0x7f,0);
  uVar4 = param_2 + 0x7cU & 3;
  uVar3 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x200) != 0) {
    uVar4 = param_2 + 0x514U & 3;
    uVar3 = *(uint *)(param_2 + 0x514U & 0xfffffffc);
    uVar6 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    uVar4 = uVar6 + 0x2c;
    uVar3 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) ^ 0x80;
  }
  uVar4 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar2 = 1;
  uVar4 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x200;
  if (uVar4 == 0) {
    return uVar2;
  }
  switch(*(undefined2 *)(param_2 + 0x74)) {
  case 0:
    if (uVar4 != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar6 + 0x2c;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) ^ 0x200;
    }
    return uVar2;
  case 1:
    if (uVar4 != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar6 + 0x2c;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) ^ 0x400;
    }
    return uVar2;
  case 2:
    if (uVar4 != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar6 + 0x2c;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) ^ 0x800;
    }
    return uVar2;
  case 3:
    if (uVar4 != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar6 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar6 + 0x2c;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar6 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) ^ 0x1000;
    }
  }
  return uVar2;
}

