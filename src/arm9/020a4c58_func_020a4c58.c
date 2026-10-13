/* Decompiled C draft; module arm9; ROM address 020a4c58. No matching claim. */
#include "types.h"
#include "deps/020a4c58_func_020a4c58.h"

void func_020a4c58(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (*(uint *)(uRam020a4d90 & 0xfffffffc) >> (uRam020a4d90 & 3) * 8 |
          *(uint *)(uRam020a4d90 & 0xfffffffc) << (uRam020a4d90 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) != 2) {
    return;
  }
  func_020a4d94(param_1,param_1);
  iVar2 = func_020a1154(param_1);
  if (iVar2 != 0) {
    do {
      iVar2 = func_020a2378();
      iVar2 = iVar2 + param_1 * 0x38;
      iVar3 = func_020a2204(param_1);
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        iVar3 = func_020a1154(param_1);
        uVar4 = iVar2 + iVar3 * 4 + 0x10;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      }
      iVar3 = func_020a1154(param_1);
      if (iVar3 == 0) {
        uVar5 = 0;
      }
      else {
        iVar3 = func_020a1154(param_1);
        uVar5 = iVar2 + (iVar3 + -1) * 4 + 0x10;
        uVar1 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      }
      iVar3 = func_020a1154(param_1);
      if ((iVar3 != 0) && (uVar5 != 0)) {
        iVar3 = func_020a2204(param_1);
        if ((iVar3 == 0) || (uVar4 == 0)) {
          MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
        }
        else {
          iVar3 = func_020a1154(param_1);
          *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar5;
          MaybeUpdateDriverBalloonShineCount(param_1,0xffffffff);
          iVar3 = func_020a1154(param_1);
          *(uint *)(iVar2 + iVar3 * 4 + 0x10) = uVar4;
        }
      }
      if (uVar5 != 0) {
        func_020a2f0c(uVar5,param_1);
      }
      iVar2 = func_020a1154(param_1);
    } while (iVar2 != 0);
    return;
  }
  return;
}

