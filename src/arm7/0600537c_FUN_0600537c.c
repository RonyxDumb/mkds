/* Decompiled C draft; module arm7; ROM address 0600537c. No matching claim. */
#include "types.h"
#include "deps/0600537c_FUN_0600537c.h"

void FUN_0600537c(int param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  uint uVar11;
  
  iVar3 = FUN_06000680();
  uVar1 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar9 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar2 = *(ushort *)(uVar9 + 0x17e);
  uVar1 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar13 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar6 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar12 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar7 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x14U & 3;
  uVar8 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar4 = param_1 + 0x18U & 3;
  uVar10 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar11 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0x1cU & 3;
  uVar10 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar4 = uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20;
  if (*(short *)(uVar9 + 0x184) != 0) {
    uVar12 = 1;
  }
  uVar10 = uVar9 + 0xc & 3;
  uVar9 = *(uint *)(uVar9 + 0xc & 0xfffffffc);
  if (uVar9 >> uVar10 * 8 == 0 && uVar9 << uVar10 * -8 + 0x20 == 0) {
    iVar3 = 3;
  }
  else if ((uVar12 & uVar2) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0600722c((uint)uVar2,(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) & 0xffff,
                         uVar7 & 0xffff,uVar12,uVar13,uVar6 & 0xffff,uVar11,uVar4);
  }
  if (iVar3 != 2) {
    puVar5 = (undefined2 *)thunk_FUN_03807424();
    *puVar5 = 0x81;
    puVar5[1] = (short)iVar3;
    puVar5[4] = 0x14;
    puVar5[5] = (short)uVar7;
    puVar5[6] = (ushort)uVar12;
    if (iVar3 == 10) {
      puVar5[7] = (ushort)uVar12 & uVar2;
    }
    else {
      puVar5[7] = 0;
    }
    puVar5[8] = 0;
    puVar5[0xc] = (short)uVar6;
    *(uint *)(puVar5 + 10) = uVar13;
    *(uint *)(puVar5 + 0xe) = uVar11;
    *(uint *)(puVar5 + 0x10) = uVar4;
    puVar5[0xd] = (short)DAT_0600548c;
    thunk_FUN_038074cc();
  }
  return;
}

