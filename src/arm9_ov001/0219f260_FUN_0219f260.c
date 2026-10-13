/* Decompiled C draft; module arm9_ov001; ROM address 0219f260. No matching claim. */
#include "types.h"
#include "deps/0219f260_FUN_0219f260.h"

void FUN_0219f260(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_0219f29c;
  *(undefined4 *)(*DAT_0219f29c + 0x20) = 1;
  *(undefined4 *)(*piVar1 + 0x24) = 0;
  iVar2 = func_0x020cccb4();
  if (iVar2 == 0x13) {
    *(undefined2 *)(*DAT_0219f29c + 0x48) = 0xff00;
    return;
  }
  *(short *)(*DAT_0219f29c + 0x48) = (short)DAT_0219f2a0;
  return;
}

