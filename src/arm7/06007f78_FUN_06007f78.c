/* Decompiled C draft; module arm7; ROM address 06007f78. No matching claim. */
#include "types.h"
#include "deps/06007f78_FUN_06007f78.h"

void FUN_06007f78(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint *puVar5;
  
  iVar2 = FUN_06000680();
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(iVar2 + 0x154c) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = iVar2 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  puVar5 = (uint *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *puVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  puVar5[2] = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  FUN_06007e1c();
  thunk_FUN_03802c6c(0xf);
  *(undefined2 *)
   (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
   *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) = 1;
  puVar3 = (undefined2 *)thunk_FUN_03807424();
  *puVar3 = 3;
  puVar3[1] = 0;
  thunk_FUN_038074cc();
  return;
}

