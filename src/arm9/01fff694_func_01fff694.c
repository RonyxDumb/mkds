/* Decompiled C draft; module arm9; ROM address 01fff694. No matching claim. */
#include "types.h"
#include "deps/01fff694_func_01fff694.h"

void func_01fff694(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar11 = param_1 + 0x200 & 3;
  uVar7 = *(uint *)(param_1 + 0x200 & 0xfffffffc);
  uVar1 = *(ushort *)(param_1 + 0x1ec);
  uVar2 = *(ushort *)(iRam01fff940 + (uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20) * 0x5c);
  uVar11 = param_1 + 0x1fc & 3;
  uVar7 = *(uint *)(param_1 + 0x1fc & 0xfffffffc);
  uVar11 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  *(ushort *)(param_1 + 0x1ec) = uVar1 & 0xdff;
  uVar12 = param_1 + 0x30;
  uVar7 = param_1 + 0x58;
  puVar3 = (ushort *)(param_1 + 0x1ec);
  if ((uVar2 & 0x600) == 0) {
    if ((uVar1 & 0x1000) != 0) {
      *puVar3 = *puVar3 | *puRam01fff948;
    }
  }
  else if ((uVar1 & 0x1000) == 0) {
    *puVar3 = *puVar3 | 0x3000;
  }
  else {
    *puVar3 = *puVar3 | *puRam01fff944;
  }
  iVar4 = DriverContext_IsKilledOrBeingKilled(uVar11);
  if (iVar4 != 0) {
    *(undefined4 *)(param_1 + 0x204) = 0;
    *(undefined4 *)(param_1 + 0x208) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x204) = 0;
  uVar10 = param_1 + 0x20c & 3;
  uVar5 = *(uint *)(param_1 + 0x20c & 0xfffffffc);
  if (uVar5 >> uVar10 * 8 == 0 && uVar5 << uVar10 * -8 + 0x20 == 0) {
    iVar4 = func_01ffc67c(uVar11);
    if ((iVar4 == 0) &&
       (uVar10 = uVar11 + 0x48 & 3, uVar5 = *(uint *)(uVar11 + 0x48 & 0xfffffffc),
       ((uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) & 0x10000) == 0)) {
      func_01fff524(param_1);
      *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam01fff94c;
    }
    else {
      *(undefined4 *)(param_1 + 0x20c) = 1;
    }
  }
  else {
    iVar4 = func_01ffc67c(uVar11);
    if (((iVar4 == 0) &&
        (uVar10 = uVar11 + 0x48 & 3, uVar5 = *(uint *)(uVar11 + 0x48 & 0xfffffffc),
        ((uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) & 0x10000) == 0)) &&
       (uVar10 = uVar11 + 0x44 & 3, uVar5 = *(uint *)(uVar11 + 0x44 & 0xfffffffc),
       ((uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) & 0x10) != 0)) {
      *(undefined4 *)(param_1 + 0x20c) = 0;
    }
  }
  if ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) != 0xf) {
    func_020eddb4(uVar7);
  }
  uVar10 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
           *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
  if (uVar10 != 0x13) {
    if ((((uRam01fff950 & *(ushort *)(param_1 + 0x1ec)) == uRam01fff950) && (uVar10 != 0x13)) &&
       ((uVar10 = param_1 + 0x50 & 3, uVar5 = *(uint *)(param_1 + 0x50 & 0xfffffffc),
        uVar5 >> uVar10 * 8 == 0 && uVar5 << uVar10 * -8 + 0x20 == 0 &&
        (((*(ushort *)(param_1 + 0x1ec) & 0x200) != 0 &&
         (uVar10 = uVar11 + 0x180 & 3, uVar11 = *(uint *)(uVar11 + 0x180 & 0xfffffffc),
         uVar11 >> uVar10 * 8 == 0 && uVar11 << uVar10 * -8 + 0x20 == 0)))))) {
      func_020ee2e4((uint *)(uintptr_t)(uVar7),uVar12);
    }
    func_020f4884((undefined4 *)(uintptr_t)(uVar12));
  }
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 != 0 ||
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 != 0) &&
     (iVar4 = func_020f850c((undefined4 *)(uintptr_t)(param_1),param_1), iVar4 != 0)) {
    uVar11 = param_1 + 0x10 & 3;
    uVar7 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
    uVar10 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
    func_020f8498((undefined4 *)(uintptr_t)(param_1));
    uVar11 = (*(uint *)(uRam01fff954 & 0xfffffffc) >> (uRam01fff954 & 3) * 8 |
             *(uint *)(uRam01fff954 & 0xfffffffc) << (uRam01fff954 & 3) * -8 + 0x20) + uVar10 * 0x1c
    ;
    uVar7 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    if (uVar11 >> uVar7 * 8 != 0 || uVar11 << uVar7 * -8 + 0x20 != 0) {
      func_020f47e4((int *)(uintptr_t)(uVar12),uVar10);
    }
  }
  uVar11 = func_02061f90();
  if ((*(ushort *)(param_1 + 0x1f8) == uVar11) &&
     (uVar11 = param_1 + 0x1f0 & 3, uVar7 = *(uint *)(param_1 + 0x1f0 & 0xfffffffc),
     uVar12 = param_1 + 0x1f0, uVar7 >> uVar11 * 8 != 0 || uVar7 << uVar11 * -8 + 0x20 != 0)) {
    uVar11 = param_1 + 0x1fc & 3;
    uVar7 = *(uint *)(param_1 + 0x1fc & 0xfffffffc);
    uVar13 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
    func_020f3c54(uVar12,(uint *)(uintptr_t)(uVar12),uVar13 + 0x98);
    uVar7 = uVar13 + 0xa0 & 3;
    uVar5 = *(uint *)(uVar13 + 0xa0 & 0xfffffffc);
    uVar11 = (*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
             *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x18;
    uVar10 = uVar11 & 3;
    uVar11 = *(uint *)(uVar11 & 0xfffffffc);
    uVar9 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
    uVar11 = uVar13 + 0x98 & 3;
    uVar14 = *(uint *)(uVar13 + 0x98 & 0xfffffffc);
    uVar10 = uVar9 + 8 & 3;
    uVar8 = *(uint *)(uVar9 + 8 & 0xfffffffc);
    iVar4 = (uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) -
            (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
    iVar6 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) -
            (uVar14 >> uVar11 * 8 | uVar14 << uVar11 * -8 + 0x20);
    if (iRam01fff958 <=
        (int)((ulonglong)((longlong)iVar6 * (longlong)iVar6 + (longlong)iVar4 * (longlong)iVar4) >>
             0x20)) {
      func_020f3a58(uVar12,(uint *)(uintptr_t)(uVar12),uVar13 + 0x98);
    }
  }
  *(undefined4 *)(param_1 + 0x208) = 0;
  return;
}

