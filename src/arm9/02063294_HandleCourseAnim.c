/* Decompiled C draft; module arm9; ROM address 02063294. No matching claim. */
#include "types.h"
#include "deps/02063294_HandleCourseAnim.h"

void HandleCourseAnim(void)

{
  uint uVar1;
  uint uVar2;
  
  if (*(short *)(iRam0206330c + 0x20) != 0) {
    Animation_Update(uRam02063310);
  }
  if (*(short *)(iRam0206330c + 0x58) != 0) {
    Animation_Update(uRam02063314);
  }
  uVar1 = iRam0206330c + 4U & 3;
  uVar2 = *(uint *)(iRam0206330c + 4U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    if (*(short *)(iRam0206330c + 0x90) != 0) {
      Animation_Update(uRam02063318);
      return;
    }
    return;
  }
  return;
}

