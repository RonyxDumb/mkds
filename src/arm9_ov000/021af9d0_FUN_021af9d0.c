/* Decompiled C draft; module arm9_ov000; ROM address 021af9d0. No matching claim. */
#include "types.h"
#include "deps/021af9d0_FUN_021af9d0.h"

void FUN_021af9d0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = param_2 + 0x14 + param_4 & 0xffff;
  *(ushort *)(param_1 + -0x12) = (ushort)(uVar1 >> 8) | (ushort)(uVar1 << 8);
  *(ushort *)(param_1 + -0xe) =
       (ushort)((param_6 & 0xffff) >> 8) | (ushort)((param_6 & 0xffff) << 8);
  *(undefined2 *)(param_1 + -10) = 0;
  iVar2 = FUN_021b0188(param_1 + -0x14,0x14);
  *(ushort *)(param_1 + -10) = (ushort)((uint)iVar2 >> 8) | (ushort)(iVar2 << 8);
  if ((param_5 != DAT_021afa98) && (param_5 != *DAT_021afa9c)) {
    FUN_021afaac(param_1 + -0x14,param_2 + 0x14,param_3,param_4,param_5,DAT_021afaa0);
  }
  if (((param_5 == DAT_021afa98) || (param_5 == *DAT_021afa9c)) ||
     (iVar2 = FUN_021b0094(param_5), iVar2 != 0)) {
    func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021afaa4),(uint *)(uintptr_t)(param_1 + -0x1c),8);
    uVar3 = func_0x0200fca0();
    FUN_021afe84(DAT_021afaa8,DAT_021afaa8,(char *)(uintptr_t)(param_1 + -0x1c),param_2 + 0x1c,param_3,param_4);
    func_0x0200fcb4(uVar3);
  }
  return;
}

