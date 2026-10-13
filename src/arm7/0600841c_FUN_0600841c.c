/* Decompiled C draft; module arm7; ROM address 0600841c. No matching claim. */
#include "types.h"
#include "deps/0600841c_FUN_0600841c.h"

void FUN_0600841c(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = FUN_06000680();
  uVar4 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar5 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xffff;
  if (uVar4 == 0) {
    uVar4 = 0x10;
  }
  thunk_FUN_037faf70();
  *(short *)(uVar5 + 0x34) = (short)uVar4;
  if ((int)uVar4 < (int)*(short *)(uVar5 + 0x36)) {
    *(short *)(uVar5 + 0x36) = (short)uVar4;
  }
  thunk_FUN_037faf84();
  puVar3 = (undefined2 *)thunk_FUN_03807424();
  *puVar3 = 0x23;
  puVar3[1] = 0;
  thunk_FUN_038074cc();
  return;
}

