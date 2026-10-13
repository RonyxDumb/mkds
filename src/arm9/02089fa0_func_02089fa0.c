/* Decompiled C draft; module arm9; ROM address 02089fa0. No matching claim. */
#include "types.h"
#include "deps/02089fa0_func_02089fa0.h"

void func_02089fa0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_60 [36];
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  Matrix4x3_Identity(&local_90);
  puVar1 = puRam0208a1cc;
  *puRam0208a1cc = local_90;
  puVar1[1] = uStack_8c;
  puVar1[2] = uStack_88;
  puVar1[3] = uStack_84;
  puVar1[4] = local_80;
  puVar1[5] = uStack_7c;
  puVar1[6] = uStack_78;
  puVar1[7] = uStack_74;
  uVar6 = uRam0208a1d0;
  puVar1[8] = local_70;
  puVar1[9] = uStack_6c;
  puVar1[10] = uStack_68;
  puVar1[0xb] = uStack_64;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0xc;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if (uVar7 >> uVar6 * 8 != 0 || uVar7 << uVar6 * -8 + 0x20 != 0) {
    return;
  }
  uVar10 = *(uint *)(uRam0208a1d4 & 0xfffffffc) >> (uRam0208a1d4 & 3) * 8 |
           *(uint *)(uRam0208a1d4 & 0xfffffffc) << (uRam0208a1d4 & 3) * -8 + 0x20;
  uVar7 = uVar10 + 0x73c & 3;
  uVar6 = *(uint *)(uVar10 + 0x73c & 0xfffffffc);
  if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) != 9) {
    uStack_3c = 0;
    uStack_34 = 0;
    uStack_30 = *puRam0208a1d8;
    uStack_2c = puRam0208a1d8[1];
    uStack_28 = puRam0208a1d8[2];
    uStack_38 = *(uint *)(uRam0208a1dc & 0xfffffffc) >> (uRam0208a1dc & 3) * 8 |
                *(uint *)(uRam0208a1dc & 0xfffffffc) << (uRam0208a1dc & 3) * -8 + 0x20;
    uVar7 = (*(uint *)(uRam0208a1d4 & 0xfffffffc) >> (uRam0208a1d4 & 3) * 8 |
            *(uint *)(uRam0208a1d4 & 0xfffffffc) << (uRam0208a1d4 & 3) * -8 + 0x20) + 0x73c;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) == 2) {
      uStack_38 = 0x50000;
    }
    MTX_Identity33_((undefined4 *)(void *)(auStack_60));
    iVar2 = iRam0208a1e0;
    uVar7 = 0;
    uVar10 = *(uint *)(uRam0208a1d4 & 0xfffffffc) >> (uRam0208a1d4 & 3) * 8 |
             *(uint *)(uRam0208a1d4 & 0xfffffffc) << (uRam0208a1d4 & 3) * -8 + 0x20;
    uVar6 = uVar10 + 0x20 & 3;
    uVar8 = *(uint *)(uVar10 + 0x20 & 0xfffffffc);
    uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
    if (*(short *)(uVar6 + 0x10) != 0) {
      do {
        uVar8 = *(uint *)(uVar6 & 0xfffffffc);
        G3i_OrthoW_(0x60000,0xfffa0000,0xfff80000,0x80000);
        uVar10 = iVar2 + 0xfcU & 3;
        uVar9 = *(uint *)(iVar2 + 0xfcU & 0xfffffffc);
        *(uint *)(iVar2 + 0xfc) = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0xffffffaf;
        func_02010fe4(&uStack_30);
        asm_MI_Copy36B((undefined4 *)(void *)(auStack_60),(undefined4 *)(uintptr_t)(uRam0208a1ec));
        uVar10 = iVar2 + 0xfcU & 3;
        uVar9 = *(uint *)(iVar2 + 0xfcU & 0xfffffffc);
        *(uint *)(iVar2 + 0xfc) = (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 0xffffff5b;
        func_0201100c(&uStack_3c);
        func_02011034();
        func_01ff8cf0((uint *)(uintptr_t)(uVar7 * 0x6c + (uVar8 >> (uVar6 & 3) * 8 | uVar8 << (uVar6 & 3) * -8 + 0x20)));
        uVar7 = uVar7 + 1 & 0xffff;
        uVar10 = *(uint *)(uRam0208a1d4 & 0xfffffffc) >> (uRam0208a1d4 & 3) * 8 |
                 *(uint *)(uRam0208a1d4 & 0xfffffffc) << (uRam0208a1d4 & 3) * -8 + 0x20;
        uVar6 = uVar10 + 0x20 & 3;
        uVar8 = *(uint *)(uVar10 + 0x20 & 0xfffffffc);
        uVar6 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
      } while (uVar7 < *(ushort *)(uVar6 + 0x10));
    }
  }
  uVar4 = uRam0208a1fc;
  puVar1 = puRam0208a1f8;
  uVar3 = uRam0208a1f4;
  uVar7 = uVar10 + 0x78c & 3;
  uVar6 = *(uint *)(uVar10 + 0x78c & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 == 0 && uVar6 << uVar7 * -8 + 0x20 == 0) {
    return;
  }
  *puRam0208a1f0 = *puRam0208a1f0 & 0xcfff | 8;
  puVar5 = puRam0208a200;
  *puVar1 = uVar3;
  puVar1 = puRam0208a204;
  *puVar5 = uVar4;
  uVar6 = uRam0208a1d4;
  *puVar1 = 0;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  G3_LoadMtx44((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + iRam0208a208);
  puVar1 = puRam0208a204;
  *puRam0208a20c = 0x20000000;
  puVar5 = puRam0208a210;
  *puVar1 = 2;
  uVar6 = uRam0208a1d4;
  *puVar5 = 0;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  func_02089d70((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + iRam0208a214);
  return;
}

