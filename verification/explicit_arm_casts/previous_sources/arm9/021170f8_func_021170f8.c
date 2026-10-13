/* Decompiled C draft; module arm9; ROM address 021170f8. No matching claim. */
#include "types.h"
#include "deps/021170f8_func_021170f8.h"

void func_021170f8(void)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  
  StructKTB_SomeFn_from_thumb(*(undefined4 *)*puRam02117160);
  if (*(int *)(*piRam02117164 + 0x20) == 0) {
    uVar3 = 1;
  }
  else {
    bVar2 = true;
    iVar1 = *(int *)(*piRam02117168 + 4);
    if ((iVar1 != 8) && (iVar1 != 9)) {
      bVar2 = false;
    }
    if (bVar2) {
      uVar3 = Math_CountPopulation(*(undefined1 *)(*piRam02117168 + iRam0211716c));
    }
    else {
      uVar3 = 0;
    }
    uVar3 = uVar3 & 0xff;
  }
  if (uVar3 < 8) {
    do {
      func_020294fc(uVar3 & 0xffff,0xffffffff);
      func_020294ac(uVar3 & 0xffff,0);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 8);
  }
  return;
}

