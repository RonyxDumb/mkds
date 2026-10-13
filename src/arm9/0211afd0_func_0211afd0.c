/* Decompiled C draft; module arm9; ROM address 0211afd0. No matching claim. */
#include "types.h"
#include "deps/0211afd0_func_0211afd0.h"

void func_0211afd0(void)

{
  int *piVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  func_0211c818();
  func_0211c14c();
  piVar1 = piRam0211b068;
  *(int *)(*piRam0211b068 + 0x38) = *(int *)(*piRam0211b068 + 0x38) + 1;
  sVar2 = func_0212825c(*(undefined4 *)(*piVar1 + 0x38));
  piVar1 = piRam0211b068;
  sVar2 = -sVar2;
  iVar4 = *piRam0211b068;
  uVar3 = (uint)*(ushort *)(*(int *)(iVar4 + 4) + 6);
  if (*(int *)(*piRam0211b06c + 0x20) == 2) {
    *(short *)(*(int *)(iVar4 + 0x14) + iRam0211b078) = sVar2;
    *(short *)(*(int *)(*piVar1 + 0x14) + (uVar3 + 0xe) * 0x40 + 6) = sVar2;
  }
  else {
    *(short *)(*(int *)(iVar4 + 0x14) + iRam0211b070) = sVar2;
    *(short *)(*(int *)(*piVar1 + 0x14) + iRam0211b074) = sVar2;
    *(short *)(*(int *)(*piVar1 + 0x14) + (uVar3 + 0xd) * 0x40 + 6) = sVar2;
  }
  iVar4 = *piRam0211b068;
  if ((*(int *)(iVar4 + 0x2c) == 0) || (*(int *)(iVar4 + 0x2c) == 1)) {
    if ((9 < *(int *)(iVar4 + 0x38)) && (iVar4 = func_02128294(), iVar4 != 0)) {
      func_0211ba98();
      return;
    }
  }
  else if (9 < *(int *)(iVar4 + 0x38)) {
    func_0211ba98();
  }
  return;
}

