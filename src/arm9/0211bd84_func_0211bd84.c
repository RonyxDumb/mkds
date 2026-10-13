/* Decompiled C draft; module arm9; ROM address 0211bd84. No matching claim. */
#include "types.h"
#include "deps/0211bd84_func_0211bd84.h"

void func_0211bd84(void)

{
  int *piVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 3;
  iVar4 = func_020cccb4();
  if (((iVar4 == 8) || (iVar4 = func_020cccb4(), iVar4 == 9)) ||
     (iVar4 = func_020cccb4(), iVar4 == 0xf)) {
    func_02029520();
    func_020295a0();
    func_020295c0(0);
    func_02029570(0);
    func_02029560(0);
    func_02029540(0);
    func_02029550(0);
  }
  iVar4 = func_0202962c();
  piVar1 = DAT_0211bf7c;
  if (iVar4 == 0) {
    iVar7 = 0;
  }
  else {
    switch(*(undefined4 *)(*DAT_0211bf7c + 0x2c)) {
    case 0:
    case 1:
      iVar7 = 1;
      break;
    case 2:
    case 3:
    case 4:
    case 5:
      iVar7 = 2;
    }
    uVar6 = 0;
    do {
      iVar4 = func_02029618(uVar6 & 0xffff);
      iVar5 = *(int *)(DAT_0211bf80 + iVar4 * 4);
      func_0211d428(uVar6 & 0xffff,iVar5);
      iVar4 = func_020296ac(uVar6 & 0xffff);
      if (iVar4 == 0) {
        iVar4 = *piVar1 + iVar5 * 2;
        *(short *)(iVar4 + 0xac) = *(short *)(iVar4 + 0xac) + 1;
      }
      else {
        iVar4 = *piVar1 + iVar5 * 2;
        *(short *)(iVar4 + 0xb0) = *(short *)(iVar4 + 0xb0) + 1;
      }
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < 8);
  }
  piVar1 = DAT_0211bf7c;
  *(undefined4 *)(*DAT_0211bf7c + 0x60) = 4;
  iVar4 = *(int *)(*piVar1 + 0x78);
  while (iVar7 != iVar4) {
    func_0211ccac(0);
    iVar4 = *(int *)(*piVar1 + 0x78);
  }
  iVar4 = func_0202967c();
  if (iVar4 == 0) {
    iVar4 = func_0202969c();
    iVar4 = *(int *)(DAT_0211bf84 + iVar4 * 4);
  }
  else {
    iVar4 = 3;
  }
  piVar1 = DAT_0211bf7c;
  *(undefined4 *)(*DAT_0211bf7c + 0x60) = 0;
  iVar7 = *(int *)(*piVar1 + 0x68);
  while (iVar4 != iVar7) {
    func_0211ccac(0);
    iVar7 = *(int *)(*piVar1 + 0x68);
  }
  iVar4 = func_0202966c();
  piVar2 = DAT_0211bf7c;
  iVar5 = *(int *)(DAT_0211bf88 + iVar4 * 4);
  *(undefined4 *)(*DAT_0211bf7c + 0x60) = 1;
  iVar4 = *piVar2;
  iVar7 = *(int *)(iVar4 + 0x6c);
  piVar1 = DAT_0211bf7c;
  while (DAT_0211bf7c = piVar1, iVar5 != iVar7) {
    func_0211ccac(0);
    iVar4 = *piVar2;
    piVar1 = DAT_0211bf7c;
    iVar7 = *(int *)(iVar4 + 0x6c);
  }
  if (((*(int *)(iVar4 + 0x2c) == 0) || (*(int *)(iVar4 + 0x2c) == 1)) && (iVar5 == 0)) {
    while (iVar7 != 2) {
      func_0211ccac(0);
      iVar7 = *(int *)(*piVar1 + 0x6c);
    }
  }
  iVar4 = func_0202965c();
  piVar1 = DAT_0211bf7c;
  iVar7 = *(int *)(DAT_0211bf8c + iVar4 * 4);
  *(undefined4 *)(*DAT_0211bf7c + 0x60) = 2;
  iVar4 = *(int *)(*piVar1 + 0x70);
  while (iVar7 != iVar4) {
    func_0211ccac(0);
    iVar4 = *(int *)(*piVar1 + 0x70);
  }
  iVar4 = func_0202963c();
  piVar1 = DAT_0211bf7c;
  iVar7 = *(int *)(DAT_0211bf90 + iVar4 * 4);
  *(undefined4 *)(*DAT_0211bf7c + 0x60) = 3;
  iVar4 = *(int *)(*piVar1 + 0x74);
  while (iVar7 != iVar4) {
    func_0211ccac(0);
    iVar4 = *(int *)(*piVar1 + 0x74);
  }
  if (iVar4 == 0) {
    sVar3 = func_0202964c();
    func_0211d910((int)sVar3);
  }
  else if (iVar4 == 1) {
    sVar3 = func_0202964c();
    func_0211d844((int)sVar3);
  }
  *(undefined4 *)(*DAT_0211bf7c + 0x60) = 0;
  return;
}

