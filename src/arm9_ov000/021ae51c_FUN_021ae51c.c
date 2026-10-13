/* Decompiled C draft; module arm9_ov000; ROM address 021ae51c. No matching claim. */
#include "types.h"
#include "deps/021ae51c_FUN_021ae51c.h"

byte * FUN_021ae51c(byte *param_1,undefined4 *param_2)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  undefined8 uVar15;
  
  puVar13 = (uint *)0x0;
  *param_2 = 0;
  uVar9 = (int)(uint)*(ushort *)(param_1 + 6) >> 8 | (*(ushort *)(param_1 + 6) & 0xff) << 8;
  if ((uVar9 & DAT_021ae704) != 0) {
    iVar4 = (*param_1 & 0xf) * 4;
    sVar1 = *(short *)(param_1 + 4);
    uVar14 = ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 | (*(ushort *)(param_1 + 0xc) & 0xff) << 8)
             << 0x10 | (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                       (*(ushort *)(param_1 + 0xe) & 0xff) << 8;
    uVar10 = 0;
    puVar12 = DAT_021ae708;
    do {
      if ((((short)puVar12[1] != 0) && (*puVar12 == uVar14)) &&
         (*(short *)((int)puVar12 + 6) == sVar1)) break;
      if (((short)puVar12[1] == 0) && (puVar13 == (uint *)0x0)) {
        puVar13 = puVar12;
      }
      puVar12 = puVar12 + 0xe;
      uVar10 = uVar10 + 1;
    } while (uVar10 < 8);
    iVar5 = ((int)(uint)*(ushort *)(param_1 + 2) >> 8 | (*(ushort *)(param_1 + 2) & 0xff) << 8) +
            (*param_1 & 0xf) * -4;
    uVar6 = uVar9 & DAT_021ae70c;
    iVar7 = uVar6 * 8;
    uVar8 = iVar5 + iVar7;
    if (uVar10 == 8) {
      if ((puVar13 == (uint *)0x0) || (DAT_021ae710 < uVar8)) {
        return (byte *)0x0;
      }
      uVar10 = (*(code *)*DAT_021ae718)(iVar4 + DAT_021ae714);
      puVar13[0xd] = uVar10;
      if (puVar13[0xd] == 0) {
        return (byte *)0x0;
      }
      *puVar13 = uVar14;
      *(short *)((int)puVar13 + 6) = sVar1;
      *(undefined2 *)(puVar13 + 2) = 0;
      uVar15 = func_0x0200f5ac();
      puVar13[0xb] = (uint)uVar15 >> 0x10 | (int)((ulonglong)uVar15 >> 0x20) << 0x10;
      puVar13[0xc] = puVar13[0xd] + 0xe + iVar4;
      func_0x0214d1fc((ushort *)(void *)(param_1),(uint *)(uintptr_t)(puVar13[0xd] + 0xe),iVar4);
      puVar12 = puVar13;
    }
    if (((short)puVar12[1] == 8) || (DAT_021ae710 < uVar8)) {
      *(undefined2 *)(puVar12 + 1) = 0;
      (*(code *)*DAT_021ae71c)(puVar12[0xd]);
      return (byte *)0x0;
    }
    sVar3 = (short)uVar6;
    sVar1 = sVar3 + (short)(iVar5 + 7U >> 3);
    if ((uVar9 & DAT_021ae720) == 0) {
      *(short *)((int)puVar12 + 10) = (short)uVar8;
      *(short *)(puVar12 + 2) = sVar1;
    }
    *(short *)((int)puVar12 + (uint)(ushort)puVar12[1] * 2 + 0xc) = sVar3;
    *(short *)((int)puVar12 + (uint)(ushort)puVar12[1] * 2 + 0x1c) = sVar1;
    *(short *)(puVar12 + 1) = (short)puVar12[1] + 1;
    func_0x0214d1fc((ushort *)(void *)(param_1 + iVar4),(uint *)(uintptr_t)(puVar12[0xc] + iVar7),iVar5);
    if ((ushort)puVar12[2] == 0) {
      return (byte *)0x0;
    }
    uVar11 = 0;
    uVar9 = 0;
    if ((ushort)puVar12[1] != 0) {
      do {
        if ((uVar11 < *(ushort *)((int)puVar12 + uVar9 * 2 + 0xc)) ||
           (uVar2 = *(ushort *)((int)puVar12 + uVar9 * 2 + 0x1c), uVar2 <= uVar11)) {
          uVar9 = uVar9 + 1;
        }
        else {
          uVar9 = 0;
          uVar11 = uVar2;
        }
      } while (uVar9 < (ushort)puVar12[1]);
    }
    if (uVar11 < (ushort)puVar12[2]) {
      return (byte *)0x0;
    }
    uVar9 = puVar12[0xd];
    param_1 = (byte *)(uVar9 + 0xe);
    uVar10 = (uint)*(ushort *)((int)puVar12 + 10) + (*(byte *)(uVar9 + 0xe) & 0xf) * 4 & 0xffff;
    *(ushort *)(uVar9 + 0x10) = (ushort)(uVar10 >> 8) | (ushort)(uVar10 << 8);
    *(undefined2 *)(puVar12 + 1) = 0;
    *param_2 = 1;
  }
  return param_1;
}

