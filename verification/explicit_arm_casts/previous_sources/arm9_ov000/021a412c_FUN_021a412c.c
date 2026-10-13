/* Decompiled C draft; module arm9_ov000; ROM address 021a412c. No matching claim. */
#include "types.h"
#include "deps/021a412c_FUN_021a412c.h"

void FUN_021a412c(undefined4 param_1,undefined4 param_2,byte *param_3,int param_4)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  byte *local_1c;
  
  local_1c = (byte *)0x0;
  pbVar3 = (byte *)0x0;
  if (2 < param_4) {
    uVar4 = (uint)*param_3;
    param_3 = param_3 + 1;
    param_4 = param_4 + -1;
    pbVar1 = param_3;
    if ((uVar4 != 0) && (uVar4 != 0xff)) {
      pbVar1 = param_3 + uVar4;
      param_4 = param_4 - uVar4;
      local_1c = param_3;
    }
    if (1 < param_4) {
      uVar7 = (uint)*pbVar1;
      pbVar1 = pbVar1 + 1;
      param_4 = param_4 + -1;
      pbVar2 = pbVar1;
      pbVar5 = (byte *)0x0;
      if ((uVar7 != 0) && (uVar7 != 0xff)) {
        pbVar2 = pbVar1 + uVar7;
        param_4 = param_4 - uVar7;
        pbVar5 = pbVar1;
      }
      if (0 < param_4) {
        uVar6 = (uint)*pbVar2;
        param_4 = param_4 + -1;
        if ((uVar6 != 0) && (uVar6 != 0xff)) {
          pbVar3 = pbVar2 + 1;
          param_4 = param_4 - uVar6;
        }
        if (-1 < param_4) {
          FUN_021a41a0(param_1,param_2,uVar4,local_1c,uVar7,pbVar5,uVar6,pbVar3);
        }
      }
    }
  }
  return;
}

