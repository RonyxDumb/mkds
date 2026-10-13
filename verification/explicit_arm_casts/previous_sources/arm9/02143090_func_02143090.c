/* Decompiled C draft; module arm9; ROM address 02143090. No matching claim. */
#include "types.h"
#include "deps/02143090_func_02143090.h"

uint func_02143090(void)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  byte local_10 [16];
  
  pbVar1 = local_10;
  Os_GetMacAddress(local_10);
  iVar2 = 0;
  uVar3 = 0;
  do {
    iVar2 = iVar2 + 1;
    uVar3 = uVar3 + *pbVar1 & 0xffff;
    pbVar1 = pbVar1 + 1;
  } while (iVar2 < 6);
  uVar3 = (uVar3 + (*(uint *)(uRam02143128 & 0xfffffffc) >> (uRam02143128 & 3) * 8 |
                   *(uint *)(uRam02143128 & 0xfffffffc) << (uRam02143128 & 3) * -8 + 0x20) & 0xffff)
          * 0xd0000 >> 0x10;
  return (uVar3 - iRam02143130 * (int)((longlong)iRam0214312c * (longlong)(int)uVar3 >> 0x22)) +
         0x1e & 0xffff;
}

