/* Decompiled C draft; module arm7; ROM address 038061e0. No matching claim. */
#include "types.h"
#include "deps/038061e0_FUN_038061e0.h"

void FUN_038061e0(void)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short *psVar8;
  ushort *local_20;
  undefined4 local_1c;
  uint uVar7;
  
  iVar1 = thunk_FUN_06000680();
  uVar7 = iVar1 + 0x154cU & 3;
  uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((uVar7 != 0) &&
     (*(short *)(*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) != 0)) {
    FUN_037fabc0(uVar7 + 0xd0);
    uVar7 = iVar1 + 0x154cU & 3;
    uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
    *(undefined4 *)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0xd0) = 0;
    uVar7 = iVar1 + 0x154cU & 3;
    uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    FUN_037fa564((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x58);
    uVar7 = iVar1 + 0x154cU & 3;
    uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
    uVar6 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined4 *)((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x58) = 0;
  }
  while (iVar2 = FUN_037f97b4(iVar1 + 0x88,&local_20,0), iVar2 != 0) {
    uVar7 = iVar1 + 0x154cU & 3;
    uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
    if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
      puVar3 = (ushort *)FUN_03807424();
      local_1c = 0;
      FUN_037fb24c(0,puVar3,0x100);
      *puVar3 = *local_20;
      puVar3[1] = 4;
      FUN_038074cc(puVar3);
      *local_20 = *local_20 | 0x8000;
    }
  }
  thunk_FUN_060000d0();
  iVar2 = FUN_03806650();
  if (iVar2 != 0) {
    FUN_037f9854(iVar1 + 0x88,0,1);
    thunk_FUN_060000d0();
    FUN_037f916c();
  }
  iVar2 = FUN_037f97b4(iVar1 + 0x88,&local_20,0);
  iVar4 = FUN_037f97b4(iVar1 + 0x58,&local_20,0);
  iVar5 = FUN_037f97b4(iVar1,&local_20,0);
  if (iVar5 != 0 || (iVar2 != 0 || iVar4 != 0)) {
    FUN_037fb000();
  }
  thunk_FUN_060086d0();
  do {
    iVar2 = FUN_037f97b4(iVar1 + 0x28,&local_20,0);
  } while (iVar2 != 0);
  thunk_FUN_060000c4();
  iVar2 = FUN_03806650();
  if (iVar2 != 0) {
    FUN_037f9854(iVar1 + 0x28,0,1);
    thunk_FUN_060000c4();
    FUN_037f916c();
  }
  FUN_03802c6c(1);
  FUN_038028e8(1);
  uVar7 = iVar1 + 0x154cU & 3;
  uVar6 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if ((uVar7 != 0) &&
     (psVar8 = (short *)(*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                        *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20), *psVar8 != 0)) {
    *psVar8 = 0;
  }
  FUN_03806714();
  do {
    iVar1 = FUN_037fb5f4(0xf,0x20000,0);
  } while (iVar1 < 0);
  FUN_037faf70();
  *DAT_03806400 = 1;
  FUN_037f92a4();
  return;
}

