/* Decompiled C draft; module arm9; ROM address 02061250. No matching claim. */
#include "types.h"
#include "deps/02061250_func_02061250.h"

bool func_02061250(void)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  
  uVar2 = *(uint *)(uRam0206128c & 0xfffffffc) >> (uRam0206128c & 3) * 8 |
          *(uint *)(uRam0206128c & 0xfffffffc) << (uRam0206128c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  lVar3 = PlayerProfileInfo_GetProfileId_from_thumb
                    ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x4c);
  return lVar3 != 0;
}

