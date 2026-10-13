/* Decompiled C draft; module arm9; ROM address 0203147c. No matching claim. */
#include "types.h"
#include "deps/0203147c_func_0203147c.h"

void func_0203147c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_24 [20];
  undefined2 local_10;
  
  Maybe_multi_select_member_m();
  iVar3 = *piRam0203152c;
  CopyMemory16(*(int *)*puRam02031530 + 0xc,(int)(uintptr_t)(auStack_24),0x14);
  local_10 = 0;
  func_0212426c(1,(int)*psRam02031534,*(undefined4 *)(iVar3 + 0x54),auStack_24,
                *(undefined4 *)(iVar3 + 0x4c),*(undefined4 *)(iVar3 + 0x58));
  uVar2 = Bmg_GetRawStringPointer_from_thumb
                    (*(undefined4 *)(*piRam0203152c + 100),*(undefined4 *)(psRam02031534 + 0x34));
  func_0212426c(1,(int)*(short *)(iRam02031538 + 0x20),*(undefined4 *)(iVar3 + 0x54),uVar2,
                *(undefined4 *)(iVar3 + 0x4c),*(undefined4 *)(iVar3 + 0x58));
  *(undefined4 *)(*piRam0203153c + 0x20) = 1;
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0203152c + 100),9);
  TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar2,0,0,1,0,0,0);
  iVar1 = iRam02031540;
  *(undefined4 *)(*(int *)(iVar3 + 0x58) + iRam02031540) = 0;
  *(undefined4 *)(*(int *)(iVar3 + 0x58) + iRam02031544) =
       *(undefined4 *)(*(int *)(iVar3 + 0x58) + iVar1);
  func_021281c8(0xffffffff);
  func_02036820(*(undefined4 *)(*piRam0203152c + iRam02031548));
  return;
}

