/* Decompiled C draft; module arm9; ROM address 02081224. No matching claim. */
#include "types.h"
#include "deps/02081224_func_02081224.h"

void func_02081224(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x58 +
          (*(uint *)(uRam0208128c & 0xfffffffc) >> (uRam0208128c & 3) * 8 |
          *(uint *)(uRam0208128c & 0xfffffffc) << (uRam0208128c & 3) * -8 + 0x20);
  uVar3 = iVar4 + 0x30U & 3;
  uVar1 = *(uint *)(iVar4 + 0x30U & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 != 0 || uVar1 << uVar3 * -8 + 0x20 != 0) {
    func_0208b710();
  }
  uVar2 = func_0208b7bc(0x5e,uRam02081290);
  *(undefined4 *)(iVar4 + 0x30) = uVar2;
  uVar3 = iVar4 + 0x30U & 3;
  uVar1 = *(uint *)(iVar4 + 0x30U & 0xfffffffc);
  uVar3 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  *(undefined1 *)(uVar3 + 0x9a) = 0;
  *(undefined1 *)(uVar3 + 0x99) = 0x78;
  uVar2 = uRam02081294;
  *(char *)(uVar3 + 0x9b) = (char)param_1;
  *(undefined4 *)(uVar3 + 0x90) = uVar2;
  return;
}

