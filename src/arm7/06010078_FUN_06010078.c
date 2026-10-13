/* Decompiled C draft; module arm7; ROM address 06010078. No matching claim. */
#include "types.h"
#include "deps/06010078_FUN_06010078.h"

void FUN_06010078(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  uVar4 = *(uint *)(DAT_06010150 & 0xfffffffc) >> (DAT_06010150 & 3) * 8 |
          *(uint *)(DAT_06010150 & 0xfffffffc) << (DAT_06010150 & 3) * -8 + 0x20;
  puVar5 = (undefined2 *)(uVar4 + DAT_06010154);
  sVar1 = *(short *)(uVar4 + 0x404);
  if (sVar1 == 0x30) {
    uVar4 = (uint)(puVar5 + 0xc) & 3;
    uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
    iVar3 = FUN_060136d0((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x10,0);
    if (iVar3 == 0) {
      uVar4 = (uint)(puVar5 + 0xe) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 4) = 8;
      *puVar5 = 0x35;
      FUN_06008a8c(2,2);
    }
    else {
      uVar4 = (uint)(puVar5 + 0xc) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
      *(undefined2 *)(iVar3 + 0x2c) =
           *(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x16);
      *(undefined2 *)(iVar3 + 0x2e) = 1;
      *(undefined2 *)(iVar3 + 0x30) = 0;
      *puVar5 = 0x31;
      FUN_060143ac();
      uVar4 = (uint)(puVar5 + 0xc) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
      FUN_060098d4(*(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x18),
                   DAT_06010158);
    }
  }
  else if (sVar1 == 0x35) {
    FUN_06014708(1);
    FUN_060147a0(1);
    FUN_060143cc(1,0);
    *puVar5 = 0;
    FUN_0600fafc();
  }
  return;
}

