/* Decompiled C draft; module arm9; ROM address 021087f4. No matching claim. */
#include "types.h"
#include "deps/021087f4_MaybeReloadRacerSbnksSwars.h"

bool MaybeReloadRacerSbnksSwars(uint param_1)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return true;
  }
  uVar1 = (uint)(puRam02108874 + 2) & 3;
  uVar4 = *(uint *)((uint)(puRam02108874 + 2) & 0xfffffffc);
  if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 0xff00) && (*puRam02108874 == param_1))
  {
    return true;
  }
  Sound_Context_DisposeLoadedStuff
            (*(uint *)(uRam02108878 & 0xfffffffc) >> (uRam02108878 & 3) * 8 |
             *(uint *)(uRam02108878 & 0xfffffffc) << (uRam02108878 & 3) * -8 + 0x20);
  puVar2 = puRam02108874;
  *puRam02108874 = 0;
  puVar2[2] = 0xff00;
  puVar2[3] = 0;
  *puVar2 = (ushort)param_1;
  puVar2[2] = 0xfe00;
  puVar2[3] = 0;
  iVar3 = MaybeLoadRacerSbnksSwars(param_1);
  return iVar3 != 0;
}

