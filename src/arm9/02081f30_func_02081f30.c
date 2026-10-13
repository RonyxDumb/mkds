/* Decompiled C draft; module arm9; ROM address 02081f30. No matching claim. */
#include "types.h"
#include "deps/02081f30_func_02081f30.h"

void func_02081f30(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = *(uint *)(uRam02082018 & 0xfffffffc) >> (uRam02082018 & 3) * 8 |
          *(uint *)(uRam02082018 & 0xfffffffc) << (uRam02082018 & 3) * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0x10) {
    uVar3 = *(uint *)((uint)piRam0208201c & 0xfffffffc) >> ((uint)piRam0208201c & 3) * 8 |
            *(uint *)((uint)piRam0208201c & 0xfffffffc) << ((uint)piRam0208201c & 3) * -8 + 0x20;
    if (uVar3 != 0) {
      *(undefined4 *)(uVar3 + 0x90) = uRam02082030;
    }
    if (*(uint *)((uint)piRam02082028 & 0xfffffffc) >> ((uint)piRam02082028 & 3) * 8 != 0 ||
        *(uint *)((uint)piRam02082028 & 0xfffffffc) << ((uint)piRam02082028 & 3) * -8 + 0x20 != 0) {
      func_0208b710();
      *piRam02082028 = 0;
      return;
    }
    return;
  }
  if (uVar3 != 0x25) {
    return;
  }
  if (*(uint *)((uint)piRam0208201c & 0xfffffffc) >> ((uint)piRam0208201c & 3) * 8 != 0 ||
      *(uint *)((uint)piRam0208201c & 0xfffffffc) << ((uint)piRam0208201c & 3) * -8 + 0x20 != 0) {
    func_0208b710();
    iVar4 = func_0208b7bc(0x3c,uRam02082020);
    uVar1 = uRam02082024;
    *piRam0208201c = iVar4;
    *(undefined4 *)(iVar4 + 0x90) = uVar1;
  }
  if (*(uint *)((uint)piRam02082028 & 0xfffffffc) >> ((uint)piRam02082028 & 3) * 8 != 0 ||
      *(uint *)((uint)piRam02082028 & 0xfffffffc) << ((uint)piRam02082028 & 3) * -8 + 0x20 != 0) {
    func_0208b710();
    iVar4 = func_0208b7bc(0x3f,uRam02082020);
    uVar1 = uRam0208202c;
    *piRam02082028 = iVar4;
    *(undefined4 *)(iVar4 + 0x90) = uVar1;
    return;
  }
  return;
}

