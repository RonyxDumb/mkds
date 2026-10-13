/* Decompiled C draft; module arm7; ROM address 06001c44. No matching claim. */
#include "types.h"
#include "deps/06001c44_FUN_06001c44.h"

void FUN_06001c44(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (*(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xbe) != 0) {
    puVar4 = (undefined2 *)thunk_FUN_03807424();
    *puVar4 = 8;
    puVar4[1] = 0;
    puVar4[4] = 2;
    thunk_FUN_038074cc();
  }
  return;
}

