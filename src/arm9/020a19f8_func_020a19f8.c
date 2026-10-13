/* Decompiled C draft; module arm9; ROM address 020a19f8. No matching claim. */
#include "types.h"
#include "deps/020a19f8_func_020a19f8.h"

void func_020a19f8(int param_1)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  uVar3 = uRam020a1b60;
  param_1 = param_1 * 0x70;
  uVar4 = *(ushort *)
           ((*(uint *)(uRam020a1b60 & 0xfffffffc) >> (uRam020a1b60 & 3) * 8 |
            *(uint *)(uRam020a1b60 & 0xfffffffc) << (uRam020a1b60 & 3) * -8 + 0x20) + param_1 + 0x48
           ) + 1;
  if (uVar4 < 8) {
    do {
      uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      uVar8 = 0;
      do {
        if ((uVar4 & 0xffff) == (uint)*(ushort *)(uVar6 + 0x48)) {
          uVar8 = uVar8 & 0xffff;
          goto LAB_020a1a5c;
        }
        uVar8 = uVar8 + 1;
        uVar6 = uVar6 + 0x70;
      } while ((int)uVar8 < 8);
      uVar8 = 0;
LAB_020a1a5c:
      uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      iVar10 = uVar8 * 0x70 + uVar6;
      iVar9 = param_1 + uVar6;
      uVar1 = *(ushort *)(iVar10 + 0x48);
      if ((*(ushort *)(iVar9 + 0x48) < uVar1) &&
         ((uVar8 = iVar9 + 0x4cU & 3, uVar7 = *(uint *)(iVar9 + 0x4cU & 0xfffffffc),
          uVar6 = iVar10 + 0x4cU & 3, uVar5 = *(uint *)(iVar10 + 0x4cU & 0xfffffffc),
          (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) <
          (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) ||
          ((uVar8 = iVar9 + 8U & 3, uVar6 = *(uint *)(iVar9 + 8U & 0xfffffffc),
           uVar6 >> uVar8 * 8 != 0 || uVar6 << uVar8 * -8 + 0x20 != 0 &&
           (uVar8 = iVar10 + 8U & 3, uVar6 = *(uint *)(iVar10 + 8U & 0xfffffffc),
           uVar6 >> uVar8 * 8 == 0 && uVar6 << uVar8 * -8 + 0x20 == 0)))))) {
        *(ushort *)(iVar10 + 0x48) = *(ushort *)(iVar9 + 0x48);
        *(ushort *)
         (param_1 + (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x48) = uVar1;
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
  }
  uVar3 = uRam020a1b60;
  uVar4 = (uint)*(byte *)((*(uint *)(uRam020a1b64 & 0xfffffffc) >> (uRam020a1b64 & 3) * 8 |
                          *(uint *)(uRam020a1b64 & 0xfffffffc) << (uRam020a1b64 & 3) * -8 + 0x20) +
                         0x3d0);
  iVar9 = 0;
  *(undefined4 *)
   ((*(uint *)(uRam020a1b60 & 0xfffffffc) >> (uRam020a1b60 & 3) * 8 |
    *(uint *)(uRam020a1b60 & 0xfffffffc) << (uRam020a1b60 & 3) * -8 + 0x20) + 0x3b0) = uRam020a1b68;
  *(undefined4 *)
   ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3ac) = 0;
  if (uVar4 == 0) {
    return;
  }
  iVar10 = 0;
  do {
    uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    bVar2 = false;
    uVar8 = uVar7 + iVar10 + 0x4c;
    uVar6 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    uVar8 = uVar7 + 0x3b0 & 3;
    uVar5 = *(uint *)(uVar7 + 0x3b0 & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    if (((int)uVar6 < (int)uVar8) && (-1 < (int)uVar6)) {
      bVar2 = true;
    }
    if (!bVar2) {
      uVar6 = uVar8;
    }
    *(uint *)(uVar7 + 0x3b0) = uVar6;
    uVar7 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    iVar9 = iVar9 + 1;
    uVar8 = uVar7 + iVar10 + 0x4c;
    uVar6 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    uVar8 = uVar7 + 0x3ac & 3;
    uVar5 = *(uint *)(uVar7 + 0x3ac & 0xfffffffc);
    uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    iVar10 = iVar10 + 0x70;
    if ((int)uVar6 <= (int)uVar8) {
      uVar6 = uVar8;
    }
    *(uint *)(uVar7 + 0x3ac) = uVar6;
  } while (iVar9 < (int)uVar4);
  return;
}

