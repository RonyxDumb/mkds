/* Decompiled C draft; module arm7; ROM address 037fce24. No matching claim. */
#include "types.h"
#include "deps/037fce24_FUN_037fce24.h"

void FUN_037fce24(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int local_40;
  uint local_30;
  uint local_2c;
  code *pcVar10;
  
  iVar11 = 0;
  local_2c = 0x7f;
  local_30 = 0;
  local_40 = 0;
  do {
    iVar12 = iVar11 * 0x54 + DAT_037fd120;
    uVar8 = (uint)*(byte *)(iVar12 + 3);
    if ((int)(uVar8 << 0x1f) < 0) {
      if ((int)(uVar8 << 0x1e) < 0) {
        *(byte *)(iVar12 + 3) =
             *(byte *)(iVar12 + 3) & 7 | (byte)(((uVar8 << 0x18) >> 0x1b | 1) << 3);
        *(byte *)(iVar12 + 3) = *(byte *)(iVar12 + 3) & 0xfd;
      }
      else {
        iVar13 = FUN_037fbbd8(iVar11);
        if (iVar13 == 0) {
          uVar8 = iVar12 + 0x48U & 3;
          uVar9 = *(uint *)(iVar12 + 0x48U & 0xfffffffc);
          pcVar10 = (code *)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
          if (pcVar10 == (code *)0x0) {
            *(undefined1 *)(iVar12 + 0x22) = 0;
          }
          else {
            uVar8 = iVar12 + 0x4cU & 3;
            uVar9 = *(uint *)(iVar12 + 0x4cU & 0xfffffffc);
            (*pcVar10)(iVar12,1,uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
          }
          *(undefined2 *)(iVar12 + 0x24) = 0;
          *(byte *)(iVar12 + 3) = *(byte *)(iVar12 + 3) & 0xfe;
          goto LAB_037fd108;
        }
      }
      sVar4 = *(short *)(DAT_037fd124 + (uint)*(byte *)(iVar12 + 9) * 2);
      bVar1 = *(byte *)(iVar12 + 8);
      bVar2 = *(byte *)(iVar12 + 5);
      iVar5 = FUN_037fcc94(iVar12,param_1);
      iVar5 = sVar4 + iVar5;
      iVar6 = FUN_037fc514(iVar12,param_1);
      iVar6 = ((uint)bVar1 - (uint)bVar2) * 0x40 + iVar6;
      iVar7 = FUN_037fc478(iVar12,param_1);
      cVar3 = *(char *)(iVar12 + 0x28);
      iVar13 = local_40;
      if (cVar3 == '\0') {
        iVar6 = iVar6 + iVar7;
      }
      else if (cVar3 == '\x01') {
        iVar5 = iVar5 + iVar7;
      }
      else if (cVar3 == '\x02') {
        iVar13 = iVar7;
      }
      iVar13 = iVar13 + *(char *)(iVar12 + 10);
      if (*(byte *)(iVar12 + 4) != 0x7f) {
        iVar13 = (int)(iVar13 * (uint)*(byte *)(iVar12 + 4) + 0x40) >> 7;
      }
      iVar5 = iVar5 + *(short *)(iVar12 + 0xc) + (int)*(short *)(iVar12 + 6);
      sVar4 = *(short *)(iVar12 + 0xe);
      cVar3 = *(char *)(iVar12 + 0xb);
      if ((*(char *)(iVar12 + 2) == '\x03') && (iVar5 <= DAT_037fd128)) {
        *(byte *)(iVar12 + 3) = *(byte *)(iVar12 + 3) & 7 | 0x10;
        uVar8 = iVar12 + 0x48U & 3;
        uVar9 = *(uint *)(iVar12 + 0x48U & 0xfffffffc);
        pcVar10 = (code *)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
        if (pcVar10 == (code *)0x0) {
          *(undefined1 *)(iVar12 + 0x22) = 0;
        }
        else {
          uVar8 = iVar12 + 0x4cU & 3;
          uVar9 = *(uint *)(iVar12 + 0x4cU & 0xfffffffc);
          (*pcVar10)(iVar12,1,uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
        }
        *(undefined2 *)(iVar12 + 0x24) = 0;
        *(byte *)(iVar12 + 3) = *(byte *)(iVar12 + 3) & 0xfe;
      }
      else {
        uVar9 = FUN_037fc010(iVar5);
        uVar8 = FUN_037fc094(*(undefined2 *)(iVar12 + 0x3c),iVar6 + sVar4);
        if (*(char *)(iVar12 + 1) == '\x01') {
          uVar8 = uVar8 & DAT_037fd12c & 0xffff;
        }
        uVar14 = iVar13 + cVar3 + 0x40;
        uVar15 = local_30;
        if ((-1 < (int)uVar14) && (uVar15 = uVar14, 0x7f < (int)uVar14)) {
          uVar15 = local_2c;
        }
        if (uVar9 != *(ushort *)(iVar12 + 0x24)) {
          *(short *)(iVar12 + 0x24) = (short)uVar9;
          *(byte *)(iVar12 + 3) =
               *(byte *)(iVar12 + 3) & 7 |
               (byte)((((uint)*(byte *)(iVar12 + 3) << 0x18) >> 0x1b | 8) << 3);
        }
        if (uVar8 != *(ushort *)(iVar12 + 0x26)) {
          *(short *)(iVar12 + 0x26) = (short)uVar8;
          *(byte *)(iVar12 + 3) =
               *(byte *)(iVar12 + 3) & 7 |
               (byte)((((uint)*(byte *)(iVar12 + 3) << 0x18) >> 0x1b | 4) << 3);
        }
        if (uVar15 != *(byte *)(iVar12 + 0x23)) {
          *(char *)(iVar12 + 0x23) = (char)uVar15;
          *(byte *)(iVar12 + 3) =
               *(byte *)(iVar12 + 3) & 7 |
               (byte)((((uint)*(byte *)(iVar12 + 3) << 0x18) >> 0x1b | 0x10) << 3);
        }
      }
    }
LAB_037fd108:
    iVar11 = iVar11 + 1;
    if (0xf < iVar11) {
      return;
    }
  } while( true );
}

