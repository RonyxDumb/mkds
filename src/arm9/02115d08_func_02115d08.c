/* Decompiled C draft; module arm9; ROM address 02115d08. No matching claim. */
#include "types.h"
#include "deps/02115d08_func_02115d08.h"

void func_02115d08(void)

{
  int *piVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_228 [32];
  undefined1 auStack_208 [512];
  
  piVar1 = piRam02115d88;
  *(undefined4 *)(*piRam02115d88 + 0x58) = 8;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  sVar2 = func_02116870();
  func_02114298(sVar2 + *(short *)(*piRam02115d88 + 0x74),(undefined4)(uintptr_t)(auStack_228),0x20);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02115d88 + 0x48),5);
  MaybeHandleBmgFormatting_from_thumb(auStack_228,uVar3,auStack_208,uRam02115d8c);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02115d88 + 0x44),0);
  uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02115d88 + 0x44),1);
  TextSystem_DisplayDoubleButtonDialog_from_thumb((undefined4)(uintptr_t)(auStack_208),uVar3,uVar4,1,0,1,1,1);
  return;
}

