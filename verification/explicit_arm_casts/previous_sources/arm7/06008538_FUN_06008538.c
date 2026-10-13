/* Decompiled C draft; module arm7; ROM address 06008538. No matching claim. */
#include "types.h"
#include "deps/06008538_FUN_06008538.h"

void FUN_06008538(int param_1)

{
  short sVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined2 local_244 [3];
  undefined2 local_23e;
  undefined1 local_236;
  undefined1 auStack_22c [6];
  undefined1 auStack_226 [14];
  undefined1 *local_218;
  undefined1 auStack_214 [512];
  
  iVar2 = FUN_06000680();
  uVar4 = iVar2 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  puVar3 = (undefined2 *)thunk_FUN_03807424();
  *puVar3 = 0x28;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (*(short *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 0xb) {
    uVar4 = param_1 + 4U & 3;
    uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
    iVar2 = FUN_06002c40(auStack_214,(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 1,0,1);
    if (*(short *)(iVar2 + 4) == 0) {
      iVar2 = FUN_06000680();
      uVar4 = iVar2 + 0x154cU & 3;
      uVar5 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
      uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      thunk_FUN_037fb390(uVar4 + DAT_060086cc,uVar4 + 0x9e,6);
      *(undefined1 **)(uVar4 + 0xa4) = auStack_214;
      *(undefined2 *)(uVar4 + 0xa8) = 0;
      *(undefined4 *)(uVar4 + 0x18) = 1;
      thunk_FUN_037fb218(0,local_244,0x30);
      local_244[0] = 0;
      local_23e = 0;
      sVar1 = *(short *)(uVar4 + 0x1e8);
      bVar6 = sVar1 == 2;
      if (bVar6) {
        sVar1 = 0x14;
      }
      local_236 = (undefined1)sVar1;
      if (!bVar6) {
        local_236 = 10;
      }
      thunk_FUN_037fb390(uVar4 + DAT_060086cc,auStack_22c,6);
      thunk_FUN_037fb390(uVar4 + 0xdc,auStack_226,6);
      local_218 = auStack_214;
      iVar2 = FUN_06002760(local_218,local_244);
      if (*(short *)(iVar2 + 4) == 0) {
        puVar3[1] = 0;
        thunk_FUN_038074cc(puVar3);
      }
      else {
        puVar3[1] = 1;
        puVar3[2] = 0x100;
        puVar3[3] = *(undefined2 *)(iVar2 + 4);
        thunk_FUN_038074cc(puVar3);
      }
    }
    else {
      puVar3[1] = 1;
      puVar3[2] = 1;
      puVar3[3] = *(undefined2 *)(iVar2 + 4);
      thunk_FUN_038074cc(puVar3);
    }
  }
  else {
    puVar3[1] = 3;
    thunk_FUN_038074cc();
  }
  return;
}

