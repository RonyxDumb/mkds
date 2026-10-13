/* Decompiled C draft; module arm9; ROM address 0205eca4. No matching claim. */
#include "types.h"
#include "deps/0205eca4_func_0205eca4.h"

undefined4 func_0205eca4(char *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_38 [34];
  byte bStack_16;
  
  uVar3 = param_2 - iRam0205ed98 *
                    (-(param_2 >> 0x1f) + (int)((longlong)iRam0205ed94 * (longlong)param_2 >> 0x21))
          & 0xff;
  if ((-(param_2 >> 0x1f) + (int)((longlong)iRam0205ed94 * (longlong)param_2 >> 0x21) & 0xffU) !=
      (int)*param_1) {
    return 0;
  }
  uVar2 = (*(uint *)(uRam0205ed9c & 0xfffffffc) >> (uRam0205ed9c & 3) * 8 |
          *(uint *)(uRam0205ed9c & 0xfffffffc) << (uRam0205ed9c & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  Mem_CpuCopy8(param_2 * 0x24 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 4,auStack_38);
  if (((int)((uint)bStack_16 << 0x1f) < 0) && ((int)((uint)bStack_16 << 0x1d) < 0)) {
    *(bool *)(param_3 + 0x200) = ((uint)(byte)param_1[8] & 1 << uVar3) != 0;
    if (*(char *)(param_3 + 0x200) != '\0') {
      Mem_CpuCopy8(param_1 + uVar3 * 0x200 + 0xc,param_3,0x200);
    }
    return 1;
  }
  return 0;
}

