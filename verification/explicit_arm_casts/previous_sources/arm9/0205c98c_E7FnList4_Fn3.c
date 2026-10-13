/* Decompiled C draft; module arm9; ROM address 0205c98c. No matching claim. */
#include "types.h"
#include "deps/0205c98c_E7FnList4_Fn3.h"

void E7FnList4_Fn3(void)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined8 uVar12;
  
  uVar6 = uRam0205cbe0;
  uVar7 = 0;
  uVar9 = 0;
  do {
    uVar3 = func_0x0219bb50();
    uVar11 = uRam0205cbe0;
    if ((uVar9 == uVar3) ||
       (uVar3 = uVar6 & 3, uVar4 = *(uint *)(uVar6 & 0xfffffffc),
       0xb < *(byte *)(uVar9 * 0x38 + (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) + 0x48))) {
      uVar7 = uVar7 | 1 << (uVar9 & 0xff) & 0xffU;
    }
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 4);
  uVar6 = *(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
          *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20;
  uVar9 = (uint)*(byte *)(uVar6 + 0x749);
  if (uVar9 == (uVar9 & uVar7)) {
    *(char *)(uVar6 + 0xfb) = (char)uVar7;
    uVar9 = uVar11 & 3;
    uVar6 = *(uint *)(uVar11 & 0xfffffffc);
    uVar9 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
    *(undefined2 *)(uVar9 + 0x10) = 2;
    *(undefined2 *)(uVar9 + 0x12) = 1;
  }
  uVar11 = 0;
  uVar7 = *(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
          *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20;
  uVar9 = uVar7 + 0x754 & 3;
  uVar6 = *(uint *)(uVar7 + 0x754 & 0xfffffffc);
  uVar9 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
  iVar10 = uVar9 + 4;
  do {
    iVar8 = uVar11 * 0x38;
    uVar6 = uVar7 + iVar8 + 0x44;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (uVar6 >> uVar3 * 8 != 0 || uVar6 << uVar3 * -8 + 0x20 != 0) {
      Mem_CpuCopy8(uVar7 + 0x14 + iVar8,iVar10,0x28);
      uVar12 = Os_GetTick();
      *(undefined8 *)(uVar9 + 0x18) = uVar12;
      iVar5 = func_0205c340(uVar11,0,0x28);
      if (iVar5 == 0) {
        Mem_CpuFill8(iVar10,0,0x28);
      }
      else {
        *(undefined4 *)
         ((*(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
          *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20) + iVar8 + 0x44) =
             0;
      }
      bVar1 = true;
      goto LAB_0205cab8;
    }
    uVar11 = uVar11 + 1 & 0xff;
  } while (uVar11 < 4);
  bVar1 = false;
LAB_0205cab8:
  if (bVar1) {
    return;
  }
  uVar9 = *(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
          *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20;
  if (3 < *(ushort *)(uVar9 + 0xf8)) {
    *(undefined2 *)(uVar9 + 0xf8) = 0;
    return;
  }
  uVar6 = *(ushort *)(uVar9 + 0xf8) & 0xff;
  if ((((uint)*(byte *)(uVar9 + 0x749) & 1 << uVar6) != 0) &&
     (uVar9 = func_0x0219bb50(), uVar6 != uVar9)) {
    iVar8 = uVar6 * 0x38;
    uVar9 = *(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
            *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20;
    iVar10 = uVar9 + iVar8;
    if (*(byte *)(iVar10 + 0x48) < 0xc) {
      uVar9 = uVar9 + 0x754;
      uVar7 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
      uVar2 = func_0x0219bb50();
      *(undefined2 *)(uVar9 + 4) = uVar2;
      uVar12 = Os_GetTick();
      *(undefined8 *)(uVar9 + 8) = uVar12;
      *(undefined4 *)(uVar9 + 0x10) = 0;
      *(undefined4 *)(uVar9 + 0x14) = 0;
      *(undefined4 *)(uVar9 + 0x18) = 0;
      *(undefined4 *)(uVar9 + 0x1c) = 0;
      *(undefined4 *)(uVar9 + 0x20) = 0;
      *(undefined4 *)(uVar9 + 0x24) = 0;
      func_0205c340(uVar6,0,0x28);
    }
    else {
      if (*(char *)(iVar10 + 0x4a) == '\0') {
        func_0205c340(uVar6,5,0);
      }
      uVar6 = uRam0205cbe0;
      iVar10 = (*(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
               *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20) + 0x4a;
      *(char *)(iVar10 + iVar8) = *(char *)(iVar10 + iVar8) + '\x01';
      uVar9 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar10 = (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) + 0x4a;
      if (4 < *(byte *)(iVar10 + iVar8)) {
        *(undefined1 *)(iVar10 + iVar8) = 0;
      }
    }
  }
  uVar9 = *(uint *)(uRam0205cbe0 & 0xfffffffc) >> (uRam0205cbe0 & 3) * 8 |
          *(uint *)(uRam0205cbe0 & 0xfffffffc) << (uRam0205cbe0 & 3) * -8 + 0x20;
  *(short *)(uVar9 + 0xf8) = *(short *)(uVar9 + 0xf8) + 1;
  return;
}

