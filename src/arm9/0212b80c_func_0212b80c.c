/* Decompiled C draft; module arm9; ROM address 0212b80c. No matching claim. */
#include "types.h"
#include "deps/0212b80c_func_0212b80c.h"

void func_0212b80c(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  puVar1 = puRam0212b870;
  piVar3 = (int *)*puRam0212b870;
  if (piVar3[1] == 0) {
    *piVar3 = *piVar3 + 1;
    if (0x59 < *(int *)*puVar1) {
      *(int *)*puVar1 = 0;
    }
  }
  iVar2 = *(int *)*puRam0212b870;
  if (iVar2 < 0x1e) {
    _s32_div_f((0x1e - iVar2) * 0x1000);
    func_0212b874();
    return;
  }
  if (iVar2 < 0x3c) {
    func_0212b874(0);
    return;
  }
  _s32_div_f((iVar2 + -0x3c) * 0x1000,0x1e);
  func_0212b874();
  return;
}

