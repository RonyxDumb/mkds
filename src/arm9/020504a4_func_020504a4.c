/* Decompiled C draft; module arm9; ROM address 020504a4. No matching claim. */
#include "types.h"
#include "deps/020504a4_func_020504a4.h"

undefined4 func_020504a4(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 local_24;
  undefined1 auStack_22 [20];
  undefined1 local_e;
  byte bStack_d;
  
  local_24 = 6;
  Mem_CpuCopy8((ushort *)(uintptr_t)(param_1 * 0x22c +
               (*(uint *)(uRam0205059c & 0xfffffffc) >> (uRam0205059c & 3) * 8 |
               *(uint *)(uRam0205059c & 0xfffffffc) << (uRam0205059c & 3) * -8 + 0x20) +
               iRam020505a0),(uint *)(void *)(auStack_22),0x14);
  local_e = (undefined1)param_1;
  uVar3 = *(uint *)(uRam0205059c & 0xfffffffc) >> (uRam0205059c & 3) * 8 |
          *(uint *)(uRam0205059c & 0xfffffffc) << (uRam0205059c & 3) * -8 + 0x20;
  if (uVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  if (uVar1 == 1) {
    bStack_d = *(byte *)(uVar3 + 0x87) | 1;
  }
  else {
    bStack_d = 0;
  }
  if ((*(ushort *)(uVar3 + 0x454) & 1) == 0) {
    return 0;
  }
  *(undefined2 *)(iRam020505a4 + 4) = 0x18;
  uVar1 = uRam0205059c;
  *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) & 0xfffe;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0x40;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = func_02050650(&local_24,0x18,param_2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (iVar2 != 0) {
    return 1;
  }
  uVar3 = *(uint *)(uRam0205059c & 0xfffffffc) >> (uRam0205059c & 3) * 8 |
          *(uint *)(uRam0205059c & 0xfffffffc) << (uRam0205059c & 3) * -8 + 0x20;
  *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) | 1;
  return 0;
}

