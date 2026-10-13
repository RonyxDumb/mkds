/* Decompiled C draft; module arm9_ov003; ROM address 021d309c. No matching claim. */
#include "types.h"
#include "deps/021d309c_FUN_021d309c.h"

int FUN_021d309c(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  
  iVar1 = DAT_021d319c * param_1;
  iVar2 = FUN_021d1cd4(*(undefined4 *)(*DAT_021d31a0 + iVar1 + DAT_021d31a4));
  iVar6 = param_2 + 3 >> 2;
  *(short *)(iVar2 + 10) = (short)iVar6;
  uVar3 = func_0x0200ca9c(1);
  if (param_3 == 0) {
    iVar7 = *DAT_021d31a0 + DAT_021d319c * param_1;
    piVar8 = (int *)(iVar7 + DAT_021d31ac);
    if (piVar8 != (int *)(iVar7 + DAT_021d31a8)) {
      piVar9 = piVar8;
      do {
        piVar8 = (int *)*piVar9;
        if ((int)((uint)*(ushort *)(piVar8 + 2) + (uint)*(ushort *)((int)piVar8 + 10)) <=
            (int)((uint)*(ushort *)(piVar9 + 2) - iVar6)) {
          *(short *)(iVar2 + 8) = (short)((uint)*(ushort *)(piVar9 + 2) - iVar6);
          FUN_021d2e68(piVar9,iVar2);
          piVar8 = piVar9;
          break;
        }
        piVar9 = piVar8;
      } while (piVar8 != (int *)(*DAT_021d31a0 + iVar1 + DAT_021d31a8));
    }
    if (piVar8 == (int *)(*DAT_021d31a0 + iVar1 + DAT_021d31a8)) {
      func_0x0200fd1c();
    }
  }
  else {
    iVar4 = *DAT_021d31a0 + DAT_021d319c * param_1;
    iVar7 = iVar4 + DAT_021d31a8;
    if (iVar7 != iVar4 + DAT_021d31ac) {
      iVar4 = iVar7;
      do {
        iVar7 = *(int *)(iVar4 + 4);
        iVar5 = (uint)*(ushort *)(iVar4 + 8) + (uint)*(ushort *)(iVar4 + 10);
        if (iVar5 + iVar6 <= (int)(uint)*(ushort *)(iVar7 + 8)) {
          *(short *)(iVar2 + 8) = (short)iVar5;
          FUN_021d2e68(iVar7,iVar2);
          iVar7 = iVar4;
          break;
        }
        iVar4 = iVar7;
      } while (iVar7 != *DAT_021d31a0 + iVar1 + DAT_021d31ac);
    }
    if (iVar7 == *DAT_021d31a0 + iVar1 + DAT_021d31ac) {
      func_0x0200fd1c();
    }
  }
  *param_4 = (uint)*(ushort *)(iVar2 + 8);
  func_0x0200cae4(uVar3);
  return iVar2;
}

