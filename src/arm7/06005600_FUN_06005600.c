/* Decompiled C draft; module arm7; ROM address 06005600. No matching claim. */
#include "types.h"
#include "deps/06005600_FUN_06005600.h"

void FUN_06005600(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  uint uVar7;
  
  iVar1 = FUN_06000680();
  uVar3 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar6 = (undefined2 *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar7 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar4 = thunk_FUN_037faf70();
  *(uint *)(puVar6 + 0x56) = uVar7;
  puVar6[0x5a] = (short)uVar3;
  *(uint *)(puVar6 + 0x58) = uVar7 + (uVar3 & 0xffff);
  puVar6[0x55] = 0;
  *(undefined4 *)(puVar6 + 0x52) = 0;
  puVar6[0x54] = 0;
  *(undefined4 *)(puVar6 + 0xc) = 0;
  *puVar6 = 0xb;
  puVar5 = (undefined2 *)thunk_FUN_03807424();
  *puVar5 = 0x11;
  puVar5[1] = 0;
  puVar5[2] = 0xe;
  thunk_FUN_038074cc();
  *(undefined4 *)(puVar6 + 8) = 1;
  thunk_FUN_037faf84(uVar4);
  return;
}

