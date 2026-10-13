/* Decompiled C draft; module arm9_ov001; ROM address 021a6238. No matching claim. */
#include "types.h"
#include "deps/021a6238_FUN_021a6238.h"

void FUN_021a6238(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  func_0x020364e8();
  uVar2 = func_0x020364e0();
  iVar3 = func_0x02036bec(uVar2,0x44);
  piVar1 = DAT_021a6274;
  *DAT_021a6274 = iVar3;
  *(undefined4 *)(iVar3 + 0x10) = param_1;
  *(undefined4 *)(*piVar1 + 0x14) = param_2;
  *(undefined4 *)(*piVar1 + 0x18) = param_3;
  func_ov001_02181274(param_3,param_4,param_5);
  return;
}

