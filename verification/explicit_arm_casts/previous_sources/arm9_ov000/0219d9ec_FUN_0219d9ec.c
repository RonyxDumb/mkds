/* Decompiled C draft; module arm9_ov000; ROM address 0219d9ec. No matching claim. */
#include "types.h"
#include "deps/0219d9ec_FUN_0219d9ec.h"

uint FUN_0219d9ec(undefined4 param_1,undefined1 *param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 auStack_228 [4];
  undefined1 auStack_224 [4];
  uint local_220;
  undefined1 auStack_21c [256];
  undefined1 auStack_11c [268];
  
  iVar2 = FUN_0219d094(param_1,auStack_224);
  if (iVar2 != 0) {
    if (local_220 == 6) {
      if (param_2 != (undefined1 *)0x0) {
        iVar2 = FUN_021a3530(DAT_0219daa0,auStack_228,auStack_21c,0x2f);
        if (iVar2 < 1) {
          *param_2 = 0;
        }
        else {
          uVar1 = func_0x0213c074(auStack_228,0,10);
          *param_2 = uVar1;
        }
      }
      if (param_3 != (undefined1 *)0x0) {
        iVar2 = FUN_021a3530(DAT_0219daa4,auStack_228,auStack_21c,0x2f);
        if (iVar2 < 1) {
          *param_3 = 0;
        }
        else {
          uVar1 = func_0x0213c074(auStack_228,0,10);
          *param_3 = uVar1;
        }
      }
    }
    else {
      if (param_2 != (undefined1 *)0x0) {
        *param_2 = 0;
      }
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = 0;
      }
    }
    if (param_4 != 0) {
      func_0x0213a2d0(param_4,auStack_11c);
    }
    return local_220 & 0xff;
  }
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 0;
  }
  return 0;
}

