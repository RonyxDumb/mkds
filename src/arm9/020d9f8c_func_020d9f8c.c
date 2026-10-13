/* Decompiled C draft; module arm9; ROM address 020d9f8c. No matching claim. */
#include "types.h"
#include "deps/020d9f8c_func_020d9f8c.h"

void func_020d9f8c(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int unaff_r5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar5 = func_02108e6c(10);
  uVar3 = (uint)(param_1 + 0x5c) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 0x5c) & 0xfffffffc);
  if (uVar7 >> uVar3 * 8 != 0 || uVar7 << uVar3 * -8 + 0x20 != 0) {
    uVar7 = *(uint *)(DAT_020da36c & 0xfffffffc) >> (DAT_020da36c & 3) * 8 |
            *(uint *)(DAT_020da36c & 0xfffffffc) << (DAT_020da36c & 3) * -8 + 0x20;
    uVar3 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) == 0x1f) {
      unaff_r5 = func_020a02c8();
    }
    else {
      unaff_r5 = 0x7f000;
    }
    if (-1 < unaff_r5) {
      func_02105b28(uVar5,unaff_r5);
    }
  }
  uVar10 = DAT_020da37c;
  uVar7 = DAT_020da374;
  uVar3 = (uint)(param_1 + 9) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 9) & 0xfffffffc);
  switch(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) {
  case 0:
    param_1[0xc] = (int)*(short *)(DAT_020da370 + ((int)(uint)*(ushort *)(param_1 + 0xb) >> 4) * 4);
    uVar3 = (uint)(param_1 + 10) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    uVar10 = (uint)(param_1 + 0xc) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 0xc) & 0xfffffffc);
    uVar6 = (uint)(param_1 + 7) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) *
            (longlong)(int)(uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20);
    param_1[1] = (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
                 ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[4] = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
    *(short *)(param_1 + 0xb) = (short)param_1[0xb] + *(short *)((int)param_1 + 0x2e);
    *(short *)((int)param_1 + 0x3a) =
         *(short *)((int)param_1 + 0x3a) + *(short *)((int)param_1 + 0x2e);
    if ((uVar7 < *(ushort *)(param_1 + 0xb)) && (*(ushort *)(param_1 + 0xb) < DAT_020da378)) {
      param_1[9] = 1;
      *(undefined2 *)(param_1 + 0xe) = 0;
      *(undefined2 *)((int)param_1 + 0x3e) = *(undefined2 *)((int)param_1 + 0x2e);
    }
    break;
  case 1:
    *(short *)(param_1 + 0xe) = (short)param_1[0xe] + 1;
    if ((uint)*(ushort *)(param_1 + 0xd) < (uint)*(ushort *)(param_1 + 0xe)) {
      param_1[9] = 2;
      uVar3 = (uint)(param_1 + 0x5c) & 3;
      uVar7 = *(uint *)((uint)(param_1 + 0x5c) & 0xfffffffc);
      if ((uVar7 >> uVar3 * 8 != 0 || uVar7 << uVar3 * -8 + 0x20 != 0) && (-1 < unaff_r5)) {
        local_30 = 0x114;
        local_2c = 0;
        local_28 = 4;
        local_24 = func_020d4ef4();
        func_0210b760((uint)(uintptr_t)(&local_30),uVar5);
      }
    }
    else if ((uint)((int)(uint)*(ushort *)(param_1 + 0xd) >> 1) < (uint)*(ushort *)(param_1 + 0xe))
    {
      *(short *)((int)param_1 + 0x3e) = *(short *)((int)param_1 + 0x3e) + 1;
      *(short *)((int)param_1 + 0x3a) =
           *(short *)((int)param_1 + 0x3a) + *(short *)((int)param_1 + 0x3e);
    }
    else {
      *(short *)((int)param_1 + 0x3e) = *(short *)((int)param_1 + 0x3e) + -1;
      *(short *)((int)param_1 + 0x3a) =
           *(short *)((int)param_1 + 0x3a) + *(short *)((int)param_1 + 0x3e);
    }
    break;
  case 2:
    param_1[0xc] = (int)*(short *)(DAT_020da370 + ((int)(uint)*(ushort *)(param_1 + 0xb) >> 4) * 4);
    uVar3 = (uint)(param_1 + 10) & 3;
    uVar9 = *(uint *)((uint)(param_1 + 10) & 0xfffffffc);
    uVar7 = (uint)(param_1 + 0xc) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 0xc) & 0xfffffffc);
    uVar6 = (uint)(param_1 + 7) & 3;
    uVar11 = *(uint *)((uint)(param_1 + 7) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) *
            (longlong)(int)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
    param_1[1] = (uVar11 >> uVar6 * 8 | uVar11 << uVar6 * -8 + 0x20) +
                 ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
    uVar3 = (uint)(param_1 + 1) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
    param_1[4] = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
    *(short *)(param_1 + 0xb) = (short)param_1[0xb] + *(short *)((int)param_1 + 0x2e);
    *(short *)((int)param_1 + 0x3a) =
         *(short *)((int)param_1 + 0x3a) + *(short *)((int)param_1 + 0x2e);
    if (uVar10 < *(ushort *)(param_1 + 0xb)) {
      param_1[9] = 3;
      *(undefined2 *)(param_1 + 0xe) = 0;
      *(undefined2 *)((int)param_1 + 0x3e) = *(undefined2 *)((int)param_1 + 0x2e);
    }
    break;
  case 3:
    *(short *)(param_1 + 0xe) = (short)param_1[0xe] + 1;
    if ((uint)*(ushort *)((int)param_1 + 0x36) < (uint)*(ushort *)(param_1 + 0xe)) {
      param_1[9] = 0;
      uVar3 = (uint)(param_1 + 0x5c) & 3;
      uVar7 = *(uint *)((uint)(param_1 + 0x5c) & 0xfffffffc);
      if ((uVar7 >> uVar3 * 8 != 0 || uVar7 << uVar3 * -8 + 0x20 != 0) && (-1 < unaff_r5)) {
        local_20 = DAT_020da380;
        local_1c = 0;
        local_18 = 4;
        local_14 = func_020d4ef4();
        func_0210b760((uint)(uintptr_t)(&local_20),uVar5);
      }
    }
    else if ((uint)((int)(uint)*(ushort *)((int)param_1 + 0x36) >> 1) <
             (uint)*(ushort *)(param_1 + 0xe)) {
      *(short *)((int)param_1 + 0x3e) = *(short *)((int)param_1 + 0x3e) + 1;
      *(short *)((int)param_1 + 0x3a) =
           *(short *)((int)param_1 + 0x3a) + *(short *)((int)param_1 + 0x3e);
    }
    else {
      *(short *)((int)param_1 + 0x3e) = *(short *)((int)param_1 + 0x3e) + -1;
      *(short *)((int)param_1 + 0x3a) =
           *(short *)((int)param_1 + 0x3a) + *(short *)((int)param_1 + 0x3e);
    }
  }
  *(short *)(param_1 + 0xf) = (short)param_1[0xf] + (short)param_1[0x10];
  iVar2 = DAT_020da370;
  uVar3 = (uint)(param_1 + 0x18) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 0x18) & 0xfffffffc);
  if (uVar7 >> uVar3 * 8 != 0 || uVar7 << uVar3 * -8 + 0x20 != 0) {
    iVar1 = (int)(uint)*(ushort *)(param_1 + 0xf) >> 4;
    uVar3 = (uint)(param_1 + 0x11) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 0x11) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) *
            (longlong)(int)*(short *)(DAT_020da370 + iVar1 * 4);
    uVar3 = (uint)(param_1 + 6) & 3;
    uVar7 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    *param_1 = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
    uVar3 = (uint)(param_1 + 0x11) & 3;
    uVar10 = *(uint *)((uint)(param_1 + 0x11) & 0xfffffffc);
    uVar7 = (uint)(param_1 + 8) & 3;
    uVar6 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) *
            (longlong)(int)*(short *)(iVar2 + (iVar1 * 2 + 1) * 2);
    param_1[2] = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
                 ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
  }
  iVar1 = DAT_020da370;
  iVar2 = (int)((uint)*(ushort *)(param_1 + 0xf) - (uint)*(ushort *)(param_1 + 0x14) & 0xffff) >> 4;
  uVar3 = (uint)(param_1 + 0x12) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 0x12) & 0xfffffffc);
  lVar4 = (longlong)(int)(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) *
          (longlong)(int)*(short *)(DAT_020da370 + iVar2 * 4);
  uVar3 = (uint)(param_1 + 6) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
  param_1[3] = (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
  uVar3 = (uint)(param_1 + 0x12) & 3;
  uVar10 = *(uint *)((uint)(param_1 + 0x12) & 0xfffffffc);
  uVar7 = (uint)(param_1 + 8) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 8) & 0xfffffffc);
  lVar4 = (longlong)(int)(uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) *
          (longlong)(int)*(short *)(iVar1 + (iVar2 * 2 + 1) * 2);
  param_1[5] = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14);
  return;
}

