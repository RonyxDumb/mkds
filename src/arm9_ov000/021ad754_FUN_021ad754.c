/* Decompiled C draft; module arm9_ov000; ROM address 021ad754. No matching claim. */
#include "types.h"
#include "deps/021ad754_FUN_021ad754.h"

int FUN_021ad754(undefined2 *param_1,undefined1 param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  
  func_0x0214d168((uint *)(void *)(param_1),0,0xec);
  *param_1 = (short)DAT_021ad860;
  *(undefined1 *)(param_1 + 1) = 6;
  lVar3 = func_0x02133048((int)DAT_021ad864[1],*(undefined4 *)((int)DAT_021ad864 + 0xc),
                          (int)*DAT_021ad864,*(undefined4 *)((int)DAT_021ad864 + 4));
  lVar3 = lVar3 + DAT_021ad864[2];
  uVar2 = (uint)((ulonglong)lVar3 >> 0x20);
  *DAT_021ad864 = lVar3;
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar2;
  }
  param_1[2] = (ushort)(byte)((ulonglong)lVar3 >> 0x38) | (ushort)((uVar2 >> 0x10) << 8);
  param_1[3] = (ushort)((uVar2 & 0xffff) >> 8) | (ushort)((uVar2 & 0xffff) << 8);
  puVar1 = DAT_021ad868;
  param_1[6] = (ushort)(byte)(*DAT_021ad868 >> 0x18) | (ushort)((*DAT_021ad868 >> 0x10) << 8);
  param_1[7] = (ushort)((*puVar1 & 0xffff) >> 8) | (ushort)((*puVar1 & 0xffff) << 8);
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021ad86c),(uint *)(void *)(param_1 + 0xe),6);
  param_1[0x76] = (short)DAT_021ad870;
  param_1[0x77] = (short)DAT_021ad874;
  param_1[0x78] = (short)DAT_021ad878;
  *(undefined1 *)(param_1 + 0x79) = param_2;
  *(undefined1 *)((int)param_1 + 0xf3) = 0x3d;
  *(undefined1 *)(param_1 + 0x7a) = 7;
  *(undefined1 *)((int)param_1 + 0xf5) = 1;
  func_0x0214d1fc((ushort *)(uintptr_t)(DAT_021ad86c),(uint *)(void *)(param_1 + 0x7b),6);
  *(undefined1 *)(param_1 + 0x7e) = 0xc;
  *(undefined1 *)((int)param_1 + 0xfd) = 10;
  func_0x0214d1fc(DAT_021ad87c,param_1 + 0x7f);
  *(undefined1 *)((int)param_1 + DAT_021ad880) = 0x37;
  *(undefined1 *)((int)param_1 + DAT_021ad884) = 3;
  *(undefined1 *)((int)param_1 + DAT_021ad888) = 1;
  *(undefined1 *)((int)param_1 + DAT_021ad88c) = 3;
  *(undefined1 *)((int)param_1 + DAT_021ad890) = 6;
  return (int)param_1 + DAT_021ad894;
}

