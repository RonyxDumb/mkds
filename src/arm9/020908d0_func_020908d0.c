/* Decompiled C draft; module arm9; ROM address 020908d0. No matching claim. */
#include "types.h"
#include "deps/020908d0_func_020908d0.h"

bool func_020908d0(int param_1,ushort *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0209091c & 0xfffffffc) >> (uRam0209091c & 3) * 8 |
          *(uint *)(uRam0209091c & 0xfffffffc) << (uRam0209091c & 3) * -8 + 0x20) +
          (param_1 + -1) * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return (int)((uint)*param_2 +
              (uint)*(byte *)((int)param_2 + 3) * 1000 + (uint)(byte)param_2[1] * iRam02090918) <
         (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
}

