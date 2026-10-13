/* Decompiled C draft; module arm9; ROM address 020d634c. No matching claim. */
#include "types.h"
#include "deps/020d634c_func_020d634c.h"

void func_020d634c(ushort *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int local_40;
  short local_3c;
  short local_3a;
  short local_38;
  int local_34;
  short local_30;
  short local_2e;
  short local_2c;
  uint uVar7;
  
  uVar4 = (uint)(param_1 + 0x3c) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 0x3c) & 0xfffffffc);
  uVar7 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = (uint)(param_1 + 0x10) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 0x10) & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  if (((uVar7 & 1) == 0) && ((param_2 != 0 || ((uVar7 & 3) == 0)))) {
    if ((int)uVar4 < 0x1001) {
      iVar10 = 3;
      iVar8 = 2;
    }
    else {
      iVar10 = 1;
      iVar8 = 0;
    }
    uVar6 = iRam020d6510 + iVar10 * 4;
    uVar7 = uVar6 & 3;
    uVar9 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = iRam020d6510 + iVar8 * 4;
    uVar1 = uVar6 & 3;
    uVar11 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = iRam020d6514 + iVar10 * 4;
    uVar2 = uVar6 & 3;
    uVar5 = *(uint *)(uVar6 & 0xfffffffc);
    iVar10 = iVar10 * 2;
    lVar3 = (longlong)(int)(uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) * (longlong)(int)uVar4;
    local_40 = (uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    uVar6 = iRam020d6514 + iVar8 * 4;
    uVar7 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    iVar8 = iVar8 * 2;
    local_3c = *(short *)(iRam020d6518 + iVar8) +
               (short)((int)*(short *)(iRam020d6518 + iVar10) * uVar4 >> 0xc);
    lVar3 = (longlong)(int)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * (longlong)(int)uVar4;
    local_34 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
    local_3a = *(short *)(iRam020d651c + iVar8) +
               (short)((int)*(short *)(iRam020d651c + iVar10) * uVar4 >> 0xc);
    local_38 = *(short *)(iRam020d6520 + iVar8) +
               (short)((int)*(short *)(iRam020d6520 + iVar10) * uVar4 >> 0xc);
    local_30 = *(short *)(iRam020d6524 + iVar8) +
               (short)((int)*(short *)(iRam020d6524 + iVar10) * uVar4 >> 0xc);
    local_2c = *(short *)(iRam020d652c + iVar8) +
               (short)((int)*(short *)(iRam020d652c + iVar10) * uVar4 >> 0xc);
    local_2e = *(short *)(iRam020d6528 + iVar8) +
               (short)((int)*(short *)(iRam020d6528 + iVar10) * uVar4 >> 0xc);
    if (*param_1 == uRam020d6530) {
      func_0208b748(0x54,param_1 + 2,&local_40,uRam020d6534);
      func_0208b748(0x57,param_1 + 2,&local_34,uRam020d6534);
    }
    else {
      func_0208b748(0x56,param_1 + 2,&local_40,uRam020d6534);
      func_0208b748(0x55,param_1 + 2,&local_34,uRam020d6534);
    }
  }
  func_020d5dd0(param_1);
  return;
}

