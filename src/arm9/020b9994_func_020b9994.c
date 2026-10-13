/* Decompiled C draft; module arm9; ROM address 020b9994. No matching claim. */
#include "types.h"
#include "deps/020b9994_func_020b9994.h"

void func_020b9994(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar6 = *(uint *)(uRam020b9df0 & 0xfffffffc) >> (uRam020b9df0 & 3) * 8 |
          *(uint *)(uRam020b9df0 & 0xfffffffc) << (uRam020b9df0 & 3) * -8 + 0x20;
  uVar10 = uVar6 + 4 & 3;
  uVar9 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  if ((int)uVar10 < 1) {
    return;
  }
  uVar6 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  if ((int)uVar10 < (int)uVar6) {
    uVar6 = uVar10;
  }
  uVar7 = GetB3C4_Cell_RaceMrM(0x15);
  sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
  uVar8 = uRam020b9df0;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 4;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  iVar2 = (int)uVar6 >> 0x1f;
  iVar3 = (int)uVar10 >> 0x1f;
  if ((int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) < 10) {
    lVar1 = (longlong)iRam020b9df8 *
            (longlong)((int)((longlong)iRam020b9df4 * (longlong)(int)uVar6 >> 0x22) - iVar2);
    uVar7 = GetB3C4_Cell_RaceMrM(uVar6 - (int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
    sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
    uVar7 = GetB3C4_Cell_RaceMrM(10);
    sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
    iVar2 = iRam020b9df4;
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
    uVar7 = GetB3C4_Cell_RaceMrM
                      ((uVar10 - iRam020b9df8 *
                                 ((int)((longlong)iVar2 * (longlong)(int)uVar10 >> 0x22) - iVar3)) +
                       0xb);
    sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                             0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
    *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
    return;
  }
  uVar7 = GetB3C4_Cell_RaceMrM
                    (-iVar2 + (int)((longlong)iRam020b9df4 * (longlong)(int)uVar6 >> 0x22),-iVar2,
                     (int)((longlong)iRam020b9df4 * (longlong)(int)uVar6));
  sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
  iVar4 = iRam020b9df4;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  lVar1 = (longlong)iRam020b9df8 *
          (longlong)((int)((longlong)iVar4 * (longlong)(int)uVar6 >> 0x22) - iVar2);
  uVar7 = GetB3C4_Cell_RaceMrM(uVar6 - (int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
  sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  uVar7 = GetB3C4_Cell_RaceMrM(10);
  sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
  iVar2 = iRam020b9df4;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  uVar7 = GetB3C4_Cell_RaceMrM
                    (((int)((longlong)iVar2 * (longlong)(int)uVar10 >> 0x22) - iVar3) + 0xb);
  sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
  iVar2 = iRam020b9df4;
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  uVar7 = GetB3C4_Cell_RaceMrM
                    ((uVar10 - iRam020b9df8 *
                               ((int)((longlong)iVar2 * (longlong)(int)uVar10 >> 0x22) - iVar3)) +
                     0xb);
  sVar5 = MaybeMakeOamSlot(param_1 + (uint)*(ushort *)(param_1 + 0x400) * 8,
                           0x80 - *(ushort *)(param_1 + 0x400) & 0xffff,uVar7);
  *(short *)(param_1 + 0x400) = *(short *)(param_1 + 0x400) + sVar5;
  return;
}

