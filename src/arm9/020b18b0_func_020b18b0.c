/* Decompiled C draft; module arm9; ROM address 020b18b0. No matching claim. */
#include "types.h"
#include "deps/020b18b0_func_020b18b0.h"

void func_020b18b0(void)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = MaybeCircuitUsesLocal3();
  if (iVar3 == 0) {
    *puRam020b198c =
         (*(uint *)((uint)puRam020b198c & 0xfffffffc) >> ((uint)puRam020b198c & 3) * 8 |
         *(uint *)((uint)puRam020b198c & 0xfffffffc) << ((uint)puRam020b198c & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1400;
  }
  else {
    *puRam020b198c =
         (*(uint *)((uint)puRam020b198c & 0xfffffffc) >> ((uint)puRam020b198c & 3) * 8 |
         *(uint *)((uint)puRam020b198c & 0xfffffffc) << ((uint)puRam020b198c & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1c00;
  }
  SetDispcntSubBgMode(5);
  puVar2 = puRam020b1994;
  puVar4 = puRam020b1990;
  uVar1 = (ushort)uRam020b1998;
  *puRam020b1990 = *puRam020b1990 & 0xfffc | 2;
  *puVar4 = *puVar4 & 0xffbf;
  *puVar2 = *puVar2 & 0xffbf;
  *puVar4 = *puVar4 & 0x43 | uVar1;
  *puVar2 = *puVar2 & 0xfffc | 3;
  *puVar2 = *puVar2 & 0xffbf;
  iVar3 = func_020b6430();
  if (iVar3 != 0) {
    puVar4 = (ushort *)0x1;
  }
  if (iVar3 == 0) {
    puVar4 = (ushort *)0x0;
  }
  *puRam020b1994 = *puRam020b1994 & 0x43 | (ushort)uRam020b199c | (ushort)((int)puVar4 << 0xd);
  return;
}

