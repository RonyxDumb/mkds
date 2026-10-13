/* Decompiled C draft; module arm9; ROM address 0205d6d0. No matching claim. */
#include "types.h"
#include "deps/0205d6d0_func_0205d6d0.h"

void func_0205d6d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = uRam0205d768;
  uVar2 = uRam0205d764;
  iVar4 = *(ushort *)
           ((*(uint *)(uRam0205d764 & 0xfffffffc) >> (uRam0205d764 & 3) * 8 |
            *(uint *)(uRam0205d764 & 0xfffffffc) << (uRam0205d764 & 3) * -8 + 0x20) + 0x60) - 1;
  iVar5 = iVar4 >> 0x1f;
  iVar5 = (*(uint *)(uRam0205d768 & 0xfffffffc) >> (uRam0205d768 & 3) * 8 |
          *(uint *)(uRam0205d768 & 0xfffffffc) << (uRam0205d768 & 3) * -8 + 0x20) + 0x144 +
          (((uint)(iVar4 * 0x40000000 + iVar5) >> 0x1e | iVar5 << 2) - iVar5 & 0xff) * 8 +
          param_1 * 4;
  *(byte *)(iVar5 + 3) = *(byte *)(iVar5 + 3) & 0xfe | 1;
  uVar1 = uVar2 & 3;
  uVar3 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  iVar4 = *(ushort *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x60) - 1;
  iVar5 = iVar4 >> 0x1f;
  iVar5 = (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0x144 +
          (((uint)(iVar4 * 0x40000000 + iVar5) >> 0x1e | iVar5 << 2) - iVar5 & 0xff) * 8 +
          (uint)(param_1 == 0) * 4;
  *(byte *)(iVar5 + 3) = *(byte *)(iVar5 + 3) & 0xfe;
  return;
}

