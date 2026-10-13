/* Decompiled C draft; module arm9_ov000; ROM address 0219ef68. No matching claim. */
#include "types.h"
#include "deps/0219ef68_FUN_0219ef68.h"

void FUN_0219ef68(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  bool local_10;
  undefined1 local_f;
  undefined1 local_e;
  
  if (param_2 == 2) {
    iVar2 = *DAT_0219eff8;
    local_10 = param_1 == *(byte *)(iVar2 + (uint)*(byte *)(iVar2 + 0xd) + DAT_0219effc);
    uVar1 = 1;
    if (*(char *)(iVar2 + 0xd) != '\0') {
      do {
        if (param_1 == *(byte *)(iVar2 + uVar1 + DAT_0219effc)) {
          local_f = (undefined1)uVar1;
          local_e = (undefined1)param_1;
          break;
        }
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 <= *(byte *)(iVar2 + 0xd));
    }
  }
  else if (param_2 == 3) {
    local_10 = SUB21(*(undefined2 *)(*DAT_0219eff8 + DAT_0219f000),0);
    local_f = (undefined1)((ushort)*(undefined2 *)(*DAT_0219eff8 + DAT_0219f000) >> 8);
  }
  FUN_021a3310(param_2,param_1,&local_10,4);
  uVar3 = FUN_021a350c();
  iVar2 = *DAT_0219eff8;
  *(int *)(iVar2 + DAT_0219f004) = (int)uVar3;
  *(int *)(iVar2 + DAT_0219f008) = (int)((ulonglong)uVar3 >> 0x20);
  return;
}

