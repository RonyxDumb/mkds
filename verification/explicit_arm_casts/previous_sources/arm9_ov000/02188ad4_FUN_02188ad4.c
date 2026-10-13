/* Decompiled C draft; module arm9_ov000; ROM address 02188ad4. No matching claim. */
#include "types.h"
#include "deps/02188ad4_FUN_02188ad4.h"

void FUN_02188ad4(undefined1 param_1,int param_2,int param_3)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = param_3 + DAT_02188b14;
  iVar3 = param_3 + DAT_02188b18;
  *(undefined1 *)(iVar4 + 1) = param_1;
  uVar1 = *(ushort *)(param_2 + 2);
  if ((uVar1 & 2) == 0) {
    cVar2 = (char)((int)(uint)uVar1 >> 2) + '\x19';
  }
  else {
    cVar2 = (char)(((uint)uVar1 << 0x16) >> 0x18);
  }
  *(char *)(iVar4 + 2) = cVar2;
  *(char *)(iVar4 + 3) = *(char *)(param_3 + DAT_02188b1c) + '\x01';
  func_0x0214d02c(param_2,iVar3,0xc0);
  return;
}

