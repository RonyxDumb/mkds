/* Decompiled C draft; module arm9; ROM address 02090638. No matching claim. */
#include "types.h"
#include "deps/02090638_func_02090638.h"

void func_02090638(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  
  iVar3 = GetDriverEntry(*(undefined2 *)(param_1 + 0x24));
  uVar6 = iVar3 + 0x44U & 3;
  uVar5 = *(uint *)(iVar3 + 0x44U & 0xfffffffc);
  uVar1 = param_1 + 0x20U & 3;
  uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  bVar10 = ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x10) != 0;
  if (bVar10) {
    param_4 = iRam02090738;
  }
  uVar6 = iVar3 + 0x78U & 3;
  uVar5 = *(uint *)(iVar3 + 0x78U & 0xfffffffc);
  if (!bVar10) {
    param_4 = 0x52;
  }
  uVar2 = *(ushort *)(iRam0209073c + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 0x5c);
  uVar4 = *(ushort *)(iVar3 + 0x236);
  uVar6 = (uint)uVar4;
  bVar10 = (uVar2 & 0x20) != 0;
  if (bVar10) {
    uVar4 = uVar4 + 0xa0;
  }
  if (bVar10) {
    *(ushort *)(iVar3 + 0x236) = uVar4;
  }
  else if ((uVar2 & 0x10) != 0) {
    *(ushort *)(iVar3 + 0x236) = uVar4 - 0xa0;
  }
  iVar9 = (uVar6 + (int)(short)((uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20) * 0xb6 + 0x800 >>
                               0xc) & 0xffff) - (uint)*(ushort *)(iVar3 + 0x236);
  iVar7 = iVar9;
  if (iVar9 < 0) {
    iVar7 = -iVar9;
  }
  if (iRam02090740 < iVar7) {
    if (iVar9 < 1) {
      iVar9 = iVar9 + iRam02090744;
    }
    else {
      iVar9 = -(iRam02090744 - iVar9);
    }
  }
  *(ushort *)(iVar3 + 0x236) = *(ushort *)(iVar3 + 0x236) + (short)((uint)(iVar9 * param_4) >> 0xc);
  return;
}

