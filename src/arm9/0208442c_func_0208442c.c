/* Decompiled C draft; module arm9; ROM address 0208442c. No matching claim. */
#include "types.h"
#include "deps/0208442c_func_0208442c.h"

void func_0208442c(int param_1)

{
  uint uVar1;
  undefined4 *puVar3;
  uint uVar2;
  
  puVar3 = (undefined4 *)
           ((uint)*(ushort *)(param_1 + 0x74) * 0x58 +
           (*(uint *)(uRam02084470 & 0xfffffffc) >> (uRam02084470 & 3) * 8 |
           *(uint *)(uRam02084470 & 0xfffffffc) << (uRam02084470 & 3) * -8 + 0x20));
  uVar2 = (uint)(puVar3 + 3) & 3;
  uVar1 = *(uint *)((uint)(puVar3 + 3) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(undefined1 *)(uVar2 + 0x99) = 1;
    puVar3[3] = 0;
    *puVar3 = 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x0208446c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02084474)(param_1,0);
  return;
}

