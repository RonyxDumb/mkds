/* Decompiled C draft; module arm7; ROM address 06003e84. No matching claim. */
#include "types.h"
#include "deps/06003e84_FUN_06003e84.h"

void FUN_06003e84(int param_1)

{
  short sVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  ushort local_252 [3];
  undefined1 auStack_24c [32];
  undefined1 local_22c;
  undefined1 auStack_22b [15];
  undefined1 auStack_21c [516];
  uint uVar10;
  
  iVar4 = FUN_06000680();
  uVar10 = iVar4 + 0x154cU & 3;
  uVar9 = *(uint *)(iVar4 + 0x154cU & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  psVar8 = (short *)(*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                    *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20);
  sVar1 = *psVar8;
  if (((sVar1 == 2) || (sVar1 == 3)) || (sVar1 == 5)) {
    uVar9 = param_1 + 4U & 3;
    uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
    *(uint *)(psVar8 + 0xc0) = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
    uVar2 = *(ushort *)(param_1 + 2);
    *(ushort *)
     ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
      *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x18c) = uVar2;
    uVar3 = *(undefined2 *)(param_1 + 8);
    thunk_FUN_037fb390(param_1 + 10,local_252,6);
    if ((local_252[0] != DAT_0600424c) && ((local_252[0] & 1) != 0)) {
      local_252[0] = local_252[0] & 0xfffe;
    }
    if (uVar2 == 0) {
      puVar5 = (undefined2 *)thunk_FUN_03807424();
      *puVar5 = 10;
      puVar5[1] = 6;
      puVar5[4] = 4;
      thunk_FUN_038074cc();
    }
    else {
      uVar9 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
              *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
      if ((1 << (uVar2 & 0xff) & (uint)*(ushort *)(uVar9 + 0x1f0)) == 0) {
        puVar5 = (undefined2 *)thunk_FUN_03807424();
        *puVar5 = 10;
        puVar5[1] = 6;
        puVar5[4] = 4;
        thunk_FUN_038074cc();
      }
      else {
        *(undefined2 *)(uVar9 + 0xe2) = 2;
        iVar4 = FUN_06002084(auStack_21c);
        if (*(short *)(iVar4 + 4) == 0) {
          if (*(short *)(iVar4 + 6) == 0x10) {
            iVar4 = FUN_06000294(10,auStack_21c);
            if (iVar4 == 0) {
              return;
            }
            iVar4 = FUN_060020f4(auStack_21c);
            if (*(short *)(iVar4 + 4) != 0) {
              FUN_06003854(DAT_06004250,*(short *)(iVar4 + 4),0);
              return;
            }
            *(undefined2 *)
             (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
             *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) = 3;
            iVar4 = FUN_06002c40(auStack_21c,1,0,1);
            if (*(short *)(iVar4 + 4) != 0) {
              FUN_06003854(1,*(short *)(iVar4 + 4),0);
              return;
            }
            *(undefined2 *)
             ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
              *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0xc2) = 1;
          }
          *(undefined2 *)
           (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
           *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) = 5;
          thunk_FUN_037fb218(DAT_0600424c & 0xffff,auStack_24c,0x20);
          local_22c = (undefined1)uVar2;
          thunk_FUN_037fb2fc(auStack_22b,0,0xf);
          iVar4 = FUN_06002b84(auStack_21c,DAT_06004254,local_252,0,auStack_24c,1,&local_22c,uVar3);
          if (*(short *)(iVar4 + 4) == 0) {
            puVar5 = (undefined2 *)thunk_FUN_03807424();
            if (*(short *)(iVar4 + 8) == 0) {
              *puVar5 = 10;
              puVar5[1] = 0;
              puVar5[4] = 4;
              puVar5[8] = uVar2;
              puVar5[9] = 0;
            }
            else {
              uVar9 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                      *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x180;
              uVar6 = uVar9 & 3;
              uVar9 = *(uint *)(uVar9 & 0xfffffffc);
              thunk_FUN_037fb218(0,(uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + 0x40,0x80);
              uVar10 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                       *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x180;
              uVar9 = uVar10 & 3;
              uVar10 = *(uint *)(uVar10 & 0xfffffffc);
              thunk_FUN_037fb390(iVar4 + 10,uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20,
                                 (uint)*(ushort *)(iVar4 + 10) << 1);
              *puVar5 = 10;
              puVar5[1] = 0;
              puVar5[4] = 5;
              puVar5[8] = *(undefined2 *)(iVar4 + 0x40);
              iVar7 = (int)(*(ushort *)(iVar4 + 0xc) & 0xff) >> 2;
              if ((*(ushort *)(iVar4 + 0xc) & 2) == 0) {
                iVar7 = iVar7 + 0x19;
              }
              uVar3 = FUN_060001b4(iVar7);
              puVar5[9] = uVar3;
              *DAT_06004258 =
                   (ushort)iVar7 ^ (ushort)((uint)*DAT_06004258 << 1) ^
                   (ushort)(((uint)*DAT_06004258 << 1) >> 0x10);
              puVar5[10] = *(undefined2 *)(iVar4 + 0x14);
              thunk_FUN_037fb390(iVar4 + 0xe,puVar5 + 5,6);
              thunk_FUN_037fb230(iVar4 + 0x16,puVar5 + 0xb,0x20);
              puVar5[0x1b] = *(undefined2 *)(iVar4 + 0x46);
              if ((ushort)puVar5[0x1b] < 0x81) {
                thunk_FUN_037fb218(0,puVar5 + 0x1c,0x80);
                thunk_FUN_037fb230(iVar4 + 0x4a,puVar5 + 0x1c,(ushort)puVar5[0x1b] + 1 & 0xfffffffe)
                ;
              }
              else {
                *puVar5 = 10;
                puVar5[1] = 0;
                puVar5[4] = 4;
                puVar5[8] = uVar2;
                puVar5[9] = 0;
              }
            }
            thunk_FUN_038074cc(puVar5);
          }
          else {
            FUN_06003854(2,*(short *)(iVar4 + 4),0);
          }
        }
        else {
          FUN_06003854(0x308,*(short *)(iVar4 + 4),0);
        }
      }
    }
  }
  else {
    puVar5 = (undefined2 *)thunk_FUN_03807424();
    *puVar5 = 10;
    puVar5[1] = 3;
    puVar5[4] = 4;
    thunk_FUN_038074cc();
  }
  return;
}

