/* Decompiled C draft; module arm9; ROM address 020680e0. No matching claim. */
#include "types.h"
#include "deps/020680e0_StructMQRacerEntry_SomeFn_72.h"

void StructMQRacerEntry_SomeFn_72(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar6;
  uint uVar5;
  
  uVar5 = param_1 + 0x4cU & 3;
  uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((uVar5 & 0x400000) == 0) {
    uVar4 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x200) == 0) {
      bVar6 = true;
      if (((uVar5 & uRam020681dc) == 0) &&
         (uVar5 = param_1 + 0x48U & 3, uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
         ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x1800) == 0)) {
        uVar5 = param_1 + 0x180U & 3;
        uVar4 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
        uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
        bVar1 = false;
        if ((uVar5 != 0) && ((uVar5 != 1 && (uVar5 != 2)))) {
          bVar1 = true;
        }
        if (!bVar1) {
          bVar6 = false;
        }
      }
      if (bVar6) {
        bVar6 = false;
      }
      else {
        bVar6 = true;
      }
    }
    else {
      uVar4 = param_1 + 0x180U & 3;
      uVar2 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
      if (((uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) &&
          (uVar4 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
          ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x1800) == 0)) &&
         ((uVar5 & uRam020681dc) == 0)) {
        bVar6 = true;
      }
      else {
        bVar6 = false;
      }
    }
  }
  else {
    bVar6 = false;
  }
  if (bVar6) {
    StructMQRacerEntry_SomeFn_59(param_1,(undefined4 *)(uintptr_t)(param_2),0);
    uVar5 = param_1 + 0x7cU & 3;
    uVar4 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 1) != 0) {
      iVar3 = GetGlobalRK();
      uVar5 = iVar3 + 0x14U & 3;
      uVar4 = *(uint *)(iVar3 + 0x14U & 0xfffffffc);
      *(uint *)(iVar3 + 0x14) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 1;
    }
    uVar5 = param_1 + 0x48U & 3;
    uVar4 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x20000;
    return;
  }
  return;
}

