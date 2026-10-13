/* Decompiled C draft; module arm9; ROM address 02133f84. No matching claim. */
#include "types.h"
#include "deps/02133f84_CheckZetaInvokeBeta.h"

void CheckZetaInvokeBeta(undefined4 param_1)

{
  code *pcVar1;
  
  if (*(uint *)(uRam02133fd0 & 0xfffffffc) >> (uRam02133fd0 & 3) * 8 == 0 &&
      *(uint *)(uRam02133fd0 & 0xfffffffc) << (uRam02133fd0 & 3) * -8 + 0x20 == 0) {
    func_021424e8();
    pcVar1 = (code *)(*(uint *)((uint)puRam02133fd4 & 0xfffffffc) >> ((uint)puRam02133fd4 & 3) * 8 |
                     *(uint *)((uint)puRam02133fd4 & 0xfffffffc) <<
                     ((uint)puRam02133fd4 & 3) * -8 + 0x20);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)();
      *puRam02133fd4 = 0;
    }
  }
  func_02133e50(param_1);
  return;
}

