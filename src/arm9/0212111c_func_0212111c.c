/* Decompiled C draft; module arm9; ROM address 0212111c. No matching claim. */
#include "types.h"
#include "deps/0212111c_func_0212111c.h"

uint func_0212111c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (((*(char *)((*(uint *)(uRam0212118c & 0xfffffffc) >> (uRam0212118c & 3) * 8 |
                  *(uint *)(uRam0212118c & 0xfffffffc) << (uRam0212118c & 3) * -8 + 0x20) + 0x194e)
        == '\0') || (iVar2 = func_0x0219bb68(), 1 < iVar2)) &&
     (uVar3 = (*(uint *)(uRam0212118c & 0xfffffffc) >> (uRam0212118c & 3) * 8 |
              *(uint *)(uRam0212118c & 0xfffffffc) << (uRam0212118c & 3) * -8 + 0x20) + 0x1f44,
     uVar1 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
     (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != 7)) {
    iVar2 = func_02121d48();
    return (uint)(iVar2 != 0);
  }
  return 0xffffffff;
}

