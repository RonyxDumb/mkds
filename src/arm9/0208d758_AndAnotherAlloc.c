/* Decompiled C draft; module arm9; ROM address 0208d758. No matching claim. */
#include "types.h"
#include "deps/0208d758_AndAnotherAlloc.h"

void AndAnotherAlloc(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = Mem_AllocateHeap(param_1,(uint)*(byte *)((*(uint *)(uRam0208d930 & 0xfffffffc) >>
                                                    (uRam0208d930 & 3) * 8 |
                                                   *(uint *)(uRam0208d930 & 0xfffffffc) <<
                                                   (uRam0208d930 & 3) * -8 + 0x20) + 0x3d0) * 0x88);
  uVar3 = uRam0208d930 & 3;
  uVar2 = *(uint *)(uRam0208d930 & 0xfffffffc);
  *puRam0208d934 = uVar1;
  uVar6 = 0;
  if (*(char *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x3d0) == '\0') {
    return;
  }
  do {
    uVar2 = uRam0208d930;
    iVar5 = uVar6 * 0x88 +
            (*(uint *)((uint)puRam0208d934 & 0xfffffffc) >> ((uint)puRam0208d934 & 3) * 8 |
            *(uint *)((uint)puRam0208d934 & 0xfffffffc) << ((uint)puRam0208d934 & 3) * -8 + 0x20);
    *(short *)(iVar5 + 0x60) = (short)uVar6;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (((uVar6 == (int)*(char *)(uVar3 + 0x62)) ||
        (uVar2 = uVar3 + 0xc & 3, uVar7 = *(uint *)(uVar3 + 0xc & 0xfffffffc),
        (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) == 5)) ||
       (uVar2 = uVar3 + 8 & 3, uVar3 = *(uint *)(uVar3 + 8 & 0xfffffffc),
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 1)) {
      *(undefined4 *)(iVar5 + 0x4c) = 0x14;
      *(undefined4 *)(iVar5 + 0x50) = 0x11;
      uVar1 = uRam0208d938;
      *(undefined4 *)(iVar5 + 0x54) = 0x12;
      *(undefined4 *)(iVar5 + 0x68) = uVar1;
      *(undefined4 *)(iVar5 + 0x6c) = uRam0208d93c;
      *(undefined4 *)(iVar5 + 0x70) = uRam0208d940;
      *(undefined4 *)(iVar5 + 0x74) = uRam0208d944;
      *(undefined4 *)(iVar5 + 0x78) = uRam0208d948;
      *(undefined4 *)(iVar5 + 0x84) = uRam0208d94c;
      *(undefined4 *)(iVar5 + 0x7c) = uRam0208d950;
      *(undefined4 *)(iVar5 + 0x80) = uRam0208d954;
    }
    else {
      *(undefined4 *)(iVar5 + 0x4c) = 0x15;
      *(undefined4 *)(iVar5 + 0x50) = 0x13;
      uVar1 = uRam0208d958;
      *(undefined4 *)(iVar5 + 0x54) = 0xffffffff;
      *(undefined4 *)(iVar5 + 0x68) = uVar1;
      *(undefined4 *)(iVar5 + 0x6c) = uRam0208d95c;
      *(undefined4 *)(iVar5 + 0x70) = uRam0208d960;
      *(undefined4 *)(iVar5 + 0x74) = uRam0208d964;
      *(undefined4 *)(iVar5 + 0x78) = uRam0208d968;
      *(undefined4 *)(iVar5 + 0x84) = uRam0208d96c;
      *(undefined4 *)(iVar5 + 0x7c) = uRam0208d970;
      *(undefined4 *)(iVar5 + 0x80) = uRam0208d974;
    }
    *(undefined4 *)(iVar5 + 0x58) = 0x16;
    *(undefined4 *)(iVar5 + 0x5c) = 0x17;
    uVar3 = 0;
    do {
      iVar4 = iVar5 + uVar3 * 4;
      *(undefined4 *)(iVar4 + 0x10) = 0;
      *(undefined4 *)(iVar4 + 0x18) = 0;
      *(undefined4 *)(iVar5 + uVar3 * 4) = 0;
      *(undefined4 *)(iVar4 + 0x20) = 0;
      *(undefined4 *)(iVar4 + 0x28) = 0;
      uVar3 = uVar3 + 1 & 0xffff;
    } while (uVar3 < 2);
    *(undefined2 *)(iVar5 + 0x30) = 0;
    *(undefined4 *)(iVar5 + 0x34) = 0;
    *(undefined4 *)(iVar5 + 0x38) = 0;
    *(undefined4 *)(iVar5 + 0x3c) = 0;
    *(undefined4 *)(iVar5 + 0x40) = 0;
    *(undefined4 *)(iVar5 + 0x44) = 0;
    *(undefined2 *)(iVar5 + 0x48) = 0;
    *(undefined2 *)(iVar5 + 0x4a) = 0;
    *(undefined2 *)(iVar5 + 0x62) = 0;
    uVar2 = uRam0208d930;
    uVar6 = uVar6 + 1 & 0xffff;
    *(undefined4 *)(iVar5 + 100) = 0;
    uVar3 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  } while (uVar6 < *(byte *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x3d0));
  return;
}

