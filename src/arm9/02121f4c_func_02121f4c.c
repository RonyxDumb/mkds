/* Decompiled C draft; module arm9; ROM address 02121f4c. No matching claim. */
#include "types.h"
#include "deps/02121f4c_func_02121f4c.h"

void func_02121f4c(uint param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
          *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
  uVar2 = uVar5 + 0x1950 & 3;
  uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
  if ((4 < (int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20)) &&
     (((uint)*(byte *)(uVar5 + 0x1f55) & 1 << (param_1 & 0xff)) == 0)) {
    return;
  }
  *(undefined4 *)(uVar5 + param_1 * 4 + 0x1984) = 0;
  uVar2 = func_0x0219bb50();
  if (((((int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) < 10) &&
       (uVar4 = param_2 + 4 & 3, uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc),
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == param_3)) &&
      (*(byte *)(param_2 + 8) == param_1)) && (*(byte *)(param_2 + 9) == uVar2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    return;
  }
  iVar3 = func_021217e8(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                        *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
  uVar2 = DAT_021225a4;
  if (iVar3 == 0) {
    return;
  }
  switch(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) {
  case 0:
    uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    *(byte *)(uVar2 + 0x19aa) = *(byte *)(uVar2 + 0x19aa) | (byte)(1 << (param_1 & 0xff));
    return;
  case 1:
    uVar4 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    *(byte *)(uVar4 + 0x19ab) = *(byte *)(uVar4 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
    uVar4 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_0x021a3264(param_1,param_1 * 0x44 +
                            (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x1d00);
    return;
  case 2:
    uVar4 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0x1950 & 3;
    uVar5 = *(uint *)(uVar4 + 0x1950 & 0xfffffffc);
    if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 1) {
      *(byte *)(uVar4 + 0x19ab) = *(byte *)(uVar4 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
    }
    return;
  case 3:
    break;
  case 4:
    uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0x1950 & 3;
    uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 5) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    if (uVar2 == 6) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    return;
  case 5:
    uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0x1950 & 3;
    uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 6) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      *(undefined1 *)
       ((*(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
        *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20) + 0x19ab) = 0xff;
      return;
    }
    if (uVar2 == 7) {
      uVar2 = param_2 + 0x38 & 3;
      uVar4 = *(uint *)(param_2 + 0x38 & 0xfffffffc);
      if (uVar4 >> uVar2 * 8 != 0 || uVar4 << uVar2 * -8 + 0x20 != 0) {
        Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
        uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
                *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
        *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
        return;
      }
      return;
    }
    return;
  case 6:
    uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0x1950 & 3;
    uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 7) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    if (uVar2 == 8) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    return;
  case 7:
    uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0x1950 & 3;
    uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 8) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    if (uVar2 == 9) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      func_0212145c(param_1);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    return;
  case 8:
    uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0x1950 & 3;
    uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
    if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) != 3) {
      return;
    }
    uVar2 = param_2 + 0x40 & 3;
    uVar4 = *(uint *)(param_2 + 0x40 & 0xfffffffc);
    if (uVar4 >> uVar2 * 8 != 0 || uVar4 << uVar2 * -8 + 0x20 != 0) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    return;
  case 9:
    uVar5 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    uVar2 = uVar5 + 0x1950 & 3;
    uVar4 = *(uint *)(uVar5 + 0x1950 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 == 3) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    if (uVar2 == 4) {
      Mem_CpuCopy8(uVar5 + 0x1d00 + param_1 * 0x44,uVar5 + DAT_021225a8 + param_1 * 0x44);
      uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
              *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
      *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
      return;
    }
    return;
  default:
    return;
  }
  uVar4 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
          *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x1950 & 3;
  uVar5 = *(uint *)(uVar4 + 0x1950 & 0xfffffffc);
  uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  if (uVar2 == 1) {
    Mem_CpuCopy8(uVar4 + 0x1d00 + param_1 * 0x44,uVar4 + DAT_021225a8 + param_1 * 0x44);
    *(undefined1 *)
     ((*(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
      *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20) + 0x19ab) = 0xff;
    return;
  }
  if (uVar2 != 5) {
    if (uVar2 == 4) {
      Mem_CpuCopy8(uVar4 + 0x1d00 + param_1 * 0x44,uVar4 + DAT_021225a8 + param_1 * 0x44);
      *(undefined1 *)
       ((*(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
        *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20) + 0x19ab) = 0xff;
      return;
    }
    return;
  }
  Mem_CpuCopy8(uVar4 + 0x1d00 + param_1 * 0x44,uVar4 + DAT_021225a8 + param_1 * 0x44);
  uVar2 = param_2 + 0x30 & 3;
  uVar4 = *(uint *)(param_2 + 0x30 & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) == 0xffffffff) {
    return;
  }
  uVar2 = param_2 + 0x34 & 3;
  uVar4 = *(uint *)(param_2 + 0x34 & 0xfffffffc);
  if ((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) != 0xffffffff) {
    uVar2 = *(uint *)(DAT_021225a4 & 0xfffffffc) >> (DAT_021225a4 & 3) * 8 |
            *(uint *)(DAT_021225a4 & 0xfffffffc) << (DAT_021225a4 & 3) * -8 + 0x20;
    *(byte *)(uVar2 + 0x19ab) = *(byte *)(uVar2 + 0x19ab) | (byte)(1 << (param_1 & 0xff));
    return;
  }
  return;
}

