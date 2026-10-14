/* Decompiled C draft; module arm9; ROM address 020853a4. No matching claim. */
#include "types.h"
#include "deps/020853a4_func_020853a4.h"

uint func_020853a4(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (*(uint *)(uRam020853d8 & 0xfffffffc) >> (uRam020853d8 & 3) * 8 |
          *(uint *)(uRam020853d8 & 0xfffffffc) << (uRam020853d8 & 3) * -8 + 0x20) + 0x108;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  iVar3 = GetSomeRacerValue();
  lVar2 = (longlong)iVar3 * (longlong)(int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x800
  ;
  return (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
}

