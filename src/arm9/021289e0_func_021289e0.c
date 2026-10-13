/* Decompiled C draft; module arm9; ROM address 021289e0. No matching claim. */
#include "types.h"
#include "deps/021289e0_func_021289e0.h"

void func_021289e0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_1c;
  
  func_0212a920();
  NavigationContext_OnSceneUpdate_from_thumb();
  piVar1 = DAT_02128b08;
  *(undefined4 *)(*DAT_02128b08 + 0xc) = *(undefined4 *)(*DAT_02128b08 + 0x10);
  if (*(int *)(*piVar1 + 0x24) != 0) {
    func_020abae0();
  }
  switch(*(undefined4 *)(*DAT_02128b08 + 0xc)) {
  case 0:
    Keyboard_SwitchFn0_from_thumb();
    break;
  case 1:
    Keyboard_SwitchFn1_from_thumb();
    break;
  case 2:
    Keyboard_SwitchFn2_from_thumb();
    break;
  case 3:
    Keyboard_SwitchFn3_from_thumb();
    break;
  case 4:
    Keyboard_SwitchFn4_from_thumb();
    break;
  case 5:
    Keyboard_SwitchFn5_from_thumb();
    break;
  case 6:
    Keyboard_SwitchFn6_from_thumb();
    break;
  case 7:
    Keyboard_SwitchFn7_from_thumb();
    break;
  case 8:
    Keyboard_SwitchFn8_from_thumb();
    break;
  case 9:
    Keyboard_SwitchFn9_from_thumb();
    break;
  case 10:
    Keyboard_SwitchFn10_from_thumb();
    break;
  case 0xb:
    Keyboard_SwitchFn11_from_thumb();
    break;
  case 0xc:
    Keyboard_SwitchFn12_from_thumb();
    break;
  case 0xd:
    Keyboard_SwitchFn13_from_thumb();
  }
  func_02128cfc();
  func_02128bd4();
  func_02128b54();
  func_02128ca0();
  func_02128c40();
  func_02129ea4();
  iVar4 = 0;
  local_1c = 0;
  iVar5 = 0;
  do {
    iVar3 = *DAT_02128b08;
    uVar2 = GetKeyboardOam_from_thumb();
    func_02124c30(*(undefined4 *)(iVar3 + iVar5 + 0x9c),*(undefined4 *)(iVar3 + 0x90),
                  *(undefined4 *)(iVar3 + iVar5 + 0xac),uVar2,*(undefined4 *)(iVar3 + iVar4 + 0x74))
    ;
    iVar4 = iVar4 + 8;
    iVar5 = iVar5 + 4;
    local_1c = local_1c + 1;
  } while (local_1c < 2);
  iVar5 = *DAT_02128b08;
  iVar3 = *(int *)(iVar5 + 4);
  uVar2 = func_02128884();
  iVar4 = iVar5 + iVar3 * 4;
  func_02124c30(*(undefined4 *)(iVar4 + 0x9c),*(undefined4 *)(iVar5 + 0x90),
                *(undefined4 *)(iVar4 + 0xac),uVar2,*(undefined4 *)(iVar5 + iVar3 * 8 + 0x78));
  return;
}

