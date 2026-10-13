/* Decompiled C draft; module arm9_ov003; ROM address 021c6508. No matching claim. */
#include "types.h"
#include "deps/021c6508_FUN_021c6508.h"

void FUN_021c6508(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_021c6580;
  uVar2 = 0;
  *(ushort *)(*DAT_021c6580 + 0x40) = (*(byte *)(*DAT_021c6580 + 0x51) - 4) * 0x1c;
  iVar3 = *piVar1;
  if (*(byte *)(iVar3 + 0x51) < 5) {
    iVar4 = 0;
    *(undefined1 *)(iVar3 + 0x53) = 0;
  }
  else if (*(byte *)(iVar3 + 0x51) < 9) {
    iVar4 = 1;
    *(undefined1 *)(iVar3 + 0x53) = 0x1f;
  }
  else {
    iVar4 = 2;
    *(undefined1 *)(iVar3 + 0x53) = 0x37;
  }
  if (iVar4 != 0) {
    uVar2 = func_0x02147d30((uint)*(byte *)(*DAT_021c6580 + 0x53) * (uint)*DAT_021c6584,
                            *(undefined2 *)(*DAT_021c6580 + 0x40));
  }
  FUN_021ccea4(iVar4,0x55,0xec,0x3f,uVar2);
  return;
}

