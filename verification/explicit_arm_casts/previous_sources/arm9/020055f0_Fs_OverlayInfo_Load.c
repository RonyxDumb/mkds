/* Decompiled C draft; module arm9; ROM address 020055f0. No matching claim. */
#include "types.h"
#include "deps/020055f0_Fs_OverlayInfo_Load.h"

undefined4 Fs_OverlayInfo_Load(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [36];
  int iStack_34;
  int iStack_30;
  
  uVar1 = uRam020056f0;
  if (param_2 != 0) {
    uVar1 = uRam020056f4;
  }
  uVar5 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    uVar1 = uRam020056f8 + 4 & 3;
    uVar4 = *(uint *)(uRam020056f8 + 4 & 0xfffffffc);
    uVar5 = uRam020056fc + 4 & 3;
    uVar6 = *(uint *)(uRam020056fc + 4 & 0xfffffffc);
    uVar3 = Fs_OverlayInfo_DoLoad
                      (param_1,param_2,param_3,uRam02005700,
                       *(uint *)(uRam020056f8 & 0xfffffffc) >> (uRam020056f8 & 3) * 8 |
                       *(uint *)(uRam020056f8 & 0xfffffffc) << (uRam020056f8 & 3) * -8 + 0x20,
                       uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
                       *(uint *)(uRam020056fc & 0xfffffffc) >> (uRam020056fc & 3) * 8 |
                       *(uint *)(uRam020056fc & 0xfffffffc) << (uRam020056fc & 3) * -8 + 0x20,
                       uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    return uVar3;
  }
  uVar4 = uVar1 + 4 & 3;
  uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc);
  if ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) <= (uint)(param_3 * 0x20)) {
    return 0;
  }
  Mem_CpuCopy8(uVar5 + param_3 * 0x20,param_1,0x20);
  *(int *)(param_1 + 0x20) = param_2;
  Fs_File_Initialize(auStack_58);
  Fs_GetOverlayFileId(&uStack_60,param_1);
  iVar2 = Fs_File_OpenById(auStack_58,uStack_60,uStack_5c);
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(param_1 + 0x24) = iStack_34;
  *(int *)(param_1 + 0x28) = iStack_30 - iStack_34;
  Fs_File_Close(auStack_58);
  return 1;
}

