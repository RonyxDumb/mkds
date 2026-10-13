/* Decompiled C draft; module arm9; ROM address 02128f7c. No matching claim. */
#include "types.h"
#include "deps/02128f7c_Keyboard_SwitchFn10_from_thumb.h"

void Keyboard_SwitchFn10_from_thumb(void)

{
  short sVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined2 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (0xe < *(int *)(*piRam0212912c + 0x28)) {
    *(undefined4 *)(*piRam0212912c + 0x28) = 0xf;
  }
  iVar5 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if ((iVar5 != 0) && (iVar5 = TextSystem_IsButton2Focused_from_thumb(), iVar5 == 1)) {
    sVar1 = psRam02129130[2];
    uVar4 = ComputeValueInterpolation_from_thumb
                      (1,(int)sVar1,(int)*(short *)(iRam02129134 + 4),
                       *(undefined4 *)(*piRam0212912c + 0x28),0xf);
    piVar2 = piRam0212912c;
    *(undefined2 *)(*piRam0212912c + 0x8a) = uVar4;
    uVar4 = ComputeValueInterpolation_from_thumb
                      (1,((int)*psRam02129130 - (0xc0 - sVar1)) * 0x10000 >> 0x10,
                       (int)*psRam02129130,*(undefined4 *)(*piVar2 + 0x28),0xf);
    *(undefined2 *)(*piRam0212912c + 0x86) = uVar4;
  }
  iVar5 = TextSystem_IsDialogFinished_from_thumb();
  if ((iVar5 != 0) && (0xe < *(int *)(*piRam0212912c + 0x28))) {
    iVar5 = TextSystem_IsButton2Focused_from_thumb();
    puVar3 = puRam02129138;
    piVar2 = piRam0212912c;
    if (iVar5 != 0) {
      *(undefined4 *)(*piRam0212912c + 0x10) = 6;
      *(undefined4 *)(*piVar2 + 0x6c) = 0;
      *(undefined4 *)(*piVar2 + 0x28) = 0;
      uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar2 + 0xc0),0xf);
      TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar6,0,0,0,0,0,0);
      return;
    }
    iVar5 = *piRam0212912c;
    if (*(short *)(iVar5 + 0x70) == 0xc) {
      func_02060cb4(iVar5 + 0x5c,iVar5 + 0x44);
      WriteFriendListSaveDataSection();
      Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0212912c + 0xc0),0x81);
      TextSystem_DisplayProgressDialog_from_thumb();
      *(undefined4 *)(*piRam0212912c + 0x10) = 0xb;
    }
    else {
      *(byte *)(*(int *)*puRam02129138 + 0x31) = *(byte *)(*(int *)*puRam02129138 + 0x31) & 0xfe | 1
      ;
      Mem_CpuFill8((uint *)(uintptr_t)(*(int *)*puVar3 + 0xc),0,0x14);
      Mem_CpuCopy8((ushort *)(uintptr_t)(iVar5 + 0x44),(uint *)(uintptr_t)(*(int *)*puRam02129138 + 0xc),0x14);
      WriteSaveDataSectionHeaderToSaveData_from_thumb();
      TextSystem_SetFadeInSseqId_from_thumb(0x21);
      uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0212912c + 0xc0),0x10);
      uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0212912c + 0xc0),4);
      TextSystem_DisplaySingleButtonDialog_from_thumb(uVar6,uVar7,0,1,1,0);
      *(undefined4 *)(*piRam0212912c + 0x10) = 0xc;
    }
    *(undefined4 *)(*piRam0212912c + 0x28) = 0;
    return;
  }
  iVar5 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
  if ((iVar5 != 0) || (iVar5 = TextSystem_IsDialogFinished_from_thumb(), iVar5 != 0)) {
    TextSystem_CloseDialog_from_thumb();
    *(int *)(*piRam0212912c + 0x28) = *(int *)(*piRam0212912c + 0x28) + 1;
  }
  return;
}

