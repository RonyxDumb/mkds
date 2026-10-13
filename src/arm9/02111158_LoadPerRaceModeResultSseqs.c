/* Decompiled C draft; module arm9; ROM address 02111158. No matching claim. */
#include "types.h"
#include "deps/02111158_LoadPerRaceModeResultSseqs.h"

undefined4 LoadPerRaceModeResultSseqs(int param_1)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  piVar2 = piRam02111240;
  uVar9 = *(uint *)((uint)puRam0211123c & 0xfffffffc) >> ((uint)puRam0211123c & 3) * 8 |
          *(uint *)((uint)puRam0211123c & 0xfffffffc) << ((uint)puRam0211123c & 3) * -8 + 0x20;
  if (param_1 == 4) {
    uVar7 = *(uint *)(uRam02111244 & 0xfffffffc) >> (uRam02111244 & 3) * 8 |
            *(uint *)(uRam02111244 & 0xfffffffc) << (uRam02111244 & 3) * -8 + 0x20;
    uVar4 = uVar7 + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 4) {
      cVar3 = *(char *)(uVar7 + 0x55);
    }
    else {
      cVar3 = -1;
    }
    uVar4 = uRam02111248;
    if (cVar3 == '\t') goto LAB_021111a8;
  }
  uVar4 = param_1 * 0x18 + iRam0211124c;
LAB_021111a8:
  uVar5 = (uint)(piRam02111240 + 2) & 3;
  uVar7 = *(uint *)((uint)(piRam02111240 + 2) & 0xfffffffc);
  if ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) == uVar4) {
    return 1;
  }
  uVar5 = (uint)(piRam02111240 + 1) & 3;
  uVar7 = *(uint *)((uint)(piRam02111240 + 1) & 0xfffffffc);
  *puRam0211123c = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar5 = (uint)(piVar2 + 1) & 3;
  uVar7 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
  Sound_Context_DisposeLoadedStuff(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  puVar1 = puRam0211123c;
  iVar10 = 0;
  while ((uVar5 = uVar4 + iVar10 * 4, uVar7 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
         uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20, uVar5 == 0xff ||
         (uVar7 = (uint)puVar1 & 3, uVar8 = *(uint *)((uint)puVar1 & 0xfffffffc),
         iVar6 = CheckMaybeLoadSseqOk(uVar5,uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20),
         iVar6 != 0))) {
    iVar10 = iVar10 + 1;
    if (5 < iVar10) {
      *piVar2 = param_1;
      puVar1 = puRam0211123c;
      piVar2[2] = uVar4;
      *puVar1 = uVar9;
      return 1;
    }
  }
  *puRam0211123c = uVar9;
  return 0;
}

