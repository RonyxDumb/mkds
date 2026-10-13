/* Decompiled C draft; module arm9; ROM address 0210920c. No matching claim. */
#include "types.h"
#include "deps/0210920c_func_0210920c.h"

int func_0210920c(int param_1)

{
  int iVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = param_1 + 0xcU & 3;
  uVar6 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar7 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = FX_Atan2((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) << 0xc,
                   (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) * -0x1000);
  if (uRam021092a8 < uVar4) {
    uVar4 = iRam021092ac - uVar4 & 0xffff;
  }
  lVar2 = (ulonglong)(uVar4 * 0x1000) * 0xffffffe0;
  uVar7 = (uint)lVar2;
  iVar1 = (int)(uVar7 + 0x800 >> 0xc |
               (((int)(uVar4 * 0x1000) >> 0x1f) * -0x20 + (int)((ulonglong)lVar2 >> 0x20) +
               (uint)(0xfffff7ff < uVar7)) * 0x100000) >> 0xc;
  iVar5 = iVar1 + 0x7f;
  if (iVar1 + 0xff < 0 == SBORROW4(iVar5,-0x80)) {
    if (0x7f < iVar5) {
      iVar5 = 0x7f;
    }
    return iVar5;
  }
  return -0x80;
}

