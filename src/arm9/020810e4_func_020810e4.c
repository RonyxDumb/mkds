/* Decompiled C draft; module arm9; ROM address 020810e4. No matching claim. */
#include "types.h"
#include "deps/020810e4_func_020810e4.h"

void func_020810e4(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x58 +
          (*(uint *)(uRam0208111c & 0xfffffffc) >> (uRam0208111c & 3) * 8 |
          *(uint *)(uRam0208111c & 0xfffffffc) << (uRam0208111c & 3) * -8 + 0x20);
  uVar2 = iVar3 + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0208b710();
    *(undefined4 *)(iVar3 + 0x30) = 0;
    return;
  }
  return;
}

