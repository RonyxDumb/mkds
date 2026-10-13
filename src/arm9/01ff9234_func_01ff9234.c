/* Decompiled C draft; module arm9; ROM address 01ff9234. No matching claim. */
#include "types.h"
#include "deps/01ff9234_func_01ff9234.h"

void func_01ff9234(void)

{
  uint uVar1;
  uint uVar2;
  
  if (*(uint *)(uRam01ff92a8 & 0xfffffffc) >> (uRam01ff92a8 & 3) * 8 != 0 ||
      *(uint *)(uRam01ff92a8 & 0xfffffffc) << (uRam01ff92a8 & 3) * -8 + 0x20 != 0) {
    func_01ff921c();
  }
  uVar1 = *(uint *)(uRam01ff92ac & 0xfffffffc) >> (uRam01ff92ac & 3) * 8 |
          *(uint *)(uRam01ff92ac & 0xfffffffc) << (uRam01ff92ac & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    if (uVar2 != 0) {
      MIi_CpuSend32((undefined4 *)(uintptr_t)(uVar1 + 4),(undefined4 *)(uintptr_t)(uRam01ff92b0),uVar2 << 2);
      *(undefined4 *)
       (*(uint *)(uRam01ff92ac & 0xfffffffc) >> (uRam01ff92ac & 3) * 8 |
       *(uint *)(uRam01ff92ac & 0xfffffffc) << (uRam01ff92ac & 3) * -8 + 0x20) = 0;
      return;
    }
    return;
  }
  return;
}

