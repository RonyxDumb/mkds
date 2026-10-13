/* Decompiled C draft; module arm9; ROM address 0210bcf4. No matching claim. */
#include "types.h"
#include "deps/0210bcf4_func_0210bcf4.h"

void func_0210bcf4(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar8;
  undefined4 *puVar9;
  undefined1 auStack_40 [40];
  uint uVar7;
  
  bVar2 = false;
  uVar7 = iRam0210bec8 + 4U & 3;
  uVar6 = *(uint *)(iRam0210bec8 + 4U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  puVar9 = (undefined4 *)auStack_40;
  if (uVar7 == 4) {
    puVar9 = (undefined4 *)&stack0xffffffe8;
  }
  bVar1 = false;
  if (uVar7 == 4) {
    return;
  }
  if (uVar7 == 0) {
    return;
  }
  if (*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 == 0 &&
      *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20 == 0) {
    bVar1 = true;
    bVar2 = bVar1;
  }
  else {
    uVar8 = *(uint *)((uint)piRam0210becc & 0xfffffffc) >> ((uint)piRam0210becc & 3) * 8 |
            *(uint *)((uint)piRam0210becc & 0xfffffffc) << ((uint)piRam0210becc & 3) * -8 + 0x20;
    uVar7 = uRam0210bed0 & 3;
    uVar6 = *(uint *)(uRam0210bed0 & 0xfffffffc);
    *piRam0210becc = uVar8 + 1;
    if ((uVar8 & 3) == (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    return;
  }
  *puVar9 = 0;
  puVar9[1] = param_3;
  puVar9[8] = puVar9[0x10];
  puVar9[5] = 0;
  puVar9[7] = 0;
  puVar9[6] = 0;
  if (param_3 == 0) {
    puVar9[4] = 0;
    puVar9[5] = 0x7f;
    puVar9[7] = 0x7f;
    puVar9[6] = 0;
  }
  else {
    uVar3 = (*(code *)(*(uint *)(uRam0210bed4 & 0xfffffffc) >> (uRam0210bed4 & 3) * 8 |
                      *(uint *)(uRam0210bed4 & 0xfffffffc) << (uRam0210bed4 & 3) * -8 + 0x20))
                      (puVar9);
    puVar9[4] = uVar3;
    uVar3 = (*(code *)(*(uint *)(uRam0210bed8 & 0xfffffffc) >> (uRam0210bed8 & 3) * 8 |
                      *(uint *)(uRam0210bed8 & 0xfffffffc) << (uRam0210bed8 & 3) * -8 + 0x20))
                      (puVar9);
    puVar9[5] = uVar3;
    puVar9[7] = uVar3;
    uVar3 = (*(code *)(*(uint *)(uRam0210bedc & 0xfffffffc) >> (uRam0210bedc & 3) * 8 |
                      *(uint *)(uRam0210bedc & 0xfffffffc) << (uRam0210bedc & 3) * -8 + 0x20))
                      (puVar9);
    puVar9[6] = uVar3;
  }
  if (0 < (int)puVar9[5]) {
    iVar5 = puVar9[7];
    iVar4 = func_0212d580(param_1,param_2);
    iVar5 = iVar5 + (*(byte *)(iVar4 + 4) - 0x40);
    if (iVar5 < 1) {
      iVar5 = 0;
    }
    else if (0x7e < iVar5) {
      iVar5 = 0x7f;
    }
    if (bVar2) {
      (*(code *)(*(uint *)(uRam0210bee0 & 0xfffffffc) >> (uRam0210bee0 & 3) * 8 |
                *(uint *)(uRam0210bee0 & 0xfffffffc) << (uRam0210bee0 & 3) * -8 + 0x20))
                (param_4,param_1,param_2,iVar5);
    }
    func_0212c678(param_4,puVar9[5]);
    func_0212c5f4(param_4,iVar5);
    func_0212c4f4(param_4,*puRam0210bee4,puVar9[6]);
    return;
  }
  if (*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 == 0 &&
      *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20 == 0) {
    return;
  }
  func_0212c6f0(param_4,0);
  return;
}

