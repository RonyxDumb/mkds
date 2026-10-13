/* Decompiled C draft; module arm9; ROM address 0208b60c. No matching claim. */
#include "types.h"
#include "deps/0208b60c_func_0208b60c.h"

void func_0208b60c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int local_10;
  int local_c;
  int local_8;
  
  local_10 = (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                  *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) >> 4;
  uVar1 = param_2 + 4 & 3;
  uVar4 = *(uint *)(param_2 + 4 & 0xfffffffc);
  local_c = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8 & 3;
  uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
  local_8 = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  iVar3 = func_02018600(*(uint *)(uRam0208b6ac & 0xfffffffc) >> (uRam0208b6ac & 3) * 8 |
                        *(uint *)(uRam0208b6ac & 0xfffffffc) << (uRam0208b6ac & 3) * -8 + 0x20,
                        param_1,(undefined4)(uintptr_t)(&local_10));
  if (iVar3 == 0) {
    return;
  }
  uVar1 = iVar3 + 0x20U & 3;
  uVar4 = *(uint *)(iVar3 + 0x20U & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  bVar2 = *(byte *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x54);
  if ((bVar2 & 0x80) == 0) {
    if ((bVar2 & 0x40) != 0) {
      uVar1 = iVar3 + 0x80U & 3;
      uVar4 = *(uint *)(iVar3 + 0x80U & 0xfffffffc);
      *(uint *)(iVar3 + 0x80) =
           (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfff8ffff | 0x20000;
    }
    return;
  }
  uVar1 = iVar3 + 0x80U & 3;
  uVar4 = *(uint *)(iVar3 + 0x80U & 0xfffffffc);
  *(uint *)(iVar3 + 0x80) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xfff8ffff | 0x10000
  ;
  return;
}

