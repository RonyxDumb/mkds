/* Decompiled C draft; module arm9; ROM address 020efbd4. No matching claim. */
#include "types.h"
#include "deps/020efbd4_StructPR_Load_from_thumb.h"

void StructPR_Load_from_thumb(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(short *)(param_1 + iRam020efc4c) = (short)param_2;
  uVar1 = GetDriverEntry(param_2);
  *(undefined4 *)(param_1 + iRam020efc50) = uVar1;
  *(undefined4 *)(param_1 + iRam020efc58) = *(undefined4 *)(*piRam020efc54 + param_2 * 0x30 + 0x7c);
  StructPRSub_Create((undefined4 *)(uintptr_t)(param_1),param_1);
  StructPRSub_Create2((undefined4 *)(uintptr_t)(param_1 + 0x30),param_1);
  func_020ee684(param_1 + 0x58,param_1);
  if (*(short *)(*piRam020efc5c + 0x60) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*piRam020efc5c + 0xb0);
  }
  *(undefined4 *)(param_1 + iRam020efc60) = uVar1;
  *(undefined4 *)(param_1 + iRam020efc64) = 1;
  *(undefined4 *)(param_1 + iRam020efc68) = 0;
  *(undefined4 *)(param_1 + iRam020efc6c) = 0;
  *(undefined4 *)(param_1 + iRam020efc70) = 0;
  return;
}

