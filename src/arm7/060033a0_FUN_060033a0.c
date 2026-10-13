/* Decompiled C draft; module arm7; ROM address 060033a0. No matching claim. */
#include "types.h"
#include "deps/060033a0_FUN_060033a0.h"

void FUN_060033a0(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  short sVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  ushort local_2b4;
  ushort local_2b2;
  undefined2 local_2b0;
  undefined2 local_2ae;
  undefined1 auStack_294 [512];
  undefined1 auStack_94 [132];
  uint uVar9;
  
  iVar2 = FUN_06000680();
  uVar9 = iVar2 + 0x154cU & 3;
  uVar8 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  psVar6 = (short *)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20);
  if (*psVar6 == 2) {
    uVar8 = param_1 + 4U & 3;
    uVar7 = *(uint *)(param_1 + 4U & 0xfffffffc);
    if (((uint)(ushort)psVar6[0xf9] & (1 << ((ushort)psVar6[0x8b] & 0xff)) >> 1) == 0) {
      puVar3 = (undefined2 *)thunk_FUN_03807424();
      *puVar3 = 8;
      puVar3[1] = 6;
      puVar3[4] = 0;
      thunk_FUN_038074cc();
    }
    else {
      psVar6[0x71] = 1;
      *(undefined2 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x184) = 0;
      thunk_FUN_037faf70();
      *(undefined2 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x17e) = 0;
      *(undefined2 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x86) = 0;
      thunk_FUN_037faf84();
      *(undefined2 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x1ea) = 1;
      iVar2 = FUN_06000294(8,(int)(uintptr_t)(auStack_294));
      if (iVar2 != 0) {
        iVar2 = FUN_060020f4((undefined4)(uintptr_t)(auStack_294));
        if (*(short *)(iVar2 + 4) == 0) {
          bVar1 = uVar7 >> uVar8 * 8 != 0 || uVar7 << uVar8 * -8 + 0x20 != 0;
          iVar2 = FUN_06002c40((undefined2 *)(void *)(auStack_294),bVar1,0,1);
          if (*(short *)(iVar2 + 4) == 0) {
            *(ushort *)
             ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
              *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0xc2) = (ushort)bVar1;
            uVar7 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
            thunk_FUN_037fb218(0,auStack_94,0x80);
            FUN_0600044c((undefined2 *)(void *)(auStack_94),uVar7 + 0xe4);
            thunk_FUN_037fb218(0,&local_2b4,0x20);
            uVar8 = uVar7 + 0xec & 3;
            uVar4 = *(uint *)(uVar7 + 0xec & 0xfffffffc);
            local_2b4 = (ushort)(uVar4 >> uVar8 * 8) | (ushort)(uVar4 << uVar8 * -8 + 0x20);
            uVar8 = uVar7 + 0xec & 3;
            uVar4 = *(uint *)(uVar7 + 0xec & 0xfffffffc);
            local_2b2 = (ushort)((uVar4 >> uVar8 * 8) >> 0x10) |
                        (ushort)((uVar4 << uVar8 * -8 + 0x20) >> 0x10);
            local_2b0 = *(undefined2 *)(uVar7 + 0xf0);
            local_2ae = 0;
            iVar2 = FUN_060028a4((undefined2 *)(void *)(auStack_294),0x20,(undefined4)(uintptr_t)(&local_2b4),*(undefined2 *)(uVar7 + 0xfc),2,
                                 *(undefined2 *)(uVar7 + 0x116),3,3,*(short *)(uVar7 + 0xe8) + 0x10,
                                 (undefined4)(uintptr_t)(auStack_94));
            if (*(short *)(iVar2 + 4) == 0) {
              if (*(short *)(uVar7 + 0xf8) == 0) {
                sVar5 = 0;
              }
              else {
                sVar5 = 0x2a;
              }
              *(short *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                         *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0x18e) =
                   *(short *)(uVar7 + 0x118) + 4 + sVar5;
              if (*(short *)(uVar7 + 0xf8) == 0) {
                sVar5 = 0;
              }
              else {
                sVar5 = 6;
              }
              *(short *)((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                         *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 400) =
                   *(short *)(uVar7 + 0x11a) + 2 + sVar5;
              puVar3 = (undefined2 *)thunk_FUN_03807424();
              *(undefined2 *)
               (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
               *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) = 7;
              *puVar3 = 8;
              puVar3[1] = 0;
              puVar3[4] = 0;
              thunk_FUN_038074cc();
              *(undefined2 *)
               ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0xbe) = 1;
            }
            else {
              FUN_0600335c(9);
            }
          }
          else {
            FUN_0600335c(1);
          }
        }
        else {
          FUN_0600335c(DAT_06003654);
        }
      }
    }
  }
  else {
    puVar3 = (undefined2 *)thunk_FUN_03807424();
    *puVar3 = 8;
    puVar3[1] = 3;
    puVar3[4] = 0;
    thunk_FUN_038074cc();
  }
  return;
}

