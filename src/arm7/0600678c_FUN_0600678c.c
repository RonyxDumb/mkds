/* Decompiled C draft; module arm7; ROM address 0600678c. No matching claim. */
#include "types.h"
#include "deps/0600678c_FUN_0600678c.h"

void FUN_0600678c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  thunk_FUN_037fadcc((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xd0);
  return;
}

