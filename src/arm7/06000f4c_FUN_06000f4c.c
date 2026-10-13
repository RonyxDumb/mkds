/* Decompiled C draft; module arm7; ROM address 06000f4c. No matching claim. */
#include "types.h"
#include "deps/06000f4c_FUN_06000f4c.h"

void FUN_06000f4c(int param_1)

{
  uint uVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  
  iVar5 = FUN_06000680();
  uVar1 = iVar5 + 0x154cU & 3;
  uVar6 = *(uint *)(iVar5 + 0x154cU & 0xfffffffc);
  uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar11 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  iVar5 = 0;
  uVar1 = uVar11 + 0xc & 3;
  uVar6 = *(uint *)(uVar11 + 0xc & 0xfffffffc);
  if (uVar6 >> uVar1 * 8 != 0 || uVar6 << uVar1 * -8 + 0x20 != 0) {
    if (*(short *)(param_1 + 0xe) == 0) {
      iVar10 = 1;
      uVar2 = *DAT_06001220;
      if ((uint)*DAT_0600121c < (uint)*DAT_0600121c) {
        uVar2 = *DAT_06001220;
      }
      if ((int)((((uVar2 & 0xf) << 0xc | (int)(uint)*DAT_0600121c >> 4) -
                (uint)*(ushort *)(uVar11 + 0x56)) * 0x10000) >> 0x10 < 1) {
        return;
      }
    }
    else {
      iVar10 = 0;
    }
    uVar7 = thunk_FUN_037faf70();
    if (*(short *)(uVar11 + 0x84) == 0) {
      thunk_FUN_037faf84();
    }
    else {
      *(undefined2 *)(uVar11 + 0x84) = 0;
      sVar3 = *(short *)(uVar11 + 0x90);
      thunk_FUN_037fa564(uVar11 + 0x58);
      thunk_FUN_037faf84(uVar7);
      bVar4 = true;
      if ((*(short *)(uVar11 + 0x8c) != 0) &&
         ((iVar10 != 0 ||
          (((uint)*(ushort *)(param_1 + 0x3e) & 1 << (*(ushort *)(uVar11 + 0x184) & 0xff)) == 0))))
      {
        bVar4 = false;
      }
      if ((sVar3 != 0) && ((iVar10 != 0 || (bVar4)))) {
        *(undefined2 *)(uVar11 + 0xba) = 4;
      }
      if (*(short *)(uVar11 + 0x8c) != 0) {
        *(undefined2 *)(uVar11 + 0x8c) = 0;
      }
      if (*(short *)(uVar11 + 0x8e) != 0) {
        *(undefined2 *)(uVar11 + 0x8e) = 0;
        iVar5 = FUN_06006f18(iVar10,bVar4);
      }
      if (sVar3 != 0) {
        puVar8 = (undefined2 *)thunk_FUN_03807424();
        *puVar8 = 0xe;
        if (iVar10 == 0) {
          if (((uint)*(ushort *)(param_1 + 0x3e) & 1 << (*(ushort *)(uVar11 + 0x184) & 0xff)) == 0)
          {
            puVar8[1] = 0;
          }
          else {
            puVar8[1] = 0xf;
          }
        }
        else {
          puVar8[1] = 9;
        }
        puVar8[2] = 0xd;
        *(undefined4 *)(puVar8 + 4) = 0;
        if (iVar10 == 0) {
          puVar8[6] = *(undefined2 *)(param_1 + 0x1c);
          puVar8[7] = *(undefined2 *)(param_1 + 0x1e);
          thunk_FUN_037fb390(param_1 + 0x28,puVar8 + 8,6);
          thunk_FUN_037fb390(param_1 + 0x2e,puVar8 + 0xb,6);
          puVar8[0xe] = *(undefined2 *)(param_1 + 0x3a);
          puVar8[0xf] = *(undefined2 *)(param_1 + 0x3c);
          puVar8[0x10] = *(undefined2 *)(param_1 + 0x3e);
        }
        thunk_FUN_038074cc(puVar8);
        if (sVar3 != 0) {
          if ((iVar5 == 1) || (*(short *)(uVar11 + 0x30) == 0)) {
            puVar9 = (undefined4 *)FUN_06000000();
            iVar5 = FUN_06000680();
            iVar10 = 0;
            *(undefined2 *)(uVar11 + 0x30) = 0;
            *(undefined2 *)(uVar11 + 0x32) = 0;
            *(undefined2 *)(uVar11 + 0x88) = 0;
            if (puVar9 != (undefined4 *)0x0) {
              *puVar9 = 0x2a;
              iVar10 = thunk_FUN_037f9854(iVar5 + 0x88,puVar9);
            }
            if ((iVar10 == 0) &&
               (uVar1 = iVar5 + 0x154cU & 3, uVar6 = *(uint *)(iVar5 + 0x154cU & 0xfffffffc),
               uVar6 >> uVar1 * 8 != 0 || uVar6 << uVar1 * -8 + 0x20 != 0)) {
              puVar8 = (undefined2 *)thunk_FUN_03807424();
              *puVar8 = 0x80;
              puVar8[1] = 8;
              puVar8[2] = 0x16;
              puVar8[3] = 0x2a;
              thunk_FUN_038074cc();
            }
          }
          else {
            *(undefined2 *)(uVar11 + 0x30) = 0;
            *(undefined2 *)(uVar11 + 0x32) = 1;
            *(undefined2 *)(uVar11 + 0x88) = 0;
          }
        }
      }
    }
  }
  return;
}

