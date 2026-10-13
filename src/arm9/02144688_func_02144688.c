/* Decompiled C draft; module arm9; ROM address 02144688. No matching claim. */
#include "types.h"
#include "deps/02144688_func_02144688.h"

void func_02144688(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  iVar2 = Wm_GetGlobal();
  uVar5 = iVar2 + 4U & 3;
  uVar4 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar3 = Os_DisableIrq();
  if (*(short *)(param_1 + (uint)*(ushort *)(param_1 + 0x808) * 0x200) != 0) {
    Os_RestoreIrq();
    return;
  }
  DC_InvalidateRangeNoClean(uVar5 + 0x86,2);
  uVar6 = (uint)*(ushort *)(param_1 + 0x808);
  uVar1 = *(ushort *)(uVar5 + 0x86);
  uVar4 = uVar6 + 1 & 3;
  uVar5 = uVar4;
  if (*(short *)(param_1 + 0x818) == 1) {
    uVar5 = uVar4 + 1 & 3;
  }
  Mem_CpuFill16(0,param_1 + uVar5 * 0x200,0x200);
  *(ushort *)(param_1 + uVar5 * 0x200) = *(ushort *)(param_1 + 0x80e) & (uVar1 | 1);
  *(short *)(param_1 + 0x808) = (short)uVar4;
  iVar2 = uVar6 * 0x200;
  *(undefined2 *)(param_1 + iVar2) = *(undefined2 *)(param_1 + 0x80e);
  if (param_2 == 1) {
    *(ushort *)(param_1 + iVar2) = *(ushort *)(param_1 + iVar2) & 0xfffe;
  }
  Os_RestoreIrq(uVar3);
  iVar2 = func_02144048(uRam0214480c,param_1,param_1 + uVar6 * 0x200,
                        *(undefined2 *)(param_1 + 0x814),*(ushort *)(param_1 + 0x80e) & uVar1,
                        *(undefined2 *)(param_1 + 0x816),1);
  if (iVar2 != 7) {
    if (iVar2 != 0) {
      if (iVar2 != 2) {
        *(undefined2 *)(param_1 + 0x81c) = 5;
      }
      return;
    }
    return;
  }
  *(short *)(param_1 + uVar6 * 2 + 0x800) = (short)uRam02144810;
  *(ushort *)(param_1 + 0x80a) = *(short *)(param_1 + 0x80a) + 1U & 3;
  return;
}

