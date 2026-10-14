/* Decompiled C draft; module arm9; ROM address 020152bc. No matching claim. */
#include "types.h"
#include "deps/020152bc_Anim_CreateBlock_BCA.h"

void Anim_CreateBlock_BCA(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = uRam02015354;
  *(int *)(param_1 + 8) = param_2;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  *(undefined1 *)(param_1 + 0x19) = *(undefined1 *)(param_3 + 0x17);
  Mem_CpuFill16(0,param_1 + 0x1a,(uint)*(byte *)(param_1 + 0x19) << 1);
  uVar5 = 0;
  if (*(short *)(param_2 + 6) != 0) {
    do {
      iVar1 = uVar5 * 2;
      iVar2 = uVar5 * 2;
      uVar5 = uVar5 + 1;
      uVar4 = param_2 + (uint)*(ushort *)(param_2 + 0x14 + iVar1);
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      *(ushort *)(param_1 + iVar2 + 0x1a) =
           (byte)((byte)((uVar4 >> uVar3 * 8) >> 0x18) |
                 (byte)((uVar4 << uVar3 * -8 + 0x20) >> 0x18)) | 0x100;
    } while (uVar5 < *(ushort *)(param_2 + 6));
    return;
  }
  return;
}

