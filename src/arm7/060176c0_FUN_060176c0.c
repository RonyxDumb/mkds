/* Decompiled C draft; module arm7; ROM address 060176c0. No matching claim. */
#include "types.h"
#include "deps/060176c0_FUN_060176c0.h"

void FUN_060176c0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  short sVar4;
  short sVar5;
  undefined2 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  short *psVar13;
  longlong lVar14;
  undefined2 uStack_6e;
  undefined2 local_6c;
  undefined2 uStack_6a;
  undefined4 local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  int local_54;
  undefined2 local_50;
  undefined2 local_4e;
  short local_4c;
  ushort local_4a;
  ushort local_48;
  undefined2 local_42;
  undefined2 local_3e;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  uVar11 = *(uint *)(DAT_06017d48 & 0xfffffffc) >> (DAT_06017d48 & 3) * 8 |
           *(uint *)(DAT_06017d48 & 0xfffffffc) << (DAT_06017d48 & 3) * -8 + 0x20;
  psVar13 = (short *)(uVar11 + DAT_06017d4c);
  uVar8 = uVar11 + 0x570 & 3;
  uVar7 = *(uint *)(uVar11 + 0x570 & 0xfffffffc);
  *(uint *)(uVar11 + 0x570) = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 1;
  uVar8 = FUN_0600ede8((ushort *)(uintptr_t)(param_1 + 0x1e));
  *(short *)(param_1 + 2) = (short)uVar8;
  if (uVar8 == 0xff) {
    return;
  }
  FUN_0600eba4(uVar8 & 0xffff,*(undefined2 *)(param_1 + 0x12));
  uVar1 = *(ushort *)(param_1 + 6);
  if (uVar1 < 0xd) {
    return;
  }
  thunk_FUN_037fb24c(0,&local_54,0x2c);
  local_54 = param_1 + 0x38;
  local_4c = uVar1 - 0xc;
  local_4a = 2;
  if (*(short *)(uVar11 + 0x362) == 0) {
    local_4a = 3;
  }
  local_48 = 0x38;
  local_50 = *(undefined2 *)(param_1 + 8);
  local_4e = *(undefined2 *)(param_1 + 0x36);
  FUN_060161b4((uint)(uintptr_t)(&local_54));
  if ((local_34 != 0) && ((*(ushort *)(param_1 + 0x16) & 0x8000) != 0)) {
    sVar4 = FUN_060096c4((ushort *)(uintptr_t)(local_34 + 6));
    sVar5 = FUN_060096c4((ushort *)(uintptr_t)(local_34 + 7));
    *DAT_06017d50 = sVar4 + sVar5 * 0x100;
  }
  if ((*psVar13 == 0x13) &&
     (uVar7 = (uint)(psVar13 + 0xc) & 3, uVar9 = *(uint *)((uint)(psVar13 + 0xc) & 0xfffffffc),
     *(short *)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + 0x38) == 1)) {
    if ((local_4a & 9) == 9) {
      FUN_06016b4c(param_1,&local_54);
    }
    goto LAB_06017d24;
  }
  if ((local_4a & 8) == 0) goto LAB_06017d24;
  if (*psVar13 == 0x21) {
    FUN_0600983c();
    if ((local_4a & 0x30) == 0x30) {
      if (*(ushort *)(param_1 + 0x34) < 0x3e9) {
        psVar13[2] = 0;
        if (((local_48 & 2) != 0) && ((local_4a & 2) == 0)) {
          FUN_0600af7c(local_42);
        }
        FUN_0600eaac(uVar8,local_3e);
        uVar7 = local_2c;
        if (*(short *)(uVar11 + 0x350) == 2) {
          if (local_2c == 0) {
            FUN_0600b908(DAT_06017d58,1);
            *DAT_06017d54 = 0;
          }
          else {
            sVar4 = FUN_060096c4((ushort *)(uintptr_t)(local_2c + 6));
            sVar5 = FUN_060096c4((ushort *)(uintptr_t)(uVar7 + 7));
            FUN_0600b908(sVar4 + sVar5 * 0x100,1);
            sVar4 = FUN_060096c4((ushort *)(uintptr_t)(local_2c + 8));
            sVar5 = FUN_060096c4((ushort *)(uintptr_t)(local_2c + 9));
            *DAT_06017d54 = sVar4 + sVar5 * 0x100;
          }
        }
        FUN_060096c4((ushort *)(uintptr_t)(local_30 + 3));
        FUN_0600b39c();
        uVar6 = FUN_060096c4((ushort *)(uintptr_t)(local_30 + 2));
        *(undefined2 *)(uVar11 + 0x3ba) = uVar6;
        FUN_0600b3e8(*(undefined2 *)(param_1 + 0x34));
        *(undefined2 *)(uVar11 + 0x356) = 1;
        *(undefined2 *)(uVar11 + 0x35e) = 1;
        if (*(short *)(uVar11 + 0x350) == 2) {
          *DAT_06017d5c = 3;
        }
        *DAT_06017d60 = *DAT_06017d60 | 1;
      }
      else {
        psVar13[2] = 0xc;
        psVar13[3] = 1;
      }
    }
    else {
      psVar13[2] = 0xc;
      psVar13[3] = 10;
    }
    uVar7 = (uint)(psVar13 + 0xe) & 3;
    uVar9 = *(uint *)((uint)(psVar13 + 0xe) & 0xfffffffc);
    FUN_0600a954((undefined2 *)(uintptr_t)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) + 8),(undefined2 *)(uintptr_t)(param_1 + 0x1e));
    *psVar13 = 0x25;
    FUN_06008a8c(2,1);
  }
  uVar7 = local_2c;
  if (*(short *)(uVar11 + 0x350) == 2) {
    if (local_2c != 0) {
      sVar4 = FUN_060096c4((ushort *)(uintptr_t)(local_2c + 6));
      sVar5 = FUN_060096c4((ushort *)(uintptr_t)(uVar7 + 7));
      FUN_0600b908(sVar4 + sVar5 * 0x100,0);
      sVar4 = FUN_060096c4((ushort *)(uintptr_t)(local_2c + 8));
      sVar5 = FUN_060096c4((ushort *)(uintptr_t)(local_2c + 9));
      *DAT_06017d54 = sVar4 + sVar5 * 0x100;
      sVar4 = FUN_060096c4(local_2c + 1);
      *(short *)(uVar11 + 0x3e4) = sVar4 + -8;
      uVar7 = (uint)*(ushort *)(uVar11 + 0x3e4);
      if (uVar7 != 0) {
        if ((local_2c & 1) == 0) {
          uVar9 = uVar11 + 0x3e0 & 3;
          uVar12 = *(uint *)(uVar11 + 0x3e0 & 0xfffffffc);
          thunk_FUN_037fb230(local_2c + 10,uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20,
                             uVar7 + 1);
          *(undefined2 *)(uVar11 + 0x3e6) = 0;
        }
        else {
          uVar9 = uVar11 + 0x3e0 & 3;
          uVar12 = *(uint *)(uVar11 + 0x3e0 & 0xfffffffc);
          thunk_FUN_037fb230(local_2c + 9,uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20,
                             uVar7 + 2);
          *(undefined2 *)(uVar11 + 0x3e6) = 1;
        }
      }
    }
LAB_06017a60:
    *(undefined2 *)(uVar11 + 0x3c4) = 0;
    FUN_0600ea58(uVar8);
    uVar1 = *(ushort *)(uVar11 + 0x3b2);
    uVar8 = (uint)uVar1 * 0x400;
    lVar14 = thunk_FUN_03806924(*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
                                uVar8,0);
    lVar3 = (ulonglong)uVar1 * 0x400 * (lVar14 + 1U & 0xffffffff);
    iVar10 = (int)(lVar14 + 1U >> 0x20) * uVar8 + (int)((ulonglong)lVar3 >> 0x20);
    uStack_6a = (undefined2)((uint)iVar10 >> 0x10);
    *DAT_06017d64 = uStack_6a;
    local_6c = (undefined2)iVar10;
    *DAT_06017d68 = local_6c;
    uStack_6e = (undefined2)((ulonglong)lVar3 >> 0x10);
    *DAT_06017d6c = uStack_6e;
    *DAT_06017d70 = (ushort)lVar3 | 1;
    if ((*(short *)(uVar11 + 0x350) == 2) && (*(short *)(uVar11 + 0x35e) != 0)) {
      uVar7 = (uint)lVar3 + (uint)uVar1 * -0x400;
      iVar10 = iVar10 - (uint)((uint)lVar3 < uVar8);
      thunk_FUN_037faf70();
      uVar1 = *DAT_06017d74;
      local_68 = CONCAT22(*DAT_06017d78,uVar1);
      local_64 = (uint)*DAT_06017d7c;
      uVar2 = *DAT_06017d74;
      local_60 = CONCAT22(*DAT_06017d78,uVar2);
      local_5c = (uint)*DAT_06017d7c;
      thunk_FUN_037faf84();
      if (uVar1 < uVar2) {
        uVar8 = local_68 - uVar7 >> 10 | (local_64 - (iVar10 + (uint)(local_68 < uVar7))) * 0x400000
        ;
      }
      else {
        uVar8 = local_60 - uVar7 >> 10 | (local_5c - (iVar10 + (uint)(local_60 < uVar7))) * 0x400000
        ;
      }
      if (uVar8 < *(ushort *)(uVar11 + 0x33c)) {
        *DAT_06017d84 = *(ushort *)(uVar11 + 0x33c) - (short)uVar8;
      }
      else {
        *DAT_06017d84 = 0;
      }
    }
    if (((*(short *)(uVar11 + 0x34c) == 0x40) && (local_30 != 0)) &&
       (*(short *)(uVar11 + 0x352) == 1)) {
      uVar8 = FUN_060096c4(local_30 + 2);
      if (*(ushort *)(uVar11 + 0x3ba) != uVar8) {
        *(short *)(uVar11 + 0x3ba) = (short)uVar8;
      }
      *(undefined2 *)(uVar11 + 0x3d2) = 0;
      if ((uVar8 == 0) && (uVar8 = FUN_060096c4(local_30 + 4), (uVar8 & 1) != 0)) {
        *(ushort *)(uVar11 + 0x3d2) = *(ushort *)(uVar11 + 0x3d2) | 1;
      }
      uVar8 = FUN_060096c4(local_30 + 4);
      uVar8 = uVar8 & 0xfe;
      iVar10 = FUN_060096c4(local_30 + 1);
      uVar7 = (uint)*(ushort *)(uVar11 + 0x3ae);
      if (((uVar8 * 8 <= uVar7) && (uVar7 <= (uVar8 + iVar10 + -3) * 8)) &&
         (uVar7 = uVar7 + uVar8 * -8, uVar8 = FUN_060096c4(local_30 + 5 + (uVar7 >> 3)),
         (1 << (uVar7 & 7) & uVar8) != 0)) {
        *(ushort *)(uVar11 + 0x3d2) = *(ushort *)(uVar11 + 0x3d2) | 2;
        FUN_0601429c();
      }
      if (((*(short *)(uVar11 + 0x19c) == 0) && (*(short *)(uVar11 + 0x1a8) == 0)) &&
         (*(short *)(uVar11 + 0x3d2) == 0)) {
        FUN_0600ae00(1);
      }
    }
  }
  else if (*(short *)(uVar11 + 0x350) == 3) goto LAB_06017a60;
  if ((int)((uint)*(ushort *)(uVar11 + 0x33a) << 0x19) < 0) {
    FUN_0600f58c(param_1);
  }
LAB_06017d24:
  if (local_38 != 0) {
    FUN_0601858c(local_42,param_1);
  }
  return;
}

