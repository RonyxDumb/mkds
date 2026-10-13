/* Decompiled C draft; module arm9; ROM address 02144814. No matching claim. */
#include "types.h"
#include "deps/02144814_func_02144814.h"

void func_02144814(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar3 = 1 << (param_2 & 0xff);
  uVar2 = uVar3 & 0xffff;
  if ((*(ushort *)(param_1 + 0x80e) & uVar2) == 0) {
    return;
  }
  uVar6 = (uint)*(ushort *)(param_1 + 0x808);
  if ((uVar2 & *(ushort *)(param_1 + uVar6 * 0x200)) == 0) {
    if (*(short *)(param_1 + 0x818) != 1) {
      return;
    }
    uVar6 = uVar6 + 1 & 3;
    if ((uVar2 & *(ushort *)(param_1 + uVar6 * 0x200)) == 0) {
      return;
    }
  }
  uVar5 = func_021445e0(param_1,(uint)*(ushort *)(param_1 + 0x80e),param_1 + uVar6 * 0x200 + 4);
  if (param_3 == 0) {
    Mem_CpuFill16(0,uVar5,*(undefined2 *)(param_1 + 0x810));
  }
  else {
    CopyMemory16(param_3,uVar5,*(undefined2 *)(param_1 + 0x810));
  }
  Os_DisableIrq();
  iVar1 = uVar6 * 0x200;
  uVar4 = (ushort)uVar3;
  *(ushort *)(param_1 + iVar1) = *(ushort *)(param_1 + iVar1) & ~uVar4;
  *(ushort *)(param_1 + 2 + iVar1) = *(ushort *)(param_1 + 2 + iVar1) | uVar4;
  Os_RestoreIrq();
  return;
}

