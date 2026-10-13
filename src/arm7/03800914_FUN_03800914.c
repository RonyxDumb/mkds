/* Decompiled C draft; module arm7; ROM address 03800914. No matching claim. */
#include "types.h"
#include "deps/03800914_FUN_03800914.h"

void FUN_03800914(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = DAT_0380097c;
  iVar2 = DAT_03800978;
  *(undefined4 *)(DAT_0380097c + 0x2c) = 4;
  *(undefined4 *)(iVar3 + 0x20) = param_1;
  *(undefined4 *)(iVar3 + 0x24) = param_2;
  *(undefined4 *)(iVar3 + 0x28) = param_3;
  *(undefined4 *)(iVar3 + 0x3c) = 0;
  *(undefined4 *)(iVar3 + 0x40) = 0;
  *(uint *)(iVar2 + 4) =
       (*(uint *)(DAT_03800980 & 0xfffffffc) >> (DAT_03800980 & 3) * 8 |
       *(uint *)(DAT_03800980 & 0xfffffffc) << (DAT_03800980 & 3) * -8 + 0x20) & 0xf8ffffff |
       0xa1000000;
  uVar1 = DAT_03800984 + 4U & 3;
  uVar4 = *(uint *)(DAT_03800984 + 4U & 0xfffffffc);
  *(uint *)(iVar3 + 0xec) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  FUN_038009ec(iVar2);
  return;
}

