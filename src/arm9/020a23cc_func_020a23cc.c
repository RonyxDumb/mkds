/* Decompiled C draft; module arm9; ROM address 020a23cc. No matching claim. */
#include "types.h"
#include "deps/020a23cc_func_020a23cc.h"

void func_020a23cc(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_98 [36];
  undefined1 auStack_74 [36];
  undefined1 auStack_50 [36];
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar3 = *(uint *)(uRam020a254c & 0xfffffffc) >> (uRam020a254c & 3) * 8 |
          *(uint *)(uRam020a254c & 0xfffffffc) << (uRam020a254c & 3) * -8 + 0x20;
  if (*(ushort *)(uVar3 + 2) < 3) {
    func_0208b870(uVar3 + 0xcc);
    func_02011034();
    func_01ff9048(0x15,0,0);
    uStack_2c = 0x1000;
    uStack_28 = 0x1000;
    uStack_24 = 0x1000;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_2c),3);
    uStack_20 = 0;
    uStack_1c = 0xffffff33;
    uStack_18 = 0xffffe000;
    func_01ff9048(0x1c,(undefined4)(uintptr_t)(&uStack_20),3);
    uVar3 = (*(uint *)(uRam020a254c & 0xfffffffc) >> (uRam020a254c & 3) * 8 |
            *(uint *)(uRam020a254c & 0xfffffffc) << (uRam020a254c & 3) * -8 + 0x20) + 0xc;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    MTX_RotX33__from_thumb
              ((undefined4 *)(void *)(auStack_98),(int)*(short *)(iRam020a2550 + 0xec),(int)*(short *)(iRam020a2550 + 0xee))
    ;
    iVar1 = (int)(uint)*(ushort *)
                        ((*(uint *)(uRam020a254c & 0xfffffffc) >> (uRam020a254c & 3) * 8 |
                         *(uint *)(uRam020a254c & 0xfffffffc) << (uRam020a254c & 3) * -8 + 0x20) + 4
                        ) >> 4;
    MTX_RotY33__from_thumb
              ((undefined4 *)(void *)(auStack_74),(int)*(short *)(iRam020a2554 + iVar1 * 4),
               (int)*(short *)(iRam020a2554 + (iVar1 * 2 + 1) * 2));
    iVar1 = (int)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xffff) >> 4;
    MTX_RotZ33__from_thumb
              ((undefined4 *)(void *)(auStack_50),(int)*(short *)(iRam020a2554 + iVar1 * 4),
               (int)*(short *)(iRam020a2554 + (iVar1 * 2 + 1) * 2));
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_98),9);
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_74),9);
    func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_50),9);
    uStack_14 = 0;
    uStack_10 = 0;
    uStack_c = 0;
    func_01ff9048(0x1c,(undefined4)(uintptr_t)(&uStack_14),3);
    func_020849d0((*(uint *)(uRam020a254c & 0xfffffffc) >> (uRam020a254c & 3) * 8 |
                  *(uint *)(uRam020a254c & 0xfffffffc) << (uRam020a254c & 3) * -8 + 0x20) + 0x28);
    func_01ff9234();
    return;
  }
  return;
}

