/* Decompiled C draft; module arm9; ROM address 0206b4d0. No matching claim. */
#include "types.h"
#include "deps/0206b4d0_StructMQRacerEntry_SomeFn_65.h"

undefined4 StructMQRacerEntry_SomeFn_65(int param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  bool bVar5;
  uint uVar4;
  
  uVar4 = param_1 + 0x4cU & 3;
  uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 & 0x400000) == 0) {
    uVar3 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x200) == 0) {
      bVar5 = true;
      if (((uVar4 & uRam0206b5b0) == 0) &&
         (uVar4 = param_1 + 0x48U & 3, uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
         ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x1800) == 0)) {
        uVar4 = param_1 + 0x180U & 3;
        uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        bVar2 = false;
        if ((uVar4 != 0) && ((uVar4 != 1 && (uVar4 != 2)))) {
          bVar2 = true;
        }
        if (!bVar2) {
          bVar5 = false;
        }
      }
      if (bVar5) {
        bVar5 = false;
      }
      else {
        bVar5 = true;
      }
    }
    else {
      uVar3 = param_1 + 0x180U & 3;
      uVar1 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
      if (((uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) &&
          (uVar3 = param_1 + 0x48U & 3, uVar1 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
          ((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar4 & uRam0206b5b0) == 0)) {
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
    }
  }
  else {
    bVar5 = false;
  }
  if (bVar5) {
    StructMQRacerEntry_SomeFn_56(param_1);
    uVar4 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x200) != 0) {
      uVar4 = param_1 + 0x514U & 3;
      uVar3 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
      uVar1 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar1 + 0x2c;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(uint *)(uVar1 + 0x2c) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) ^ 0x10;
    }
    return 1;
  }
  return 0;
}

