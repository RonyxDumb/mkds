/* Decompiled C draft; module arm7; ROM address 06005060. No matching claim. */
#include "types.h"
#include "deps/06005060_FUN_06005060.h"

void FUN_06005060(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 local_10 [4];
  
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  iVar2 = FUN_06004a9c(param_1,0,local_10);
  if (iVar2 == 1) {
    puVar3 = (undefined2 *)thunk_FUN_03807424();
    *puVar3 = 0xd;
    puVar3[1] = 0;
    puVar3[4] = (ushort)(uVar4 >> uVar1 * 8) | (ushort)(uVar4 << uVar1 * -8 + 0x20);
    puVar3[5] = local_10[0];
    thunk_FUN_038074cc();
  }
  return;
}

