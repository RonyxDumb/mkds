/* Decompiled C draft; module arm9; ROM address 02111b94. No matching claim. */
#include "types.h"
#include "deps/02111b94_func_02111b94.h"

void func_02111b94(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02111c74;
  *(undefined4 *)(*DAT_02111c74 + 0x4c) = *(undefined4 *)(*DAT_02111c74 + 0x50);
  switch(*(undefined4 *)(*piVar1 + 0x4c)) {
  case 0:
    func_02112b30();
    break;
  case 1:
    func_02112a0c();
    break;
  case 2:
    func_021128cc();
    break;
  case 3:
    func_021128b4();
    break;
  case 4:
    func_0211256c();
    break;
  case 5:
    func_021123a0();
    break;
  case 6:
    func_021121d4();
    break;
  case 7:
    func_0211209c();
    break;
  case 8:
    func_02111f54();
    break;
  case 9:
    func_02111ef4();
    break;
  case 10:
    func_02111db8();
    break;
  case 0xb:
    func_02111c78();
  }
  func_02113d84();
  iVar3 = *DAT_02111c74;
  if (*(int *)(iVar3 + 0x40) == 0) {
    uVar2 = func_02111318();
    func_02124c30(*(undefined4 *)(iVar3 + 8),*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0xc)
                  ,uVar2,*(undefined4 *)(iVar3 + 0x14));
  }
  else if (*(int *)(iVar3 + 0x40) == 1) {
    uVar2 = func_02111318();
    func_02124c30(*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x1c),uVar2,*(undefined4 *)(iVar3 + 0x24));
  }
  iVar3 = *DAT_02111c74;
  uVar2 = func_0211130c();
  func_02124c30(*(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x2c),
                *(undefined4 *)(iVar3 + 0x38),uVar2,*(undefined4 *)(iVar3 + 0x3c));
  return;
}

