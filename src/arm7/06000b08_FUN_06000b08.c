/* Decompiled C draft; module arm7; ROM address 06000b08. No matching claim. */
#include "types.h"
#include "deps/06000b08_FUN_06000b08.h"

void FUN_06000b08(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  
  iVar2 = FUN_06000680();
  uVar7 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  uVar1 = *(ushort *)(param_1 + 0x16);
  uVar7 = (uint)uVar1;
  if ((uVar7 != 0) && (uVar7 < 0x10)) {
    if (*(short *)(uVar3 + 0xf2) == 0) {
      puVar4 = (undefined4 *)FUN_06000000();
      if (puVar4 == (undefined4 *)0x0) {
        iVar2 = 0;
      }
      else {
        *puVar4 = 0x22;
        thunk_FUN_037fb390(param_1 + 0x10,puVar4 + 1,6);
        iVar2 = FUN_06000680();
        iVar2 = thunk_FUN_037f9854(iVar2 + 0x88,puVar4,0);
      }
      if (iVar2 == 0) {
        puVar5 = (undefined2 *)thunk_FUN_03807424();
        *puVar5 = 0x80;
        puVar5[1] = 8;
        puVar5[2] = 0x16;
        puVar5[3] = 0x22;
        thunk_FUN_038074cc();
      }
    }
    else {
      thunk_FUN_037fb390(param_1 + 0x10,(uVar7 - 1) * 6 + uVar3 + 0x124);
      uVar6 = thunk_FUN_037faf70();
      *(ushort *)(uVar3 + 0x17e) = *(ushort *)(uVar3 + 0x17e) | (ushort)(1 << (uVar7 & 0xff));
      *(ushort *)(uVar3 + 0x86) = *(ushort *)(uVar3 + 0x86) & ~(ushort)(1 << (uVar7 & 0xff));
      uVar8 = thunk_FUN_037fa278();
      iVar2 = uVar3 + uVar7 * 8;
      *(uint *)(iVar2 + 0x734) = (uint)uVar8 | 1;
      *(int *)(iVar2 + 0x738) = (int)((ulonglong)uVar8 >> 0x20);
      thunk_FUN_037faf84(uVar6);
      thunk_FUN_037fb218(1,uVar3 + 500 + uVar7 * 0x10,0x10);
      puVar5 = (undefined2 *)thunk_FUN_03807424();
      *puVar5 = 8;
      puVar5[1] = 0;
      puVar5[4] = 7;
      thunk_FUN_037fb390(param_1 + 0x10,puVar5 + 5,6);
      puVar5[8] = uVar1;
      thunk_FUN_037fb230(param_1 + 0x22,puVar5 + 10,0x18);
      thunk_FUN_038074cc(puVar5);
    }
  }
  return;
}

