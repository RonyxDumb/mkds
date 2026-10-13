/* Decompiled C draft; module arm9; ROM address 02084334. No matching claim. */
#include "types.h"
#include "deps/02084334_func_02084334.h"

void func_02084334(int param_1)

{
  uint uVar1;
  undefined4 *puVar3;
  uint uVar2;
  
  puVar3 = (undefined4 *)
           ((uint)*(ushort *)(param_1 + 0x74) * 0x58 +
           (*(uint *)(uRam0208437c & 0xfffffffc) >> (uRam0208437c & 3) * 8 |
           *(uint *)(uRam0208437c & 0xfffffffc) << (uRam0208437c & 3) * -8 + 0x20));
  uVar2 = (uint)(puVar3 + 3) & 3;
  uVar1 = *(uint *)((uint)(puVar3 + 3) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(undefined1 *)(uVar2 + 0x99) = 1;
    puVar3[3] = 0;
    *puVar3 = 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x02084378. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02084380)(2);
  return;
}

