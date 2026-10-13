/* Decompiled C draft; module arm9; ROM address 02030a20. No matching claim. */
#include "types.h"
#include "deps/02030a20_func_02030a20.h"

void func_02030a20(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x17;
  iVar2 = func_02025ebc(*piRam02030abc + 0xc0);
  puVar1 = puRam02030ac0;
  if ((*(int *)(*piRam02030abc + 0x84) == 0) && (*(int *)(*piRam02030abc + 0x94) != 6)) {
    iVar3 = 0x1f;
  }
  *puRam02030ac0 = *puRam02030ac0 & uRam02030ac4 | iVar3 << 8;
  *puRam02030acc = iVar2 * -0x10000 & uRam02030ac8;
  if (iVar2 != 0) {
    *puVar1 = *puVar1 & uRam02030ad0 | uRam02030ad4;
    *puRam02030ad8 = *puRam02030ad8 & 0xffc0 | 0x3f;
    *puRam02030adc = *puRam02030adc & 0xffc0 | 0x27;
    *puRam02030ae0 = 0xff;
    *puRam02030ae4 = (short)iVar2 + 0xc0U & 0xff;
    return;
  }
  *puVar1 = *puVar1 & uRam02030ad0;
  return;
}

