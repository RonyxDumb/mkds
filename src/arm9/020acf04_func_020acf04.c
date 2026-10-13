/* Decompiled C draft; module arm9; ROM address 020acf04. No matching claim. */
#include "types.h"
#include "deps/020acf04_func_020acf04.h"

void func_020acf04(void)

{
  switch(*(undefined4 *)(*DAT_020acf40 + 0x54)) {
  case 0:
  case 1:
  case 2:
    MaybePlaySomeSseqFromSarc0(9);
    break;
  case 3:
  case 4:
    MaybePlaySomeSseqFromSarc0(8);
  }
  return;
}

