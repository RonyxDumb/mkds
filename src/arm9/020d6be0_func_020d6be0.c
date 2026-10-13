/* Decompiled C draft; module arm9; ROM address 020d6be0. No matching claim. */
#include "types.h"
#include "deps/020d6be0_func_020d6be0.h"

uint func_020d6be0(int param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_10;
  uint local_c;
  
  uVar3 = (uint)*param_2;
  uVar1 = param_2[1];
  iVar2 = 0;
  if (99 < uVar3) {
    do {
      uVar3 = uVar3 - 100;
      iVar2 = iVar2 + 1;
    } while (99 < (int)uVar3);
  }
  uVar5 = (uint)(param_2 + 0x4c) & 3;
  uVar4 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar5 * 8 != 0 || uVar4 << uVar5 * -8 + 0x20 != 0) {
    uVar5 = param_1 + 0x29cU & 3;
    uVar4 = *(uint *)(param_1 + 0x29cU & 0xfffffffc);
    uVar5 = iRam020d6d28 + iVar2 * 0x10 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    local_10 = (uint)*(byte *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + uVar3);
    if ((((uVar1 & 0x800) != 0) && (local_10 != 2)) && (local_10 != 4)) {
      local_10 = 0;
    }
    uVar5 = param_1 + 0x29cU & 3;
    uVar4 = *(uint *)(param_1 + 0x29cU & 0xfffffffc);
    uVar5 = iRam020d6d2c + iVar2 * 0x10 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    local_c = (uint)*(byte *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + uVar3);
    if (local_c == 1) {
      if ((uVar1 & 0x800) == 0) {
        local_c = 0;
      }
      else {
        local_c = 2;
      }
    }
    if ((param_2[1] & 0x80) == 0) {
      uVar3 = (uint)(param_2 + 0x4c) & 3;
      uVar5 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
      uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
      uVar3 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      local_c = (*(code *)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20))
                          (param_2,param_1,&local_10,&local_c);
    }
    uVar3 = (*(uint *)(uRam020d6d30 & 0xfffffffc) >> (uRam020d6d30 & 3) * 8 |
            *(uint *)(uRam020d6d30 & 0xfffffffc) << (uRam020d6d30 & 3) * -8 + 0x20) + 8;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) == 4) && (local_10 == 1)) {
      func_0x0218175c(*param_2);
    }
    return local_c;
  }
  uVar5 = param_1 + 0x29cU & 3;
  uVar4 = *(uint *)(param_1 + 0x29cU & 0xfffffffc);
  uVar5 = iRam020d6d2c + iVar2 * 0x10 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar3 = (uint)*(byte *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + uVar3);
  if (uVar3 != 1) {
    return uVar3;
  }
  if ((uVar1 & 0x800) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}

