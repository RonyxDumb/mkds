/* Decompiled C draft; module arm9; ROM address 0211a7bc. No matching claim. */
#include "types.h"
#include "deps/0211a7bc_func_0211a7bc.h"

undefined4 func_0211a7bc(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = DAT_0211a8fc;
  *(undefined4 *)(*DAT_0211a8fc + 0x30) = *(undefined4 *)(*DAT_0211a8fc + 0x34);
  *(undefined4 *)(*piVar1 + 100) = *(undefined4 *)(*piVar1 + 0x60);
  *(undefined4 *)(*piVar1 + 0x80) = *(undefined4 *)(*piVar1 + 0x7c);
  switch(*(undefined4 *)(*piVar1 + 0x30)) {
  case 0:
    func_0211b224();
    break;
  case 1:
    func_0211b07c();
    break;
  case 2:
    func_0211afd0();
    break;
  case 3:
    func_0211acec();
    break;
  case 4:
    func_0211ac88();
    break;
  case 5:
    func_0211ac70();
    break;
  case 6:
    func_0211ac24();
    break;
  case 7:
    func_0211abd0();
    break;
  case 8:
    func_0211a9d8();
  }
  if (*(int *)(*DAT_0211a900 + 0x20) == 2) {
    func_02116d24();
  }
  iVar2 = *(int *)(*DAT_0211a8fc + 0x78);
  if (iVar2 == 0) {
    func_0202b6f0(0);
  }
  else if ((iVar2 == 1) || (iVar2 == 2)) {
    func_0202b6f0(1);
  }
  func_0202bb80();
  if (*DAT_0211a904 != 2) {
    func_0212b80c();
  }
  func_0211d9dc();
  func_0211d66c();
  func_0211c0cc();
  puVar3 = (undefined4 *)*DAT_0211a8fc;
  func_02124c30(puVar3[1],*puVar3,puVar3[3],puVar3[0x2d],puVar3[5]);
  iVar2 = 0;
  do {
    func_0211a908(iVar2);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  iVar2 = *DAT_0211a8fc;
  if (*(int *)(iVar2 + 0x30) == 8) {
    if ((*(int *)(iVar2 + 0xb8) == 1) &&
       ((*(int *)(iVar2 + 0x2c) == 3 || (*(int *)(iVar2 + 0x70) == 1)))) {
      if ((9 < *(int *)(iVar2 + 0x38)) && (iVar2 = func_02128274(), iVar2 != 0)) {
        return *(undefined4 *)(*DAT_0211a8fc + 0xb8);
      }
    }
    else if (9 < *(int *)(iVar2 + 0x38)) {
      return *(undefined4 *)(iVar2 + 0xb8);
    }
  }
  return 0;
}

