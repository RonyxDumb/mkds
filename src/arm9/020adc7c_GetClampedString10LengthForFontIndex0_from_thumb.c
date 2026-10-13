/* Decompiled C draft; module arm9; ROM address 020adc7c. No matching claim. */
#include "types.h"
#include "deps/020adc7c_GetClampedString10LengthForFontIndex0_from_thumb.h"

int GetClampedString10LengthForFontIndex0_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_1c [2];
  
  iVar3 = 0;
  uVar1 = GetLoadedFont_from_thumb(0);
  DoFill16(param_2,0,0x14);
  iVar4 = 0;
  while( true ) {
    if (9 < iVar4) {
      return 10;
    }
    iVar2 = iVar4 * 2;
    if (*(short *)(param_1 + iVar2) == 0) break;
    MaybeGetNftrCodepointPixelSize(local_1c,uVar1);
    if (0x30 < iVar3 + *(char *)(local_1c[0] + 2)) {
      return iVar4;
    }
    iVar3 = iVar3 + *(char *)(local_1c[0] + 2) + 1;
    *(undefined2 *)(param_2 + iVar2) = *(undefined2 *)(param_1 + iVar2);
    iVar4 = iVar4 + 1;
  }
  return iVar4;
}

