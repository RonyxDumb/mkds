/* Decompiled C draft; module arm9; ROM address 0204aab4. No matching claim. */
#include "types.h"
#include "deps/0204aab4_func_0204aab4.h"

bool func_0204aab4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar6;
  uint uVar5;
  
  bVar6 = true;
  uVar2 = *(uint *)(uRam0204ab60 & 0xfffffffc) >> (uRam0204ab60 & 3) * 8 |
          *(uint *)(uRam0204ab60 & 0xfffffffc) << (uRam0204ab60 & 3) * -8 + 0x20;
  uVar3 = uVar2 + 0x48 & 3;
  uVar4 = *(uint *)(uVar2 + 0x48 & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 + 0x4c & 3;
  uVar4 = *(uint *)(uVar2 + 0x4c & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (param_1 == 0) {
    uVar5 = 1;
  }
  else if (param_1 == 1) {
    uVar5 = 0;
  }
  if (param_2 == 0) {
    uVar3 = 1;
  }
  else if (param_2 == 1) {
    uVar3 = 0;
  }
  uVar4 = uVar2 + 0x48 & 3;
  uVar2 = *(uint *)(uVar2 + 0x48 & 0xfffffffc);
  if (uVar5 != (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    iVar1 = func_0214fba8(0,uVar5);
    bVar6 = iVar1 == 0;
    if (bVar6) {
      *(uint *)((*(uint *)(uRam0204ab60 & 0xfffffffc) >> (uRam0204ab60 & 3) * 8 |
                *(uint *)(uRam0204ab60 & 0xfffffffc) << (uRam0204ab60 & 3) * -8 + 0x20) + 0x48) =
           uVar5;
    }
  }
  uVar2 = (*(uint *)(uRam0204ab60 & 0xfffffffc) >> (uRam0204ab60 & 3) * 8 |
          *(uint *)(uRam0204ab60 & 0xfffffffc) << (uRam0204ab60 & 3) * -8 + 0x20) + 0x4c;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar3 != (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    iVar1 = func_0214fba8(1,uVar3);
    if (iVar1 == 0) {
      *(uint *)((*(uint *)(uRam0204ab60 & 0xfffffffc) >> (uRam0204ab60 & 3) * 8 |
                *(uint *)(uRam0204ab60 & 0xfffffffc) << (uRam0204ab60 & 3) * -8 + 0x20) + 0x4c) =
           uVar3;
    }
    else {
      bVar6 = false;
    }
  }
  return bVar6;
}

