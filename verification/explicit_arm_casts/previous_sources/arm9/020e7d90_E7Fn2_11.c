/* Decompiled C draft; module arm9; ROM address 020e7d90. No matching claim. */
#include "types.h"
#include "deps/020e7d90_E7Fn2_11.h"

void E7Fn2_11(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int unaff_r4;
  int iVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  
  func_02147288(uRam020e7e34,uRam020e7e38,iRam020e7e3c);
  iVar3 = iRam020e7e4c;
  piVar2 = piRam020e7e48;
  piVar1 = piRam020e7e44;
  uVar4 = (*(uint *)(uRam020e7e40 & 0xfffffffc) >> (uRam020e7e40 & 3) * 8 |
          *(uint *)(uRam020e7e40 & 0xfffffffc) << (uRam020e7e40 & 3) * -8 + 0x20) + 0x48;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  bVar9 = ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 1) != 0;
  if (bVar9) {
    unaff_r4 = 0x2000;
  }
  if (!bVar9) {
    unaff_r4 = 0x800;
  }
  iVar6 = (*(uint *)((uint)piRam020e7e44 & 0xfffffffc) >> ((uint)piRam020e7e44 & 3) * 8 |
          *(uint *)((uint)piRam020e7e44 & 0xfffffffc) << ((uint)piRam020e7e44 & 3) * -8 + 0x20) +
          unaff_r4;
  uVar4 = iRam020e7e3c + 4U & 3;
  uVar7 = *(uint *)(iRam020e7e3c + 4U & 0xfffffffc);
  iVar8 = (*(uint *)((uint)piRam020e7e48 & 0xfffffffc) >> ((uint)piRam020e7e48 & 3) * 8 |
          *(uint *)((uint)piRam020e7e48 & 0xfffffffc) << ((uint)piRam020e7e48 & 3) * -8 + 0x20) +
          iVar6;
  *(uint *)(iRam020e7e3c + 4) = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) + iVar8;
  *piVar1 = iVar6;
  *piVar2 = iVar8;
  if (iVar3 < iVar8) {
    if (*(uint *)(uRam020e7e50 & 0xfffffffc) >> (uRam020e7e50 & 3) * 8 == 0 &&
        *(uint *)(uRam020e7e50 & 0xfffffffc) << (uRam020e7e50 & 3) * -8 + 0x20 == 0) {
      uVar5 = func_02108e6c(4);
      func_0212c6f0(uVar5,1);
      StateDualHandler_SetState(uRam020e7e54,0);
      return;
    }
    return;
  }
  return;
}

