/* Decompiled C draft; module arm9; ROM address 02053020. No matching claim. */
#include "types.h"
#include "deps/02053020_func_02053020.h"

void func_02053020(int param_1)

{
  int iVar1;
  short *psVar2;
  
  if (*(short *)(param_1 + 2) == 0) {
    iVar1 = (*(uint *)(uRam02053090 & 0xfffffffc) >> (uRam02053090 & 3) * 8 |
            *(uint *)(uRam02053090 & 0xfffffffc) << (uRam02053090 & 3) * -8 + 0x20) + 0x8c;
    psVar2 = (short *)(iVar1 + (uint)*(ushort *)(param_1 + 8) * 2);
    if (*(short *)(iVar1 + (uint)*(ushort *)(param_1 + 8) * 2) < 0) {
      *psVar2 = 0;
    }
    *psVar2 = *psVar2 + *(short *)(param_1 + 10);
    func_02053094(*(undefined2 *)(param_1 + 8));
    return;
  }
  func_020533a0();
  return;
}

