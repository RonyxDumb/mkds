/* Decompiled C draft; module arm7; ROM address 06001f08. No matching claim. */
#include "types.h"
#include "deps/06001f08_FUN_06001f08.h"

void FUN_06001f08(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *local_28 [2];
  
  iVar2 = FUN_06000680();
  iVar1 = DAT_06001fbc;
  while (thunk_FUN_037f97b4(iVar2 + 0x88,local_28,1), local_28[0] != (ushort *)0x0) {
    uVar5 = (uint)*local_28[0];
    if ((*local_28[0] & 0x8000) != 0) {
      uVar5 = uVar5 & 0xffff7fff;
    }
    if (uVar5 < 0x2c) {
      uVar4 = iVar2 + 0x154cU & 3;
      uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
      uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(undefined4 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4) = 1;
      uVar4 = iVar2 + 0x154cU & 3;
      uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
      uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(ushort *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 2) = (ushort)uVar5;
      uVar4 = iVar1 + uVar5 * 4;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      (*(code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))(local_28[0]);
      uVar4 = iVar2 + 0x154cU & 3;
      uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
      uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(undefined4 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 4) = 0;
    }
    *local_28[0] = (ushort)uVar5 | 0x8000;
  }
  thunk_FUN_037f92a4();
  return;
}

