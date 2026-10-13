/* Decompiled C draft; module arm9; ROM address 020af86c. No matching claim. */
#include "types.h"
#include "deps/020af86c_func_020af86c.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_020af86c(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam020af988 & 0xfffffffc) >> (uRam020af988 & 3) * 8 |
          *(uint *)(uRam020af988 & 0xfffffffc) << (uRam020af988 & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar2 == 3) {
    Reset33();
    return;
  }
  if (uVar2 != 5) {
    if (uVar2 != 6) {
      G2x_SetBlendAlpha_(uRam020af98c,0,0);
      G2x_SetBlendAlpha_(uRam020af990,0,0);
      *puRam020af994 = 0;
      ResetGlobalB358();
      func_020b3af4();
      func_020b65dc();
      ResetGlobalB3C4();
      uVar2 = (*(uint *)(uRam020af988 & 0xfffffffc) >> (uRam020af988 & 3) * 8 |
              *(uint *)(uRam020af988 & 0xfffffffc) << (uRam020af988 & 3) * -8 + 0x20) + 0xc;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 4) {
        func_020d129c();
      }
      func_020bb51c();
      ResetGlobalB3EC();
      func_020ba50c();
      ResetGlobalB3F0();
      func_020bc108();
      func_020bcb60();
      func_020d2094();
      func_020d0bbc();
      func_020be7e8();
      func_020beb40();
      func_020c31ec();
      ResetGlobalE8();
      func_020c476c();
      _DAT_04000000 = _DAT_04000000 & 0xffff1fff;
      *puRam020af998 =
           (*(uint *)((uint)puRam020af998 & 0xfffffffc) >> ((uint)puRam020af998 & 3) * 8 |
           *(uint *)((uint)puRam020af998 & 0xfffffffc) << ((uint)puRam020af998 & 3) * -8 + 0x20) &
           0xffff1fff;
      return;
    }
    ResetStaffRollStuffObject();
    ResetStaffRoll();
    return;
  }
  return;
}

