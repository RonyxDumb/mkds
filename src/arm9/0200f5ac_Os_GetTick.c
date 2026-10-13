/* Decompiled C draft; module arm9; ROM address 0200f5ac. No matching claim. */
#include "types.h"
#include "deps/0200f5ac_Os_GetTick.h"

undefined8 Os_GetTick(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  undefined4 local_c;
  undefined4 local_8;
  
  Os_DisableIrq();
  uVar2 = *puRam0200f64c;
  local_c = *(uint *)(uRam0200f650 & 0xfffffffc) >> (uRam0200f650 & 3) * 8 |
            *(uint *)(uRam0200f650 & 0xfffffffc) << (uRam0200f650 & 3) * -8 + 0x20;
  uVar1 = uRam0200f650 + 4 & 3;
  uVar3 = *(uint *)(uRam0200f650 + 4 & 0xfffffffc);
  local_8 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam0200f654;
  if ((((*(uint *)(uRam0200f658 & 0xfffffffc) >> (uRam0200f658 & 3) * 8 |
        *(uint *)(uRam0200f658 & 0xfffffffc) << (uRam0200f658 & 3) * -8 + 0x20) & 8) != 0) &&
     ((uVar2 & 0x8000) == 0)) {
    bVar4 = 0xfffffffe < local_c;
    local_c = local_c + 1;
    local_8 = local_8 + bVar4;
  }
  Os_RestoreIrq();
  return CONCAT44(local_8 << 0x10 | local_c >> 0x10,(uint)uVar2 | local_c << 0x10);
}

