/* Decompiled C draft; module arm9; ROM address 0210add4. No matching claim. */
#include "types.h"
#include "deps/0210add4_func_0210add4.h"

void func_0210add4(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  
  iVar2 = iRam0210aef8;
  uVar5 = iRam0210aef8 + 100U & 3;
  uVar3 = *(uint *)(iRam0210aef8 + 100U & 0xfffffffc);
  if (uVar3 >> uVar5 * 8 != 0 || uVar3 << uVar5 * -8 + 0x20 != 0) {
    return;
  }
  uVar5 = iRam0210aef8 + 0x6cU & 3;
  uVar3 = *(uint *)(iRam0210aef8 + 0x6cU & 0xfffffffc);
  uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  if (uVar5 == 0xffffffff) {
    iVar10 = 0;
    piVar9 = (int *)(iRam0210aef8 + 0x68);
    do {
      uVar5 = iVar2 + iVar10 * 4;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if (uVar5 >> uVar3 * 8 != 0 || uVar5 << uVar3 * -8 + 0x20 != 0) {
        iVar6 = iVar2 + iVar10 * 4;
        uVar5 = iVar6 + 0x40;
        uVar3 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
        if (uVar5 == 0) {
          if ((iVar10 == 0) ||
             (uVar5 = iVar2 + (iVar10 + -1) * 4 + 0x40, uVar3 = uVar5 & 3,
             uVar5 = *(uint *)(uVar5 & 0xfffffffc),
             0x13 < (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20))) {
            if ((iVar10 == 0) ||
               (uVar5 = iVar2 + (iVar10 + -1) * 4 + 0x40, uVar3 = uVar5 & 3,
               uVar5 = *(uint *)(uVar5 & 0xfffffffc),
               (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) != 0x14)) {
              *(undefined4 *)(iVar2 + 0x68) = 0x5f;
            }
            else {
              *piVar9 = (*(uint *)((uint)piVar9 & 0xfffffffc) >> ((uint)piVar9 & 3) * 8 |
                        *(uint *)((uint)piVar9 & 0xfffffffc) << ((uint)piVar9 & 3) * -8 + 0x20) -
                        0xf;
            }
            uVar5 = iVar2 + 0x68U & 3;
            uVar3 = *(uint *)(iVar2 + 0x68U & 0xfffffffc);
            if ((int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) < 0x1e) {
              *(undefined4 *)(iVar2 + 0x68) = 0x1e;
            }
            uVar5 = iVar2 + iVar10 * 4;
            uVar3 = uVar5 & 3;
            uVar4 = *(uint *)(uVar5 & 0xfffffffc);
            uVar5 = iVar2 + iVar10 * 4 + 0x20;
            uVar1 = uVar5 & 3;
            uVar7 = *(uint *)(uVar5 & 0xfffffffc);
            uVar5 = iVar2 + 0x68U & 3;
            uVar8 = *(uint *)(iVar2 + 0x68U & 0xfffffffc);
            StructMQRacerEntry_SomeFn_13
                      (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                       uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,0,
                       uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
            iVar6 = iVar2 + iVar10 * 4;
            uVar5 = iVar6 + 0x40;
            uVar3 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            *(uint *)(iVar6 + 0x40) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 1;
          }
        }
        else {
          *(uint *)(iVar6 + 0x40) = uVar5 + 1;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < 8);
    return;
  }
  *(uint *)(iRam0210aef8 + 0x6c) = uVar5 + 1;
  uVar5 = iVar2 + 0x6cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x6cU & 0xfffffffc);
  if (0x18 < (int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20)) {
    *(undefined4 *)(iVar2 + 0x6c) = 0xffffffff;
  }
  return;
}

