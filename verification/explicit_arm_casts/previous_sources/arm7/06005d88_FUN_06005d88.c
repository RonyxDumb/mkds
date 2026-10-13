/* Decompiled C draft; module arm7; ROM address 06005d88. No matching claim. */
#include "types.h"
#include "deps/06005d88_FUN_06005d88.h"

void FUN_06005d88(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  undefined2 *puVar8;
  uint uVar9;
  undefined1 local_22c [16];
  undefined1 auStack_21c [512];
  uint uVar10;
  
  iVar7 = FUN_06000680();
  uVar10 = iVar7 + 0x154cU & 3;
  uVar9 = *(uint *)(iVar7 + 0x154cU & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  if (*(short *)(*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) == 2) {
    iVar7 = FUN_06002084(auStack_21c);
    if (*(short *)(iVar7 + 4) == 0) {
      sVar1 = *(short *)(iVar7 + 6);
      *(undefined2 *)
       ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
        *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0xe2) = 2;
      if (sVar1 == 0x10) {
        iVar7 = FUN_06000294(10,auStack_21c);
        if (iVar7 == 0) {
          return;
        }
        iVar7 = FUN_060020f4(auStack_21c);
        if (*(short *)(iVar7 + 4) != 0) {
          FUN_06005d4c(DAT_06005f48);
          return;
        }
        *(undefined2 *)
         (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
         *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) = 3;
        iVar7 = FUN_06002c40(auStack_21c,1,0,1);
        if (*(short *)(iVar7 + 4) != 0) {
          FUN_06005d4c(1);
          return;
        }
        *(undefined2 *)
         ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
          *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0xc2) = 1;
      }
      uVar2 = *(undefined2 *)(param_1 + 2);
      uVar3 = *(undefined2 *)(param_1 + 4);
      uVar4 = *(undefined2 *)(param_1 + 6);
      uVar5 = *(undefined2 *)(param_1 + 8);
      thunk_FUN_037fb2fc(local_22c,0,0x10);
      local_22c[0] = (undefined1)uVar4;
      iVar7 = FUN_06002818(auStack_21c,uVar2,uVar3,uVar5,local_22c);
      if (*(short *)(iVar7 + 4) == 0) {
        uVar6 = *(ushort *)(iVar7 + 8);
        iVar7 = FUN_0600210c(auStack_21c);
        if (*(short *)(iVar7 + 4) == 0) {
          *(undefined2 *)
           (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
           *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) = 2;
          puVar8 = (undefined2 *)thunk_FUN_03807424();
          *puVar8 = 0x1e;
          puVar8[1] = 0;
          puVar8[4] = uVar6 & 0xff;
          puVar8[5] = uVar6 >> 8;
          thunk_FUN_038074cc();
        }
        else {
          FUN_06005d4c(DAT_06005f4c);
        }
      }
      else {
        FUN_06005d4c(10);
      }
    }
    else {
      FUN_06005d4c(0x308);
    }
  }
  else {
    puVar8 = (undefined2 *)thunk_FUN_03807424();
    *puVar8 = 0x1e;
    puVar8[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

