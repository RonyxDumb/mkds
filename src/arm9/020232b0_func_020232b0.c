/* Decompiled C draft; module arm9; ROM address 020232b0. No matching claim. */
#include "types.h"
#include "deps/020232b0_func_020232b0.h"

void func_020232b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_6 < 0x21) {
    func_02023244((ushort *)(uintptr_t)(param_1 + (param_6 * param_5 + param_4) * 2),param_2,param_3,param_6,param_7,
                  param_8);
    return;
  }
  param_3 = param_5 + param_3;
  if (param_3 <= param_5) {
    return;
  }
  do {
    iVar1 = param_5;
    if (0x1f < param_5) {
      iVar1 = param_5 + 0x20;
    }
    iVar3 = param_4;
    if (param_4 < param_4 + param_2) {
      do {
        iVar2 = iVar3;
        if (0x1f < iVar3) {
          iVar2 = iVar3 + 0x3e0;
        }
        iVar3 = iVar3 + 1;
        *(ushort *)(param_1 + iVar1 * 0x40 + iVar2 * 2) =
             (ushort)((uint)(param_8 << 0x1c) >> 0x10) | (ushort)param_7;
        param_7 = param_7 + 1;
      } while (iVar3 < param_4 + param_2);
    }
    param_5 = param_5 + 1;
  } while (param_5 < param_3);
  return;
}

