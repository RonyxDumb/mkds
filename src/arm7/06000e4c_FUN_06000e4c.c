/* Decompiled C draft; module arm7; ROM address 06000e4c. No matching claim. */
#include "types.h"
#include "deps/06000e4c_FUN_06000e4c.h"

void FUN_06000e4c(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = FUN_06000680();
  uVar6 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar5 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = uVar5 + 0x10 & 3;
  uVar3 = *(uint *)(uVar5 + 0x10 & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
    FUN_06000680();
    iVar2 = (int)(uint)*(byte *)(param_1 + 0x1f) >> 2;
    if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
      iVar2 = iVar2 + 0x19;
    }
    FUN_06000250(iVar2);
    uVar1 = FUN_060001dc();
    *(undefined2 *)(uVar5 + 0xb8) = uVar1;
    iVar2 = FUN_060004fc((char *)(uintptr_t)(param_1 + 0x2e));
    if ((iVar2 != 1) && (*(ushort *)(param_1 + 0x16) <= DAT_06000f48)) {
      *(ushort *)(uVar5 + 0xaa) = *(ushort *)(uVar5 + 0xaa) ^ 1;
      uVar6 = uVar5 + (uint)*(ushort *)(uVar5 + 0xaa) * 4 + 0xac;
      uVar3 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      thunk_FUN_037fb390(param_1 + 0x10,uVar6,*(ushort *)(param_1 + 0x16) + 0x2d & 0xfffffffe);
      thunk_FUN_037fb390(param_1 + 0x28,uVar6 + 0x18,6);
      thunk_FUN_037fb390(param_1 + 0x2e,uVar6 + 0x1e,6);
      puVar4 = (undefined2 *)thunk_FUN_03807424();
      *puVar4 = 0x11;
      puVar4[1] = 0;
      puVar4[2] = 0xf;
      *(uint *)(puVar4 + 4) = uVar6;
      thunk_FUN_038074cc();
    }
  }
  return;
}

