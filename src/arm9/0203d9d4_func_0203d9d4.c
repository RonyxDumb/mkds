/* Decompiled C draft; module arm9; ROM address 0203d9d4. No matching claim. */
#include "types.h"
#include "deps/0203d9d4_func_0203d9d4.h"

void func_0203d9d4(void)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  bool bVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  undefined1 local_b8 [8];
  uint local_b0 [8];
  uint auStack_90 [8];
  uint auStack_70 [8];
  ushort local_50 [8];
  undefined1 auStack_40 [12];
  undefined1 local_34 [16];
  
  uVar17 = 0;
  uVar8 = *(uint *)(DAT_0203df64 & 0xfffffffc) >> (DAT_0203df64 & 3) * 8 |
          *(uint *)(DAT_0203df64 & 0xfffffffc) << (DAT_0203df64 & 3) * -8 + 0x20;
  uVar18 = (uint)*(byte *)(uVar8 + 0x3d0);
  if (uVar18 != 0) {
    do {
      iVar11 = (*(uint *)(DAT_0203df68 & 0xfffffffc) >> (DAT_0203df68 & 3) * 8 |
               *(uint *)(DAT_0203df68 & 0xfffffffc) << (DAT_0203df68 & 3) * -8 + 0x20) + 0x14;
      iVar16 = iVar11 + uVar17 * 0x8c;
      uVar18 = iVar11 + uVar17 * 0x8c;
      uVar10 = uVar18 & 3;
      uVar18 = *(uint *)(uVar18 & 0xfffffffc);
      if (((uVar18 >> uVar10 * 8 | uVar18 << uVar10 * -8 + 0x20) != 4) &&
         (uVar18 = uVar8 + 0xc & 3, uVar8 = *(uint *)(uVar8 + 0xc & 0xfffffffc),
         (uVar8 >> uVar18 * 8 | uVar8 << uVar18 * -8 + 0x20) != 6)) {
        iVar11 = 0;
        do {
          *(undefined4 *)(iVar16 + iVar11 * 4 + 0x4c) = 0;
          iVar11 = iVar11 + 1;
        } while (iVar11 < 0x10);
        GetDriverMaybeSfxPosition((undefined4 *)(void *)(auStack_40),uVar17);
        uVar9 = GetDriverEntry(uVar17);
        GetMQRacerVector333(uVar9,(uint *)(void *)(local_34));
        func_0203df74((undefined4)(uintptr_t)(auStack_40),iVar16);
        bVar5 = false;
        iVar11 = IsDriverInLoop(((uint)*(ushort *)(iVar16 + 0x3c) << 0x18) >> 0x1c);
        if ((iVar11 == 0) &&
           (uVar8 = (*(uint *)(DAT_0203df6c & 0xfffffffc) >> (DAT_0203df6c & 3) * 8 |
                    *(uint *)(DAT_0203df6c & 0xfffffffc) << (DAT_0203df6c & 3) * -8 + 0x20) + 0x44,
           uVar18 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
           iVar11 = func_02040d68((uint)(uintptr_t)(local_b8),(uint)*(ushort *)(iVar16 + 0x32) * 0x24 +
                                           (uVar8 >> uVar18 * 8 | uVar8 << uVar18 * -8 + 0x20) +
                                           0x10), iVar11 < DAT_0203df70)) {
          bVar5 = true;
        }
        if (bVar5) {
          *(ushort *)(iVar16 + 0x30) = *(ushort *)(iVar16 + 0x30) | 4;
        }
        else {
          *(ushort *)(iVar16 + 0x30) = *(ushort *)(iVar16 + 0x30) & 0xfffb;
        }
        uVar8 = iVar16 + 0x44U & 3;
        uVar18 = *(uint *)(iVar16 + 0x44U & 0xfffffffc);
        local_b0[uVar17] = uVar18 >> uVar8 * 8 | uVar18 << uVar8 * -8 + 0x20;
      }
      uVar8 = *(uint *)(DAT_0203df64 & 0xfffffffc) >> (DAT_0203df64 & 3) * 8 |
              *(uint *)(DAT_0203df64 & 0xfffffffc) << (DAT_0203df64 & 3) * -8 + 0x20;
      uVar18 = (uint)*(byte *)(uVar8 + 0x3d0);
      uVar17 = uVar17 + 1 & 0xffff;
    } while (uVar17 < uVar18);
  }
  uVar10 = DAT_0203df68;
  uVar17 = DAT_0203df64;
  if (uVar18 < 2) {
    uVar8 = *(uint *)(DAT_0203df68 & 0xfffffffc) >> (DAT_0203df68 & 3) * 8 |
            *(uint *)(DAT_0203df68 & 0xfffffffc) << (DAT_0203df68 & 3) * -8 + 0x20;
    uVar17 = 1;
    *(ushort *)(uVar8 + 0x50) = *(ushort *)(uVar8 + 0x50) & 0xfff0 | 1;
    uVar14 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
             *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
    uVar8 = uVar14 + 0x3c;
    uVar18 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)(uVar14 + 0x3c) = (uVar8 >> uVar18 * 8 | uVar8 << uVar18 * -8 + 0x20) + 1;
    *(undefined1 *)
     ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
      *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x474) = 0;
    do {
      iVar11 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
               *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + uVar17;
      uVar17 = uVar17 + 1 & 0xffff;
      *(undefined1 *)(iVar11 + 0x474) = 0xff;
      uVar8 = DAT_0203df68;
    } while (uVar17 < 8);
  }
  else {
    uVar15 = *(uint *)(DAT_0203df68 & 0xfffffffc) >> (DAT_0203df68 & 3) * 8 |
             *(uint *)(DAT_0203df68 & 0xfffffffc) << (DAT_0203df68 & 3) * -8 + 0x20;
    uVar14 = 0;
    uVar2 = *(ushort *)(uVar15 + 0x10);
    uVar13 = (uint)*(ushort *)(uVar15 + 0xe);
    uVar7 = uVar13;
    if (uVar18 != 0) {
      do {
        iVar11 = uVar14 * 0x8c + uVar15;
        iVar16 = (*(ushort *)(iVar11 + 0x50) & 0xf) - 1;
        auStack_90[iVar16] = local_b0[uVar14];
        local_50[iVar16] = (ushort)uVar14;
        uVar12 = iVar11 + 0x38;
        uVar1 = uVar12 & 3;
        uVar12 = *(uint *)(uVar12 & 0xfffffffc);
        auStack_70[iVar16] = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
        uVar14 = uVar14 + 1 & 0xffff;
      } while (uVar14 < *(byte *)(uVar8 + 0x3d0));
    }
    while (uVar7 = uVar7 + 1 & 0xffff, (int)uVar7 < (int)(uVar18 - uVar2)) {
      uVar15 = auStack_90[uVar7];
      uVar3 = local_50[uVar7];
      uVar14 = auStack_70[uVar7];
      for (uVar8 = uVar7; (int)uVar13 < (int)uVar8; uVar8 = uVar8 - 1) {
        iVar11 = uVar8 - 1;
        uVar12 = auStack_70[iVar11];
        if (((int)uVar14 <= (int)uVar12) &&
           ((uVar14 != uVar12 || ((int)uVar15 <= (int)auStack_90[iVar11])))) break;
        auStack_70[uVar8] = uVar12;
        uVar4 = local_50[iVar11];
        auStack_90[uVar8] = auStack_90[iVar11];
        local_50[uVar8] = uVar4;
      }
      auStack_90[uVar8] = uVar15;
      local_50[uVar8] = uVar3;
    }
    uVar8 = 0;
    if (uVar18 != 0) {
      do {
        if (local_50[uVar8] < 8) {
          iVar11 = (uint)local_50[uVar8] * 0x8c;
          iVar16 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                   *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x50;
          *(ushort *)(iVar16 + iVar11) =
               *(ushort *)(iVar16 + iVar11) & 0xfff0 | (ushort)((uVar8 + 1) * 0x10000 >> 0x10) & 0xf
          ;
        }
        uVar18 = uVar17 & 3;
        uVar14 = *(uint *)(uVar17 & 0xfffffffc);
        uVar8 = uVar8 + 1 & 0xffff;
      } while (uVar8 < *(byte *)((uVar14 >> uVar18 * 8 | uVar14 << uVar18 * -8 + 0x20) + 0x3d0));
    }
    uVar10 = DAT_0203df68;
    uVar18 = DAT_0203df64;
    iVar11 = (*(uint *)(DAT_0203df68 & 0xfffffffc) >> (DAT_0203df68 & 3) * 8 |
             *(uint *)(DAT_0203df68 & 0xfffffffc) << (DAT_0203df68 & 3) * -8 + 0x20) + 0x3c;
    uVar17 = iVar11 + (uint)local_50[0] * 0x8c;
    uVar8 = uVar17 & 3;
    uVar14 = *(uint *)(uVar17 & 0xfffffffc);
    uVar17 = 0;
    *(uint *)(iVar11 + (uint)local_50[0] * 0x8c) =
         (uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20) + 1;
    uVar8 = DAT_0203df68;
    if (*(char *)((*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                  *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
      do {
        uVar8 = uVar10 & 3;
        uVar14 = *(uint *)(uVar10 & 0xfffffffc);
        *(char *)((uVar14 >> uVar8 * 8 | uVar14 << uVar8 * -8 + 0x20) + uVar17 + 0x474) =
             (char)local_50[uVar17];
        uVar17 = uVar17 + 1 & 0xffff;
        uVar8 = DAT_0203df68;
      } while (uVar17 < *(byte *)((*(uint *)(uVar18 & 0xfffffffc) >> (uVar18 & 3) * 8 |
                                  *(uint *)(uVar18 & 0xfffffffc) << (uVar18 & 3) * -8 + 0x20) +
                                 0x3d0));
    }
    for (; uVar18 = DAT_0203df68, uVar17 < 8; uVar17 = uVar17 + 1 & 0xffff) {
      puVar6 = (uint *)(DAT_0203df68 & 0xfffffffc);
      uVar10 = DAT_0203df68 & 3;
      DAT_0203df68 = uVar8;
      *(undefined1 *)((*puVar6 >> uVar10 * 8 | *puVar6 << uVar10 * -8 + 0x20) + uVar17 + 0x474) =
           0xff;
      uVar8 = DAT_0203df68;
      DAT_0203df68 = uVar18;
    }
  }
  DAT_0203df68 = uVar8;
  uVar9 = 0;
  uVar17 = (*(uint *)(DAT_0203df64 & 0xfffffffc) >> (DAT_0203df64 & 3) * 8 |
           *(uint *)(DAT_0203df64 & 0xfffffffc) << (DAT_0203df64 & 3) * -8 + 0x20) + 0xc;
  uVar8 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  switch(uVar17 >> uVar8 * 8 | uVar17 << uVar8 * -8 + 0x20) {
  case 0:
    iVar11 = func_02040bc0();
    if (iVar11 != 0) {
      uVar9 = 1;
    }
    break;
  case 1:
    goto LAB_0203ddf0;
  case 2:
    goto LAB_0203ddf0;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
LAB_0203ddf0:
    uVar9 = 1;
  }
  uVar18 = DAT_0203df68;
  uVar8 = DAT_0203df64;
  *(undefined4 *)
   ((*(uint *)(DAT_0203df68 & 0xfffffffc) >> (DAT_0203df68 & 3) * 8 |
    *(uint *)(DAT_0203df68 & 0xfffffffc) << (DAT_0203df68 & 3) * -8 + 0x20) + 0x4f0) = uVar9;
  uVar17 = 0;
  if (*(char *)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3d0) == '\0') {
    return;
  }
  do {
    uVar10 = uVar18 & 3;
    uVar14 = *(uint *)(uVar18 & 0xfffffffc);
    iVar11 = (uVar14 >> uVar10 * 8 | uVar14 << uVar10 * -8 + 0x20) + 0x14;
    uVar10 = iVar11 + uVar17 * 0x8c;
    uVar14 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar10 = uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20;
    iVar11 = iVar11 + uVar17 * 0x8c;
    if (((uVar10 == 1) || (uVar10 == 2)) || (uVar14 = 0, uVar10 == 3)) {
      uVar14 = 1;
    }
    if ((uVar14 != 0) || ((*(ushort *)(iVar11 + 0x30) & 0x40) == 0)) goto LAB_0203def4;
    NotifyDriverFinished((undefined4 *)(uintptr_t)(iVar11),1);
    iVar16 = func_0203ef58();
    if (iVar16 == 0) goto LAB_0203dee8;
    uVar10 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
             *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8;
    uVar14 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    switch(uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) {
    case 0:
    default:
switchD_0203deac_default:
      RaceModeDefault_SomeFn();
      break;
    case 1:
      break;
    case 2:
      RaceModeBattle_OrMissionRun_SomeFn();
      break;
    case 3:
      goto switchD_0203deac_default;
    case 4:
      RaceModeMissionRun_SomeFn();
      break;
    case 5:
      RaceModeNet_SomeFn();
    }
LAB_0203dee8:
    *(ushort *)(iVar11 + 0x30) = *(ushort *)(iVar11 + 0x30) & 0xffbf;
LAB_0203def4:
    if ((((*(ushort *)(iVar11 + 0x30) & 8) != 0) &&
        (*(ushort *)(iVar11 + 0x30) = *(ushort *)(iVar11 + 0x30) & 0xfff7,
        uVar10 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                 *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 8, uVar14 = uVar10 & 3,
        uVar10 = *(uint *)(uVar10 & 0xfffffffc),
        (uVar10 >> uVar14 * 8 | uVar10 << uVar14 * -8 + 0x20) != 4)) &&
       (StructMQRacerEntry_SomeFn_21_ById(((uint)*(ushort *)(iVar11 + 0x3c) << 0x18) >> 0x1c),
       (*(ushort *)(iVar11 + 0x30) & 1) != 0)) {
      MaybePlayCrowdAmbientNoise(0);
    }
    uVar17 = uVar17 + 1 & 0xffff;
    if (*(byte *)((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x3d0) <= uVar17) {
      return;
    }
  } while( true );
}

