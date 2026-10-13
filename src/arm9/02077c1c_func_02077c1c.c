/* Decompiled C draft; module arm9; ROM address 02077c1c. No matching claim. */
#include "types.h"
#include "deps/02077c1c_func_02077c1c.h"

void func_02077c1c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  G3X_SetHOffset(*(undefined4 *)(*piRam02077d4c + 0x50));
  if (*(int *)(*piRam02077d50 + 0xf8) == 0) {
    iVar1 = *piRam02077d4c;
    iVar3 = iVar1 + iRam02077d54 + *(short *)(iVar1 + iRam02077d58) * 0x34;
    if (*(int *)(iVar3 + 0x2c) != 0) {
      piVar4 = *(int **)(iVar1 + 0x20);
      if (*(short *)(iVar3 + 0x30) == 0) {
        MaybeLoadWinModelTextureAnimationHelper_from_thumb
                  (*(undefined4 *)(iVar3 + 4),piVar4[4],piVar4[2],*(undefined4 *)(iVar3 + 8),
                   *(undefined4 *)(iVar3 + 0xc),*(undefined4 *)(iVar3 + 0x14));
        *(short *)(iVar3 + 0x30) = *(short *)(iVar3 + 0x30) + 1;
        return;
      }
      if (*(short *)(iVar3 + 0x30) == 1) {
        func_02078f78(*(undefined4 *)(iVar3 + 0x10));
        *(undefined4 *)(*(int *)(*piRam02077d4c + 0x20) + 0xb4) =
             *(undefined4 *)(*piRam02077d4c + iRam02077d5c);
        StructAD00Sh_SomeFn_1_from_thumb(piVar4[7],*(undefined4 *)(iVar3 + 0x28));
        func_02079014(piVar4[6],*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x24));
        *(short *)(iVar3 + 0x30) = *(short *)(iVar3 + 0x30) + 1;
        return;
      }
      Model_CreateFromNsbmdNsbtx2_from_thumb
                (piVar4[5],*(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c));
      StructCESub_SomeFn_from_thumb(*(undefined4 *)(*piRam02077d4c + 0x20));
      LoadKartBodyPalette_from_thumb
                (piVar4[5],piVar4[1],*(undefined4 *)(*piRam02077d4c + iRam02077d60));
      CharacterKart_PatchRobPalette_from_thumb(piVar4,1);
      *(undefined4 *)(iVar3 + 0x2c) = 0;
      *(undefined2 *)(iVar3 + 0x30) = 0;
      iVar1 = (int)*(short *)(*piRam02077d4c + iRam02077d64);
      if ((-1 < iVar1) &&
         (iVar3 = *piRam02077d4c + 0x58, iVar1 = iVar1 * 0xb8, *piVar4 == *(int *)(iVar3 + iVar1)))
      {
        iVar2 = piVar4[2];
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(*(int *)(iVar3 + iVar1 + 8) + 0xc);
        **(undefined4 **)(*(int *)(iVar2 + 0x1c) + (uint)*(ushort *)(iVar2 + 0x1a) * 4) =
             *(undefined4 *)(iVar2 + 0xc);
      }
      iVar1 = iRam02077d58;
      piVar4 = piRam02077d4c;
      *(undefined2 *)(*piRam02077d4c + iRam02077d64) =
           *(undefined2 *)(*piRam02077d4c + iRam02077d58);
      iVar3 = iRam02077d58;
      *(ushort *)(*piVar4 + iRam02077d58) = (ushort)(*(short *)(*piVar4 + iVar1) == 0);
      iVar1 = *piRam02077d4c;
      *(int *)(iVar1 + 0x20) = iVar1 + 0x58 + *(short *)(iVar1 + iVar3) * 0xb8;
    }
  }
  return;
}

