/* Decompiled C draft; module arm9_ov000; ROM address 021ae048. No matching claim. */
#include "types.h"
#include "deps/021ae048_FUN_021ae048.h"

void FUN_021ae048(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  iVar3 = *(int *)(*(int *)(DAT_021ae08c + 4) + 0xa4);
  if (iVar3 != 0) {
    uVar4 = func_0x0200f5ac();
    puVar1 = DAT_021ae090;
    while ((iVar2 = (*(code *)*puVar1)(), iVar2 != 0 && (*(char *)(iVar3 + 8) != '\0'))) {
      uVar5 = func_0x0200f5ac();
      if (0x26 < (int)(((uint)uVar5 >> 0x10 | (int)((ulonglong)uVar5 >> 0x20) << 0x10) -
                      ((uint)uVar4 >> 0x10 | (int)((ulonglong)uVar4 >> 0x20) << 0x10))) {
        return;
      }
      FUN_021b04d4();
    }
  }
  return;
}

