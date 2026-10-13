/* Decompiled C draft; module arm7; ROM address 037fe634. No matching claim. */
#include "types.h"
#include "deps/037fe634_FUN_037fe634.h"

int FUN_037fe634(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  int unaff_r5;
  
  switch(param_3) {
  case 0:
    uVar1 = param_1 + 0x28U & 3;
    uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    unaff_r5 = FUN_037fe7ec(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x28U & 3;
    uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 1;
    break;
  case 1:
    unaff_r5 = FUN_037fe79c();
    break;
  case 2:
    unaff_r5 = FUN_037fe6fc();
    break;
  case 3:
    sVar2 = FUN_037fe79c();
    sVar3 = FUN_037fe79c(param_1);
    iVar7 = FUN_037fbf70();
    unaff_r5 = (iVar7 * (((int)sVar3 - (int)sVar2) + 1) >> 0x10) + (int)sVar2;
    break;
  case 4:
    uVar1 = param_1 + 0x28U & 3;
    uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    uVar5 = FUN_037fe7ec(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x28U & 3;
    uVar4 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 1;
    psVar6 = (short *)FUN_037fd3c0(param_2,uVar5);
    if (psVar6 != (short *)0x0) {
      unaff_r5 = (int)*psVar6;
    }
  }
  return unaff_r5;
}

