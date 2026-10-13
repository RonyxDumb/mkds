/* Decompiled C draft; module arm9; ROM address 02086250. No matching claim. */
#include "types.h"
#include "deps/02086250_func_02086250.h"

void func_02086250(undefined4 param_1)

{
  longlong lVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  iVar6 = func_02061818();
  if ((iVar6 != 0) && (iVar6 = func_02061818(), iVar6 != 3)) {
    return;
  }
  uVar5 = uRam02086594;
  puVar4 = puRam02086590;
  uVar3 = uRam0208658c;
  *puRam02086588 = *puRam02086588 & 0xcfff | 8;
  *puVar4 = uVar3;
  puVar4 = puRam0208659c;
  *puRam02086598 = uVar5;
  uVar3 = uRam020865a0;
  *puVar4 = 0;
  G3_LoadMtx44(uVar3);
  *puRam0208659c = 3;
  uVar7 = uRam020865a8;
  *puRam020865a4 = 0;
  uVar12 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar6 = *(byte *)((uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20) + 0x3d0) - 1;
  if (-1 < iVar6) {
    do {
      uVar10 = *(uint *)(uRam020865ac & 0xfffffffc) >> (uRam020865ac & 3) * 8 |
               *(uint *)(uRam020865ac & 0xfffffffc) << (uRam020865ac & 3) * -8 + 0x20;
      uVar12 = uVar10 + (uint)*(ushort *)(uVar10 + iVar6 * 2 + 0x44) * 4;
      uVar7 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      uVar12 = uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20;
      if ((((uVar12 != 0) &&
           (uVar7 = uVar10 + iVar6 * 4 + 0x54, uVar10 = uVar7 & 3,
           uVar7 = *(uint *)(uVar7 & 0xfffffffc),
           0 < (int)(uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20))) &&
          (*(short *)(uVar12 + 0x24) != 0)) &&
         ((iVar8 = GetDriverEntry(), uVar7 = iVar8 + 0x7cU & 3,
          uVar10 = *(uint *)(iVar8 + 0x7cU & 0xfffffffc),
          ((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) & 0xe0) == 0 &&
          (func_02147288(uVar12,param_1,&iStack_34), iStack_2c < 0)))) {
        uVar9 = func_02076cc4();
        uVar7 = uVar9 + 0x20 & 3;
        uVar10 = *(uint *)(uVar9 + 0x20 & 0xfffffffc);
        lVar1 = (longlong)
                (int)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                     *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) * (longlong)iStack_34
                + (longlong)iStack_2c *
                  (longlong)(int)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20);
        uVar7 = uVar9 + 0x24 & 3;
        uVar11 = *(uint *)(uVar9 + 0x24 & 0xfffffffc);
        uVar10 = uVar9 + 0x14 & 3;
        uVar9 = *(uint *)(uVar9 + 0x14 & 0xfffffffc);
        lVar2 = (longlong)(int)(uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) *
                (longlong)iStack_30 +
                (longlong)iStack_2c *
                (longlong)(int)(uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20);
        iVar8 = -iStack_2c;
        FX_Div((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14,iVar8);
        FX_Div((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14,iVar8);
        uVar7 = uVar12 + 0x1c & 3;
        uVar10 = *(uint *)(uVar12 + 0x1c & 0xfffffffc);
        uVar9 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
        uVar7 = uVar9 + 0x78;
        uVar10 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        if (uVar7 >> uVar10 * 8 != 0 || uVar7 << uVar10 * -8 + 0x20 != 0) {
          func_02086098(uVar9 + 0x6c,uVar12,param_1,
                        *(uint *)(uRam020865c0 & 0xfffffffc) >> (uRam020865c0 & 3) * 8 |
                        *(uint *)(uRam020865c0 & 0xfffffffc) << (uRam020865c0 & 3) * -8 + 0x20);
        }
        uVar7 = uVar12 + 0x1c & 3;
        uVar10 = *(uint *)(uVar12 + 0x1c & 0xfffffffc);
        func_02086098((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x48,uVar12,param_1,
                      *(uint *)(uRam020865c4 & 0xfffffffc) >> (uRam020865c4 & 3) * 8 |
                      *(uint *)(uRam020865c4 & 0xfffffffc) << (uRam020865c4 & 3) * -8 + 0x20);
        uVar7 = uVar12 + 0x1c & 3;
        uVar10 = *(uint *)(uVar12 + 0x1c & 0xfffffffc);
        func_02086098((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x24,uVar12,param_1,
                      0x21000);
        uVar7 = uVar12 + 0x1c & 3;
        uVar10 = *(uint *)(uVar12 + 0x1c & 0xfffffffc);
        func_02086098(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20,uVar12,param_1,
                      *(uint *)(uRam020865dc & 0xfffffffc) >> (uRam020865dc & 3) * 8 |
                      *(uint *)(uRam020865dc & 0xfffffffc) << (uRam020865dc & 3) * -8 + 0x20);
      }
      iVar6 = iVar6 + -1;
    } while (-1 < iVar6);
    return;
  }
  return;
}

