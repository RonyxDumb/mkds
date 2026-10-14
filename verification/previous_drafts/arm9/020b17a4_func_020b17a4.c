/* Decompiled C draft; module arm9; ROM address 020b17a4. No matching claim. */
#include "types.h"
#include "deps/020b17a4_func_020b17a4.h"

void func_020b17a4(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  
  *puRam020b188c =
       (*(uint *)((uint)puRam020b188c & 0xfffffffc) >> ((uint)puRam020b188c & 3) * 8 |
       *(uint *)((uint)puRam020b188c & 0xfffffffc) << ((uint)puRam020b188c & 3) * -8 + 0x20) &
       0xffffe0ff | 0x1e00;
  SetDispcntSubBgMode(0);
  puVar3 = puRam020b1894;
  *puRam020b1890 = 0;
  puVar4 = puRam020b1898;
  *puVar3 = *puVar3 & 0xfffc | 3;
  puVar5 = puRam020b189c;
  uVar1 = (ushort)uRam020b18a0;
  *puVar3 = *puVar3 & 0xffbf;
  puVar7 = puRam020b18a8;
  puVar6 = puRam020b18a4;
  *puVar3 = *puVar3 & 0x43 | 8;
  *puVar4 = 0x100;
  uVar2 = (ushort)uRam020b18ac;
  *puVar5 = *puVar5 & 0xfffc | 2;
  *puVar5 = *puVar5 & 0xffbf;
  *puVar5 = *puVar5 & 0x43 | uVar1;
  *puVar6 = 0x100;
  *puVar7 = *puVar7 & 0xfffc | 2;
  *puVar7 = *puVar7 & 0xffbf;
  *puVar7 = *puVar7 & 0x43 | uVar2;
  return;
}

