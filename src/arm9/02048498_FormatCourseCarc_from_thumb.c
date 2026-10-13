/* Decompiled C draft; module arm9; ROM address 02048498. No matching claim. */
#include "types.h"
#include "deps/02048498_FormatCourseCarc_from_thumb.h"

void FormatCourseCarc_from_thumb(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = false;
  if ((*psRam020484e4 == 2) && (*(char *)(iRam020484e8 + param_2 * 8) == '\x01')) {
    bVar1 = true;
  }
  uVar3 = uRam020484f0;
  if (param_3 != 0) {
    uVar3 = uRam020484ec;
  }
  uVar2 = uRam020484f8;
  if (bVar1) {
    uVar2 = uRam020484f4;
  }
  Util_SNPrintF(param_1,0x80,uRam020484fc,*(undefined4 *)(iRam02048500 + param_2 * 8),uVar2,uVar3);
  return;
}

