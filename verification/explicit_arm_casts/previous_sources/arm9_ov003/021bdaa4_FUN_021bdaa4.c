/* Decompiled C draft; module arm9_ov003; ROM address 021bdaa4. No matching claim. */
#include "types.h"
#include "deps/021bdaa4_FUN_021bdaa4.h"

undefined1 * FUN_021bdaa4(ushort *param_1,uint param_2,undefined4 param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  
  *(undefined1 *)param_1 = 0;
  *(undefined1 *)((int)param_1 + 1) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 3) = 0;
  uVar1 = (ushort)DAT_021bdb08;
  *param_1 = (ushort)((param_2 & 0xffff) >> 8) | (ushort)((param_2 & 0xffff) << 8) & uVar1;
  iVar2 = (param_4 + 0xb & 0xfffffff8) - 4;
  param_1[1] = (ushort)((param_4 & 0xffff) >> 8) | (ushort)((param_4 & 0xffff) << 8) & uVar1;
  param_1 = param_1 + 2;
  func_0x02134de0(param_1,0,iVar2);
  func_0x02134eb8(param_1,param_3,param_4);
  return (undefined1 *)((int)param_1 + iVar2);
}

