/* Decompiled C draft; module arm9_ov000; ROM address 021ac4f4. No matching claim. */
#include "types.h"
#include "deps/021ac4f4_FUN_021ac4f4.h"

void FUN_021ac4f4(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar1 = (*(code *)*DAT_021ac644)(param_4 * 0x16);
  if (iVar1 != 0) {
    func_0x0214d168(iVar1,0,param_4 * 0x16);
    iVar2 = param_4 * 2;
    iVar4 = iVar1 + iVar2;
    iVar5 = iVar4 + iVar2;
    iVar6 = iVar5 + iVar2;
    iVar7 = iVar6 + iVar2;
    iVar8 = iVar7 + iVar2;
    iVar2 = iVar8 + iVar2;
    iVar3 = thunk_FUN_021acecc(param_5,param_4);
    *(undefined2 *)(iVar1 + iVar3 * 2) = 1;
    FUN_021ac718(iVar4,iVar1,param_5,param_4,iVar5);
    FUN_021acbf8(iVar6,iVar1,iVar4,param_4);
    FUN_021acccc(iVar4,iVar6,1,param_4);
    FUN_021ac900(iVar4,iVar4,param_5,0,param_4,iVar2);
    FUN_021acbf8(iVar5,param_2,iVar1,param_4);
    FUN_021ac900(0,iVar5,param_5,iVar5,param_4,iVar2);
    FUN_021ac900(0,iVar1,param_5,param_1,param_4,iVar2);
    uVar9 = 0;
    if (iVar3 * 0x10 != 0) {
      do {
        FUN_021ac650(param_1,iVar8,1,param_4,iVar3,param_5,iVar4,iVar6,iVar7);
        if ((DAT_021ac648 >> (uVar9 & 0xf) &
            (uint)*(ushort *)(param_3 + ((iVar3 - ((int)uVar9 >> 4)) + -1) * 2)) != 0) {
          FUN_021ac650(param_1,iVar8,iVar5,param_4,iVar3,param_5,iVar4,iVar6,iVar7);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < (uint)(iVar3 * 0x10));
    }
    FUN_021ac650(param_1,iVar8,0,param_4,iVar3,param_5,iVar4,iVar6,iVar7);
    (*(code *)*DAT_021ac64c)(iVar1);
  }
  return;
}

