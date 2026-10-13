/* Decompiled C draft; module arm7; ROM address 06007e1c. No matching claim. */
#include "types.h"
#include "deps/06007e1c_FUN_06007e1c.h"

void FUN_06007e1c(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar7;
  uint uVar6;
  
  iVar1 = FUN_06000680();
  uVar3 = iVar1 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  uVar2 = thunk_FUN_037faf70();
  uVar4 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0xc;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  bVar7 = (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == 1;
  if (bVar7) {
    *(undefined4 *)(uVar4 + 0xc) = 0;
    thunk_FUN_037fabc0(uVar6 + 0xd0);
    FUN_06000154();
  }
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x17e) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x86) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x14) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x10) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1c) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x92) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x94) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x96) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x18e) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 400) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xca) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xbe) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xc2) = 0;
  *(undefined2 *)
   ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
    *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1ea) = 1;
  thunk_FUN_037faf84(uVar2);
  if (bVar7) {
    FUN_06006d24(DAT_06007f68);
  }
  iVar1 = 0;
  do {
    *(undefined4 *)(uVar6 + iVar1 * 0x10 + 0xf8) = 0x8000;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  thunk_FUN_037fb218(1,(*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                       *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 500,0x100);
  thunk_FUN_037fa814((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                     *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x58);
  thunk_FUN_037f9a98((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                     *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + DAT_06007f6c);
  FUN_0600678c();
  return;
}

