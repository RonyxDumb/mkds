/* Decompiled C draft; module arm9; ROM address 02035b78. No matching claim. */
#include "types.h"
#include "deps/02035b78_func_02035b78.h"

void func_02035b78(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_240 [20];
  undefined1 auStack_22c [20];
  undefined2 local_218;
  undefined1 auStack_216 [518];
  
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035c0c + 0x88),0x12);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035c0c + 0x84),0);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035c0c + 0x84),1);
  iVar4 = func_0202ddb0();
  func_0202dc68(*(int *)(*piRam02035c0c + 0x80) + iVar4,auStack_240);
  CopyMemory16(auStack_240,auStack_22c,0x14);
  local_218 = 0;
  MaybeHandleBmgFormatting_from_thumb(auStack_22c,uVar1,auStack_216,uRam02035c10);
  TextSystem_SetButtonPressSseqId_from_thumb(0,0xffffffff);
  TextSystem_DisplayDoubleButtonDialog_from_thumb(auStack_216,uVar2,uVar3,1,0,1,1,0);
  return;
}

