/* Decompiled C draft; module arm9; ROM address 020a5268. No matching claim. */
#include "types.h"
#include "deps/020a5268_func_020a5268.h"

undefined4 func_020a5268(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint local_28;
  int local_24;
  uint local_20;
  
  iVar1 = GetDriverEntry();
  func_020a2378();
  uVar2 = func_020a1154(param_2);
  if ((uVar2 < 3) && (iVar3 = func_020a1154(param_1), iVar3 != 0)) {
    iVar3 = func_020a2378();
    iVar3 = param_1 * 0x38 + iVar3;
    iVar4 = func_020a2204(param_1);
    if (iVar4 == 0) {
      uVar2 = 0;
    }
    else {
      iVar4 = func_020a1154(param_1);
      uVar2 = iVar3 + iVar4 * 4 + 0x10;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    }
    iVar4 = func_020a1154(param_1);
    if (iVar4 == 0) {
      uVar8 = 0;
    }
    else {
      iVar4 = func_020a1154(param_1);
      uVar8 = iVar3 + (iVar4 + -1) * 4 + 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
    iVar4 = func_020a1154(param_1);
    if ((iVar4 != 0) && (uVar8 != 0)) {
      iVar4 = func_020a2204(param_1);
      if ((iVar4 == 0) || (uVar2 == 0)) {
        MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
      }
      else {
        iVar4 = func_020a1154(param_1);
        *(uint *)(iVar3 + iVar4 * 4 + 0x10) = uVar8;
        MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
        iVar4 = func_020a1154(param_1);
        *(uint *)(iVar3 + iVar4 * 4 + 0x10) = uVar2;
      }
    }
    if (uVar8 != 0) {
      iVar3 = func_020a2378();
      iVar3 = param_2 * 0x38 + iVar3;
      iVar4 = func_020a1154(param_2);
      iVar5 = func_020a1154(param_2);
      uVar2 = iVar3 + iVar5 * 4 + 0x10;
      uVar7 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(uint *)(iVar3 + (iVar4 + 1) * 4 + 0x10) = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
      iVar4 = func_020a1154(param_2);
      *(uint *)(iVar3 + iVar4 * 4 + 0x10) = uVar8;
      MaybeUpdateDriverBalloonShineCount(param_2,1);
      func_020a2e68(uVar8);
      func_020a2e58(uVar8,param_2);
      uVar2 = func_020a1154(param_2);
      if ((1 < uVar2) && (iVar4 = func_020a2204(param_2), iVar4 != 0)) {
        *(undefined4 *)(iVar3 + 0x34) = 4;
      }
      uVar6 = func_0208b7bc(0x7a,iVar1 + 0x80);
      func_02081f10(uVar6,*(undefined2 *)(iVar1 + 0x74),0x20);
      uVar6 = func_0208b7bc(0x7b,iVar1 + 0x80);
      func_02081f10(uVar6,*(undefined2 *)(iVar1 + 0x74),0x20);
      uVar6 = GetDriverEntry(param_2);
      func_020d26ec(uVar6,uRam020a5604);
      iVar1 = func_020a1154(param_1);
      if (iVar1 == 0) {
        func_020a16d0(param_1);
      }
      return 1;
    }
  }
  else {
    iVar3 = func_020a2378();
    iVar3 = param_1 * 0x38 + iVar3;
    iVar4 = func_020a2204(param_1);
    if (iVar4 == 0) {
      uVar2 = 0;
    }
    else {
      iVar4 = func_020a1154(param_1);
      uVar2 = iVar3 + iVar4 * 4 + 0x10;
      uVar8 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20;
    }
    iVar4 = func_020a1154(param_1);
    if (iVar4 == 0) {
      uVar8 = 0;
    }
    else {
      iVar4 = func_020a1154(param_1);
      uVar8 = iVar3 + (iVar4 + -1) * 4 + 0x10;
      uVar7 = uVar8 & 3;
      uVar8 = *(uint *)(uVar8 & 0xfffffffc);
      uVar8 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
    }
    iVar4 = func_020a1154(param_1);
    if ((iVar4 != 0) && (uVar8 != 0)) {
      iVar4 = func_020a2204(param_1);
      if ((iVar4 == 0) || (uVar2 == 0)) {
        MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
      }
      else {
        iVar4 = func_020a1154(param_1);
        *(uint *)(iVar3 + iVar4 * 4 + 0x10) = uVar8;
        MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
        iVar4 = func_020a1154(param_1);
        *(uint *)(iVar3 + iVar4 * 4 + 0x10) = uVar2;
      }
    }
    if (uVar8 != 0) {
      if (param_1 ==
          *(char *)((*(uint *)(uRam020a55f8 & 0xfffffffc) >> (uRam020a55f8 & 3) * 8 |
                    *(uint *)(uRam020a55f8 & 0xfffffffc) << (uRam020a55f8 & 3) * -8 + 0x20) + 0x62))
      {
        func_020a2ebc(uVar8,0);
      }
      else {
        uVar2 = iVar1 + 0x80U & 3;
        uVar7 = *(uint *)(iVar1 + 0x80U & 0xfffffffc);
        local_28 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
        iVar3 = func_020a23a0(iVar1);
        uVar2 = iVar1 + 0x84U & 3;
        uVar7 = *(uint *)(iVar1 + 0x84U & 0xfffffffc);
        local_24 = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar3 + iRam020a55fc;
        uVar2 = iVar1 + 0x88U & 3;
        uVar7 = *(uint *)(iVar1 + 0x88U & 0xfffffffc);
        local_20 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
        *(ushort *)(uVar8 + 2) = *(ushort *)(uVar8 + 2) & 0xfffb;
        *(ushort *)(uVar8 + 2) = *(ushort *)(uVar8 + 2) & 0xfffd;
        *(ushort *)(uVar8 + 2) = *(ushort *)(uVar8 + 2) & 0xfff7;
        *(undefined2 *)(uVar8 + 0x66) = 0x1f;
        func_020a2ebc(uVar8,&local_28);
      }
      func_020d26ec(iVar1,uRam020a5600);
      iVar1 = func_020a1154(param_1);
      if (iVar1 == 0) {
        func_020a16d0(param_1);
      }
      return 0;
    }
  }
  return 0;
}

