/* Decompiled C draft; module arm9; ROM address 02000800. No matching claim. */
#include "types.h"
#include "deps/02000800_Entry.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Entry(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar3;
  undefined4 *puVar7;
  
  _DAT_04000208 = 0x4000000;
  Crt0_InitializePU();
  Crt0_MemorySet32(0,iRam020008fc,0x4000);
  Crt0_MemorySet32(0,uRam02000904,0x400);
  Crt0_MemorySet32(0x200,uRam02000908,0x400);
  uVar5 = iRam0200090c + 0x14U & 3;
  uVar1 = *(uint *)(iRam0200090c + 0x14U & 0xfffffffc);
  Crt0_DecompressFlushCode(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
  Crt0_RegionCopy();
  uVar5 = iRam0200090c + 0xcU & 3;
  uVar2 = *(uint *)(iRam0200090c + 0xcU & 0xfffffffc);
  uVar1 = iRam0200090c + 0x10U & 3;
  uVar6 = *(uint *)(iRam0200090c + 0x10U & 0xfffffffc);
  puVar7 = (undefined4 *)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  puVar3 = (undefined4 *)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
  for (puVar4 = puVar3; puVar4 < puVar7; puVar4 = puVar4 + 1) {
    *puVar4 = 0;
  }
  uVar5 = (uint)puVar3 & 0xffffffe0;
  do {
    coproc_moveto_Data_Synchronization(0);
    coproc_moveto_Invalidate_Instruction_Cache_by_MVA(uVar5);
    coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar5);
    uVar5 = uVar5 + 0x20;
  } while ((int)uVar5 < (int)puVar7);
  *puRam02000910 = 0;
  *(undefined4 *)(iRam020008fc + 0x3ffc) = uRam02000914;
  Crt0_Reset32sAndAlphaFlags();
  NtrStartup();
  Crt0_RunInitArray();
                    /* WARNING: Could not recover jumptable at 0x020008f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02000918)();
  return;
}

