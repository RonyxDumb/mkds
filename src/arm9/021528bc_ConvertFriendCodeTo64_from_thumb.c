/* Decompiled C draft; module arm9; ROM address 021528bc. No matching claim. */
#include "types.h"
#include "deps/021528bc_ConvertFriendCodeTo64_from_thumb.h"

longlong ConvertFriendCodeTo64_from_thumb(int param_1)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar1 = 0;
  uVar6 = 1;
  iVar3 = 0;
  do {
    uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
    iVar2 = *(char *)((param_1 + 0xb) - iVar3) + -0x30;
    lVar5 = Multiply64((int)uVar6,uVar4,iVar2,iVar2 >> 0x1f);
    lVar1 = lVar5 + lVar1;
    uVar6 = Multiply64((int)uVar6,uVar4,10,0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  return lVar1;
}

