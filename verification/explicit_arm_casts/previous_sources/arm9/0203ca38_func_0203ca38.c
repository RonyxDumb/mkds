/* Decompiled C draft; module arm9; ROM address 0203ca38. No matching claim. */
#include "types.h"
#include "deps/0203ca38_func_0203ca38.h"

void func_0203ca38(void)

{
  bool bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  
  func_0203fed4();
  uVar7 = DAT_0203ccfc;
  uVar5 = DAT_0203ccf8;
  uVar3 = *(uint *)(DAT_0203ccf8 & 0xfffffffc) >> (DAT_0203ccf8 & 3) * 8 |
          *(uint *)(DAT_0203ccf8 & 0xfffffffc) << (DAT_0203ccf8 & 3) * -8 + 0x20;
  uVar10 = uVar3 + 8 & 3;
  uVar6 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  if (((uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) == 5) &&
     (uVar10 = 0, *(char *)(uVar3 + 0x3d0) != '\0')) {
    do {
      uVar3 = uVar7 & 3;
      uVar6 = *(uint *)(uVar7 & 0xfffffffc);
      iVar9 = uVar10 * 0x8c + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) + 0x14;
      uVar3 = ((uint)*(ushort *)(iVar9 + 0x3c) << 0x16) >> 0x1e;
      if (uVar3 == 0) goto LAB_0203cb04;
      NotifyDriverFinished(iVar9,uVar3 == 1);
      iVar4 = func_0203ef58();
      if (iVar4 == 0) goto LAB_0203caf8;
      uVar3 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 8;
      uVar6 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      switch(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) {
      case 0:
      default:
switchD_0203cabc_default:
        RaceModeDefault_SomeFn();
        break;
      case 1:
        break;
      case 2:
        RaceModeBattle_OrMissionRun_SomeFn();
        break;
      case 3:
        goto switchD_0203cabc_default;
      case 4:
        RaceModeMissionRun_SomeFn();
        break;
      case 5:
        RaceModeNet_SomeFn();
      }
LAB_0203caf8:
      *(ushort *)(iVar9 + 0x3c) = *(ushort *)(iVar9 + 0x3c) & 0xfcff;
LAB_0203cb04:
      uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < *(byte *)(uVar3 + 0x3d0));
  }
  uVar10 = (*(uint *)(DAT_0203cd00 & 0xfffffffc) >> (DAT_0203cd00 & 3) * 8 |
           *(uint *)(DAT_0203cd00 & 0xfffffffc) << (DAT_0203cd00 & 3) * -8 + 0x20) + 0x44;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if (uVar10 >> uVar5 * 8 != 0 || uVar10 << uVar5 * -8 + 0x20 != 0) {
    func_0203d9d4();
    goto LAB_0203cb8c;
  }
  uVar10 = uVar3 + 0xc & 3;
  uVar5 = *(uint *)(uVar3 + 0xc & 0xfffffffc);
  uVar8 = 0;
  switch(uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) {
  case 0:
    iVar9 = func_02040bc0();
    if (iVar9 != 0) {
      uVar8 = 1;
    }
    break;
  case 1:
    goto LAB_0203cb6c;
  case 2:
    goto LAB_0203cb6c;
  case 3:
    break;
  case 4:
    break;
  case 5:
    break;
  case 6:
LAB_0203cb6c:
    uVar8 = 1;
  }
  *(undefined4 *)
   ((*(uint *)(DAT_0203ccfc & 0xfffffffc) >> (DAT_0203ccfc & 3) * 8 |
    *(uint *)(DAT_0203ccfc & 0xfffffffc) << (DAT_0203ccfc & 3) * -8 + 0x20) + 0x4f0) = uVar8;
LAB_0203cb8c:
  uVar3 = DAT_0203ccfc;
  uVar7 = DAT_0203ccf8;
  uVar6 = *(uint *)(DAT_0203ccf8 & 0xfffffffc) >> (DAT_0203ccf8 & 3) * 8 |
          *(uint *)(DAT_0203ccf8 & 0xfffffffc) << (DAT_0203ccf8 & 3) * -8 + 0x20;
  uVar10 = uVar6 + 8;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) == 2) {
    uVar10 = 0;
    if (*(char *)(uVar6 + 0x3d0) != '\0') {
      do {
        sVar2 = func_020a1250(uVar10);
        uVar5 = uVar3 & 3;
        uVar6 = *(uint *)(uVar3 & 0xfffffffc);
        iVar9 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x50;
        *(ushort *)(iVar9 + uVar10 * 0x8c) =
             *(ushort *)(iVar9 + uVar10 * 0x8c) & 0xfff0 | sVar2 + 1U & 0xf;
        uVar5 = uVar7 & 3;
        uVar6 = *(uint *)(uVar7 & 0xfffffffc);
        uVar10 = uVar10 + 1 & 0xffff;
      } while (uVar10 < *(byte *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x3d0));
    }
    uVar5 = DAT_0203ccfc;
    uVar10 = 0;
    do {
      uVar7 = uVar5 & 3;
      uVar3 = *(uint *)(uVar5 & 0xfffffffc);
      iVar9 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + uVar10;
      uVar10 = uVar10 + 1 & 0xffff;
      *(undefined1 *)(iVar9 + 0x474) = 0xff;
    } while (uVar10 < 8);
    func_0203d078();
    iVar9 = func_0203cfb4();
    if (iVar9 != 0) {
      func_0203d21c();
    }
  }
  uVar10 = (*(uint *)(DAT_0203ccf8 & 0xfffffffc) >> (DAT_0203ccf8 & 3) * 8 |
           *(uint *)(DAT_0203ccf8 & 0xfffffffc) << (DAT_0203ccf8 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) == 4) {
    func_0203cd14();
  }
  uVar7 = *(uint *)(DAT_0203ccf8 & 0xfffffffc) >> (DAT_0203ccf8 & 3) * 8 |
          *(uint *)(DAT_0203ccf8 & 0xfffffffc) << (DAT_0203ccf8 & 3) * -8 + 0x20;
  uVar10 = uVar7 + 8;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if ((uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) == 1) {
    bVar1 = false;
    uVar7 = *(uint *)(DAT_0203ccfc & 0xfffffffc) >> (DAT_0203ccfc & 3) * 8 |
            *(uint *)(DAT_0203ccfc & 0xfffffffc) << (DAT_0203ccfc & 3) * -8 + 0x20;
    uVar10 = uVar7 + 0x14 & 3;
    uVar5 = *(uint *)(uVar7 + 0x14 & 0xfffffffc);
    uVar10 = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
    if (((uVar10 == 1) || (uVar10 == 2)) || (uVar10 == 3)) {
      bVar1 = true;
    }
    if (!bVar1) {
      return;
    }
    uVar10 = uVar7 + 0x4cc & 3;
    uVar5 = *(uint *)(uVar7 + 0x4cc & 0xfffffffc);
    if (uVar5 >> uVar10 * 8 == 0 && uVar5 << uVar10 * -8 + 0x20 == 0) {
      *(undefined4 *)(uVar7 + 0x4cc) = 1;
    }
    return;
  }
  uVar10 = *(uint *)(DAT_0203ccfc & 0xfffffffc) >> (DAT_0203ccfc & 3) * 8 |
           *(uint *)(DAT_0203ccfc & 0xfffffffc) << (DAT_0203ccfc & 3) * -8 + 0x20;
  if (*(ushort *)(uVar10 + 0xe) < (ushort)*(byte *)(uVar7 + 0x3d0)) {
    return;
  }
  uVar10 = uVar10 + 0x4cc;
  uVar5 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  if (uVar10 >> uVar5 * 8 != 0 || uVar10 << uVar5 * -8 + 0x20 != 0) {
    return;
  }
  func_0203d21c();
  return;
}

