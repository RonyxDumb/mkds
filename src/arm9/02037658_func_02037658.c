/* Decompiled C draft; module arm9; ROM address 02037658. No matching claim. */
#include "types.h"
#include "deps/02037658_func_02037658.h"

void func_02037658(int param_1)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  code *pcVar9;
  uint uVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  undefined8 uVar14;
  
  pcVar9 = (code *)(*(uint *)(uRam02037830 & 0xfffffffc) >> (uRam02037830 & 3) * 8 |
                   *(uint *)(uRam02037830 & 0xfffffffc) << (uRam02037830 & 3) * -8 + 0x20);
  sVar2 = *(short *)(iRam02037834 + 8);
  sVar3 = *(short *)(iRam02037838 + 8);
  if (pcVar9 != (code *)0x0) {
    (*pcVar9)(1);
  }
  Bright_UpdateContext((undefined2 *)(uintptr_t)(iRam02037834));
  Bright_UpdateContext((undefined2 *)(uintptr_t)(iRam02037838));
  DC_func_0002();
  uVar8 = uRam0203783c;
  uVar10 = *(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
           *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20;
  bVar1 = *(byte *)(uVar10 + 0xd8);
  if ((bVar1 & 1) == 0) {
    *(byte *)(uVar10 + 0xd8) = bVar1 | 2;
  }
  else {
    *(byte *)(uVar10 + 0xd8) = bVar1 & 0xfd;
    uVar10 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
    *(byte *)(uVar8 + 0xd8) = *(byte *)(uVar8 + 0xd8) & 0xfe;
  }
  if ((param_1 == 0) ||
     ((*(byte *)((*(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
                 *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20) + 0xd8) & 2
      ) == 0)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  uVar8 = *(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
          *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20;
  if ((*(short *)(uVar8 + 10) == 1) && (bVar5)) {
    uVar8 = uVar8 + 0x6c;
    uVar10 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20;
    *puRam02037840 = (uint)*(byte *)(uVar8 + 2) | (uint)*(byte *)(uVar8 + 3) << 1;
  }
  uVar11 = *(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
           *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20;
  uVar14 = Os_GetTick();
  uVar8 = uVar11 + 0xbc & 3;
  uVar10 = *(uint *)(uVar11 + 0xbc & 0xfffffffc);
  uVar10 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
  uVar8 = uVar11 + 0xc0 & 3;
  uVar13 = *(uint *)(uVar11 + 0xc0 & 0xfffffffc);
  lVar4 = (ulonglong)((uint)uVar14 - uVar10) * 64000;
  uVar7 = _ll_udiv((int)lVar4,
                   ((int)((ulonglong)uVar14 >> 0x20) -
                   ((uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20) +
                   (uint)((uint)uVar14 < uVar10))) * 64000 + (int)((ulonglong)lVar4 >> 0x20),
                   uRam02037844);
  *(undefined4 *)(uVar11 + 0xcc) = uVar7;
  uVar8 = uRam0203783c;
  if ((bVar5) &&
     (uVar12 = 0,
     *(short *)(*(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
               *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20) != 0)) {
    do {
      WaitForIRQ(1,1);
      uVar10 = uVar8 & 3;
      uVar11 = *(uint *)(uVar8 & 0xfffffffc);
      uVar12 = uVar12 + 1;
    } while (uVar12 < *(ushort *)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20));
  }
  uVar8 = *(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
          *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20;
  *(byte *)(uVar8 + 0xd8) = *(byte *)(uVar8 + 0xd8) | 1;
  uVar14 = Os_GetTick();
  iVar6 = iRam02037834;
  *(undefined8 *)
   ((*(uint *)(uRam0203783c & 0xfffffffc) >> (uRam0203783c & 3) * 8 |
    *(uint *)(uRam0203783c & 0xfffffffc) << (uRam0203783c & 3) * -8 + 0x20) + 0xc4) = uVar14;
  if (sVar2 != *(short *)(iVar6 + 8)) {
    SetBrightness(uRam02037848);
  }
  if (sVar3 != *(short *)(iRam02037838 + 8)) {
    SetBrightness(uRam0203784c);
  }
  pcVar9 = (code *)(*(uint *)(uRam02037830 & 0xfffffffc) >> (uRam02037830 & 3) * 8 |
                   *(uint *)(uRam02037830 & 0xfffffffc) << (uRam02037830 & 3) * -8 + 0x20);
  if (pcVar9 == (code *)0x0) {
    return;
  }
  (*pcVar9)(2);
  return;
}

