/* Decompiled C draft; module arm9; ROM address 0205dc84. No matching claim. */
#include "types.h"
#include "deps/0205dc84_RunMain.h"

void RunMain(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  undefined1 auStack_18 [24];
  
  uVar2 = uRam0205dd24;
  *(undefined2 *)
   ((*(uint *)(uRam0205dd24 & 0xfffffffc) >> (uRam0205dd24 & 3) * 8 |
    *(uint *)(uRam0205dd24 & 0xfffffffc) << (uRam0205dd24 & 3) * -8 + 0x20) + 8) = 9;
  psVar4 = psRam0205dd28;
  *(undefined4 *)
   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = 0;
  uVar6 = uRam0205dd30;
  if (*psVar4 == 2) {
    *(undefined4 *)
     ((*(uint *)(uRam0205dd2c & 0xfffffffc) >> (uRam0205dd2c & 3) * 8 |
      *(uint *)(uRam0205dd2c & 0xfffffffc) << (uRam0205dd2c & 3) * -8 + 0x20) + 0x20) = 2;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(undefined4 *)((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + 0x74) = 0;
    *(undefined2 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 8) = 6;
  }
  do {
    uVar5 = uRam0205dd34;
    *(undefined4 *)
     ((*(uint *)(uRam0205dd24 & 0xfffffffc) >> (uRam0205dd24 & 3) * 8 |
      *(uint *)(uRam0205dd24 & 0xfffffffc) << (uRam0205dd24 & 3) * -8 + 0x20) + 4) = 3;
    ExecutionContext_Create(auStack_18,uVar5);
    ExecutionContext_Execute
              (auStack_18,
               (*(uint *)(uRam0205dd24 & 0xfffffffc) >> (uRam0205dd24 & 3) * 8 |
               *(uint *)(uRam0205dd24 & 0xfffffffc) << (uRam0205dd24 & 3) * -8 + 0x20) + 8);
    puVar7 = (uint *)(*(uint *)(uRam0205dd24 & 0xfffffffc) >> (uRam0205dd24 & 3) * 8 |
                     *(uint *)(uRam0205dd24 & 0xfffffffc) << (uRam0205dd24 & 3) * -8 + 0x20);
    puVar1 = puVar7 + 1;
    uVar2 = (uint)puVar1 & 3;
    uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
    *puVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  } while( true );
}

