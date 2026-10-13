/* Decompiled C draft; module arm9; ROM address 020adec0. No matching claim. */
#include "types.h"
#include "deps/020adec0_func_020adec0.h"

void func_020adec0(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int extraout_r1;
  
  iVar2 = _s32_div_f(param_2 + param_3 * 0x40,8);
  uVar1 = *(ushort *)(param_1 + iVar2 * 2);
  _s32_div_f(param_2,8);
  *(ushort *)(param_1 + iVar2 * 2) =
       uVar1 & ~(ushort)(3 << (extraout_r1 << 1 & 0xffU)) |
       (ushort)(param_4 << (extraout_r1 << 1 & 0xffU));
  return;
}

