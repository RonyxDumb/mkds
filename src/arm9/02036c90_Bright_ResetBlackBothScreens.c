/* Decompiled C draft; module arm9; ROM address 02036c90. No matching claim. */
#include "types.h"
#include "deps/02036c90_Bright_ResetBlackBothScreens.h"

void Bright_ResetBlackBothScreens(void)

{
  short sVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  puVar2 = puRam02036cf8;
  puRam02036cf8[4] = 0;
  uVar4 = uRam02036d00;
  puVar3 = puRam02036cfc;
  sVar1 = puVar2[4];
  *puVar2 = 2;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  *puVar3 = 2;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[4] = 0;
  SetBrightness((ushort *)(uintptr_t)(uVar4),(int)sVar1);
  SetBrightness((ushort *)(uintptr_t)(uRam02036d04),(int)(short)puRam02036cfc[4]);
  return;
}

