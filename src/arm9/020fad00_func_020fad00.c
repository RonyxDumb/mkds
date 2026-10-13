/* Decompiled C draft; module arm9; ROM address 020fad00. No matching claim. */
#include "types.h"
#include "deps/020fad00_func_020fad00.h"

void func_020fad00(void)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  *piRam020fad6c = iRam020fad68;
  uVar2 = FX_Div(uRam020fad70);
  *puRam020fad74 = uVar2;
  *puRam020fad7c = uRam020fad78;
  uVar5 = Multiply64(*piRam020fad6c,*piRam020fad6c >> 0x1f,*(int *)(*piRam020fad80 + iRam020fad84),
                     *(int *)(*piRam020fad80 + iRam020fad84) >> 0x1f);
  puVar1 = puRam020fad88;
  uVar4 = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
  *puRam020fad88 = uVar4;
  uVar4 = (int)uVar4 >> 0xc;
  *puVar1 = uVar4;
  *puVar1 = uVar4 * uVar4;
  iVar3 = func_020ed490(uRam020fad8c,uRam020fad90);
  *piRam020fad94 = iVar3;
  if (*(int *)*puRam020fad98 == 0x1d) {
    Maybe_helper_013044(*(undefined4 *)(iVar3 + 4),0);
  }
  return;
}

