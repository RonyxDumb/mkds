/* Decompiled C draft; module arm9_ov000; ROM address 0219bc78. No matching claim. */
#include "types.h"
#include "deps/0219bc78_FUN_0219bc78.h"

void FUN_0219bc78(int param_1,undefined4 param_2,char param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_a0;
  undefined1 local_94 [64];
  byte local_54 [64];
  
  iVar3 = FUN_0219c39c();
  if ((iVar3 == 0) && (*(int *)(*DAT_0219bd88 + 0x24) == 3)) {
    FUN_0219b964();
    piVar1 = DAT_0219bd88;
    *(undefined4 *)(*DAT_0219bd88 + 0x6c) = param_5;
    *(undefined4 *)(*piVar1 + 0x70) = param_6;
    FUN_0219b8a8(5);
    if (param_1 != 0) {
      FUN_021a2468(param_1,param_2,param_3 + -1,param_4,DAT_0219bd8c,0,param_7,param_8);
      return;
    }
    uVar4 = 0;
    local_a0 = 0;
    iVar3 = FUN_0219d660();
    if (0 < iVar3) {
      do {
        cVar2 = FUN_021a3448(0x80);
        local_54[uVar4] = cVar2 + 1;
        local_a0 = local_a0 + 1;
        uVar4 = uVar4 + 1 & 0xff;
        iVar3 = FUN_0219d660();
      } while ((int)uVar4 < iVar3);
    }
    uVar4 = 0;
    iVar3 = FUN_0219d660();
    if (0 < iVar3) {
      do {
        if (local_54[uVar4] != 0) {
          uVar5 = 0;
          uVar6 = 0;
          iVar3 = FUN_0219d660();
          if (0 < iVar3) {
            do {
              if ((uVar4 != uVar5) && (local_54[uVar4] < local_54[uVar5])) {
                uVar6 = uVar6 + 1 & 0xff;
              }
              uVar5 = uVar5 + 1 & 0xff;
              iVar3 = FUN_0219d660();
            } while ((int)uVar5 < iVar3);
          }
          local_94[uVar6] = (char)uVar4;
        }
        uVar4 = uVar4 + 1 & 0xff;
        iVar3 = FUN_0219d660();
      } while ((int)uVar4 < iVar3);
    }
    FUN_021a2468(local_94,local_a0,param_3 + -1,param_4,DAT_0219bd8c,0,param_7,param_8);
  }
  return;
}

