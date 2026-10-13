/* Decompiled C draft; module arm9_ov003; ROM address 021d19e0. No matching claim. */
#include "types.h"
#include "deps/021d19e0_FUN_021d19e0.h"

void FUN_021d19e0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  iVar1 = DAT_021d1adc * param_1;
  iVar2 = FUN_021d1cd4(*(undefined4 *)(*DAT_021d1ae0 + iVar1 + DAT_021d1ae4));
  uVar3 = func_0x0200ca9c(1);
  if (param_3 == 0) {
    iVar7 = *DAT_021d1ae0 + DAT_021d1adc * param_1;
    piVar8 = (int *)(iVar7 + DAT_021d1aec);
    if (piVar8 != (int *)(iVar7 + DAT_021d1ae8)) {
      piVar9 = piVar8;
      do {
        piVar8 = (int *)*piVar9;
        uVar4 = piVar9[2] + param_2 * -8;
        if (piVar8[2] + (uint)*(byte *)(piVar8 + 3) * 8 <= uVar4) {
          *(uint *)(iVar2 + 8) = uVar4;
          FUN_021d2e68(piVar9,iVar2);
          piVar8 = piVar9;
          break;
        }
        piVar9 = piVar8;
      } while (piVar8 != (int *)(*DAT_021d1ae0 + iVar1 + DAT_021d1ae8));
    }
    if (piVar8 == (int *)(*DAT_021d1ae0 + iVar1 + DAT_021d1ae8)) {
      func_0x0200fd1c();
    }
  }
  else {
    iVar5 = *DAT_021d1ae0 + DAT_021d1adc * param_1;
    iVar7 = iVar5 + DAT_021d1ae8;
    if (iVar7 != iVar5 + DAT_021d1aec) {
      iVar5 = iVar7;
      do {
        iVar7 = *(int *)(iVar5 + 4);
        iVar6 = *(int *)(iVar5 + 8) + (uint)*(byte *)(iVar5 + 0xc) * 8;
        if ((uint)(iVar6 + param_2 * 8) <= *(uint *)(iVar7 + 8)) {
          *(int *)(iVar2 + 8) = iVar6;
          FUN_021d2e68(iVar7,iVar2);
          iVar7 = iVar5;
          break;
        }
        iVar5 = iVar7;
      } while (iVar7 != *DAT_021d1ae0 + iVar1 + DAT_021d1aec);
    }
    if (iVar7 == *DAT_021d1ae0 + iVar1 + DAT_021d1aec) {
      func_0x0200fd1c();
    }
  }
  func_0x0200cae4(uVar3);
  *(char *)(iVar2 + 0xc) = (char)param_2;
  return;
}

