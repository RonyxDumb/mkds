/* Decompiled C draft; module arm9; ROM address 020b19b4. No matching claim. */
#include "types.h"
#include "deps/020b19b4_func_020b19b4.h"

void func_020b19b4(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = iRam020b19f4;
  uVar3 = uRam020b19ec;
  *param_1 = (*(uint *)(uRam020b19ec & 0xfffffffc) >> (uRam020b19ec & 3) * 8 |
             *(uint *)(uRam020b19ec & 0xfffffffc) << (uRam020b19ec & 3) * -8 + 0x20) + iRam020b19f0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *param_2 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + iVar2;
  return;
}

