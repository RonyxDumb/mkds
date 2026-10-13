/* Decompiled C draft; module arm9; ROM address 0203fed4. No matching claim. */
#include "types.h"
#include "deps/0203fed4_func_0203fed4.h"

void func_0203fed4(void)

{
  uint uVar1;
  byte bVar2;
  longlong lVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  iVar13 = 0;
  puVar14 = (uint *)(*(uint *)(DAT_0204018c & 0xfffffffc) >> (DAT_0204018c & 3) * 8 |
                    *(uint *)(DAT_0204018c & 0xfffffffc) << (DAT_0204018c & 3) * -8 + 0x20);
  uVar17 = (uint)(puVar14 + 1) & 3;
  uVar8 = *(uint *)((uint)(puVar14 + 1) & 0xfffffffc);
  puVar7 = puVar14;
  if (uVar8 >> uVar17 * 8 == 0 && uVar8 << uVar17 * -8 + 0x20 == 0) goto LAB_02040164;
  uVar17 = (uint)(puVar14 + 0x13d) & 3;
  uVar8 = *(uint *)((uint)(puVar14 + 0x13d) & 0xfffffffc);
  uVar8 = uVar8 >> uVar17 * 8 | uVar8 << uVar17 * -8 + 0x20;
  uVar17 = DAT_02040190;
  if (uVar8 != 0) {
    uVar17 = uVar8;
  }
  uVar16 = *(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
           *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20;
  uVar5 = (*(uint *)(DAT_02040194 & 0xfffffffc) >> (DAT_02040194 & 3) * 8 |
          *(uint *)(DAT_02040194 & 0xfffffffc) << (DAT_02040194 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 5) || (uVar16 <= DAT_02040198))
  goto LAB_02040000;
  iVar6 = func_0x0219bb50();
  bVar2 = *(byte *)((*(uint *)(DAT_0204019c & 0xfffffffc) >> (DAT_0204019c & 3) * 8 |
                    *(uint *)(DAT_0204019c & 0xfffffffc) << (DAT_0204019c & 3) * -8 + 0x20) + iVar6
                   + 6);
  if ((char)bVar2 < 0) goto LAB_02040000;
  uVar10 = *(uint *)(DAT_0204018c & 0xfffffffc) >> (DAT_0204018c & 3) * 8 |
           *(uint *)(DAT_0204018c & 0xfffffffc) << (DAT_0204018c & 3) * -8 + 0x20;
  uVar5 = (uint)bVar2 * 0x8c + uVar10 + 0x14;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  bVar4 = false;
  if (((uVar5 == 1) || (uVar5 == 2)) || (uVar5 == 3)) {
    bVar4 = true;
  }
  if (bVar4) goto LAB_02040000;
  NotifyDriverFinished((undefined4 *)(uintptr_t)((char)bVar2 * 0x8c + uVar10 + 0x14),0);
  iVar6 = func_0203ef58();
  if (iVar6 == 0) goto LAB_0203fffc;
  uVar5 = (*(uint *)(DAT_02040194 & 0xfffffffc) >> (DAT_02040194 & 3) * 8 |
          *(uint *)(DAT_02040194 & 0xfffffffc) << (DAT_02040194 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  switch(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) {
  case 0:
  default:
switchD_0203ffc0_default:
    RaceModeDefault_SomeFn();
    break;
  case 1:
    break;
  case 2:
    RaceModeBattle_OrMissionRun_SomeFn();
    break;
  case 3:
    goto switchD_0203ffc0_default;
  case 4:
    RaceModeMissionRun_SomeFn();
    break;
  case 5:
    RaceModeNet_SomeFn();
  }
LAB_0203fffc:
  func_0205af90();
LAB_02040000:
  uVar5 = DAT_02040194;
  if (uVar17 < uVar16) {
    if (uVar8 != 0) {
      iVar13 = 1;
    }
  }
  else {
    uVar16 = uVar16 + 1;
  }
  *puVar14 = uVar16;
  uVar1 = DAT_02040190;
  uVar8 = DAT_0204018c;
  uVar16 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
           *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  uVar17 = 0;
  if (*(char *)(uVar16 + 0x3d0) != '\0') {
    do {
      uVar16 = uVar8 & 3;
      uVar10 = *(uint *)(uVar8 & 0xfffffffc);
      iVar6 = uVar17 * 0x8c + (uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20);
      uVar16 = iVar6 + 0x18;
      uVar10 = uVar16 & 3;
      uVar16 = *(uint *)(uVar16 & 0xfffffffc);
      uVar16 = uVar16 >> uVar10 * 8 | uVar16 << uVar10 * -8 + 0x20;
      if (uVar16 <= uVar1) {
        uVar16 = uVar16 + 1;
      }
      *(uint *)(iVar6 + 0x18) = uVar16;
      uVar16 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
               *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar17 = uVar17 + 1 & 0xffff;
    } while (uVar17 < *(byte *)(uVar16 + 0x3d0));
  }
  if (iVar13 != 0) {
    uVar17 = uVar16 + 8 & 3;
    uVar8 = *(uint *)(uVar16 + 8 & 0xfffffffc);
    uVar17 = uVar8 >> uVar17 * 8 | uVar8 << uVar17 * -8 + 0x20;
    if (uVar17 == 2) {
      uVar17 = uVar16 + 0x18 & 3;
      uVar8 = *(uint *)(uVar16 + 0x18 & 0xfffffffc);
      if ((uVar8 >> uVar17 * 8 | uVar8 << uVar17 * -8 + 0x20) == 1) {
        iVar13 = func_020a1520();
        *(int *)((*(uint *)(DAT_0204018c & 0xfffffffc) >> (DAT_0204018c & 3) * 8 |
                 *(uint *)(DAT_0204018c & 0xfffffffc) << (DAT_0204018c & 3) * -8 + 0x20) + 0x4f4) =
             iVar13 * 0x3c;
        *puVar14 = 0;
      }
    }
    else if (uVar17 == 4) {
      func_0203e788((short)*(char *)(uVar16 + 0x62),1);
      bVar4 = true;
      uVar17 = DAT_020401a0 + 4U & 3;
      uVar8 = *(uint *)(DAT_020401a0 + 4U & 0xfffffffc);
      uVar17 = uVar8 >> uVar17 * 8 | uVar8 << uVar17 * -8 + 0x20;
      if ((uVar17 != 2) && (uVar17 != 3)) {
        bVar4 = false;
      }
      if (bVar4) {
        NNSi_MaybeSndPlayerStartSeq(DAT_020401a4,0,0x4a);
      }
    }
  }
  iVar13 = DAT_020401a8;
  puVar7 = (uint *)(*(uint *)(DAT_0204018c & 0xfffffffc) >> (DAT_0204018c & 3) * 8 |
                   *(uint *)(DAT_0204018c & 0xfffffffc) << (DAT_0204018c & 3) * -8 + 0x20);
  uVar17 = (int)puVar7 + DAT_020401a8 + 8;
  uVar8 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  uVar11 = uVar17 >> uVar8 * 8 | uVar17 << uVar8 * -8 + 0x20;
  uVar17 = (uint)(puVar7 + 0x11f) & 3;
  uVar8 = *(uint *)((uint)(puVar7 + 0x11f) & 0xfffffffc);
  uVar9 = uVar8 >> uVar17 * 8 | uVar8 << uVar17 * -8 + 0x20;
  uVar17 = (int)puVar7 + DAT_020401a8 + 4;
  uVar8 = uVar17 & 3;
  uVar16 = *(uint *)(uVar17 & 0xfffffffc);
  lVar3 = (ulonglong)uVar9 * (ulonglong)uVar11;
  uVar15 = (uint)lVar3;
  uVar17 = (int)puVar7 + DAT_020401a8 + 0xc;
  uVar5 = uVar17 & 3;
  uVar10 = *(uint *)(uVar17 & 0xfffffffc);
  uVar17 = (int)puVar7 + DAT_020401a8 + 0x10;
  uVar1 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  uVar12 = uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20;
  uVar17 = (int)puVar7 + DAT_020401a8 + 0x14;
  uVar1 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  puVar7[0x11f] = uVar12 + uVar15;
  *(uint *)((int)puVar7 + iVar13 + 4) =
       (uVar17 >> uVar1 * 8 | uVar17 << uVar1 * -8 + 0x20) +
       (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) * uVar9 +
       uVar11 * (uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20) +
       (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar12,uVar15);
  uVar17 = (int)puVar7 + iVar13 + 4;
  uVar8 = uVar17 & 3;
  uVar17 = *(uint *)(uVar17 & 0xfffffffc);
  iVar13 = -(int)(short)((ushort)((ushort)((uVar17 >> uVar8 * 8) >> 0x10) |
                                 (ushort)((uVar17 << uVar8 * -8 + 0x20) >> 0x10)) >> 4);
LAB_02040164:
  MaybeConvertElapsedTime
            ((undefined1 *)(uintptr_t)((int)puVar7 + 10),(undefined1 *)(uintptr_t)((int)puVar7 + 0xb),(undefined2 *)(void *)(puVar7 + 2),iVar13,
             *(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
             *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20);
  return;
}

