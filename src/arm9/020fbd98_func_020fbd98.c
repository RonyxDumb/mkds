/* Decompiled C draft; module arm9; ROM address 020fbd98. No matching claim. */
#include "types.h"
#include "deps/020fbd98_func_020fbd98.h"

void func_020fbd98(int param_1)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = param_1 + 0x2ecU & 3;
  uVar3 = *(uint *)(param_1 + 0x2ecU & 0xfffffffc);
  if ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) == 8) {
    uVar8 = param_1 + 0xd0U & 3;
    uVar3 = *(uint *)(param_1 + 0xd0U & 0xfffffffc);
    uVar4 = func_0208ec64(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
    *(undefined4 *)(param_1 + 0x26c) = uVar4;
  }
  uVar8 = param_1 + 0x27cU & 3;
  uVar3 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  func_020ec918(param_1,uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20,0x21,
                *(undefined2 *)(param_1 + 0x276));
  uVar8 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 1) == 0) {
    uVar8 = param_1 + 0xd4U & 3;
    uVar3 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210b7ec((undefined4 *)(uintptr_t)(param_1 + 0x300),(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x3fffffe0);
    uVar8 = param_1 + 0x270U & 3;
    uVar3 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
    uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
    if (uVar8 != 1) {
      func_02109078(param_1,uVar8,0x7f,0);
    }
  }
  uVar8 = param_1 + 300U & 3;
  uVar3 = *(uint *)(param_1 + 300U & 0xfffffffc);
  uVar10 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  lVar1 = (ulonglong)uVar10 * 0x66;
  uVar8 = param_1 + 0x60U & 3;
  uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(uint *)(param_1 + 0x60) =
       (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) -
       ((uint)lVar1 >> 0xc |
       (((int)uVar10 >> 0x1f) * 0x66 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar8 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 1) != 0) {
    return;
  }
  func_020fc654(param_1);
  func_020fc2e8(param_1,param_1 + 0x5c,1);
  uVar10 = uRam020fc260;
  uVar3 = uRam020fc25c;
  uVar8 = param_1 + 0x278U & 3;
  uVar5 = *(uint *)(param_1 + 0x278U & 0xfffffffc);
  if (uVar5 >> uVar8 * 8 == 0 && uVar5 << uVar8 * -8 + 0x20 == 0) {
    uVar9 = *(uint *)(uRam020fc25c & 0xfffffffc) >> (uRam020fc25c & 3) * 8 |
            *(uint *)(uRam020fc25c & 0xfffffffc) << (uRam020fc25c & 3) * -8 + 0x20;
    uVar8 = uVar9 + 0x4cc;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if (uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0) {
      *(short *)(param_1 + 0x276) =
           (short)*(char *)(uVar9 + (*(ushort *)(param_1 + 0x274) & 0xff) + 0x473);
      while ((iVar6 = IsRacerFinishedRace(*(undefined2 *)(param_1 + 0x276)), iVar6 != 0 &&
             (uVar8 = uVar10 & 3, uVar5 = *(uint *)(uVar10 & 0xfffffffc),
             *(ushort *)(param_1 + 0x274) <
             (ushort)*(byte *)((uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + 0x3d0)))) {
        *(short *)(param_1 + 0x274) = *(short *)(param_1 + 0x274) + 1;
        *(short *)(param_1 + 0x276) =
             (short)*(char *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) +
                              (*(ushort *)(param_1 + 0x274) & 0xff) + 0x473);
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x274) = 1;
      *(short *)(param_1 + 0x276) =
           (short)*(char *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) +
                            (*(ushort *)(param_1 + 0x274) & 0xff) + 0x473);
    }
    if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
      uVar2 = *(ushort *)(param_1 + 0x78) & 0xff;
    }
    else {
      uVar2 = 8;
    }
    if (*(ushort *)(param_1 + 0x276) != uVar2) {
      GetDriverEntry();
      iVar6 = DriverContext_IsKilledOrBeingKilled();
      if (iVar6 == 0) {
        *(ushort *)(param_1 + 0x280) =
             *(ushort *)(param_1 + 0x280) | (ushort)(1 << (*(ushort *)(param_1 + 0x276) & 0xff));
        goto LAB_020fbfdc;
      }
    }
    *(undefined4 *)(param_1 + 0x278) = 1;
  }
LAB_020fbfdc:
  uVar3 = uRam020fc25c;
  uVar8 = param_1 + 0x278U & 3;
  uVar10 = *(uint *)(param_1 + 0x278U & 0xfffffffc);
  if (uVar10 >> uVar8 * 8 != 0 || uVar10 << uVar8 * -8 + 0x20 != 0) {
    uVar8 = 1;
    uVar10 = (uint)*(byte *)((*(uint *)(uRam020fc260 & 0xfffffffc) >> (uRam020fc260 & 3) * 8 |
                             *(uint *)(uRam020fc260 & 0xfffffffc) << (uRam020fc260 & 3) * -8 + 0x20)
                            + 0x3d0);
    if (uVar10 != 0) {
      do {
        uVar5 = uVar3 & 3;
        uVar9 = *(uint *)(uVar3 & 0xfffffffc);
        *(short *)(param_1 + 0x276) =
             (short)*(char *)((uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + (uVar8 & 0xff) +
                             0x473);
        GetDriverEntry(*(undefined2 *)(param_1 + 0x276));
        iVar6 = DriverContext_IsKilledOrBeingKilled();
        if (iVar6 == 0) break;
        uVar8 = uVar8 + 1 & 0xffff;
      } while (uVar8 <= uVar10);
    }
    *(ushort *)(param_1 + 0x280) =
         *(ushort *)(param_1 + 0x280) | (ushort)(1 << (*(ushort *)(param_1 + 0x276) & 0xff));
  }
  iVar6 = func_020fcbb8(param_1,*(undefined2 *)(param_1 + 0x276));
  if (iVar6 != 0) {
    uVar8 = param_1 + 0x228U & 3;
    uVar10 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    uVar3 = param_1 + 0x74U & 3;
    uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    uVar8 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + 0x1fc;
    uVar10 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if ((((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x40000000) == 0) &&
       (uVar8 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x48, uVar3 = uVar8 & 3,
       uVar8 = *(uint *)(uVar8 & 0xfffffffc),
       ((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) & 1) == 0)) {
      uVar7 = 3;
    }
    else {
      uVar7 = 2;
    }
    *(undefined2 *)(param_1 + 0x2f8) = uVar7;
    *(undefined2 *)(param_1 + 0x2fa) = 1;
    uVar8 = param_1 + 0x74U & 3;
    uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x8000000) != 0) {
      uVar8 = param_1 + 0x228U & 3;
      uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      func_020fe71c(5,*(undefined2 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 0x1f8),
                    (int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  uVar3 = func_02061f90();
  uVar8 = uVar3 & 0xffff;
  if ((((((uint)*(ushort *)(param_1 + 0x280) & 1 << (uVar3 & 0xff)) != 0) &&
       (*(ushort *)(param_1 + 0x276) != uVar8)) && (iVar6 = IsRacerFinishedRace(uVar8), iVar6 != 0))
     && (iVar6 = func_020fcbb8(param_1,uVar8), iVar6 != 0)) {
    uVar8 = param_1 + 0x228U & 3;
    uVar10 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    uVar3 = param_1 + 0x74U & 3;
    uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    uVar8 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + 0x1fc;
    uVar10 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    if ((((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x40000000) == 0) &&
       (uVar8 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x48, uVar3 = uVar8 & 3,
       uVar8 = *(uint *)(uVar8 & 0xfffffffc),
       ((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) & 1) == 0)) {
      uVar7 = 3;
    }
    else {
      uVar7 = 2;
    }
    *(undefined2 *)(param_1 + 0x2f8) = uVar7;
    *(undefined2 *)(param_1 + 0x2fa) = 1;
    uVar8 = param_1 + 0x74U & 3;
    uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x8000000) != 0) {
      uVar8 = param_1 + 0x228U & 3;
      uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
      func_020fe71c(5,*(undefined2 *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 0x1f8),
                    (int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  uVar8 = param_1 + 0x2ecU & 3;
  uVar3 = *(uint *)(param_1 + 0x2ecU & 0xfffffffc);
  if ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) <= uRam020fc264) {
    return;
  }
  uVar8 = param_1 + 0x228U & 3;
  uVar3 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar2 = (ushort)*(char *)((*(uint *)(uRam020fc25c & 0xfffffffc) >> (uRam020fc25c & 3) * 8 |
                            *(uint *)(uRam020fc25c & 0xfffffffc) << (uRam020fc25c & 3) * -8 + 0x20)
                           + 0x474);
  if (uVar3 >> uVar8 * 8 != 0 || uVar3 << uVar8 * -8 + 0x20 != 0) {
    return;
  }
  if (7 < uVar2) {
    uVar2 = 0;
  }
  func_020fcb9c(param_1,uVar2);
  uVar8 = param_1 + 0x228U & 3;
  uVar10 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar3 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar8 = (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + 0x1fc;
  uVar10 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  if ((((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) & 0x40000000) == 0) &&
     (uVar8 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) + 0x48, uVar3 = uVar8 & 3,
     uVar8 = *(uint *)(uVar8 & 0xfffffffc),
     ((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) & 1) == 0)) {
    uVar7 = 3;
  }
  else {
    uVar7 = 2;
  }
  *(undefined2 *)(param_1 + 0x2f8) = uVar7;
  *(undefined2 *)(param_1 + 0x2fa) = 1;
  return;
}

