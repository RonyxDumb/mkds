/* Decompiled C draft; module arm9; ROM address 0205081c. No matching claim. */
#include "types.h"
#include "deps/0205081c_func_0205081c.h"

void func_0205081c(byte param_1,undefined2 *param_2)

{
  uint uVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar9 = DAT_02050b7c;
  switch(*param_2) {
  case 0:
    break;
  case 1:
    uVar9 = (uint)(param_2 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    *(byte *)((*(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
              *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20) + 0x15f6) =
         (byte)(uVar7 >> uVar9 * 8) | (byte)(uVar7 << uVar9 * -8 + 0x20);
    func_02050080();
    func_02058b10();
    return;
  case 2:
    uVar9 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
    if (uVar9 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
    }
    if (uVar7 == 2) {
      uVar7 = (uint)(param_2 + 2) & 3;
      uVar4 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
      *(byte *)(uVar9 + 0x457) = (byte)(uVar4 >> uVar7 * 8) | (byte)(uVar4 << uVar7 * -8 + 0x20);
    }
    iVar5 = (*(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20) + DAT_02050b80;
    *(undefined2 *)(iVar5 + 0x10) = 1;
    *(undefined2 *)(iVar5 + 0x12) = 1;
    return;
  case 3:
    uVar9 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
    *(byte *)(uVar9 + 0x1d54) = *(byte *)(uVar9 + 0x1d54) & ~(byte)(1 << (uint)param_1);
    return;
  case 4:
    uVar7 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
    *(byte *)(uVar7 + 0x1d54) = *(byte *)(uVar7 + 0x1d54) | (byte)(1 << (uint)param_1);
    uVar9 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
    if (*(char *)(uVar9 + 0x1d54) == *(char *)(uVar9 + 0x87)) {
      *(undefined4 *)(uVar9 + 0x10) = 0;
    }
    return;
  case 5:
    uVar7 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
    *(byte *)(uVar7 + 0x1e44) = *(byte *)(uVar7 + 0x1e44) | 2;
    *(undefined4 *)
     ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
      *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  case 6:
    uVar9 = (*(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20) + 4;
    uVar7 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    if (uVar9 == 6) {
      func_020559ec((undefined4)(uintptr_t)(param_2 + 1),*(undefined1 *)(param_2 + 0xb),*(undefined1 *)((int)param_2 + 0x17))
      ;
      return;
    }
    if (uVar9 == 10) {
      func_020597d0((undefined4)(uintptr_t)(param_2 + 1),param_1,*(undefined1 *)(param_2 + 0xb),
                    *(undefined1 *)((int)param_2 + 0x17));
      return;
    }
    return;
  case 7:
    uVar4 = (uint)(param_2 + 2) & 3;
    uVar6 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    uVar7 = 0;
    do {
      uVar12 = 1 << (uVar7 & 0xff);
      if (((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0xffff & uVar12) != 0) {
        uVar13 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        uVar1 = uVar13 + 4 & 3;
        uVar10 = *(uint *)(uVar13 + 4 & 0xfffffffc);
        if (uVar13 == 0) {
          uVar11 = 0;
        }
        else {
          uVar11 = *(uint *)(uVar13 & 0xfffffffc) >> (uVar13 & 3) * 8 |
                   *(uint *)(uVar13 & 0xfffffffc) << (uVar13 & 3) * -8 + 0x20;
        }
        bVar2 = (byte)uVar12;
        if ((uVar11 == 1) &&
           (*(byte *)(uVar13 + 0x87) = *(byte *)(uVar13 + 0x87) & ~bVar2,
           (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20) == 9)) {
          uVar12 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                   *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
          *(byte *)(uVar12 + 0x8a) = *(byte *)(uVar12 + 0x8a) | bVar2;
        }
        uVar12 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        *(byte *)(uVar12 + 0x457) = *(byte *)(uVar12 + 0x457) & ~bVar2;
      }
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < 8);
    uVar9 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
    if (uVar9 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
    }
    if (uVar7 != 1) {
      return;
    }
    if ((*(ushort *)(uVar9 + 0x454) & 0x100) == 0) {
      return;
    }
    bVar3 = false;
    if ((*(ushort *)(uVar9 + 0x454) & 0x40) != 0) {
      if (uVar9 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
      }
      bVar8 = true;
      if ((uVar7 != 1) && (*DAT_02050b84 != 2)) {
        bVar8 = false;
      }
      if (bVar8) {
        bVar3 = true;
      }
    }
    if (bVar3) {
      if (uVar9 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
      }
      if (uVar7 == 1) {
        func_0204bcb4(*(undefined1 *)(uVar9 + 0x457));
        return;
      }
      return;
    }
    return;
  case 8:
    uVar9 = (uint)(param_2 + 2) & 3;
    uVar7 = *(uint *)((uint)(param_2 + 2) & 0xfffffffc);
    *(uint *)((*(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
              *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20) + 0x1eb0) =
         uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
    break;
  case 9:
    uVar9 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
            *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
    if (((uint)*(byte *)(uVar9 + 0x164d) & 1 << (uint)*(byte *)(param_2 + 5)) == 0) {
      Mem_CpuCopy8(param_2 + 1,(uint *)(uintptr_t)((uint)*(byte *)(param_2 + 5) * 0x22c + uVar9 + 0x680),4);
      uVar9 = *(uint *)(DAT_02050b7c & 0xfffffffc) >> (DAT_02050b7c & 3) * 8 |
              *(uint *)(DAT_02050b7c & 0xfffffffc) << (DAT_02050b7c & 3) * -8 + 0x20;
      *(byte *)(uVar9 + 0x164d) = *(byte *)(uVar9 + 0x164d) | (byte)(1 << *(sbyte *)(param_2 + 5));
      return;
    }
    return;
  }
  return;
}

