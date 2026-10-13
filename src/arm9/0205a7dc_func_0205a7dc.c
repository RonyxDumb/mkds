/* Decompiled C draft; module arm9; ROM address 0205a7dc. No matching claim. */
#include "types.h"
#include "deps/0205a7dc_func_0205a7dc.h"

void func_0205a7dc(int param_1,ushort param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (*(uint *)(uRam0205a854 & 0xfffffffc) >> (uRam0205a854 & 3) * 8 |
          *(uint *)(uRam0205a854 & 0xfffffffc) << (uRam0205a854 & 3) * -8 + 0x20) + 0x754;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar3 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x24;
  param_1 = param_1 * 2;
  *(ushort *)(iVar3 + param_1) = *(ushort *)(iVar3 + param_1) & 0xff80 | param_2 & 0x7f;
  *(ushort *)(iVar3 + param_1) =
       *(ushort *)(iVar3 + param_1) & 0xf07f | (ushort)((param_3 & 0x1f) << 7);
  *(ushort *)(iVar3 + param_1) =
       *(ushort *)(iVar3 + param_1) & 0xcfff | (ushort)((param_4 & 3) << 0xc);
  return;
}

