/* Decompiled C draft; module arm9; ROM address 0206be54. No matching claim. */
#include "types.h"
#include "deps/0206be54_func_0206be54.h"

undefined4 func_0206be54(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 & 0x400000) == 0) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x200) == 0) {
      if ((param_2 == 1) || (param_2 == 2)) {
        bVar1 = true;
        if (((uVar5 & uRam0206bf84) == 0) &&
           (uVar5 = param_1 + 0x48U & 3, uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
           ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x1800) == 0)) {
          uVar5 = param_1 + 0x180U & 3;
          uVar4 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
          uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          bVar3 = false;
          if (((uVar5 != 0) && (uVar5 != 1)) && (uVar5 != 2)) {
            bVar3 = true;
          }
          if (!bVar3) {
            bVar1 = false;
          }
        }
        bVar1 = !bVar1;
      }
      else {
        bVar1 = true;
        if (((uVar5 & uRam0206bf84) == 0) &&
           (uVar5 = param_1 + 0x48U & 3, uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
           ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x1800) == 0)) {
          uVar5 = param_1 + 0x180U & 3;
          uVar4 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
          uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
          bVar3 = false;
          if ((uVar5 != 0) && ((uVar5 != 1 && (uVar5 != 2)))) {
            bVar3 = true;
          }
          if (!bVar3) {
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
    }
    else {
      uVar4 = param_1 + 0x180U & 3;
      uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
      if (((uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) &&
          (uVar4 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
          ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar5 & uRam0206bf84) == 0)) {
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
  DriverContext_HandleSomeCollision(param_1);
  return 1;
}

