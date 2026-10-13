/* Decompiled C draft; module arm9; ROM address 02142ab8. No matching claim. */
#include "types.h"
#include "deps/02142ab8_WM_SomeFn.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 WM_SomeFn(ushort param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  ushort *apuStack_20 [2];
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar2 = Os_ReceiveMessage(uRam02142c04,(uint *)(void *)(apuStack_20),0);
  if (iVar2 == 0) {
    return 8;
  }
  DC_InvalidateRangeNoClean((uint)(uintptr_t)(apuStack_20[0]),2);
  if ((*apuStack_20[0] & 0x8000) != 0) {
    if ((short)uStack_c == 0) {
      uVar3 = (*(uint *)(uRam02142c08 & 0xfffffffc) >> (uRam02142c08 & 3) * 8 |
              *(uint *)(uRam02142c08 & 0xfffffffc) << (uRam02142c08 & 3) * -8 + 0x20) + 0xc;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      DC_SomeClean(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0x100);
      DC_InvalidateRangeNoClean((uint)(uintptr_t)(apuStack_20[0]),0x100);
      uVar6 = *(uint *)(uRam02142c08 & 0xfffffffc) >> (uRam02142c08 & 3) * 8 |
              *(uint *)(uRam02142c08 & 0xfffffffc) << (uRam02142c08 & 3) * -8 + 0x20;
      uVar3 = uVar6 + 0xc;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      MI_DmaCopy32(*(undefined2 *)(uVar6 + 0x14),uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,
                   (undefined4)(uintptr_t)(apuStack_20[0]),0x100);
    }
    puVar4 = &uStack_c;
    *apuStack_20[0] = param_1;
    iVar2 = 0;
    if ((uStack_c & 0xffff) != 0) {
      do {
        puVar4 = puVar4 + 1;
        iVar7 = iVar2 + 1;
        *(uint *)(apuStack_20[0] + iVar2 * 2 + 2) = *puVar4;
        iVar2 = iVar7;
      } while (iVar7 < (int)(uStack_c & 0xffff));
    }
    DC_SomeClean((uint)(uintptr_t)(apuStack_20[0]),0x100);
    iVar2 = Fifo_SendWord(10,(int)(uintptr_t)(apuStack_20[0]),0);
    Os_MessageQueue_Send(uRam02142c04,(undefined4)(uintptr_t)(apuStack_20[0]),1);
    if (iVar2 < 0) {
      uVar5 = 8;
    }
    else {
      uVar5 = 2;
    }
    return uVar5;
  }
  OS_JamMessage(uRam02142c04,(undefined4)(uintptr_t)(apuStack_20[0]),1);
  return 8;
}

