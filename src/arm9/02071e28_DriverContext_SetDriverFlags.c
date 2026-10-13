/* Decompiled C draft; module arm9; ROM address 02071e28. No matching claim. */
#include "types.h"
#include "deps/02071e28_DriverContext_SetDriverFlags.h"

void DriverContext_SetDriverFlags(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  *(undefined4 *)(param_1 + 0x7c) = 0;
  uVar1 = uRam02071f40;
  uVar5 = *(uint *)(uRam02071f40 & 0xfffffffc) >> (uRam02071f40 & 3) * 8 |
          *(uint *)(uRam02071f40 & 0xfffffffc) << (uRam02071f40 & 3) * -8 + 0x20;
  if ((uint)*(ushort *)(param_1 + 0x74) == (int)*(char *)(uVar5 + 0x62)) {
    uVar5 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    puVar4 = (uint *)(param_1 + 0x7c);
    *(uint *)(param_1 + 0x7c) = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20 | 1;
    uVar5 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 8;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 5) {
      *puVar4 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20 | 0x200;
      iVar2 = func_0203c5e4();
      if (iVar2 != 0) {
        uVar5 = param_1 + 0x7cU & 3;
        uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0xfffffdff;
        uVar5 = param_1 + 0x7cU & 3;
        uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
        *(uint *)(param_1 + 0x7c) = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20 | 0x400;
      }
    }
  }
  else {
    uVar5 = uVar5 + 8;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 5) {
      uVar5 = param_1 + 0x7cU & 3;
      uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      *(uint *)(param_1 + 0x7c) = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20 | 0x400;
    }
  }
  uVar5 = (uint)*(ushort *)(param_1 + 0x74) * 0x30 +
          (*(uint *)(uRam02071f40 & 0xfffffffc) >> (uRam02071f40 & 3) * 8 |
          *(uint *)(uRam02071f40 & 0xfffffffc) << (uRam02071f40 & 3) * -8 + 0x20) + 0x70;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == 2) {
    uVar5 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20 | 4;
    *(undefined2 *)(param_1 + 900) = 0;
  }
  uVar5 = param_1 + 0x590U & 3;
  uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
  uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 8;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar1 * 8 != 0 || uVar5 << uVar1 * -8 + 0x20 != 0) {
    uVar5 = param_1 + 0x7cU & 3;
    uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    *(uint *)(param_1 + 0x7c) = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20 | 0x10;
  }
  uVar5 = (*(uint *)(uRam02071f40 & 0xfffffffc) >> (uRam02071f40 & 3) * 8 |
          *(uint *)(uRam02071f40 & 0xfffffffc) << (uRam02071f40 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 1) &&
     (iVar2 = IsAwardOrStaffRoll_0(), iVar2 == 0)) {
    return;
  }
  uVar5 = param_1 + 0x7cU & 3;
  uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20 | 0x8000000;
  return;
}

