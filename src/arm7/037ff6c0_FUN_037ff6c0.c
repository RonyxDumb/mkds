/* Decompiled C draft; module arm7; ROM address 037ff6c0. No matching claim. */
#include "types.h"
#include "deps/037ff6c0_FUN_037ff6c0.h"

void FUN_037ff6c0(uint param_1,byte param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_037faf70();
  iVar2 = 0;
  for (; (iVar2 < 0x10 && (param_1 != 0)); param_1 = param_1 >> 1) {
    if ((param_1 & 1) != 0) {
      *(byte *)(iVar2 * 0x10 + 0x4000403) = *(byte *)(iVar2 * 0x10 + 0x4000403) | 0x80;
    }
    iVar2 = iVar2 + 1;
  }
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) != 0) {
      *DAT_037ff7b0 = *DAT_037ff7b0 | 0x80;
    }
  }
  else if ((param_2 & 2) == 0) {
    *(byte *)DAT_037ff7a8 = (byte)*DAT_037ff7a8 | 0x80;
  }
  else {
    *DAT_037ff7a8 = *DAT_037ff7a8 | (ushort)DAT_037ff7ac;
  }
  iVar2 = 0;
  for (; (iVar2 < 8 && (param_3 != 0)); param_3 = param_3 >> 1) {
    if ((param_3 & 1) != 0) {
      FUN_037ff440(iVar2);
    }
    iVar2 = iVar2 + 1;
  }
  FUN_037faf84(uVar1);
  FUN_037ff2f4();
  return;
}

