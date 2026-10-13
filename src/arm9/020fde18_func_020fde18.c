/* Decompiled C draft; module arm9; ROM address 020fde18. No matching claim. */
#include "types.h"
#include "deps/020fde18_func_020fde18.h"

void func_020fde18(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  
  uVar4 = func_02061f90();
  if (*(byte *)((*(uint *)(uRam020fdf60 & 0xfffffffc) >> (uRam020fdf60 & 3) * 8 |
                *(uint *)(uRam020fdf60 & 0xfffffffc) << (uRam020fdf60 & 3) * -8 + 0x20) + 0x3d0) <=
      uVar4) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar5 = *(ushort *)(param_1 + 0x78) & 0xff;
  }
  else {
    uVar5 = 8;
  }
  if (uVar4 != uVar5) {
    iVar6 = GetDriverEntry(uVar4);
    iVar7 = StructMQRacerEntry_SomeFn_86();
    if (iVar7 == 0) {
      uVar3 = param_1 + 0x17cU & 3;
      uVar8 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      if ((int)(uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) < 8) {
        GetDriverMaybeSfxPosition(&iStack_20,*(undefined2 *)(param_1 + 0x178));
        uVar3 = param_1 + 0x54U & 3;
        uVar9 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
        uVar8 = param_1 + 0x50U & 3;
        uVar10 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
        iVar7 = (int)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) - iStack_1c) >> 0xc;
        iVar1 = (int)((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) - iStack_20) >> 0xc;
        uVar3 = param_1 + 0x58U & 3;
        uVar8 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
        iVar2 = (int)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) - iStack_18) >> 0xc;
        *(int *)(param_1 + 0x17c) = iVar2 * iVar2 + iVar1 * iVar1 + iVar7 * iVar7;
      }
      uVar3 = param_1 + 0x54U & 3;
      uVar9 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
      uVar8 = param_1 + 0x50U & 3;
      uVar10 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
      iVar7 = (int)((uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20) - *(int *)(iVar6 + 0x9c)) >>
              0xc;
      iVar1 = (int)((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) - *(int *)(iVar6 + 0x98)) >>
              0xc;
      uVar3 = param_1 + 0x58U & 3;
      uVar10 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
      uVar8 = param_1 + 0x17cU & 3;
      uVar9 = *(uint *)(param_1 + 0x17cU & 0xfffffffc);
      iVar6 = (int)((uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20) - *(int *)(iVar6 + 0xa0)) >>
              0xc;
      iVar6 = iVar6 * iVar6 + iVar1 * iVar1 + iVar7 * iVar7;
      if (iVar6 < (int)(uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20)) {
        *(ushort *)(param_1 + 0x178) = uVar4;
        *(int *)(param_1 + 0x17c) = iVar6;
      }
      return;
    }
    return;
  }
  return;
}

