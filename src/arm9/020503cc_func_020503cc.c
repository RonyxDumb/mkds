/* Decompiled C draft; module arm9; ROM address 020503cc. No matching claim. */
#include "types.h"
#include "deps/020503cc_func_020503cc.h"

undefined4 func_020503cc(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_24;
  undefined1 auStack_22 [8];
  undefined1 local_1a;
  
  local_24 = 9;
  Mem_CpuCopy8((ushort *)(uintptr_t)(param_1 * 0x22c +
               (*(uint *)(uRam0205049c & 0xfffffffc) >> (uRam0205049c & 3) * 8 |
               *(uint *)(uRam0205049c & 0xfffffffc) << (uRam0205049c & 3) * -8 + 0x20) + 0x680),
               (uint *)(void *)(auStack_22),4);
  uVar3 = uRam0205049c;
  local_1a = (undefined1)param_1;
  uVar1 = *(uint *)(uRam0205049c & 0xfffffffc) >> (uRam0205049c & 3) * 8 |
          *(uint *)(uRam0205049c & 0xfffffffc) << (uRam0205049c & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar1 + 0x454) & 1) == 0) {
    return 0;
  }
  *(undefined2 *)(iRam020504a0 + 4) = 0x18;
  *(ushort *)(uVar1 + 0x454) = *(ushort *)(uVar1 + 0x454) & 0xfffe;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x40;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = func_02050650(&local_24,0x12,param_2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (iVar2 == 0) {
    uVar3 = *(uint *)(uRam0205049c & 0xfffffffc) >> (uRam0205049c & 3) * 8 |
            *(uint *)(uRam0205049c & 0xfffffffc) << (uRam0205049c & 3) * -8 + 0x20;
    *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) | 1;
    return 0;
  }
  return 1;
}

