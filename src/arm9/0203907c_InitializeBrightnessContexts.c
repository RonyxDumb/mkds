/* Decompiled C draft; module arm9; ROM address 0203907c. No matching claim. */
#include "types.h"
#include "deps/0203907c_InitializeBrightnessContexts.h"

void InitializeBrightnessContexts(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  puVar2 = puRam020390e0;
  puRam020390e0[4] = 0x10;
  uVar4 = uRam020390e8;
  puVar3 = puRam020390e4;
  sVar1 = puVar2[4];
  *puVar2 = 0;
  puVar2[1] = 1;
  puVar2[2] = 0;
  puVar2[3] = 0;
  *puVar3 = 0;
  puVar3[1] = 1;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0x10;
  SetBrightness((ushort *)(uintptr_t)(uVar4),(int)sVar1);
  SetBrightness((ushort *)(uintptr_t)(uRam020390ec),(int)(short)puRam020390e4[4]);
  return;
}

