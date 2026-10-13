/* Decompiled C draft; module arm9_ov001; ROM address 02185bb8. No matching claim. */
#include "types.h"
#include "deps/02185bb8_FUN_02185bb8.h"

void FUN_02185bb8(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0xac) == 0) {
    if (*(int *)(*DAT_02185c44 + 8) == 4) {
      iVar2 = func_ov001_02181820();
    }
    else {
      iVar2 = 0;
    }
    if (*(short *)(*(int *)(param_2 + 0x9c) + 0x28) + -1 <= iVar2) {
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
      *(undefined4 *)(param_2 + 0xac) = 1;
      return;
    }
  }
  else {
    if (*(int *)(param_2 + 0xac) != 2) {
      return;
    }
    iVar2 = func_0x0209b710(*DAT_02185c48);
    *(short *)(param_2 + 0xa8) = *(short *)(param_2 + 0xa8) + 1;
    if (iVar2 + -1 <= (int)(uint)*(ushort *)(param_2 + 0xa8)) {
      sVar1 = func_0x0209b710(*DAT_02185c48);
      *(short *)(param_2 + 0xa8) = sVar1 + -1;
      *(undefined4 *)(param_2 + 0xac) = 1;
    }
  }
  return;
}

