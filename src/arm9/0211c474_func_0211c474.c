/* Decompiled C draft; module arm9; ROM address 0211c474. No matching claim. */
#include "types.h"
#include "deps/0211c474_func_0211c474.h"

void func_0211c474(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = iRam0211c598;
  piVar1 = piRam0211c594;
  uVar5 = 0;
  iVar4 = 0;
  do {
    iVar2 = func_0211d40c(uVar5 & 0xffff);
    if (iVar2 == 0) {
      if (*(int *)(*piVar1 + 0x6c) == 0) {
        func_020294d4(uVar5 & 0xffff,4);
        func_0202950c(uVar5 & 0xffff,*(undefined4 *)(iVar3 + *(int *)(*piVar1 + iVar4 + 0x8c) * 4));
      }
      else {
        func_020294d4(uVar5 & 0xffff,1);
        func_0202950c(uVar5 & 0xffff,*(undefined4 *)(iVar3 + *(int *)(*piVar1 + iVar4 + 0x8c) * 4));
      }
    }
    else {
      func_020294d4(uVar5 & 0xffff,0);
      func_0202950c(uVar5 & 0xffff,*(undefined4 *)(iVar3 + *(int *)(*piVar1 + iVar4 + 0x8c) * 4));
    }
    iVar4 = iVar4 + 4;
    uVar5 = uVar5 + 1;
  } while ((int)uVar5 < 8);
  if (*(int *)(*piRam0211c594 + 0x68) == 3) {
    func_020295c0(*(undefined4 *)(iRam0211c59c + 8));
    func_020295b0();
  }
  else {
    func_020295c0(*(undefined4 *)(iRam0211c59c + *(int *)(*piRam0211c594 + 0x68) * 4));
    func_020295a0();
  }
  func_02029570(*(undefined4 *)(iRam0211c5a0 + *(int *)(*piRam0211c594 + 0x6c) * 4));
  func_02029560(*(undefined4 *)(iRam0211c5a4 + *(int *)(*piRam0211c594 + 0x70) * 4));
  func_02029540(*(undefined4 *)(iRam0211c5a8 + *(int *)(*piRam0211c594 + 0x74) * 4));
  iVar3 = *piRam0211c594;
  if (*(int *)(iVar3 + 0x74) == 0) {
    func_02029550(*(undefined2 *)(iVar3 + 0x88));
  }
  else if (*(int *)(iVar3 + 0x74) == 1) {
    func_02029550(*(undefined2 *)(iVar3 + 0x8a));
  }
  if (*(int *)(*piRam0211c594 + 0x78) == 0) {
    func_02029520();
  }
  else {
    func_02029530();
  }
  func_0211c5ac();
  return;
}

