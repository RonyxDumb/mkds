/* Decompiled C draft; module arm9; ROM address 0205fbb8. No matching claim. */
#include "types.h"
#include "deps/0205fbb8_CheckSecretFlag.h"

void CheckSecretFlag(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  bVar3 = false;
  uVar1 = *(uint *)(uRam0205fc20 & 0xfffffffc) >> (uRam0205fc20 & 3) * 8 |
          *(uint *)(uRam0205fc20 & 0xfffffffc) << (uRam0205fc20 & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  }
  if ((uVar2 != 0) &&
     (uVar2 = uVar1 + 4 & 3, uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc),
     (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 0xd)) {
    bVar3 = true;
  }
  if (bVar3) {
    CheckSecretFlagWith_from_thumb
              (param_1,(*(uint *)(uRam0205fc24 & 0xfffffffc) >> (uRam0205fc24 & 3) * 8 |
                       *(uint *)(uRam0205fc24 & 0xfffffffc) << (uRam0205fc24 & 3) * -8 + 0x20) +
                       0x34);
    return;
  }
  CheckSavedSecretFlag_from_thumb();
  return;
}

