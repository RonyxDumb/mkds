/* Decompiled C draft; module arm9; ROM address 02082aec. No matching claim. */
#include "types.h"
#include "deps/02082aec_func_02082aec.h"

void func_02082aec(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar5;
  int iVar6;
  uint uVar4;
  
  uVar3 = (*(uint *)(uRam02082d28 & 0xfffffffc) >> (uRam02082d28 & 3) * 8 |
          *(uint *)(uRam02082d28 & 0xfffffffc) << (uRam02082d28 & 3) * -8 + 0x20) + 0x10;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  uVar3 = uRam02082d30;
  if ((uVar4 != 0) && (uVar3 = 0x1000, uVar4 == 1)) {
    uVar3 = uRam02082d2c;
  }
  uVar4 = (uint)((ulonglong)uRam02082d34 * (ulonglong)uVar3);
  uVar5 = FX_Div(0x1000,uVar4 + 0x800 >> 0xc |
                        (((int)uVar3 >> 0x1f) * uRam02082d34 +
                         (int)((ulonglong)uRam02082d34 * (ulonglong)uVar3 >> 0x20) +
                        (uint)(0xfffff7ff < uVar4)) * 0x100000);
  piVar2 = piRam02082d40;
  piVar1 = piRam02082d3c;
  uVar4 = *(uint *)(uRam02082d28 & 0xfffffffc) >> (uRam02082d28 & 3) * 8 |
          *(uint *)(uRam02082d28 & 0xfffffffc) << (uRam02082d28 & 3) * -8 + 0x20;
  *puRam02082d38 = uVar5;
  *piVar1 = 0;
  *piVar2 = 0;
  uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  if (uVar3 == 0x10) {
    iVar6 = IsNotStaffRoll();
    if (iVar6 != 0) {
      iVar6 = func_0208b7bc(0x3e,uRam02082d44);
      uVar5 = uRam02082d58;
      *piRam02082d40 = iVar6;
      *(undefined4 *)(iVar6 + 0x90) = uVar5;
      return;
    }
    uVar3 = (*(uint *)(uRam02082d28 & 0xfffffffc) >> (uRam02082d28 & 3) * 8 |
            *(uint *)(uRam02082d28 & 0xfffffffc) << (uRam02082d28 & 3) * -8 + 0x20) + 0xc;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar3 >> uVar4 * 8 == 0 && uVar3 << uVar4 * -8 + 0x20 == 0) {
      iVar6 = func_0208b7bc(0x29,uRam02082d44);
      uVar5 = uRam02082d5c;
      *piRam02082d40 = iVar6;
      *(undefined4 *)(iVar6 + 0x90) = uVar5;
      iVar6 = func_0208b7bc(0x25,uRam02082d44);
      uVar5 = uRam02082d60;
      *piRam02082d3c = iVar6;
      *(undefined4 *)(iVar6 + 0x90) = uVar5;
      return;
    }
    iVar6 = func_0208b7bc(0x29,uRam02082d44);
    uVar5 = uRam02082d58;
    *piRam02082d40 = iVar6;
    *(undefined4 *)(iVar6 + 0x90) = uVar5;
    return;
  }
  if (uVar3 != 0x25) {
    return;
  }
  uVar3 = uVar4 + 0xc & 3;
  uVar4 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0) {
    iVar6 = func_0208b7bc(0x24,uRam02082d44);
    uVar5 = uRam02082d48;
    *piRam02082d40 = iVar6;
    *(undefined4 *)(iVar6 + 0x90) = uVar5;
    iVar6 = func_0208b7bc(0x27,uRam02082d44);
    uVar5 = uRam02082d4c;
    *piRam02082d3c = iVar6;
    *(undefined4 *)(iVar6 + 0x90) = uVar5;
    return;
  }
  iVar6 = IsNotStaffRoll();
  if (iVar6 != 0) {
    iVar6 = func_0208b7bc(0x3d,uRam02082d44);
    uVar5 = uRam02082d50;
    *piRam02082d40 = iVar6;
    *(undefined4 *)(iVar6 + 0x90) = uVar5;
    iVar6 = func_0208b7bc(0x3f,uRam02082d44);
    uVar5 = uRam02082d54;
    *piRam02082d3c = iVar6;
    *(undefined4 *)(iVar6 + 0x90) = uVar5;
    return;
  }
  iVar6 = func_0208b7bc(0x3c,uRam02082d44);
  uVar5 = uRam02082d50;
  *piRam02082d40 = iVar6;
  *(undefined4 *)(iVar6 + 0x90) = uVar5;
  iVar6 = func_0208b7bc(0x3f,uRam02082d44);
  uVar5 = uRam02082d54;
  *piRam02082d3c = iVar6;
  *(undefined4 *)(iVar6 + 0x90) = uVar5;
  return;
}

