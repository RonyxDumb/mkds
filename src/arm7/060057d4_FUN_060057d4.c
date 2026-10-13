/* Decompiled C draft; module arm7; ROM address 060057d4. No matching claim. */
#include "types.h"
#include "deps/060057d4_FUN_060057d4.h"

void FUN_060057d4(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  short *psVar5;
  undefined1 auStack_208 [512];
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  psVar5 = (short *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  thunk_FUN_037faf70();
  if (*psVar5 == 0xb) {
    psVar5[8] = 0;
    psVar5[9] = 0;
    *psVar5 = 8;
    thunk_FUN_037faf84();
    iVar2 = FUN_060025fc((undefined2 *)(void *)(auStack_208),7);
    if (*(short *)(iVar2 + 4) == 0) {
      puVar4 = (undefined2 *)thunk_FUN_03807424();
      *puVar4 = 0x13;
      puVar4[1] = 0;
      thunk_FUN_038074cc();
    }
    else {
      FUN_06005798(0x104);
    }
  }
  else {
    thunk_FUN_037faf84();
    puVar4 = (undefined2 *)thunk_FUN_03807424();
    *puVar4 = 0x13;
    puVar4[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

