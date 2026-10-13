/* Decompiled C draft; module arm9_ov003; ROM address 021cd5e0. No matching claim. */
#include "types.h"
#include "deps/021cd5e0_FUN_021cd5e0.h"

void FUN_021cd5e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *DAT_021cd6c8 + DAT_021cd6cc;
  func_0x0214d168((uint *)(uintptr_t)(iVar1),0,0xef);
  func_0x0214d1fc((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(iVar1 + 0x40),0x20);
  iVar2 = *(int *)(param_1 + 0x20);
  if (iVar2 == 1) {
    *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 0xfc | 1;
    uVar4 = 5;
  }
  else if (iVar2 == 2) {
    *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 0xfc | 2;
    uVar4 = 0xd;
  }
  else if (iVar2 == 3) {
    *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 0xfc | 3;
    uVar4 = 0x10;
  }
  else {
    *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 0xfc;
    uVar4 = 0;
  }
  *(byte *)(iVar1 + 0xe6) = *(byte *)(iVar1 + 0xe6) & 3;
  iVar3 = 0;
  iVar2 = iVar1 + 0x80;
  param_1 = param_1 + 0x28;
  do {
    func_0x0214d1fc((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(iVar2),uVar4);
    iVar2 = iVar2 + 0x10;
    param_1 = param_1 + 0x20;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  *(undefined1 *)(iVar1 + 0xe7) = 2;
  func_0x0214d168((uint *)(uintptr_t)(iVar1 + 0xf0),0,4);
  *(undefined1 *)(iVar1 + 0xf5) = 1;
  *(undefined1 *)(iVar1 + 0xf6) = 1;
  FUN_021cd6d0();
  return;
}

