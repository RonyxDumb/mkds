/* Decompiled C draft; module arm9; ROM address 02110114. No matching claim. */
#include "types.h"
#include "deps/02110114_func_02110114.h"

void func_02110114(undefined4 param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(DAT_02110300 & 0xfffffffc) >> (DAT_02110300 & 3) * 8 |
          *(uint *)(DAT_02110300 & 0xfffffffc) << (DAT_02110300 & 3) * -8 + 0x20;
  switch(*(uint *)(DAT_021102fc & 0xfffffffc) >> (DAT_021102fc & 3) * 8 |
         *(uint *)(DAT_021102fc & 0xfffffffc) << (DAT_021102fc & 3) * -8 + 0x20) {
  case 0:
    iVar2 = func_0x02181528();
    lVar1 = (longlong)
            (int)(*(uint *)(DAT_02110304 & 0xfffffffc) >> (DAT_02110304 & 3) * 8 |
                 *(uint *)(DAT_02110304 & 0xfffffffc) << (DAT_02110304 & 3) * -8 + 0x20) *
            (longlong)(0x29000 - iVar2) + 0x800;
    uVar4 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc;
    uVar5 = 0;
    if ((-1 < (int)uVar4) &&
       (uVar5 = *(uint *)(DAT_02110300 & 0xfffffffc) >> (DAT_02110300 & 3) * 8 |
                *(uint *)(DAT_02110300 & 0xfffffffc) << (DAT_02110300 & 3) * -8 + 0x20,
       (int)uVar4 <= (int)uVar5)) {
      uVar5 = uVar4;
    }
    break;
  case 1:
    uVar5 = 0;
    break;
  case 2:
    uVar5 = 0;
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    if (((*(uint *)(DAT_02110308 & 0xfffffffc) >> (DAT_02110308 & 3) * 8 |
         *(uint *)(DAT_02110308 & 0xfffffffc) << (DAT_02110308 & 3) * -8 + 0x20) == 2) &&
       ((int)(*(uint *)((uint)DAT_0211030c & 0xfffffffc) >> ((uint)DAT_0211030c & 3) * 8 |
             *(uint *)((uint)DAT_0211030c & 0xfffffffc) << ((uint)DAT_0211030c & 3) * -8 + 0x20) <
        0x14)) {
      uVar5 = 0;
    }
    break;
  case 6:
    break;
  case 7:
  }
  if ((*(uint *)(DAT_02110310 & 0xfffffffc) >> (DAT_02110310 & 3) * 8 |
      *(uint *)(DAT_02110310 & 0xfffffffc) << (DAT_02110310 & 3) * -8 + 0x20) ==
      (*(uint *)(DAT_021102fc & 0xfffffffc) >> (DAT_021102fc & 3) * 8 |
      *(uint *)(DAT_021102fc & 0xfffffffc) << (DAT_021102fc & 3) * -8 + 0x20)) {
    *DAT_0211030c =
         (*(uint *)((uint)DAT_0211030c & 0xfffffffc) >> ((uint)DAT_0211030c & 3) * 8 |
         *(uint *)((uint)DAT_0211030c & 0xfffffffc) << ((uint)DAT_0211030c & 3) * -8 + 0x20) + 1;
  }
  else {
    *DAT_0211030c = 0;
  }
  if (uVar5 == (*(uint *)(DAT_02110300 & 0xfffffffc) >> (DAT_02110300 & 3) * 8 |
               *(uint *)(DAT_02110300 & 0xfffffffc) << (DAT_02110300 & 3) * -8 + 0x20)) {
    uVar4 = DAT_02110314 + 4 & 3;
    uVar3 = *(uint *)(DAT_02110314 + 4 & 0xfffffffc);
    *DAT_02110318 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  }
  else {
    *DAT_02110318 =
         *(uint *)(DAT_02110314 & 0xfffffffc) >> (DAT_02110314 & 3) * 8 |
         *(uint *)(DAT_02110314 & 0xfffffffc) << (DAT_02110314 & 3) * -8 + 0x20;
  }
  func_02108eb4(1,0x7f);
  func_0212c524(param_1,DAT_0211031c,0);
  uVar4 = (uint)(DAT_02110318 + 1) & 3;
  uVar3 = *(uint *)((uint)(DAT_02110318 + 1) & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = (int)uVar4 >> 0xc;
  if (uVar5 == uVar3) {
    uVar5 = 0xffffffff;
  }
  else {
    if ((int)uVar5 < (int)uVar3) {
      uVar4 = uVar4 - (*(uint *)((uint)DAT_02110318 & 0xfffffffc) >> ((uint)DAT_02110318 & 3) * 8 |
                      *(uint *)((uint)DAT_02110318 & 0xfffffffc) <<
                      ((uint)DAT_02110318 & 3) * -8 + 0x20);
      if ((int)uVar4 >> 0xc < (int)uVar5) {
        uVar4 = uVar5 << 0xc;
      }
    }
    else {
      uVar4 = uVar4 + (*(uint *)((uint)DAT_02110318 & 0xfffffffc) >> ((uint)DAT_02110318 & 3) * 8 |
                      *(uint *)((uint)DAT_02110318 & 0xfffffffc) <<
                      ((uint)DAT_02110318 & 3) * -8 + 0x20);
      if ((int)uVar5 < (int)uVar4 >> 0xc) {
        uVar4 = uVar5 << 0xc;
      }
    }
    uVar5 = (int)uVar4 >> 0xc;
    DAT_02110318[1] = uVar4;
    uVar3 = uVar5;
  }
  uVar4 = *(uint *)(DAT_02110300 & 0xfffffffc) >> (DAT_02110300 & 3) * 8 |
          *(uint *)(DAT_02110300 & 0xfffffffc) << (DAT_02110300 & 3) * -8 + 0x20;
  *DAT_02110320 = uVar3;
  if (((int)uVar3 <= (int)uVar4) && (uVar4 = uVar3, (int)uVar3 < 0)) {
    uVar4 = 0;
  }
  *DAT_02110320 = uVar4;
  if (uVar5 != 0xffffffff) {
    func_0212c678(param_1);
    return;
  }
  return;
}

