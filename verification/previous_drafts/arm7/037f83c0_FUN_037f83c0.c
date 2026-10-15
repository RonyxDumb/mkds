/* Decompiled C draft; module arm7; ROM address 037f83c0. No matching claim. */
#include "types.h"
#include "deps/037f83c0_FUN_037f83c0.h"

int FUN_037f83c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = FUN_037f9bf0(8);
  uVar2 = FUN_037f9bdc(8);
  iVar3 = FUN_037f9ef4(8,(undefined4 *)(uintptr_t)(uVar2),uVar1,1);
  iVar4 = FUN_037f9bf0(8);
  FUN_037fb2fc((uint *)(uintptr_t)(iVar3),0,iVar4 - iVar3);
  FUN_037f9aec(8,iVar3);
  uVar1 = FUN_037f9bf0(8);
  uVar2 = FUN_037f9bdc(8);
  iVar3 = FUN_037f9e4c(8,uVar2,uVar1);
  if (iVar3 < 0) {
    FUN_037fb000();
  }
  FUN_037f9f9c(8,iVar3);
  FUN_037f9ca8(8,iVar3);
  return iVar3;
}

