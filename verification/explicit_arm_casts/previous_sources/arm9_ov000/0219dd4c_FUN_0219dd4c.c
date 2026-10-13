/* Decompiled C draft; module arm9_ov000; ROM address 0219dd4c. No matching claim. */
#include "types.h"
#include "deps/0219dd4c_FUN_0219dd4c.h"

void FUN_0219dd4c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_a8 [4];
  int local_a4;
  undefined1 local_a0;
  byte local_9f;
  undefined2 local_9e;
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 auStack_94 [128];
  
  iVar2 = 0;
  if (0x13 < param_2) {
    while( true ) {
      func_0x0214d1fc(param_1,auStack_a8,0x14);
      iVar1 = func_0x0213a038(auStack_a8,DAT_0219ddb8,4);
      if ((iVar1 != 0) || (local_a4 != 3)) break;
      func_0x0214d1fc(param_1 + 0x14,auStack_94,local_9f);
      iVar1 = FUN_021a01dc(local_a0,local_98,local_9c,local_9e,auStack_94,(int)(uint)local_9f >> 2);
      if (iVar1 == 0) {
        return;
      }
      iVar2 = iVar2 + local_9f + 0x14;
      if (param_2 < iVar2 + 0x14U) {
        return;
      }
    }
  }
  return;
}

