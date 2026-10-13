/* Decompiled C draft; module arm9; ROM address 02114604. No matching claim. */
#include "types.h"
#include "deps/02114604_func_02114604.h"

void func_02114604(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = uRam02114658;
  uVar2 = uRam02114654;
  piVar1 = piRam02114650;
  *puRam0211465c =
       -*(int *)(*piRam02114650 + 0x60) & uRam02114654 |
       *(int *)(*piRam02114650 + 100) * -0x10000 & uRam02114658;
  iVar4 = *piVar1;
  *puRam02114660 = -*(int *)(iVar4 + 0x68) & uVar2 | *(int *)(iVar4 + 0x6c) * -0x10000 & uVar3;
  *puRam02114664 = *(int *)(*piVar1 + 0x70) * -0x10000 & uVar3;
  func_02111428();
  return;
}

