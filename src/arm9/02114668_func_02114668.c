/* Decompiled C draft; module arm9; ROM address 02114668. No matching claim. */
#include "types.h"
#include "deps/02114668_func_02114668.h"

void func_02114668(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_02114750;
  *(undefined4 *)(*DAT_02114750 + 0x54) = *(undefined4 *)(*DAT_02114750 + 0x58);
  switch(*(undefined4 *)(*piVar1 + 0x54)) {
  case 0:
    func_021156bc();
    break;
  case 1:
    func_021156a4();
    break;
  case 2:
    func_0211568c();
    break;
  case 3:
    func_0211553c();
    break;
  case 4:
    func_02115204();
    break;
  case 5:
    func_02115000();
    break;
  case 6:
    func_02114dfc();
    break;
  case 7:
    func_02114cb0();
    break;
  case 8:
    func_02114c98();
    break;
  case 9:
    func_02114c48();
    break;
  case 10:
    func_02114ad8();
    break;
  case 0xb:
    func_0211489c();
    break;
  case 0xc:
    func_02114754();
  }
  func_02116624();
  iVar3 = *DAT_02114750;
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
  iVar3 = *DAT_02114750;
  uVar2 = func_0211130c();
  func_02124c30(*(undefined4 *)(iVar3 + 0x30),*(undefined4 *)(iVar3 + 0x2c),
                *(undefined4 *)(iVar3 + 0x38),uVar2,*(undefined4 *)(iVar3 + 0x3c));
  return;
}

