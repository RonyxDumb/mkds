/* Decompiled C draft; module arm9; ROM address 02148a88. No matching claim. */
#include "types.h"
#include "deps/02148a88_Gfx_Initialize.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Gfx_Initialize(void)

{
  short sVar1;
  ushort uVar2;
  ushort *puVar3;
  undefined4 uVar4;
  short *psVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  uVar4 = uRam02148be4;
  puVar3 = puRam02148bdc;
  uVar2 = (ushort)uRam02148be0;
  *puRam02148bdc = *puRam02148bdc | 0x8000;
  *puVar3 = *puVar3 & uVar2 | (ushort)uVar4;
  *puVar3 = *puVar3 | 1;
  Gfx_InitializeState();
  psVar5 = psRam02148be8;
  sVar1 = *psRam02148be8;
  while (sVar1 == 0) {
    iVar8 = Os_AllocateLockId();
    if (iVar8 == -3) {
      Os_Terminate();
    }
    *psVar5 = (short)iVar8;
    sVar1 = *psVar5;
  }
  *puRam02148bec = 0;
  _DAT_04000000 = 0;
  uVar9 = *(uint *)(uRam02148bf0 & 0xfffffffc) >> (uRam02148bf0 & 3) * 8 |
          *(uint *)(uRam02148bf0 & 0xfffffffc) << (uRam02148bf0 & 3) * -8 + 0x20;
  if (uVar9 == 0xffffffff) {
    MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(uRam02148bf4),0x60);
    *puRam02148bf8 = 0;
    MIi_CpuClear32(0,(undefined4 *)(uintptr_t)(uRam02148bfc),0x70);
  }
  else {
    Mem_DmaFill32(uVar9,uRam02148bf4,0,0x60);
    uVar10 = uRam02148bf0;
    *puRam02148bf8 = 0;
    uVar9 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    Mem_DmaFill32(uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20,uRam02148bfc,0,0x70);
  }
  puVar6 = puRam02148c04;
  *puRam02148c00 = 0x100;
  puVar7 = puRam02148c08;
  *puVar6 = 0x100;
  puVar6 = puRam02148c0c;
  *puVar7 = 0x100;
  puVar7 = puRam02148c10;
  *puVar6 = 0x100;
  puVar6 = puRam02148c14;
  *puVar7 = 0x100;
  puVar7 = puRam02148c18;
  *puVar6 = 0x100;
  puVar6 = puRam02148c1c;
  *puVar7 = 0x100;
  *puVar6 = 0x100;
  return;
}

