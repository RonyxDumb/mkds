/* Decompiled C draft; module arm7; ROM address 060043b8. No matching claim. */
#include "types.h"
#include "deps/060043b8_FUN_060043b8.h"

void FUN_060043b8(int param_1)

{
  uint uVar1;
  bool bVar2;
  ushort uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  undefined8 uVar14;
  undefined1 auStack_266 [6];
  undefined1 auStack_260 [8];
  undefined1 auStack_258 [512];
  undefined1 auStack_58 [10];
  undefined2 local_4e;
  ushort local_4c;
  ushort local_4a;
  undefined2 local_48;
  undefined2 local_46;
  undefined1 auStack_44 [48];
  uint uVar13;
  
  iVar5 = FUN_06000680();
  uVar13 = iVar5 + 0x154cU & 3;
  uVar12 = *(uint *)(iVar5 + 0x154cU & 0xfffffffc);
  uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) == 2) {
    uVar12 = param_1 + 4U & 3;
    uVar7 = *(uint *)(param_1 + 4U & 0xfffffffc);
    thunk_FUN_037fb390(uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20,uVar13 + 0x10,0xc0);
    if ((*(ushort *)(uVar13 + 0x4c) < 0x10) || ((*(byte *)(uVar13 + 0x5b) & 1) != 0)) {
      uVar12 = 1 << (*(ushort *)(uVar13 + 0x46) & 0xff);
      if (((uVar12 & *(ushort *)
                      ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                       *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x1f0)) == 0)
         || (((int)uVar12 >> 1 & DAT_060049ec) == 0)) {
        puVar6 = (undefined2 *)thunk_FUN_03807424();
        *puVar6 = 0xc;
        puVar6[1] = 6;
        puVar6[4] = 6;
        thunk_FUN_038074cc();
      }
      else {
        puVar6 = (undefined2 *)thunk_FUN_03807424();
        *puVar6 = 0xc;
        puVar6[1] = 0;
        puVar6[4] = 6;
        thunk_FUN_038074cc();
        uVar12 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                 *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
        if (*(short *)(uVar12 + 0x1e8) == 1) {
          if ((*(ushort *)(uVar13 + 0x3e) & 1) == 0) {
            *(undefined2 *)(uVar12 + 0x1e8) = 2;
          }
          else {
            *(undefined2 *)(uVar12 + 0x1e8) = 1;
          }
        }
        else if ((*(ushort *)(uVar13 + 0x3e) & 2) == 0) {
          *(undefined2 *)(uVar12 + 0x1e8) = 1;
        }
        else {
          *(undefined2 *)(uVar12 + 0x1e8) = 2;
        }
        if ((*(ushort *)(uVar13 + 0x3c) & 0x20) == 0) {
          *(undefined2 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x1ea) = 0;
        }
        else {
          *(undefined2 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x1ea) = 1;
        }
        if ((*(ushort *)(uVar13 + 0x3c) & 0x10) == 0) {
          *(undefined4 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x194) = 0;
        }
        else {
          *(undefined4 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x194) = 1;
        }
        if (*(short *)(uVar13 + 0x4c) == 0) {
          *(undefined2 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xe2) = 3;
        }
        else {
          *(undefined2 *)
           ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
            *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xe2) = 2;
        }
        iVar5 = FUN_06000294(0xc,(int)(uintptr_t)(auStack_258));
        if (iVar5 != 0) {
          iVar5 = FUN_06002274((undefined2 *)(void *)(auStack_258),0);
          if (*(short *)(iVar5 + 4) == 0) {
            if (*(ushort *)(uVar13 + 0x4c) < 0x10) {
              if (*(short *)(uVar13 + 0x42) == 0) {
                uVar3 = 1;
              }
              else {
                uVar3 = thunk_FUN_03806b2c(DAT_060049f4);
              }
              if (0xff < uVar3) {
                uVar3 = 0xff;
              }
              iVar5 = FUN_060024e0((undefined2 *)(void *)(auStack_258),uVar3);
              if (*(short *)(iVar5 + 4) != 0) {
                FUN_0600437c(DAT_060049f8,*(short *)(iVar5 + 4),0);
                return;
              }
            }
            iVar5 = FUN_060020f4((undefined4)(uintptr_t)(auStack_258));
            if (*(short *)(iVar5 + 4) == 0) {
              *(undefined2 *)
               (*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
               *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) = 3;
              uVar12 = param_1 + 0x20U & 3;
              uVar7 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
              bVar2 = uVar7 >> uVar12 * 8 != 0 || uVar7 << uVar12 * -8 + 0x20 != 0;
              iVar5 = FUN_06002c40((undefined2 *)(void *)(auStack_258),bVar2,0,1);
              if (*(short *)(iVar5 + 4) == 0) {
                *(ushort *)
                 ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                  *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xc2) =
                     (ushort)bVar2;
                thunk_FUN_037fb390(uVar13 + 0x10,auStack_58,0x40);
                if (*(short *)((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                               *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xe2)
                    == 2) {
                  local_4e = 0x20;
                  uVar12 = uVar13 + 0x54 & 3;
                  uVar7 = *(uint *)(uVar13 + 0x54 & 0xfffffffc);
                  local_4c = (ushort)(uVar7 >> uVar12 * 8) | (ushort)(uVar7 << uVar12 * -8 + 0x20);
                  uVar12 = uVar13 + 0x54 & 3;
                  uVar7 = *(uint *)(uVar13 + 0x54 & 0xfffffffc);
                  local_4a = (ushort)((uVar7 >> uVar12 * 8) >> 0x10) |
                             (ushort)((uVar7 << uVar12 * -8 + 0x20) >> 0x10);
                  local_48 = *(undefined2 *)(uVar13 + 0x58);
                  local_46 = 0;
                  thunk_FUN_037fb390(param_1 + 8,auStack_44,0x18);
                }
                iVar5 = FUN_06002b00((undefined2 *)(void *)(auStack_258),2000,(undefined4)(uintptr_t)(auStack_58));
                if ((*(short *)(iVar5 + 4) == 0) && (*(short *)(iVar5 + 6) == 0)) {
                  thunk_FUN_037fb390(iVar5 + 8,
                                     (*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                                     *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) +
                                     DAT_06004a00,6);
                  if ((*(byte *)(uVar13 + 0x5b) & 4) == 0) {
                    sVar10 = 0;
                  }
                  else {
                    sVar10 = 6;
                  }
                  *(short *)((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                             *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x18e) =
                       *(short *)(uVar13 + 0x5e) + 2 + sVar10;
                  if ((*(byte *)(uVar13 + 0x5b) & 4) == 0) {
                    sVar10 = 0;
                  }
                  else {
                    sVar10 = 0x2a;
                  }
                  *(short *)((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                             *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 400) =
                       *(short *)(uVar13 + 0x5c) + 4 + sVar10;
                  thunk_FUN_037fb390((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                                     *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) +
                                     DAT_06004a00,auStack_266,6);
                  iVar5 = FUN_06002a7c(auStack_258,auStack_266,*(undefined2 *)(param_1 + 0x26),2000)
                  ;
                  sVar10 = *(short *)(iVar5 + 4);
                  if ((sVar10 == 0xc) && (*(short *)(iVar5 + 6) == 0x13)) {
                    puVar6 = (undefined2 *)thunk_FUN_03807424();
                    *puVar6 = 0xc;
                    puVar6[1] = 0xc;
                    puVar6[4] = 6;
                    thunk_FUN_038074cc();
                  }
                  else if ((sVar10 == 0) && (*(short *)(iVar5 + 6) == 0)) {
                    thunk_FUN_037fb390((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                                       *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) +
                                       DAT_06004a00,auStack_260,6);
                    iVar5 = FUN_06002978(auStack_258,auStack_260,1,2000);
                    uVar8 = thunk_FUN_037faf70();
                    if ((*(short *)(iVar5 + 4) == 0xc) && (*(short *)(iVar5 + 6) == 0x13)) {
                      thunk_FUN_037faf84();
                      puVar6 = (undefined2 *)thunk_FUN_03807424();
                      *puVar6 = 0xc;
                      puVar6[1] = 0xc;
                      puVar6[4] = 6;
                      thunk_FUN_038074cc();
                    }
                    else if ((*(short *)(iVar5 + 4) == 0) && (*(short *)(iVar5 + 6) == 0)) {
                      *(undefined2 *)
                       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x184) =
                           *(undefined2 *)(iVar5 + 8);
                      *(undefined2 *)
                       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xb6) =
                           *(undefined2 *)(uVar13 + 0x58);
                      thunk_FUN_037fb218(1,(*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                                           *(uint *)(uVar13 & 0xfffffffc) <<
                                           (uVar13 & 3) * -8 + 0x20) + 500,0x10);
                      iVar5 = (int)(*(ushort *)(uVar13 + 0x12) & 0xff) >> 2;
                      if ((*(ushort *)(uVar13 + 0x12) & 2) == 0) {
                        iVar5 = iVar5 + 0x19;
                      }
                      uVar4 = FUN_060001b4(iVar5);
                      *(undefined2 *)
                       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xb8) = uVar4;
                      FUN_06000218(iVar5);
                      uVar9 = thunk_FUN_037faf70();
                      *(undefined2 *)
                       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x17e) = 1;
                      *(undefined2 *)
                       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0x86) = 1;
                      uVar7 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                              *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
                      uVar12 = uVar7 + 0x7b4;
                      uVar1 = uVar12 & 3;
                      uVar11 = *(uint *)(uVar12 & 0xfffffffc);
                      uVar7 = uVar7 + 0x7b8;
                      uVar12 = uVar7 & 3;
                      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
                      if ((uVar7 >> uVar12 * 8 != 0 || uVar7 << uVar12 * -8 + 0x20 != 0) ||
                          (uVar11 >> uVar1 * 8 != 0 || uVar11 << uVar1 * -8 + 0x20 != 0)) {
                        uVar14 = thunk_FUN_037fa278();
                        uVar12 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                                 *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
                        *(uint *)(uVar12 + 0x734) = (uint)uVar14 | 1;
                        *(int *)(uVar12 + 0x738) = (int)((ulonglong)uVar14 >> 0x20);
                      }
                      *(undefined2 *)
                       (*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                       *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) = 8;
                      thunk_FUN_037faf84(uVar9);
                      *(undefined2 *)
                       ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                        *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) + 0xbe) = 1;
                      puVar6 = (undefined2 *)thunk_FUN_03807424();
                      *puVar6 = 0xc;
                      puVar6[1] = 0;
                      puVar6[4] = 7;
                      puVar6[5] = *(undefined2 *)
                                   ((*(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                                    *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20) +
                                   0x184);
                      thunk_FUN_038074cc();
                      thunk_FUN_037faf84(uVar8);
                    }
                    else {
                      thunk_FUN_037faf84(uVar8);
                      FUN_0600437c(6,*(undefined2 *)(iVar5 + 4),*(undefined2 *)(iVar5 + 6));
                    }
                  }
                  else {
                    FUN_0600437c(4,sVar10,*(undefined2 *)(iVar5 + 6));
                  }
                }
                else {
                  FUN_0600437c(3,*(short *)(iVar5 + 4),*(undefined2 *)(iVar5 + 6));
                }
              }
              else {
                FUN_0600437c(1,*(short *)(iVar5 + 4),0);
              }
            }
            else {
              FUN_0600437c(DAT_060049fc,*(short *)(iVar5 + 4),0);
            }
          }
          else {
            FUN_0600437c(DAT_060049f0,*(short *)(iVar5 + 4),0);
          }
        }
      }
    }
    else {
      puVar6 = (undefined2 *)thunk_FUN_03807424();
      *puVar6 = 0xc;
      puVar6[1] = 0xb;
      puVar6[4] = 6;
      thunk_FUN_038074cc();
    }
  }
  else {
    puVar6 = (undefined2 *)thunk_FUN_03807424();
    *puVar6 = 0xc;
    puVar6[1] = 3;
    puVar6[4] = 6;
    thunk_FUN_038074cc();
  }
  return;
}

