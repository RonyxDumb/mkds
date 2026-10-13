/* Decompiled C draft; module arm7; ROM address 06000250. No matching claim. */
#include "types.h"
#include "deps/06000250_FUN_06000250.h"

void FUN_06000250(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_06000288;
  uVar2 = DAT_06000288 + 0x560U & 3;
  uVar3 = *(uint *)(DAT_06000288 + 0x560U & 0xfffffffc);
  *(char *)(DAT_0600028c + (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) = (char)param_1;
  uVar2 = iVar1 + 0x560;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(iVar1 + 0x560) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1 & 0xf;
  param_1 = param_1 ^ (uint)*DAT_06000290 << 1;
  *DAT_06000290 = (ushort)param_1 ^ (ushort)(param_1 >> 0x10);
  return;
}

