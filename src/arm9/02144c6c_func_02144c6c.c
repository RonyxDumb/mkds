/* Decompiled C draft; module arm9; ROM address 02144c6c. No matching claim. */
#include "types.h"
#include "deps/02144c6c_func_02144c6c.h"

int func_02144c6c(int param_1,int param_2,int param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint unaff_r7;
  undefined4 uVar8;
  bool bVar9;
  uint uVar7;
  
  iVar3 = Wm_GetGlobal();
  uVar7 = iVar3 + 4U & 3;
  uVar6 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  iVar3 = func_02142988(2,9,10);
  if (iVar3 != 0) {
    return iVar3;
  }
  DC_InvalidateRangeNoClean(uVar7 + 0xc,4);
  uVar6 = uVar7 + 0xc & 3;
  uVar4 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
  if (uVar4 >> uVar6 * 8 == 0 && uVar4 << uVar6 * -8 + 0x20 == 0) {
    return 3;
  }
  if (param_1 == 0) {
    return 6;
  }
  if (param_2 == 0) {
    return 6;
  }
  if (param_3 == 0) {
    return 6;
  }
  DC_InvalidateRangeNoClean(uVar7 + 0x184,2);
  sVar1 = *(short *)(uVar7 + 0x184);
  if (sVar1 == 0) {
    DC_InvalidateRangeNoClean(uVar7 + 0x86,2);
    unaff_r7 = (uint)*(ushort *)(uVar7 + 0x86);
  }
  sVar2 = *(short *)(param_1 + 0x81c);
  if (sVar2 == 5) {
    return 1;
  }
  if ((sVar2 != 1) && (sVar2 != 4)) {
    return 3;
  }
  iVar3 = 5;
  if (sVar1 == 0) {
    bVar9 = false;
    uVar8 = 0;
    if (sVar2 == 4) {
      *(undefined2 *)(param_1 + 0x81c) = 1;
      uVar7 = *(ushort *)(param_1 + 0x808) + 3 & 3;
      iVar5 = func_02144048(uRam02145028,param_1,param_1 + uVar7 * 0x200,
                            *(undefined2 *)(param_1 + 0x814));
      if (iVar5 == 7) {
        *(short *)(param_1 + uVar7 * 2 + 0x800) = (short)uRam0214502c;
        *(ushort *)(param_1 + 0x80a) = *(short *)(param_1 + 0x80a) + 1U & 3;
      }
      else if ((iVar5 != 0) && (iVar5 != 2)) {
        *(undefined2 *)(param_1 + 0x81c) = 5;
        return 1;
      }
    }
    if ((uint)*(ushort *)(param_1 + 0x80c) != (uint)*(ushort *)(param_1 + 0x80a)) {
      iVar3 = (uint)*(ushort *)(param_1 + 0x80c) * 0x200;
      *(ushort *)(param_1 + iVar3) = *(ushort *)(param_1 + iVar3) | 1;
      CopyMemory16(param_1 + (uint)*(ushort *)(param_1 + 0x80c) * 0x200,param_3,0x200);
      bVar9 = true;
      iVar3 = 0;
      *(undefined2 *)(param_1 + 0x81a) =
           *(undefined2 *)(param_1 + (uint)*(ushort *)(param_1 + 0x80c) * 2 + 0x800);
      *(ushort *)(param_1 + 0x80c) = *(short *)(param_1 + 0x80c) + 1U & 3;
      if (((*(short *)(param_1 + 0x818) == 0) && (unaff_r7 != 0)) &&
         (*(short *)(param_1 + (uint)*(ushort *)(param_1 + 0x808) * 0x200) == 1)) {
        uVar8 = 1;
      }
      else {
        uVar8 = 0;
      }
    }
    func_02144688(param_1,0);
    if ((bVar9) && (func_02144814(param_1,0,param_2), *(short *)(param_1 + 0x818) == 0)) {
      func_02144688(param_1,uVar8);
    }
  }
  else {
    bVar9 = sVar2 == 4;
    if (bVar9) {
      *(ushort *)(param_1 + 0x81c) = (ushort)bVar9;
    }
    else if ((uint)*(ushort *)(param_1 + 0x80c) != (uint)*(ushort *)(param_1 + 0x808)) {
      iVar5 = (uint)*(ushort *)(param_1 + 0x80c) * 0x200;
      if ((*(ushort *)(param_1 + iVar5) & 1) == 0) {
        *(ushort *)(param_1 + iVar5) = *(ushort *)(param_1 + iVar5) | 1;
      }
      else {
        CopyMemory16(param_1 + iVar5,param_3,0x200);
        bVar9 = true;
        iVar3 = 0;
        *(undefined2 *)(param_1 + 0x81a) =
             *(undefined2 *)(param_1 + (uint)*(ushort *)(param_1 + 0x80c) * 2 + 0x800);
        *(ushort *)(param_1 + 0x80c) = *(short *)(param_1 + 0x80c) + 1U & 3;
      }
    }
    if (bVar9) {
      iVar5 = param_1 + (uint)*(ushort *)(param_1 + 0x80a) * 0x200 + 0x20;
      CopyMemory16(param_2,iVar5,*(undefined2 *)(param_1 + 0x810));
      iVar5 = func_02144048(uRam02145028,param_1,iVar5,*(undefined2 *)(param_1 + 0x810));
      *(ushort *)(param_1 + 0x80a) = *(short *)(param_1 + 0x80a) + 1U & 3;
      if ((iVar5 != 2) && (iVar5 != 0)) {
        *(undefined2 *)(param_1 + 0x81c) = 5;
        iVar3 = 1;
      }
    }
  }
  return iVar3;
}

