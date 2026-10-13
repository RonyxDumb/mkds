/* Decompiled C draft; module arm9; ROM address 020842ac. No matching claim. */
#include "types.h"
#include "deps/020842ac_func_020842ac.h"

void func_020842ac(int param_1)

{
  uint uVar1;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar2;
  
  puVar4 = (undefined4 *)
           ((uint)*(ushort *)(param_1 + 0x74) * 0x58 +
           (*(uint *)(uRam02084328 & 0xfffffffc) >> (uRam02084328 & 3) * 8 |
           *(uint *)(uRam02084328 & 0xfffffffc) << (uRam02084328 & 3) * -8 + 0x20));
  uVar2 = (uint)(puVar4 + 3) & 3;
  uVar1 = *(uint *)((uint)(puVar4 + 3) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(undefined1 *)(uVar2 + 0x99) = 1;
    puVar4[3] = 0;
    *puVar4 = 0xffffffff;
  }
  uVar2 = iRam02084330 + 0x1cU & 3;
  uVar3 = *(uint *)(iRam02084330 + 0x1cU & 0xfffffffc);
  uVar1 = iRam02084330 + 0x18U & 3;
  uVar5 = *(uint *)(iRam02084330 + 0x18U & 0xfffffffc);
  (*(code *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))
            ((uint)*(ushort *)
                    ((*(uint *)(uRam0208432c & 0xfffffffc) >> (uRam0208432c & 3) * 8 |
                     *(uint *)(uRam0208432c & 0xfffffffc) << (uRam0208432c & 3) * -8 + 0x20) +
                    (uint)*(ushort *)(param_1 + 0x74) * 2) * 0xc + iRam02084330,
             uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  return;
}

