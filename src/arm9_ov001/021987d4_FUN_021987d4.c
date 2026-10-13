/* Decompiled C draft; module arm9_ov001; ROM address 021987d4. No matching claim. */
#include "types.h"
#include "deps/021987d4_FUN_021987d4.h"

void FUN_021987d4(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar2 = func_0x02036bec(param_1,0x18);
  *DAT_0219884c = iVar2;
  *(undefined4 *)(iVar2 + 8) = param_1;
  uVar3 = func_0x021250b0(param_1);
  *(undefined4 *)(*DAT_0219884c + 0x10) = uVar3;
  local_38 = 1;
  local_34 = func_0x020b403c();
  local_30 = 0;
  local_2c = 1;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 1;
  local_18 = 1;
  local_14 = 0;
  func_0x02125c2c();
  func_0x02125de0(param_1,&local_38);
  piVar1 = DAT_0219884c;
  *(undefined2 *)(*DAT_0219884c + 0xc) = param_2;
  *(undefined2 *)(*piVar1 + 0xe) = 0xffff;
  *(undefined4 *)*piVar1 = 0;
  ((undefined4 *)*piVar1)[1] = *(undefined4 *)*piVar1;
  uVar3 = func_0x02047a28(DAT_02198850);
  *(undefined4 *)(*DAT_0219884c + 0x14) = uVar3;
  return;
}

