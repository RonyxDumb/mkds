/* Decompiled C draft; module arm7; ROM address 06001acc. No matching claim. */
#include "types.h"
#include "deps/06001acc_FUN_06001acc.h"

void FUN_06001acc(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  uint uVar6;
  short *psVar7;
  uint uVar8;
  uint uVar9;
  
  iVar3 = FUN_06000680();
  uVar9 = iVar3 + 0x154cU & 3;
  uVar8 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  uVar2 = (ushort)((int)(uint)*(byte *)(param_1 + 0x1f) >> 2);
  if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
    uVar2 = uVar2 + 0x19;
  }
  *DAT_06001c3c =
       uVar2 ^ (ushort)((uint)*DAT_06001c3c << 1) ^ (ushort)(((uint)*DAT_06001c3c << 1) >> 0x10);
  psVar7 = (short *)(*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                    *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20);
  sVar1 = *psVar7;
  if ((sVar1 == 8) || (sVar1 == 10)) {
    if (psVar7[0x5b] == *(short *)(param_1 + 0x44)) {
      iVar3 = FUN_06000680();
      uVar8 = iVar3 + 0x154cU & 3;
      uVar6 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
      uVar6 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
      uVar8 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if (*(short *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0xbe) != 0) {
        puVar5 = (undefined2 *)thunk_FUN_03807424();
        *puVar5 = 0x80;
        puVar5[1] = 0;
        puVar5[2] = 0x10;
        puVar5[3] = *(undefined2 *)(param_1 + 0x44);
        puVar5[4] = *(undefined2 *)
                     (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                     *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20);
        puVar5[5] = *(undefined2 *)(param_1 + 0x16);
        if ((ushort)puVar5[5] < 0x81) {
          thunk_FUN_037fb230(param_1 + 0x3c,puVar5 + 6,(ushort)puVar5[5] + 1 & 0xfffffffe);
        }
        thunk_FUN_038074cc(puVar5);
      }
    }
    else {
      puVar4 = (undefined4 *)FUN_06000000();
      if (puVar4 == (undefined4 *)0x0) {
        iVar3 = 0;
      }
      else {
        *puVar4 = 0x25;
        puVar4[1] = 1;
        puVar4[2] = DAT_06001c40;
        iVar3 = FUN_06000680();
        iVar3 = thunk_FUN_037f9854(iVar3 + 0x88,puVar4,0);
      }
      if (iVar3 == 0) {
        puVar5 = (undefined2 *)thunk_FUN_03807424();
        *puVar5 = 0x80;
        puVar5[1] = 8;
        puVar5[2] = 0x16;
        puVar5[3] = 0x25;
        thunk_FUN_038074cc();
      }
    }
  }
  return;
}

