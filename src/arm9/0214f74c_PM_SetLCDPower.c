/* Decompiled C draft; module arm9; ROM address 0214f74c. No matching claim. */
#include "types.h"
#include "deps/0214f74c_PM_SetLCDPower.h"

undefined4 PM_SetLCDPower(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = puRam0214f834;
  uVar3 = uRam0214f830;
  if (param_1 == 0) {
    *puRam0214f838 = *puRam0214f838 & 0xfffe;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *puVar2 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    if (param_2 != 0) {
      if (param_4 == 0) {
        func_0214fcb0(param_2,0,0);
      }
      else {
        func_0214fc74(param_2);
      }
    }
  }
  else if (param_1 == 1) {
    if ((param_3 == 0) &&
       ((*(uint *)(uRam0214f830 & 0xfffffffc) >> (uRam0214f830 & 3) * 8 |
        *(uint *)(uRam0214f830 & 0xfffffffc) << (uRam0214f830 & 3) * -8 + 0x20) -
        (*(uint *)((uint)puRam0214f834 & 0xfffffffc) >> ((uint)puRam0214f834 & 3) * 8 |
        *(uint *)((uint)puRam0214f834 & 0xfffffffc) << ((uint)puRam0214f834 & 3) * -8 + 0x20) < 8))
    {
      return 0;
    }
    if (param_2 != 0) {
      if (param_4 == 0) {
        func_0214fcb0(param_2,0,0);
      }
      else {
        func_0214fc74(param_2);
      }
    }
    *puRam0214f838 = *puRam0214f838 | 1;
  }
  return 1;
}

