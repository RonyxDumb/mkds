/* Decompiled C draft; module arm9_ov000; ROM address 021ab5e4. No matching claim. */
#include "types.h"
#include "deps/021ab5e4_FUN_021ab5e4.h"

int FUN_021ab5e4(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  uVar8 = func_0x0200f5ac();
  uVar5 = (uint)uVar8 >> 0x10 | (int)((ulonglong)uVar8 >> 0x20) << 0x10;
  uVar2 = 0;
  iVar3 = 0;
  iVar1 = DAT_021ab638;
  iVar6 = DAT_021ab638;
  do {
    iVar7 = iVar1;
    if (*(char *)(iVar1 + 0x5a) == '\0') break;
    uVar4 = uVar5 - *(int *)(iVar1 + 0x50);
    if (uVar2 < uVar4) {
      uVar2 = uVar4;
      iVar6 = iVar1;
    }
    iVar1 = iVar1 + 0x5c;
    iVar3 = iVar3 + 1;
    iVar7 = iVar6;
  } while (iVar3 < 4);
  func_0x0214d1fc(param_1,iVar7,0x20);
  *(uint *)(iVar7 + 0x50) = uVar5;
  *(undefined1 *)(iVar7 + 0x5a) = 1;
  return iVar7;
}

