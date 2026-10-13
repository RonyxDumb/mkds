/* Decompiled C draft; module arm7; ROM address 06005b48. No matching claim. */
#include "types.h"
#include "deps/06005b48_FUN_06005b48.h"

void FUN_06005b48(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined1 auStack_208 [512];
  
  FUN_06000680();
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  iVar2 = FUN_060022d4((undefined2 *)(void *)(auStack_208),(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xffff);
  if (*(short *)(iVar2 + 4) == 0) {
    puVar3 = (undefined2 *)thunk_FUN_03807424();
    *puVar3 = 0x19;
    puVar3[1] = 0;
    thunk_FUN_038074cc();
  }
  else {
    FUN_06005b0c(DAT_06005ba8);
  }
  return;
}

