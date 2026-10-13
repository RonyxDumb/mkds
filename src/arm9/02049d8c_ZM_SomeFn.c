/* Decompiled C draft; module arm9; ROM address 02049d8c. No matching claim. */
#include "types.h"
#include "deps/02049d8c_ZM_SomeFn.h"

void ZM_SomeFn(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  
  uVar2 = uRam02049e30;
  uVar7 = uRam02049e2c;
  do {
    LoopFn_Some3D();
    iVar4 = func_02054f58();
    uVar6 = uVar2 & 3;
    uVar5 = *(uint *)(uVar2 & 0xfffffffc);
    if (iVar4 != 1) {
      param_3 = 1;
    }
    if (iVar4 == 1) {
      param_3 = 0;
    }
    if (*(char *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x28) == '\0') {
      uVar6 = uVar7 & 3;
      uVar5 = *(uint *)(uVar7 & 0xfffffffc);
      uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = uVar5 + 0xc;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if (uVar6 >> uVar1 * 8 == 0 && uVar6 << uVar1 * -8 + 0x20 == 0) {
        uVar6 = 0;
      }
      else {
        uVar5 = uVar5 + 0x10;
        uVar6 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      }
    }
    else {
      uVar6 = 1;
    }
    if ((param_3 == 0) && (uVar6 == 0)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    LoopFn_Brightness();
    LoopFn_DisplayConfig();
  } while (!bVar3);
  uVar7 = (*(uint *)(uRam02049e34 & 0xfffffffc) >> (uRam02049e34 & 3) * 8 |
          *(uint *)(uRam02049e34 & 0xfffffffc) << (uRam02049e34 & 3) * -8 + 0x20) + 0xfc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  pcVar8 = (code *)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
  if (pcVar8 == (code *)0x0) {
    return;
  }
  (*pcVar8)();
  return;
}

