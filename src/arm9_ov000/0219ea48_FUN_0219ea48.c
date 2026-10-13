/* Decompiled C draft; module arm9_ov000; ROM address 0219ea48. No matching claim. */
#include "types.h"
#include "deps/0219ea48_FUN_0219ea48.h"

void FUN_0219ea48(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = 0;
  iVar2 = *DAT_0219ea80;
  do {
    iVar3 = 0;
    do {
      if (bVar1 == *(byte *)(iVar2 + iVar3 + DAT_0219ea84)) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)(uint)*(byte *)(iVar2 + 0x14));
    if ((int)(uint)*(byte *)(iVar2 + 0x14) < iVar3) {
      return;
    }
    bVar1 = bVar1 + 1;
    if (0x1f < bVar1) {
      return;
    }
  } while( true );
}

