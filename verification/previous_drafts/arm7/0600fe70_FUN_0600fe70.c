/* Decompiled C draft; module arm7; ROM address 0600fe70. No matching claim. */
#include "types.h"
#include "deps/0600fe70_FUN_0600fe70.h"

void FUN_0600fe70(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  uVar4 = *(uint *)(DAT_0600ff20 & 0xfffffffc) >> (DAT_0600ff20 & 3) * 8 |
          *(uint *)(DAT_0600ff20 & 0xfffffffc) << (DAT_0600ff20 & 3) * -8 + 0x20;
  puVar5 = (undefined2 *)(uVar4 + DAT_0600ff24);
  sVar1 = *(short *)(uVar4 + 0x404);
  if (sVar1 == 0x60) {
    uVar4 = (uint)(puVar5 + 0xc) & 3;
    uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
    iVar3 = FUN_06013bc8((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x10);
    if (iVar3 == 0) {
      uVar4 = (uint)(puVar5 + 0xe) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 4) = 8;
      *puVar5 = 99;
      FUN_06008a8c(2,4);
    }
    else {
      *puVar5 = 0x61;
      FUN_060143ac();
      uVar4 = (uint)(puVar5 + 0xc) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
      FUN_060098d4(*(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x18),
                   DAT_0600ff28);
    }
  }
  else if (sVar1 == 99) {
    FUN_060147a0(1);
    FUN_060143cc(1,0);
    *puVar5 = 0;
    FUN_0600fafc();
  }
  return;
}

