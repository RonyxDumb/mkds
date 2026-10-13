/* Decompiled C draft; module arm9; ROM address 020a8a6c. No matching claim. */
#include "types.h"
#include "deps/020a8a6c_func_020a8a6c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020a8a6c(uint param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uStack_48;
  
  if (param_1 == 0) {
    return;
  }
  uStack_48 = 10;
  iVar8 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar8) {
      return;
    }
    uVar7 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar8 * 4;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
    if (uVar7 == 0) break;
    iVar2 = IsNotStaffRoll();
    uVar6 = uRam020a8ecc;
    if (iVar2 == 0) {
      uVar3 = *(uint *)(uRam020a8eb4 & 0xfffffffc) >> (uRam020a8eb4 & 3) * 8 |
              *(uint *)(uRam020a8eb4 & 0xfffffffc) << (uRam020a8eb4 & 3) * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 == 0x14) {
        *(undefined4 *)(uVar7 + 0xf0) = 1;
        *(undefined4 *)(uVar7 + 0xa0) = 0x108;
        *(undefined4 *)(uVar7 + 0xa8) = 8;
        *(uint *)(uVar7 + 0xa4) = uVar7 + 0xb0;
        uVar6 = func_02108e6c(8);
        *(undefined4 *)(uVar7 + 0xbc) = uVar6;
        *(undefined4 *)(uVar7 + 0xb0) = 0;
        *(undefined4 *)(uVar7 + 0xb4) = 0;
        *(undefined4 *)(uVar7 + 0xb8) = 0;
        *(undefined4 *)(uVar7 + 200) = uRam020a8ed0;
        *(undefined4 *)(uVar7 + 0xd0) = 8;
        *(uint *)(uVar7 + 0xcc) = uVar7 + 0xd8;
        uVar6 = func_02108e6c(9);
        *(undefined4 *)(uVar7 + 0xe4) = uVar6;
        *(undefined4 *)(uVar7 + 0xd8) = 0;
        *(undefined4 *)(uVar7 + 0xdc) = 0;
        *(undefined4 *)(uVar7 + 0xe0) = 0;
        func_020a8ed8(uVar7 + 0xa0,uVar7 + 4);
      }
      else if (uVar4 == 0x16) {
        *(undefined4 *)(uVar7 + 0xf0) = 6;
        uVar4 = uVar7 + 0x9c & 3;
        uVar3 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
        uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = uVar5 + 8 & 3;
        uVar9 = *(uint *)(uVar5 + 8 & 0xfffffffc);
        uVar3 = uVar5 + 4 & 3;
        uVar10 = *(uint *)(uVar5 + 4 & 0xfffffffc);
        uVar12 = *(uint *)(uVar5 & 0xfffffffc);
        *(undefined4 *)(uVar7 + 0xa0) = uVar6;
        *(undefined4 *)(uVar7 + 0xa8) = 6;
        *(uint *)(uVar7 + 0xa4) = uVar7 + 0xb0;
        uVar6 = func_02108e6c(8);
        *(undefined4 *)(uVar7 + 0xbc) = uVar6;
        *(uint *)(uVar7 + 0xb0) = uVar12 >> (uVar5 & 3) * 8 | uVar12 << (uVar5 & 3) * -8 + 0x20;
        *(uint *)(uVar7 + 0xb4) = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        *(uint *)(uVar7 + 0xb8) = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
        uVar4 = uVar7 + 0x24 & 3;
        uVar3 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
        lVar1 = (ulonglong)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x5000;
        VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,
                          uVar7 + 0x40,uVar7 + 0xb0,(int *)(uintptr_t)(uVar7 + 0xb0));
        uVar4 = uVar7 + 0x9c & 3;
        uVar3 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
        uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = uVar5 + 8 & 3;
        uVar9 = *(uint *)(uVar5 + 8 & 0xfffffffc);
        uVar3 = uVar5 + 4 & 3;
        uVar10 = *(uint *)(uVar5 + 4 & 0xfffffffc);
        uVar12 = *(uint *)(uVar5 & 0xfffffffc);
        *(undefined4 *)(uVar7 + 200) = uRam020a8ecc;
        *(undefined4 *)(uVar7 + 0xd0) = 6;
        *(uint *)(uVar7 + 0xcc) = uVar7 + 0xd8;
        uVar6 = func_02108e6c(9);
        *(undefined4 *)(uVar7 + 0xe4) = uVar6;
        *(uint *)(uVar7 + 0xd8) = uVar12 >> (uVar5 & 3) * 8 | uVar12 << (uVar5 & 3) * -8 + 0x20;
        *(uint *)(uVar7 + 0xdc) = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        *(uint *)(uVar7 + 0xe0) = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
        uVar4 = uVar7 + 0x24 & 3;
        uVar3 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
        uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        lVar1 = (ulonglong)uVar4 * 0xffffb000;
        VecFx32_AddScale1((uint)lVar1 >> 0xc | ((int)((ulonglong)lVar1 >> 0x20) - uVar4) * 0x100000,
                          uVar7 + 0x40,uVar7 + 0xd8,(int *)(uintptr_t)(uVar7 + 0xd8));
      }
      else if (uVar4 == 0x19) {
        *(undefined4 *)(uVar7 + 0xf0) = 1;
        *(undefined4 *)(uVar7 + 0xa0) = 0x1a0;
        *(undefined4 *)(uVar7 + 0xa8) = 8;
        *(uint *)(uVar7 + 0xa4) = uVar7 + 0xb0;
        uVar6 = func_02108e6c(8);
        *(undefined4 *)(uVar7 + 0xbc) = uVar6;
        *(undefined4 *)(uVar7 + 0xb0) = 0;
        *(undefined4 *)(uVar7 + 0xb4) = 0;
        *(undefined4 *)(uVar7 + 0xb8) = 0;
        *(undefined4 *)(uVar7 + 200) = uRam020a8ed4;
        *(undefined4 *)(uVar7 + 0xd0) = 8;
        *(uint *)(uVar7 + 0xcc) = uVar7 + 0xd8;
        uVar6 = func_02108e6c(9);
        *(undefined4 *)(uVar7 + 0xe4) = uVar6;
        *(undefined4 *)(uVar7 + 0xd8) = 0;
        *(undefined4 *)(uVar7 + 0xdc) = 0;
        *(undefined4 *)(uVar7 + 0xe0) = 0;
        func_020a8ed8(uVar7 + 0xa0,uVar7 + 4);
      }
      else if ((*(ushort *)(uVar7 + 2) & 0x100) == 0) {
        func_020d2398(uVar7);
      }
    }
    else {
      uVar3 = *(uint *)(uRam020a8eb4 & 0xfffffffc) >> (uRam020a8eb4 & 3) * 8 |
              *(uint *)(uRam020a8eb4 & 0xfffffffc) << (uRam020a8eb4 & 3) * -8 + 0x20;
      uVar4 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      if (uVar4 == 0x14) {
        *(undefined4 *)(uVar7 + 0xf0) = 4;
        uVar4 = uVar7 + 0x9c & 3;
        uVar3 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
        uVar9 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = uVar9 + 8 & 3;
        uVar5 = *(uint *)(uVar9 + 8 & 0xfffffffc);
        uVar3 = uVar9 + 4 & 3;
        uVar10 = *(uint *)(uVar9 + 4 & 0xfffffffc);
        iVar2 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iRam020a8eb8;
        iVar11 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iRam020a8ebc;
        *(undefined4 *)(uVar7 + 0xa0) = uRam020a8ec0;
        *(undefined4 *)(uVar7 + 0xa8) = 5;
        *(uint *)(uVar7 + 0xa4) = uVar7 + 0xb0;
        uVar6 = func_02108e6c(8);
        *(undefined4 *)(uVar7 + 0xbc) = uVar6;
        *(int *)(uVar7 + 0xb0) = iVar11;
        *(uint *)(uVar7 + 0xb4) = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        *(int *)(uVar7 + 0xb8) = iVar2;
        uVar4 = uVar7 + 0x9c & 3;
        uVar3 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
        uVar9 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = uVar9 + 8 & 3;
        uVar5 = *(uint *)(uVar9 + 8 & 0xfffffffc);
        uVar3 = uVar9 + 4 & 3;
        uVar10 = *(uint *)(uVar9 + 4 & 0xfffffffc);
        iVar2 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + iRam020a8ec4;
        iVar11 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iRam020a8ec8;
        *(undefined4 *)(uVar7 + 200) = uRam020a8ec0;
        *(undefined4 *)(uVar7 + 0xd0) = 5;
        *(uint *)(uVar7 + 0xcc) = uVar7 + 0xd8;
        uVar6 = func_02108e6c(9);
        *(undefined4 *)(uVar7 + 0xe4) = uVar6;
        *(int *)(uVar7 + 0xd8) = iVar11;
        *(uint *)(uVar7 + 0xdc) = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        *(int *)(uVar7 + 0xe0) = iVar2;
      }
      else if (uVar4 == 0x16) {
        *(undefined4 *)(uVar7 + 0xf0) = 5;
        uVar4 = uVar7 + 0x9c & 3;
        uVar3 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
        uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
        uVar4 = uVar5 + 8 & 3;
        uVar9 = *(uint *)(uVar5 + 8 & 0xfffffffc);
        uVar3 = uVar5 + 4 & 3;
        uVar10 = *(uint *)(uVar5 + 4 & 0xfffffffc);
        uVar12 = *(uint *)(uVar5 & 0xfffffffc);
        *(undefined4 *)(uVar7 + 0xa0) = uRam020a8ecc;
        *(undefined4 *)(uVar7 + 0xa8) = 4;
        *(uint *)(uVar7 + 0xa4) = uVar7 + 0xb0;
        uVar6 = 8;
        if ((iVar8 != 0) && (uVar6 = 9, iVar8 != 1)) {
          uVar6 = uStack_48;
        }
        uVar6 = func_02108e6c(uVar6);
        *(undefined4 *)(uVar7 + 0xbc) = uVar6;
        *(uint *)(uVar7 + 0xb0) = uVar12 >> (uVar5 & 3) * 8 | uVar12 << (uVar5 & 3) * -8 + 0x20;
        *(uint *)(uVar7 + 0xb4) = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
        *(uint *)(uVar7 + 0xb8) = uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20;
        uVar4 = uVar7 + 0x24 & 3;
        uVar3 = *(uint *)(uVar7 + 0x24 & 0xfffffffc);
        lVar1 = (ulonglong)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 0x5000;
        VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,
                          uVar7 + 0x40,uVar7 + 0xb0,(int *)(uintptr_t)(uVar7 + 0xb0));
      }
      else if ((*(ushort *)(uVar7 + 2) & 0x100) == 0) {
        func_020d2398(uVar7);
      }
    }
    iVar8 = iVar8 + 1;
  }
  return;
}

