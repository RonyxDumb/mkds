/* Decompiled C draft; module arm9; ROM address 020328f8. No matching claim. */
#include "types.h"
#include "deps/020328f8_func_020328f8.h"

void func_020328f8(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = *piRam0203293c;
  iVar4 = 0;
  if (0 < *(int *)(iVar1 + 0x48)) {
    iVar3 = 0;
    iVar2 = iVar1;
    do {
      if ((iVar4 == *(int *)(iVar2 + 0x44)) && (param_1 != 0)) {
        uVar5 = 1;
      }
      else {
        uVar5 = 0;
      }
      *(undefined4 *)
       (*(int *)(iVar1 + 0x34) + (uint)*(ushort *)(*(int *)(iVar2 + 0x4c) + iVar3) * 0x40) = uVar5;
      iVar3 = iVar3 + 6;
      iVar4 = iVar4 + 1;
      iVar2 = *piRam0203293c;
    } while (iVar4 < *(int *)(iVar2 + 0x48));
  }
  return;
}

