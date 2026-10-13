/* Decompiled C draft; module arm9; ROM address 021055b0. No matching claim. */
#include "types.h"
#include "deps/021055b0_func_021055b0.h"

void func_021055b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  short sVar2;
  longlong lVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  bool bVar7;
  int iVar8;
  bool bVar9;
  
  uVar5 = DAT_021057ec;
  uVar1 = DAT_021057e0;
  piVar4 = (int *)(*(uint *)(DAT_021057c8 & 0xfffffffc) >> (DAT_021057c8 & 3) * 8 |
                  *(uint *)(DAT_021057c8 & 0xfffffffc) << (DAT_021057c8 & 3) * -8 + 0x20);
  if (piVar4 == (int *)0x0) {
    uVar1 = DAT_021057cc + 0xcU & 3;
    uVar5 = *(uint *)(DAT_021057cc + 0xcU & 0xfffffffc);
    if (uVar5 >> uVar1 * 8 != 0 || uVar5 << uVar1 * -8 + 0x20 != 0) {
      return;
    }
    func_0210d5c0();
    return;
  }
  if ((param_1 != 0) && (param_1 != 0x32)) {
    return;
  }
  bVar9 = param_1 == 0x32;
  if (bVar9) {
    piVar4 = DAT_021057d0;
  }
  bVar7 = false;
  if (bVar9) {
    piVar4 = (int *)(*(uint *)((uint)piVar4 & 0xfffffffc) >> ((uint)piVar4 & 3) * 8 |
                    *(uint *)((uint)piVar4 & 0xfffffffc) << ((uint)piVar4 & 3) * -8 + 0x20);
  }
  uVar6 = 0x78;
  if (!bVar9) {
    piVar4 = (int *)(*(uint *)((uint)DAT_021057d4 & 0xfffffffc) >> ((uint)DAT_021057d4 & 3) * 8 |
                    *(uint *)((uint)DAT_021057d4 & 0xfffffffc) <<
                    ((uint)DAT_021057d4 & 3) * -8 + 0x20);
  }
  if ((int)piVar4 < 5) {
    switch(piVar4) {
    case (int *)0x0:
      uVar6 = 0xf;
      break;
    case (int *)0x1:
      uVar6 = 0x1e;
      bVar7 = true;
      break;
    case (int *)0x2:
      uVar6 = 0x2d;
      break;
    case (int *)0x3:
      uVar6 = 0x46;
      break;
    case (int *)0x4:
      uVar6 = 0x2d;
    }
  }
  else {
    iVar8 = (int)piVar4 - 5;
    lVar3 = (longlong)DAT_021057dc *
            (longlong)
            ((int)((ulonglong)((longlong)DAT_021057d8 * (longlong)iVar8) >> 0x20) - (iVar8 >> 0x1f))
    ;
    param_3 = (undefined4)((ulonglong)lVar3 >> 0x20);
    switch(iVar8 - (int)lVar3) {
    case 0:
      uVar6 = 0x1e;
      break;
    case 1:
      uVar6 = 0x2d;
      break;
    case 2:
      uVar6 = 0x46;
      break;
    case 3:
      uVar6 = 0x5f;
      bVar7 = true;
      break;
    case 4:
      uVar6 = 0x46;
      break;
    case 5:
      uVar6 = 0x2d;
    }
  }
  if (param_1 == 0x32) {
    if (*(uint *)(DAT_021057e0 & 0xfffffffc) >> (DAT_021057e0 & 3) * 8 != 0 ||
        *(uint *)(DAT_021057e0 & 0xfffffffc) << (DAT_021057e0 & 3) * -8 + 0x20 != 0) {
      func_0212c6f0(DAT_021057e0,0,param_3);
    }
    NNSi_MaybeSndPlayerStartSeq(uVar1,4,0);
    if (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 != 0 ||
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20 != 0) {
      func_0212c554(uVar1,*DAT_021057e4,uVar6);
    }
    *DAT_021057d0 =
         (*(uint *)((uint)DAT_021057d0 & 0xfffffffc) >> ((uint)DAT_021057d0 & 3) * 8 |
         *(uint *)((uint)DAT_021057d0 & 0xfffffffc) << ((uint)DAT_021057d0 & 3) * -8 + 0x20) + 1;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  if ((bVar7) && (sVar2 = *DAT_021057e8, sVar2 != 0xff)) {
    if (*(uint *)(DAT_021057ec & 0xfffffffc) >> (DAT_021057ec & 3) * 8 != 0 ||
        *(uint *)(DAT_021057ec & 0xfffffffc) << (DAT_021057ec & 3) * -8 + 0x20 != 0) {
      func_0212c6f0(DAT_021057ec,0,param_3);
    }
    NNSi_MaybeSndPlayerStartSeq(uVar5,4,sVar2);
  }
  *DAT_021057d4 =
       (*(uint *)((uint)DAT_021057d4 & 0xfffffffc) >> ((uint)DAT_021057d4 & 3) * 8 |
       *(uint *)((uint)DAT_021057d4 & 0xfffffffc) << ((uint)DAT_021057d4 & 3) * -8 + 0x20) + 1;
  return;
}

