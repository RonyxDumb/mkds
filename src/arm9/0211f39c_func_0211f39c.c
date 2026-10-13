/* Decompiled C draft; module arm9; ROM address 0211f39c. No matching claim. */
#include "types.h"
#include "deps/0211f39c_func_0211f39c.h"

void func_0211f39c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = piRam0211f3e4;
  *(undefined4 *)(*piRam0211f3e4 + 0x1c) = *(undefined4 *)(*piRam0211f3e4 + 0x20);
  iVar2 = *(int *)(*piVar1 + 0x1c);
  if (iVar2 == 0) {
    func_0211f440();
  }
  else if ((iVar2 != 1) && (iVar2 == 2)) {
    func_0211f3e8();
  }
  func_02116d24();
  puVar3 = (undefined4 *)*piRam0211f3e4;
  func_02124c30(puVar3[1],*puVar3,puVar3[3],puVar3[6],puVar3[4]);
  return;
}

