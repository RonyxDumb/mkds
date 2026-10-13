/* Decompiled C draft; module arm9; ROM address 02051f00. No matching claim. */
#include "types.h"
#include "deps/02051f00_func_02051f00.h"

void func_02051f00(int param_1)

{
  byte *pbVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  code *pcVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined1 uStack_d8;
  undefined1 uStack_d7;
  undefined1 uStack_d6;
  undefined1 uStack_d5;
  undefined1 uStack_d4;
  undefined1 uStack_d3;
  undefined4 auStack_d0 [15];
  ushort uStack_94;
  int iStack_8c;
  ushort uStack_88;
  byte bStack_85;
  undefined1 auStack_80 [116];
  
  uVar9 = *(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
          *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20;
  uVar5 = uVar9 + 0xc & 3;
  uVar4 = *(uint *)(uVar9 + 0xc & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) != 7) {
    return;
  }
  if (*(short *)(param_1 + 2) == 0) {
    if (*(short *)(param_1 + 8) == 4) {
      if (*(char *)(uVar9 + 0x438) == '\0') {
        *(char *)(uVar9 + 0x439) = *(char *)(uVar9 + 0x439) + '\x01';
      }
    }
    else if (*(short *)(param_1 + 8) == 5) {
      uVar5 = uVar9 + 0x28 & 3;
      uVar4 = *(uint *)(uVar9 + 0x28 & 0xfffffffc);
      DC_InvalidateRangeNoClean(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,0xc0);
      uVar5 = (*(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
              *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20) + 0x28;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      Mem_CpuCopy8((ushort *)(uintptr_t)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20),auStack_d0,0xc0);
      DC_SomeClean((uint)(uintptr_t)(auStack_d0),0xc0);
      uVar4 = *(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
              *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20;
      uVar5 = uVar4 + 4;
      uVar9 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) == 0xd) {
        uVar2 = *(undefined2 *)(param_1 + 0x12);
        iVar6 = func_020204c0((int)(uintptr_t)(auStack_d0));
        uVar5 = uRam02052284;
        if (iVar6 == 0) {
          if (((7 < uStack_94) && (iStack_8c == 0x25)) && ((bStack_85 & 1) != 0)) {
            if ((bStack_85 & 2) == 0) {
              *(undefined4 *)
               ((*(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
                *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20) + 0x1ed8) =
                   3;
            }
            else {
              *(undefined4 *)
               ((*(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
                *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20) + 0x1ed8) =
                   2;
            }
            uVar4 = uRam02052284;
            *(undefined2 *)
             ((*(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
              *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20) + 0x1edc) =
                 uVar2;
            uVar5 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            *(undefined2 *)((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0x1ede) = 0;
          }
        }
        else {
          *(undefined4 *)
           ((*(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
            *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20) + 0x1ed0) = 1;
          *(undefined2 *)
           ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x1ed4) = uVar2;
          *(undefined2 *)
           ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x1ed6) = 0;
        }
      }
      else {
        bVar3 = true;
        if (((uStack_94 < 8) || (iStack_8c != 0x25)) || ((bStack_85 & 1) == 0)) {
          bVar3 = false;
        }
        else {
          uVar4 = uVar4 + 0x444;
          uVar5 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          pcVar12 = (code *)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
          if ((pcVar12 != (code *)0x0) && (iVar6 = (*pcVar12)(auStack_d0), iVar6 == 0)) {
            bVar3 = false;
          }
        }
        if (bVar3) {
          uVar9 = *(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
                  *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20;
          uVar5 = uVar9 + 0x440;
          uVar4 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          pcVar12 = (code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
          if (pcVar12 == (code *)0x0) {
            if (((*(ushort *)(uVar9 + 0x436) & 1) != 0) && ((uStack_88 & 0x8000) != 0)) {
              uStack_d8 = *(undefined1 *)(param_1 + 10);
              uStack_d7 = *(undefined1 *)(param_1 + 0xb);
              uStack_d6 = *(undefined1 *)(param_1 + 0xc);
              uStack_d5 = *(undefined1 *)(param_1 + 0xd);
              uStack_d4 = *(undefined1 *)(param_1 + 0xe);
              uStack_d3 = *(undefined1 *)(param_1 + 0xf);
              func_02052288((int)(uintptr_t)(auStack_d0),&uStack_d8,(undefined4)(uintptr_t)(auStack_80));
              puVar16 = auStack_d0;
              iVar6 = 0xc;
              uVar5 = (*(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
                      *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20) + 0x24
              ;
              uVar4 = uVar5 & 3;
              uVar5 = *(uint *)(uVar5 & 0xfffffffc);
              puVar17 = (undefined4 *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20);
              do {
                uVar7 = *puVar16;
                uVar10 = puVar16[1];
                uVar13 = puVar16[2];
                uVar15 = puVar16[3];
                puVar16 = puVar16 + 4;
                *puVar17 = uVar7;
                puVar17[1] = uVar10;
                puVar17[2] = uVar13;
                puVar17[3] = uVar15;
                puVar17 = puVar17 + 4;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
            }
          }
          else {
            (*pcVar12)(param_1,auStack_d0);
          }
        }
        else {
          uVar5 = *(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
                  *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20;
          if (*(char *)(uVar5 + 0x438) == '\0') {
            *(char *)(uVar5 + 0x439) = *(char *)(uVar5 + 0x439) + '\x01';
          }
        }
      }
    }
    uVar5 = uRam02052284;
    uVar4 = *(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
            *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20;
    if (((*(ushort *)(uVar4 + 0x436) & 1) != 0) &&
       (uVar9 = uVar4 + 4 & 3, uVar8 = *(uint *)(uVar4 + 4 & 0xfffffffc),
       (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) != 0xd)) {
      iVar6 = uVar4 + 0xac;
      iVar14 = 0;
      do {
        if (((int)((uint)*(byte *)(iVar6 + 0xdc) << 0x1f) < 0) &&
           (*(char *)(iVar6 + 0xdb) = *(char *)(iVar6 + 0xdb) + '\x01',
           200 < *(byte *)(iVar6 + 0xdb))) {
          iVar11 = 0;
          *(byte *)(iVar6 + 0xdc) = *(byte *)(iVar6 + 0xdc) & 0xfe;
          uVar4 = uVar5 & 3;
          uVar9 = *(uint *)(uVar5 & 0xfffffffc);
          uVar4 = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
          iVar18 = uVar4 + 0xac;
          *(undefined2 *)(uVar4 + 0x434) = 0;
          do {
            pbVar1 = (byte *)(iVar18 + 0xdc);
            iVar11 = iVar11 + 1;
            iVar18 = iVar18 + 0xe0;
            if ((int)((uint)*pbVar1 << 0x1f) < 0) {
              *(short *)(uVar4 + 0x434) = *(short *)(uVar4 + 0x434) + 1;
            }
          } while (iVar11 < 4);
        }
        iVar14 = iVar14 + 1;
        iVar6 = iVar6 + 0xe0;
      } while (iVar14 < 4);
    }
    uVar5 = *(uint *)(uRam02052284 & 0xfffffffc) >> (uRam02052284 & 3) * 8 |
            *(uint *)(uRam02052284 & 0xfffffffc) << (uRam02052284 & 3) * -8 + 0x20;
    if (*(char *)(uVar5 + 0x43b) != '\0') {
      uVar4 = uVar5 + 0x440 & 3;
      uVar8 = *(uint *)(uVar5 + 0x440 & 0xfffffffc);
      uVar9 = uVar5 + 0x444 & 3;
      uVar5 = *(uint *)(uVar5 + 0x444 & 0xfffffffc);
      func_020527c0(1,uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,
                    uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20);
      return;
    }
    *(undefined4 *)(uVar5 + 0x10) = 0;
    return;
  }
  func_020533a0();
  return;
}

