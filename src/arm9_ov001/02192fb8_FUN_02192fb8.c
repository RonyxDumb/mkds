/* Decompiled C draft; module arm9_ov001; ROM address 02192fb8. No matching claim. */
#include "types.h"
#include "deps/02192fb8_FUN_02192fb8.h"

void FUN_02192fb8(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
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
  
  puVar2 = (undefined4 *)func_0x02036bec(param_1,0x2c);
  *DAT_021930a4 = (int)puVar2;
  *puVar2 = param_1;
  uVar3 = func_0x021250b0(param_1);
  *(undefined4 *)(*DAT_021930a4 + 0x28) = uVar3;
  FUN_021930ac();
  uVar3 = FUN_0219e920();
  func_0x0212abdc(param_1,uVar3);
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
  uVar3 = func_0x020369fc(*(undefined4 *)*DAT_021930a4);
  *(undefined4 *)(*DAT_021930a4 + 4) = uVar3;
  FUN_02193144();
  FUN_021932c8();
  piVar1 = DAT_021930a4;
  *(undefined2 *)(*DAT_021930a4 + 0x14) = 0xffff;
  if (param_2 == 0) {
    *(undefined4 *)(*piVar1 + 0x10) = 4;
    *(undefined4 *)(*piVar1 + 8) = 0;
    FUN_021932e4();
  }
  else if (param_2 == 3) {
    *(undefined4 *)(*piVar1 + 0x10) = 6;
    if (*(int *)(*DAT_021930a8 + 0x18) == 0) {
      *(undefined4 *)(*piVar1 + 8) = 2;
      FUN_02199964();
    }
    else {
      *(undefined4 *)(*piVar1 + 8) = 3;
      FUN_0219d5dc();
    }
  }
  else if (param_2 == 0xe) {
    *(undefined4 *)(*piVar1 + 0x10) = 5;
    *(undefined4 *)(*piVar1 + 8) = 2;
    FUN_02199964();
  }
  piVar1 = DAT_021930a4;
  *(undefined4 *)(*DAT_021930a4 + 0xc) = 0xffffffff;
  (**(code **)(*piVar1 + 0x18))(*(undefined4 *)(*piVar1 + 4));
  return;
}

