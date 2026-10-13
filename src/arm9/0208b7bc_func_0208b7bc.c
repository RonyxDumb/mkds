/* Decompiled C draft; module arm9; ROM address 0208b7bc. No matching claim. */
#include "types.h"
#include "deps/0208b7bc_func_0208b7bc.h"

void func_0208b7bc(undefined4 param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  
  uVar3 = (*(code *)(*(uint *)(uRam0208b86c & 0xfffffffc) >> (uRam0208b86c & 3) * 8 |
                    *(uint *)(uRam0208b86c & 0xfffffffc) << (uRam0208b86c & 3) * -8 + 0x20))
                    (&local_18,param_1);
  local_14 = (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                  *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  local_10 = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  local_c = (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) >> 4;
  iVar4 = func_02018600(uVar3,local_18,(undefined4)(uintptr_t)(&local_14));
  if (iVar4 == 0) {
    return;
  }
  uVar1 = iVar4 + 0x20U & 3;
  uVar5 = *(uint *)(iVar4 + 0x20U & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  bVar2 = *(byte *)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x54);
  if ((bVar2 & 0x80) == 0) {
    if ((bVar2 & 0x40) != 0) {
      uVar1 = iVar4 + 0x80U & 3;
      uVar5 = *(uint *)(iVar4 + 0x80U & 0xfffffffc);
      *(uint *)(iVar4 + 0x80) =
           (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xfff8ffff | 0x20000;
    }
    return;
  }
  uVar1 = iVar4 + 0x80U & 3;
  uVar5 = *(uint *)(iVar4 + 0x80U & 0xfffffffc);
  *(uint *)(iVar4 + 0x80) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) & 0xfff8ffff | 0x10000
  ;
  return;
}

