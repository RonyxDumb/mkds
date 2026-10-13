/* Decompiled C draft; module arm9_ov000; ROM address 021afb58. No matching claim. */
#include "types.h"
#include "deps/021afb58_FUN_021afb58.h"

void FUN_021afb58(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  
  if ((((param_2 != DAT_021afc10) && (param_2 != *DAT_021afc14)) &&
      (iVar3 = FUN_021b00fc(param_2), iVar3 != 0)) && (iVar3 = FUN_021b0094(param_2), iVar3 == 0)) {
    uVar4 = func_0x0200f5ac();
    piVar2 = DAT_021afc18;
    uVar6 = 0;
    piVar7 = DAT_021afc18;
    do {
      uVar1 = (undefined2)(uVar4 >> 0x10);
      if (param_2 == *piVar7) {
        *(undefined2 *)(DAT_021afc1c + uVar6 * 0xc) = uVar1;
        func_0x0214d1fc(param_1,DAT_021afc18 + uVar6 * 3 + 1,6);
        return;
      }
      piVar7 = piVar7 + 3;
      uVar6 = uVar6 + 1;
    } while (uVar6 < 8);
    if (param_3 != 0) {
      uVar9 = 0;
      uVar6 = 0;
      uVar8 = 0;
      piVar7 = DAT_021afc18;
      do {
        uVar5 = uVar8;
        if (*piVar7 == 0) break;
        uVar5 = (uVar4 >> 0x10) - (uint)*(ushort *)((int)piVar7 + 10);
        if ((int)uVar9 < (int)(uVar5 * 0x10000) >> 0x10) {
          uVar9 = uVar5 & 0xffff;
          uVar6 = uVar8;
        }
        piVar7 = piVar7 + 3;
        uVar8 = uVar8 + 1;
        uVar5 = uVar6;
      } while (uVar8 < 8);
      DAT_021afc18[uVar5 * 3] = param_2;
      func_0x0214d1fc(param_1,piVar2 + uVar5 * 3 + 1,6);
      *(undefined2 *)(DAT_021afc1c + uVar5 * 0xc) = uVar1;
    }
  }
  return;
}

