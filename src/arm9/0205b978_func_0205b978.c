/* Decompiled C draft; module arm9; ROM address 0205b978. No matching claim. */
#include "types.h"
#include "deps/0205b978_func_0205b978.h"

int func_0205b978(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (*(uint *)(uRam0205b9a4 & 0xfffffffc) >> (uRam0205b9a4 & 3) * 8 |
          *(uint *)(uRam0205b9a4 & 0xfffffffc) << (uRam0205b9a4 & 3) * -8 + 0x20) + 0x104;
  uVar3 = iVar2 + param_1 * 0x88;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = iVar2 + param_1 * 0x88;
  if (param_2 != ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xffffff)) {
    iVar2 = 0;
  }
  return iVar2;
}

