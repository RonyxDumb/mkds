/* Decompiled C draft; module arm9; ROM address 02005314. No matching claim. */
#include "types.h"
#include "deps/02005314_Fs_OverlayInfo_Start.h"

void Fs_OverlayInfo_Start(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  iVar1 = Fs_OverlayInfo_GetBinarySize();
  if (*psRam02005404 == 2) {
    iVar2 = 0;
    if (((*(byte *)(param_1 + 0x1f) & 2) != 0) &&
       (uVar7 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
       uVar7 < (uint)((int)((longlong)iRam02005410 * (longlong)(iRam02005408 - iRam0200540c) >> 0x23
                           ) - (iRam02005408 - iRam0200540c >> 0x1f)))) {
      uVar3 = param_1 + 4 & 3;
      uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
      iVar2 = Fs_ComputeCompareDigest
                        (uVar7 * 0x14 + iRam0200540c,uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20
                         ,iVar1);
    }
    if (iVar2 == 0) {
      uVar7 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      Mem_CpuFill8((uint *)(uintptr_t)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20),0,iVar1);
      Os_Terminate();
      return;
    }
  }
  if ((*(byte *)(param_1 + 0x1f) & 1) != 0) {
    uVar7 = param_1 + 4 & 3;
    uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
    Crt0_DecompressFlushCode((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + iVar1);
  }
  uVar7 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  Arm_FlushRange(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,
                 uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
  uVar7 = param_1 + 0x10 & 3;
  uVar3 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar5 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 0x14 & 3;
  uVar3 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
  if (uVar5 < uVar7) {
    do {
      pcVar4 = (code *)(*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                       *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)();
      }
      uVar5 = uVar5 + 4;
    } while (uVar5 < uVar7);
    return;
  }
  return;
}

