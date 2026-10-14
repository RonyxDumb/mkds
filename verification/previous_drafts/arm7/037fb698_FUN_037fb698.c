/* Decompiled C draft; module arm7; ROM address 037fb698. No matching claim. */
#include "types.h"
#include "deps/037fb698_FUN_037fb698.h"

bool FUN_037fb698(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_037fb6bc + param_2 * 4 + 0x388;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (1 << (param_1 & 0xff) & (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) != 0;
}

