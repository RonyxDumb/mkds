/* Decompiled C draft; module arm9; ROM address 020ba3ec. No matching claim. */
#include "types.h"
#include "deps/020ba3ec_func_020ba3ec.h"

/* WARNING: Removing unreachable block (ram,0x020ba424) */

void func_020ba3ec(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  short *psVar8;
  
  uVar6 = *(uint *)(uRam020ba504 & 0xfffffffc) >> (uRam020ba504 & 3) * 8 |
          *(uint *)(uRam020ba504 & 0xfffffffc) << (uRam020ba504 & 3) * -8 + 0x20;
  uVar3 = uVar6 + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (uVar3 == 1) {
    return;
  }
  if (uVar3 != 2) {
    if (uVar3 != 4) {
      GetCurrentPlayerRacerId();
      iVar5 = GetDriverPlace();
      *(int *)(*(uint *)(uRam020ba508 & 0xfffffffc) >> (uRam020ba508 & 3) * 8 |
              *(uint *)(uRam020ba508 & 0xfffffffc) << (uRam020ba508 & 3) * -8 + 0x20) = iVar5 + -1;
      return;
    }
    uVar4 = func_0x02181820();
    *(undefined4 *)
     (*(uint *)(uRam020ba508 & 0xfffffffc) >> (uRam020ba508 & 3) * 8 |
     *(uint *)(uRam020ba508 & 0xfffffffc) << (uRam020ba508 & 3) * -8 + 0x20) = uVar4;
    return;
  }
  uVar6 = uVar6 + 0x18;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if (uVar6 >> uVar3 * 8 != 0 || uVar6 << uVar3 * -8 + 0x20 != 0) {
    GetCurrentPlayerRacerId();
    uVar2 = func_020a1154();
    *(undefined2 *)
     (*(uint *)(uRam020ba508 & 0xfffffffc) >> (uRam020ba508 & 3) * 8 |
     *(uint *)(uRam020ba508 & 0xfffffffc) << (uRam020ba508 & 3) * -8 + 0x20) = uVar2;
    return;
  }
  GetCurrentPlayerRacerId();
  iVar5 = func_020a2204();
  uVar3 = uRam020ba508;
  if (iVar5 == 0) {
    *(undefined2 *)
     (*(uint *)(uRam020ba508 & 0xfffffffc) >> (uRam020ba508 & 3) * 8 |
     *(uint *)(uRam020ba508 & 0xfffffffc) << (uRam020ba508 & 3) * -8 + 0x20) = 0;
  }
  else {
    psVar8 = (short *)(*(uint *)(uRam020ba508 & 0xfffffffc) >> (uRam020ba508 & 3) * 8 |
                      *(uint *)(uRam020ba508 & 0xfffffffc) << (uRam020ba508 & 3) * -8 + 0x20);
    *psVar8 = *psVar8 + 1;
    uVar6 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    puVar7 = (ushort *)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
    if (8 < *puVar7) {
      *puVar7 = 0;
    }
  }
  GetCurrentPlayerRacerId();
  uVar2 = func_020a10d4();
  *(undefined2 *)
   ((*(uint *)(uRam020ba508 & 0xfffffffc) >> (uRam020ba508 & 3) * 8 |
    *(uint *)(uRam020ba508 & 0xfffffffc) << (uRam020ba508 & 3) * -8 + 0x20) + 2) = uVar2;
  return;
}

