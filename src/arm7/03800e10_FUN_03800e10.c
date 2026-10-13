/* Decompiled C draft; module arm7; ROM address 03800e10. No matching claim. */
#include "types.h"
#include "deps/03800e10_FUN_03800e10.h"

void FUN_03800e10(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_03800eec;
  if ((param_1 == 0xb) && (param_3 != 0)) {
    uVar3 = DAT_03800eec + 8U & 3;
    uVar2 = *(uint *)(DAT_03800eec + 8U & 0xfffffffc);
    if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
      *(undefined4 *)(DAT_03800eec + 4) = param_2;
    }
    uVar3 = iVar1 + 4U & 3;
    uVar2 = *(uint *)(iVar1 + 4U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
                    /* WARNING: Could not recover jumptable at 0x03800e40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar3 < 0xd) {
      (*(code *)(&UNK_03800e48 + uVar3 * 4))();
      return;
    }
    uVar3 = iVar1 + 0xfcU & 3;
    uVar2 = *(uint *)(iVar1 + 0xfcU & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x10) == 0) {
      uVar3 = iVar1 + 8U & 3;
      uVar2 = *(uint *)(iVar1 + 8U & 0xfffffffc);
      *(uint *)(iVar1 + 8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
    }
    else {
      *(undefined4 *)(iVar1 + 8) = 0;
      uVar3 = iVar1 + 0xfcU & 3;
      uVar2 = *(uint *)(iVar1 + 0xfcU & 0xfffffffc);
      if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 4) == 0) {
        uVar3 = iVar1 + 0x48;
      }
      else {
        uVar3 = iVar1 + 0xecU & 3;
        uVar2 = *(uint *)(iVar1 + 0xecU & 0xfffffffc);
        uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      }
      FUN_037f9054(uVar3);
    }
  }
  return;
}

