/* Decompiled C draft; module arm9; ROM address 021450ec. No matching claim. */
#include "types.h"
#include "deps/021450ec_func_021450ec.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int func_021450ec(int param_1,uint param_2,int param_3,short param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar9;
  ushort uVar10;
  uint uVar8;
  
  uVar10 = 1;
  iVar4 = Wm_GetGlobal();
  uVar8 = iVar4 + 4U & 3;
  uVar7 = *(uint *)(iVar4 + 4U & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  iVar4 = func_02142988(2,9,10);
  if (iVar4 != 0) {
    return iVar4;
  }
  DC_InvalidateRangeNoClean(uVar8 + 0xc,4);
  uVar7 = uVar8 + 0xc & 3;
  uVar5 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  if (uVar5 >> uVar7 * 8 == 0 && uVar5 << uVar7 * -8 + 0x20 == 0) {
    return 3;
  }
  if (param_1 == 0) {
    return 6;
  }
  if (param_2 < 0x10) {
    if (param_3 == 0) {
      return 6;
    }
    DC_InvalidateRangeNoClean(uVar8 + 0x184,2);
    uVar7 = (uint)*(ushort *)(uVar8 + 0x184);
    if (uVar7 == 0) {
      DC_InvalidateRangeNoClean(uVar8 + 0x86,2);
      uVar10 = *(ushort *)(uVar8 + 0x86);
    }
    Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(param_1),0x820);
    *(undefined2 *)(param_1 + 0x808) = 0;
    *(undefined2 *)(param_1 + 0x80a) = 0;
    *(undefined2 *)(param_1 + 0x80c) = 0;
    *(short *)(param_1 + 0x810) = param_4;
    *(short *)(param_1 + 0x816) = (short)param_2;
    *(undefined2 *)(param_1 + 0x80e) = 0;
    *(ushort *)(param_1 + 0x818) = (ushort)(param_5 != 0);
    *(ushort *)(param_1 + 0x80e) = (ushort)param_3 | (ushort)(1 << (uVar7 & 0xff));
    sVar3 = Math_CountPopulation();
    *(short *)(param_1 + 0x812) = sVar3;
    *(short *)(param_1 + 0x814) = param_4 * sVar3;
    if (0x1fc < *(ushort *)(param_1 + 0x814)) {
      *(undefined2 *)(param_1 + 0x80e) = 0;
      return 6;
    }
    *(ushort *)(param_1 + 0x814) = *(ushort *)(param_1 + 0x814) + 4;
    *(undefined2 *)(param_1 + 0x81c) = 1;
    uVar1 = uRam021453b0;
    if (uVar7 == 0) {
      iVar4 = 0;
      do {
        iVar9 = iVar4 * 0x200;
        iVar4 = iVar4 + 1;
        *(ushort *)(param_1 + iVar9) = *(ushort *)(param_1 + 0x80e) & (uVar10 | 1);
      } while (iVar4 < 4);
      func_0214358c(param_2,uRam021453a4,param_1);
      uVar2 = uRam021453ac;
      uVar1 = uRam021453a8;
      iVar9 = 0;
      iVar4 = param_1;
      while( true ) {
        iVar6 = 1;
        if (*(short *)(param_1 + 0x818) == 1) {
          iVar6 = 2;
        }
        if (iVar6 <= iVar9) break;
        *(ushort *)(param_1 + 0x808) = *(short *)(param_1 + 0x808) + 1U & 3;
        iVar6 = func_02144048(uVar1,param_1,iVar4,*(undefined2 *)(param_1 + 0x814));
        if (iVar6 == 7) {
          *(short *)(param_1 + iVar9 * 2 + 0x800) = (short)uVar2;
          *(ushort *)(param_1 + 0x80a) = *(short *)(param_1 + 0x80a) + 1U & 3;
        }
        else if ((iVar6 != 0) && (iVar6 != 2)) {
          *(undefined2 *)(param_1 + 0x81c) = 5;
          return 1;
        }
        iVar4 = iVar4 + 0x200;
        iVar9 = iVar9 + 1;
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x80a) = 3;
      func_0214358c(param_2,uVar1,param_1);
    }
    return 0;
  }
  return 6;
}

