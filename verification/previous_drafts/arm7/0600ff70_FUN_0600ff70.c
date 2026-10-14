/* Decompiled C draft; module arm7; ROM address 0600ff70. No matching claim. */
#include "types.h"
#include "deps/0600ff70_FUN_0600ff70.h"

void FUN_0600ff70(void)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  uVar4 = *(uint *)(DAT_06010028 & 0xfffffffc) >> (DAT_06010028 & 3) * 8 |
          *(uint *)(DAT_06010028 & 0xfffffffc) << (DAT_06010028 & 3) * -8 + 0x20;
  puVar5 = (undefined2 *)(uVar4 + DAT_0601002c);
  sVar1 = *(short *)(uVar4 + 0x404);
  if (sVar1 == 0x50) {
    uVar4 = (uint)(puVar5 + 0xc) & 3;
    uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
    iVar3 = FUN_06013c80((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x10);
    if (iVar3 == 0) {
      uVar4 = (uint)(puVar5 + 0xe) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xe) & 0xfffffffc);
      *(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 4) = 8;
      *puVar5 = 0x53;
      FUN_06008a8c(2,3);
    }
    else {
      *puVar5 = 0x51;
      FUN_060143ac();
      uVar4 = (uint)(puVar5 + 0xc) & 3;
      uVar2 = *(uint *)((uint)(puVar5 + 0xc) & 0xfffffffc);
      FUN_060098d4(*(undefined2 *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x18),
                   DAT_06010030);
    }
  }
  else if (sVar1 == 0x53) {
    FUN_06014708(1);
    FUN_060147a0(1);
    FUN_060143cc(1,0);
    *puVar5 = 0;
    FUN_0600fafc();
  }
  return;
}

