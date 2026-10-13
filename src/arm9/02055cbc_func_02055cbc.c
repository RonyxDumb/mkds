/* Decompiled C draft; module arm9; ROM address 02055cbc. No matching claim. */
#include "types.h"
#include "deps/02055cbc_func_02055cbc.h"

void func_02055cbc(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(uRam02055d58 & 0xfffffffc) >> (uRam02055d58 & 3) * 8 |
          *(uint *)(uRam02055d58 & 0xfffffffc) << (uRam02055d58 & 3) * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 1) {
    if (param_1 == 0) {
      func_02055e54();
    }
  }
  else if (uVar3 == 2) {
    func_02055d5c();
  }
  if ((*(ushort *)
        ((*(uint *)(uRam02055d58 & 0xfffffffc) >> (uRam02055d58 & 3) * 8 |
         *(uint *)(uRam02055d58 & 0xfffffffc) << (uRam02055d58 & 3) * -8 + 0x20) + 8) & 4) == 0) {
    return;
  }
  iVar1 = Bright_IsBothScreensFadedIn();
  uVar3 = uRam02055d58;
  if (iVar1 == 0) {
    return;
  }
  uVar2 = *(uint *)(uRam02055d58 & 0xfffffffc) >> (uRam02055d58 & 3) * 8 |
          *(uint *)(uRam02055d58 & 0xfffffffc) << (uRam02055d58 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 8) = *(ushort *)(uVar2 + 8) & 0xfffb;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  *(ushort *)(uVar3 + 8) = *(ushort *)(uVar3 + 8) & 0xfff7;
  return;
}

