/* Decompiled C draft; module arm7; ROM address 06003694. No matching claim. */
#include "types.h"
#include "deps/06003694_FUN_06003694.h"

void FUN_06003694(void)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_230 [8];
  undefined1 auStack_228 [516];
  uint uVar9;
  
  iVar3 = FUN_06000680();
  uVar9 = iVar3 + 0x154cU & 3;
  uVar8 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) == 7) {
    uVar8 = 1;
    do {
      uVar6 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
      uVar7 = 1 << (uVar8 & 0xff);
      if ((*(ushort *)(uVar6 + 0x17e) & uVar7) != 0) {
        thunk_FUN_037fb390((uVar8 - 1) * 6 + uVar6 + 0x124,auStack_230,6);
        for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
          iVar5 = FUN_060029f8(auStack_228,auStack_230,3);
          sVar1 = *(short *)(iVar5 + 4);
          if ((sVar1 == 0) || ((sVar1 != 7 && (sVar1 != 0xc)))) break;
        }
        thunk_FUN_037faf70();
        uVar2 = ~(ushort)uVar7;
        uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        *(ushort *)(uVar7 + 0x17e) = *(ushort *)(uVar7 + 0x17e) & uVar2;
        uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        *(ushort *)(uVar7 + 0x86) = *(ushort *)(uVar7 + 0x86) & uVar2;
        iVar3 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + uVar8 * 8;
        *(undefined4 *)(iVar3 + 0x734) = 0;
        *(undefined4 *)(iVar3 + 0x738) = 0;
        thunk_FUN_037faf84();
      }
      uVar8 = uVar8 + 1;
    } while ((int)uVar8 < 0x10);
    iVar3 = FUN_06002ca4(auStack_228,1);
    if (*(short *)(iVar3 + 4) == 0) {
      *(undefined2 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0xbe) = 0;
      *(undefined2 *)
       (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
       *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) = 3;
      iVar3 = FUN_0600210c(auStack_228);
      if (*(short *)(iVar3 + 4) == 0) {
        *(undefined2 *)
         (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
         *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) = 2;
        *(undefined2 *)
         ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x18e) = 0;
        *(undefined2 *)
         ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 400) = 0;
        puVar4 = (undefined2 *)thunk_FUN_03807424();
        *puVar4 = 9;
        puVar4[1] = 0;
        thunk_FUN_038074cc();
      }
      else {
        FUN_06003658(DAT_06003850);
      }
    }
    else {
      FUN_06003658(0);
    }
  }
  else {
    puVar4 = (undefined2 *)thunk_FUN_03807424();
    *puVar4 = 9;
    puVar4[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

