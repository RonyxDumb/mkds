/* Decompiled C draft; module arm9; ROM address 020a1b6c. No matching claim. */
#include "types.h"
#include "deps/020a1b6c_func_020a1b6c.h"

void func_020a1b6c(int param_1)

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
  uint uVar11;
  
  uVar11 = uRam020a1ccc;
  param_1 = param_1 * 0x70;
  uVar4 = (uint)*(ushort *)
                 ((*(uint *)(uRam020a1ccc & 0xfffffffc) >> (uRam020a1ccc & 3) * 8 |
                  *(uint *)(uRam020a1ccc & 0xfffffffc) << (uRam020a1ccc & 3) * -8 + 0x20) + param_1
                 + 0x48);
  uVar3 = uRam020a1ccc;
  do {
    uVar4 = uVar4 - 1;
    uRam020a1ccc = uVar3;
    if ((int)uVar4 < 0) {
      uVar4 = (uint)*(byte *)((*(uint *)(uRam020a1cd0 & 0xfffffffc) >> (uRam020a1cd0 & 3) * 8 |
                              *(uint *)(uRam020a1cd0 & 0xfffffffc) << (uRam020a1cd0 & 3) * -8 + 0x20
                              ) + 0x3d0);
      iVar9 = 0;
      *(undefined4 *)
       ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3b0) = uRam020a1cd4;
      *(undefined4 *)
       ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3ac) = 0;
      if (uVar4 == 0) {
        return;
      }
      iVar10 = 0;
      do {
        uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        bVar2 = false;
        uVar11 = uVar5 + iVar10 + 0x4c;
        uVar8 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        uVar8 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
        uVar11 = uVar5 + 0x3b0 & 3;
        uVar6 = *(uint *)(uVar5 + 0x3b0 & 0xfffffffc);
        uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
        if (((int)uVar8 < (int)uVar11) && (-1 < (int)uVar8)) {
          bVar2 = true;
        }
        if (!bVar2) {
          uVar8 = uVar11;
        }
        *(uint *)(uVar5 + 0x3b0) = uVar8;
        uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        iVar9 = iVar9 + 1;
        uVar11 = uVar5 + iVar10 + 0x4c;
        uVar8 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        uVar8 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
        uVar11 = uVar5 + 0x3ac & 3;
        uVar6 = *(uint *)(uVar5 + 0x3ac & 0xfffffffc);
        uVar11 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
        iVar10 = iVar10 + 0x70;
        if ((int)uVar8 <= (int)uVar11) {
          uVar8 = uVar11;
        }
        *(uint *)(uVar5 + 0x3ac) = uVar8;
      } while (iVar9 < (int)uVar4);
      return;
    }
    uVar6 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
            *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
    uVar8 = 0;
    do {
      if ((uVar4 & 0xffff) == (uint)*(ushort *)(uVar6 + 0x48)) {
        uVar8 = uVar8 & 0xffff;
        goto LAB_020a1bcc;
      }
      uVar8 = uVar8 + 1;
      uVar6 = uVar6 + 0x70;
    } while ((int)uVar8 < 8);
    uVar8 = 0;
LAB_020a1bcc:
    uVar6 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
            *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
    iVar10 = uVar8 * 0x70 + uVar6;
    iVar9 = param_1 + uVar6;
    uVar1 = *(ushort *)(iVar10 + 0x48);
    if ((uVar1 < *(ushort *)(iVar9 + 0x48)) &&
       ((uVar8 = iVar9 + 0x4cU & 3, uVar7 = *(uint *)(iVar9 + 0x4cU & 0xfffffffc),
        uVar6 = iVar10 + 0x4cU & 3, uVar5 = *(uint *)(iVar10 + 0x4cU & 0xfffffffc),
        (int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) <
        (int)(uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) ||
        ((uVar8 = iVar9 + 8U & 3, uVar6 = *(uint *)(iVar9 + 8U & 0xfffffffc),
         uVar6 >> uVar8 * 8 == 0 && uVar6 << uVar8 * -8 + 0x20 == 0 &&
         (uVar8 = iVar10 + 8U & 3, uVar6 = *(uint *)(iVar10 + 8U & 0xfffffffc),
         uVar6 >> uVar8 * 8 != 0 || uVar6 << uVar8 * -8 + 0x20 != 0)))))) {
      *(ushort *)(iVar10 + 0x48) = *(ushort *)(iVar9 + 0x48);
      *(ushort *)
       (param_1 + (*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                  *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) + 0x48) = uVar1;
      uVar3 = uRam020a1ccc;
    }
  } while( true );
}

