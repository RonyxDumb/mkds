/* Decompiled C draft; module arm9_ov000; ROM address 021a9280. No matching claim. */
#include "types.h"
#include "deps/021a9280_FUN_021a9280.h"

int FUN_021a9280(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_3c;
  uint local_38;
  int local_34;
  int local_28;
  uint local_1c;
  
  uVar1 = *(undefined4 *)(param_5 + 0xc);
  uVar6 = param_2 + param_4;
  local_28 = 0;
  local_1c = 0;
  local_3c = param_1;
  local_38 = param_2;
  local_34 = param_3;
  while( true ) {
    uVar5 = uVar6;
    if ((int)DAT_021a934c < (int)uVar6) {
      uVar5 = DAT_021a934c;
    }
    puVar2 = (undefined1 *)(*(code *)*DAT_021a9350)(uVar5 + 0x19);
    if (puVar2 == (undefined1 *)0x0) {
      return local_28;
    }
    uVar3 = local_38;
    if (uVar5 <= local_38) {
      uVar3 = uVar5;
    }
    func_0x0214d1fc(local_3c,puVar2 + 5,uVar3);
    local_3c = local_3c + uVar3;
    local_38 = local_38 - uVar3;
    func_0x0214d1fc(local_34,puVar2 + uVar3 + 5,uVar5 - uVar3);
    local_34 = local_34 + (uVar5 - uVar3);
    *puVar2 = 0x17;
    puVar2[1] = 3;
    puVar2[2] = 0;
    puVar2[3] = (char)(uVar5 >> 8);
    puVar2[4] = (char)uVar5;
    uVar3 = FUN_021aa054(uVar1,puVar2);
    uVar4 = FUN_021adcec(puVar2,uVar3,0,0,param_5);
    if (uVar4 < uVar3) {
      uVar5 = local_1c;
    }
    (*(code *)*DAT_021a9354)(puVar2);
    uVar6 = uVar6 - uVar5;
    local_28 = local_28 + uVar5;
    if (uVar6 == 0) break;
    if (uVar5 == 0) {
      return local_28;
    }
  }
  return local_28;
}

