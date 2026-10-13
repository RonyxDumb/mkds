/* Decompiled C draft; module arm9; ROM address 020839d8. No matching claim. */
#include "types.h"
#include "deps/020839d8_func_020839d8.h"

void func_020839d8(int param_1)

{
  uint uVar1;
  undefined4 *puVar3;
  uint uVar2;
  
  puVar3 = (undefined4 *)
           ((uint)*(ushort *)(param_1 + 0x74) * 0x58 +
           (*(uint *)(uRam02083a1c & 0xfffffffc) >> (uRam02083a1c & 3) * 8 |
           *(uint *)(uRam02083a1c & 0xfffffffc) << (uRam02083a1c & 3) * -8 + 0x20));
  uVar2 = (uint)(puVar3 + 3) & 3;
  uVar1 = *(uint *)((uint)(puVar3 + 3) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(undefined1 *)(uVar2 + 0x99) = 1;
    puVar3[3] = 0;
    *puVar3 = 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x02083a18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02083a20)(param_1,0);
  return;
}

