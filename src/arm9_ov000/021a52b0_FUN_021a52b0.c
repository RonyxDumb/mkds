/* Decompiled C draft; module arm9_ov000; ROM address 021a52b0. No matching claim. */
#include "types.h"
#include "deps/021a52b0_FUN_021a52b0.h"

void FUN_021a52b0(int param_1)

{
  int *piVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int extraout_r1;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar5 = 0x14;
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0:
    if (*(int *)(*DAT_021a5468 + DAT_021a546c) == 5) {
      FUN_021a57fc(6);
      FUN_021a58a4(0,0,0,DAT_021a5470);
    }
    piVar1 = DAT_021a5468;
    iVar4 = *(int *)(*DAT_021a5468 + DAT_021a546c);
    if (iVar4 == 6) {
      *(undefined2 *)(*DAT_021a5468 + DAT_021a5474) = 7;
      if (*(short *)(param_1 + 8) == 5) {
        func_0x0200ee3c(*(undefined4 *)(*piVar1 + DAT_021a5478),
                        *(undefined2 *)(*piVar1 + DAT_021a547c));
        iVar7 = 0;
        iVar5 = param_1;
        iVar4 = param_1;
        if (*(short *)(param_1 + 0xe) != 0) {
          do {
            FUN_021a671c(*(undefined4 *)(iVar5 + 0x10),*(undefined2 *)(iVar4 + 0x50));
            FUN_021a586c(7,0,*(undefined4 *)(iVar5 + 0x10),param_1,DAT_021a5480);
            iVar7 = iVar7 + 1;
            iVar5 = iVar5 + 4;
            iVar4 = iVar4 + 2;
          } while (iVar7 < (int)(uint)*(ushort *)(param_1 + 0xe));
        }
      }
      if (((*(uint *)(*DAT_021a5468 + DAT_021a5484) & DAT_021a5488) == DAT_021a5488) &&
         (iVar5 = FUN_021a4b98(*(uint *)(*DAT_021a5468 + DAT_021a5484) & DAT_021a548c), iVar5 != 0))
      {
        uVar6 = *(undefined4 *)(*DAT_021a5468 + DAT_021a5490);
        func_0x02133274(uVar6);
        if (extraout_r1 == 0) {
          FUN_021a586c(8,0,uVar6,0,DAT_021a5494);
        }
      }
      sVar2 = FUN_021a4bbc(*(undefined2 *)(param_1 + 10));
      uVar3 = FUN_021a58dc(0x20 - sVar2);
      piVar1 = DAT_021a5468;
      *(short *)(*DAT_021a5468 + DAT_021a5498) = (short)((1 << (uVar3 & 0xff)) >> 1);
      func_0x0200ee3c(*(undefined4 *)(*piVar1 + DAT_021a5478),
                      *(undefined2 *)(*piVar1 + DAT_021a547c));
      piVar1 = DAT_021a5468;
      *(int *)(*DAT_021a5468 + DAT_021a5490) = *(int *)(*DAT_021a5468 + DAT_021a5490) + 1;
      iVar5 = func_0x021438f0(DAT_021a549c,*piVar1 + DAT_021a5478);
    }
    else if (iVar4 == 7) {
      iVar5 = func_0x021438a8(DAT_021a54a0);
    }
    else if (iVar4 == 0xd) {
      FUN_021a574c();
      return;
    }
    if (iVar5 != 2) {
      if ((iVar5 != 3) && (iVar5 == 8)) {
        FUN_021a57fc(0xc);
        FUN_021a58a4(1,0,0,DAT_021a54a4);
        return;
      }
      FUN_021a57fc(0xb);
      FUN_021a58a4(7,0,0,DAT_021a54a8);
      return;
    }
    break;
  case 1:
    FUN_021a574c();
    return;
  default:
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,0,0,DAT_021a54ac);
  }
  return;
}

