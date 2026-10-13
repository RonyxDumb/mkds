/* Decompiled C draft; module arm9_ov000; ROM address 02182688. No matching claim. */
#include "types.h"
#include "deps/02182688_FUN_02182688.h"

void FUN_02182688(void)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = func_ov000_021806c4();
  if (((iVar3 == -1) && (*(int *)(*DAT_02182864 + 0x20) == 0xe)) &&
     (iVar3 = FUN_021832f0(), iVar3 != 0)) {
    func_ov000_021806b8(8);
  }
  piVar1 = DAT_02182864;
  *(int *)(*DAT_02182864 + 0x10) = *(int *)(*DAT_02182864 + 0x10) + 1;
  if (*(int *)(*piVar1 + 0x10) < 0xb) {
    sVar2 = func_0x020ae4c0(1,0,DAT_02182868,*(int *)(*piVar1 + 0x10),10);
  }
  else {
    sVar2 = (short)DAT_02182868;
  }
  piVar1 = DAT_02182864;
  iVar7 = 0;
  iVar3 = 0;
  do {
    if (iVar7 == 0) {
      *(short *)(*piVar1 + iVar3 + 0x14) = sVar2;
    }
    else {
      *(short *)(*piVar1 + iVar3 + 0x14) = -sVar2;
    }
    iVar3 = iVar3 + 4;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  if (*(int *)(*DAT_02182864 + 0x10) < 3) {
    sVar2 = func_0x020ae584(0);
  }
  else {
    sVar2 = func_0x02128244(*(int *)(*DAT_02182864 + 0x10) + -3);
  }
  piVar1 = DAT_02182864;
  iVar3 = 0;
  iVar7 = *(int *)(DAT_0218286c + 8);
  if (0 < iVar7) {
    do {
      *(short *)(*piVar1 + 0x1e) = -sVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar7);
  }
  if (((((9 < *(int *)(*DAT_02182864 + 0x10)) && (0xc < *(int *)(*DAT_02182864 + 0x10))) &&
       (iVar3 = func_0x02125f88(), iVar3 != 0)) &&
      (((*(int *)(*DAT_02182864 + 0x28) != 0 && (iVar3 = func_0x02128274(), iVar3 != 0)) ||
       (iVar3 = func_0x02128294(), iVar3 != 0)))) && (iVar3 = func_ov000_021806c4(), iVar3 == -1)) {
    if ((*(int *)(*DAT_02182864 + 0x20) == 0xe) &&
       (iVar3 = FUN_021832f0(), piVar1 = DAT_02182864, iVar3 == 0)) {
      *(undefined4 *)(*DAT_02182864 + 4) = 7;
      *(undefined4 *)(*piVar1 + 0x20) = 0xffffffff;
      func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_02182870),0x76);
      func_0x021266e4();
      *(undefined4 *)(*DAT_02182864 + 0x10) = 0;
      return;
    }
    if (((*(int *)(*DAT_02182864 + 0x20) == 3) && (*(int *)(*DAT_02182864 + 0xc) == 0)) &&
       (iVar3 = FUN_021832f0(), piVar1 = DAT_02182864, iVar3 == 0)) {
      *(undefined4 *)(*DAT_02182864 + 4) = 8;
      *(undefined4 *)(*piVar1 + 0x20) = 0xffffffff;
      func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_02182874),0xe);
      func_0x021266e4();
      *(undefined4 *)(*DAT_02182864 + 0x10) = 0;
      return;
    }
    piVar1 = DAT_02182864;
    if (*(int *)(*DAT_02182864 + 0x20) == 1) {
      *(undefined4 *)(*DAT_02182864 + 4) = 9;
      *(undefined4 *)(*piVar1 + 0x10) = 0;
      *(undefined4 *)(*piVar1 + 0x34) = 0;
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + DAT_02182874),0x17);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*DAT_02182864 + DAT_02182870),0);
      uVar6 = func_0x020b3f7c(*(undefined4 *)(*DAT_02182864 + DAT_02182870),1);
      func_0x02126454(uVar4,uVar5,uVar6,0);
      return;
    }
    func_ov000_021806e0();
  }
  return;
}

