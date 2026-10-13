/* Decompiled C draft; module arm9; ROM address 02149098. No matching claim. */
#include "types.h"
#include "deps/02149098_GX_SetBankForSubOBJExtPltt.h"

void GX_SetBankForSubOBJExtPltt(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  
  puVar3 = puRam02149118;
  uVar1 = puRam02149118[0xc];
  uVar2 = *puRam02149118;
  puRam02149118[0xc] = (ushort)param_1;
  *puVar3 = ~(ushort)param_1 & (uVar2 | uVar1);
  puVar4 = puRam02149120;
  if (param_1 == 0) {
    *puRam0214911c =
         (*(uint *)((uint)puRam0214911c & 0xfffffffc) >> ((uint)puRam0214911c & 3) * 8 |
         *(uint *)((uint)puRam0214911c & 0xfffffffc) << ((uint)puRam0214911c & 3) * -8 + 0x20) &
         0x7fffffff;
  }
  else if (param_1 == 0x100) {
    *puRam0214911c =
         *(uint *)((uint)puRam0214911c & 0xfffffffc) >> ((uint)puRam0214911c & 3) * 8 |
         *(uint *)((uint)puRam0214911c & 0xfffffffc) << ((uint)puRam0214911c & 3) * -8 + 0x20 |
         0x80000000;
    *puVar4 = 0x83;
  }
  GX_VRAMCNT_SetLCDC_(*puRam02149118);
  return;
}

