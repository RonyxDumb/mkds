/* Decompiled C draft; module arm7; ROM address 060159f8. No matching claim. */
#include "types.h"
#include "deps/060159f8_FUN_060159f8.h"

void FUN_060159f8(ushort *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = (*(uint *)(DAT_06015c3c & 0xfffffffc) >> (DAT_06015c3c & 3) * 8 |
          *(uint *)(DAT_06015c3c & 0xfffffffc) << (DAT_06015c3c & 3) * -8 + 0x20) + DAT_06015c40;
  uVar6 = 0;
  uVar3 = 0xffffffff;
  while( true ) {
    if (2 < uVar6) {
      if (uVar3 != 0xffffffff) {
        iVar2 = FUN_06009138((*(uint *)(DAT_06015c3c & 0xfffffffc) >> (DAT_06015c3c & 3) * 8 |
                             *(uint *)(DAT_06015c3c & 0xfffffffc) << (DAT_06015c3c & 3) * -8 + 0x20)
                             + 0x188,DAT_06015c44);
        if (iVar2 == 0) {
          FUN_06009360(4);
        }
        else {
          iVar5 = iVar7 + uVar3 * 0x18;
          thunk_FUN_037fb230(param_2,iVar5 + 4,0x10);
          *(undefined2 *)(iVar7 + uVar3 * 0x18) = 5;
          *(int *)(iVar5 + 0x14) = iVar2;
          thunk_FUN_037fb230(param_1,iVar2 + 0x18,param_1[4] + 0xc);
          uVar3 = (*(uint *)(DAT_06015c3c & 0xfffffffc) >> (DAT_06015c3c & 3) * 8 |
                  *(uint *)(DAT_06015c3c & 0xfffffffc) << (DAT_06015c3c & 3) * -8 + 0x20) + 0x30c;
          uVar6 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          thunk_FUN_037fb1a8(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
          iVar7 = thunk_FUN_03806b2c(*(ushort *)(iVar2 + 0x18) & 0xf0,0x10);
          *(ushort *)(iVar5 + 0x10) = *(ushort *)(iVar5 + 0x10) & 0xfff0 | (ushort)iVar7 & 0xf;
          uVar4 = *(uint *)(DAT_06015c3c & 0xfffffffc) >> (DAT_06015c3c & 3) * 8 |
                  *(uint *)(DAT_06015c3c & 0xfffffffc) << (DAT_06015c3c & 3) * -8 + 0x20;
          uVar3 = uVar4 + 0x560;
          uVar6 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          *(uint *)(uVar4 + 0x560) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7;
          *(ushort *)(iVar2 + 0x20) = param_1[4] - 0x18;
          uVar1 = thunk_FUN_03806d38(*(undefined2 *)(iVar2 + 0x20));
          *(undefined2 *)(iVar5 + 2) = uVar1;
        }
      }
      return;
    }
    iVar2 = iVar7 + uVar6 * 0x18;
    uVar4 = uVar6;
    if ((((*(short *)(iVar7 + uVar6 * 0x18) != 0) &&
         (iVar5 = FUN_0600a578((short *)(uintptr_t)(iVar2 + 4),(short *)(uintptr_t)(param_2)), uVar4 = uVar3, iVar5 != 0)) &&
        (iVar5 = FUN_0600a578((short *)(uintptr_t)(iVar2 + 10),(short *)(uintptr_t)(param_2 + 6)), iVar5 != 0)) &&
       (((uint)*(ushort *)(param_2 + 0xc) << 0x10) >> 0x14 ==
        ((uint)*(ushort *)(iVar2 + 0x10) << 0x10) >> 0x14)) break;
    uVar6 = uVar6 + 1;
    uVar3 = uVar4;
  }
  iVar7 = thunk_FUN_03806b2c(*param_1 & 0xf0,0x10);
  uVar3 = iVar7 - (*(ushort *)(iVar2 + 0x10) & 0xf);
  if (uVar3 == 0) {
    return;
  }
  if ((uVar3 & 0x80000000) != 0) {
    return;
  }
  uVar3 = iVar2 + 0x14U & 3;
  uVar6 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  uVar6 = (uint)*(ushort *)(uVar3 + 0x20);
  uVar4 = (param_1[4] - uVar6) - 0x18;
  if (uVar4 == 0) {
    return;
  }
  if ((uVar4 & 0x80000000) != 0) {
    return;
  }
  thunk_FUN_037fb230((int)param_1 + uVar6 + 0x24,uVar3 + 0x3c + uVar6,uVar4);
  *(short *)(uVar3 + 0x20) = *(short *)(uVar3 + 0x20) + (short)uVar4;
  *(ushort *)(iVar2 + 0x10) = *(ushort *)(iVar2 + 0x10) & 0xfff0 | (ushort)iVar7 & 0xf;
  uVar4 = *(uint *)(DAT_06015c3c & 0xfffffffc) >> (DAT_06015c3c & 3) * 8 |
          *(uint *)(DAT_06015c3c & 0xfffffffc) << (DAT_06015c3c & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x560;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 0x560) = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + iVar7;
  return;
}

