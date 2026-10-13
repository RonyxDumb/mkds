/* Decompiled C draft; module arm7; ROM address 0600608c. No matching claim. */
#include "types.h"
#include "deps/0600608c_FUN_0600608c.h"

void FUN_0600608c(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  
  iVar1 = FUN_06000680();
  uVar6 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  thunk_FUN_037faf70();
  if (*(short *)(uVar6 + 0xca) == 1) {
    thunk_FUN_037faf84();
  }
  else {
    *(undefined2 *)(uVar6 + 0xca) = 1;
    thunk_FUN_037faf84();
    puVar3 = (undefined4 *)FUN_06000000();
    if (puVar3 == (undefined4 *)0x0) {
      iVar4 = 0;
    }
    else {
      *puVar3 = 0x1c;
      iVar4 = thunk_FUN_037f9854(iVar1 + 0x88,puVar3,0);
    }
    if ((iVar4 == 0) &&
       (*(undefined2 *)(uVar6 + 0xca) = 0, uVar6 = iVar1 + 0x154cU & 3,
       uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc),
       uVar2 >> uVar6 * 8 != 0 || uVar2 << uVar6 * -8 + 0x20 != 0)) {
      puVar5 = (undefined2 *)thunk_FUN_03807424();
      *puVar5 = 0x80;
      puVar5[1] = 8;
      puVar5[2] = 0x16;
      puVar5[3] = 0x1c;
      thunk_FUN_038074cc();
    }
  }
  return;
}

