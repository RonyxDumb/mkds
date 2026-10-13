/* Decompiled C draft; module arm9; ROM address 02037850. No matching claim. */
#include "types.h"
#include "deps/02037850_LoopFn_Brightness.h"

void LoopFn_Brightness(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  code *pcVar8;
  ushort *puVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  undefined8 uVar14;
  
  pcVar8 = (code *)(*(uint *)(uRam020379e4 & 0xfffffffc) >> (uRam020379e4 & 3) * 8 |
                   *(uint *)(uRam020379e4 & 0xfffffffc) << (uRam020379e4 & 3) * -8 + 0x20);
  sVar2 = *(short *)(iRam020379e8 + 8);
  sVar3 = *(short *)(iRam020379ec + 8);
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(1);
  }
  Bright_UpdateContext(iRam020379e8);
  Bright_UpdateContext(iRam020379ec);
  DC_func_0002();
  uVar7 = *(uint *)(uRam020379f0 & 0xfffffffc) >> (uRam020379f0 & 3) * 8 |
          *(uint *)(uRam020379f0 & 0xfffffffc) << (uRam020379f0 & 3) * -8 + 0x20;
  if (*(short *)(uVar7 + 10) == 1) {
    uVar7 = uVar7 + 0x6c;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    *puRam020379f4 = (uint)*(byte *)(uVar7 + 2) | (uint)*(byte *)(uVar7 + 3) << 1;
  }
  uVar7 = uRam020379f0;
  uVar10 = *(uint *)(uRam020379f0 & 0xfffffffc) >> (uRam020379f0 & 3) * 8 |
           *(uint *)(uRam020379f0 & 0xfffffffc) << (uRam020379f0 & 3) * -8 + 0x20;
  bVar1 = *(byte *)(uVar10 + 0xd8);
  if ((bVar1 & 1) == 0) {
    *(byte *)(uVar10 + 0xd8) = bVar1 | 2;
  }
  else {
    *(byte *)(uVar10 + 0xd8) = bVar1 & 0xfd;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
    *(byte *)(uVar7 + 0xd8) = *(byte *)(uVar7 + 0xd8) & 0xfe;
  }
  uVar11 = *(uint *)(uRam020379f0 & 0xfffffffc) >> (uRam020379f0 & 3) * 8 |
           *(uint *)(uRam020379f0 & 0xfffffffc) << (uRam020379f0 & 3) * -8 + 0x20;
  uVar14 = Os_GetTick();
  uVar7 = uVar11 + 0xbc & 3;
  uVar10 = *(uint *)(uVar11 + 0xbc & 0xfffffffc);
  uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = uVar11 + 0xc0 & 3;
  uVar13 = *(uint *)(uVar11 + 0xc0 & 0xfffffffc);
  lVar4 = (ulonglong)((uint)uVar14 - uVar10) * 64000;
  uVar6 = _ll_udiv((int)lVar4,
                   ((int)((ulonglong)uVar14 >> 0x20) -
                   ((uVar13 >> uVar7 * 8 | uVar13 << uVar7 * -8 + 0x20) +
                   (uint)((uint)uVar14 < uVar10))) * 64000 + (int)((ulonglong)lVar4 >> 0x20),
                   uRam020379f8);
  uVar7 = uRam020379f0;
  *(undefined4 *)(uVar11 + 0xcc) = uVar6;
  puVar9 = (ushort *)
           (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
           *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20);
  uVar12 = 0;
  if (*puVar9 != 0) {
    do {
      WaitForIRQ(1,1);
      puVar9 = (ushort *)
               (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20);
      uVar12 = uVar12 + 1;
    } while (uVar12 < *puVar9);
  }
  *(byte *)(puVar9 + 0x6c) = (byte)puVar9[0x6c] | 1;
  uVar14 = Os_GetTick();
  iVar5 = iRam020379e8;
  *(undefined8 *)
   ((*(uint *)(uRam020379f0 & 0xfffffffc) >> (uRam020379f0 & 3) * 8 |
    *(uint *)(uRam020379f0 & 0xfffffffc) << (uRam020379f0 & 3) * -8 + 0x20) + 0xc4) = uVar14;
  if (sVar2 != *(short *)(iVar5 + 8)) {
    SetBrightness(uRam020379fc);
  }
  if (sVar3 != *(short *)(iRam020379ec + 8)) {
    SetBrightness(uRam02037a00);
  }
  pcVar8 = (code *)(*(uint *)(uRam020379e4 & 0xfffffffc) >> (uRam020379e4 & 3) * 8 |
                   *(uint *)(uRam020379e4 & 0xfffffffc) << (uRam020379e4 & 3) * -8 + 0x20);
  if (pcVar8 == (code *)0x0) {
    return;
  }
  (*pcVar8)(2);
  return;
}

