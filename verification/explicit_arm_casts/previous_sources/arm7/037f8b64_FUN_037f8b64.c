/* Decompiled C draft; module arm7; ROM address 037f8b64. No matching claim. */
#include "types.h"
#include "deps/037f8b64_FUN_037f8b64.h"

int FUN_037f8b64(undefined4 param_1,int param_2,code *param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_4 == 0) {
    uVar1 = FUN_037faf70();
  }
  else {
    uVar1 = FUN_037faf9c();
  }
  iVar2 = FUN_037fb4c0(param_1,param_2);
  if (iVar2 == 0) {
    if (param_3 != (code *)0x0) {
      (*param_3)();
    }
    *(short *)(param_2 + 4) = (short)param_1;
  }
  if (param_4 == 0) {
    FUN_037faf84(uVar1);
  }
  else {
    FUN_037fafb0(uVar1);
  }
  return iVar2;
}

