/* Decompiled C draft; module arm9; ROM address 0212bd10. No matching claim. */
#include "types.h"
#include "deps/0212bd10_SoundDtorFn.h"

void SoundDtorFn(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 + 8U & 3;
  uVar1 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (uVar1 >> uVar2 * 8 == 0 && uVar1 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  Sound_Context_Dispose();
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 == 0) {
    uVar2 = param_1 + 0x10U & 3;
    uVar1 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    IntrusiveListWrapper_RemoveItem
              ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) * 0x24 + iRam0212bd68 + 0xc,param_1
              );
    return;
  }
  *(undefined4 *)(uVar2 + 8) = 0;
  return;
}

