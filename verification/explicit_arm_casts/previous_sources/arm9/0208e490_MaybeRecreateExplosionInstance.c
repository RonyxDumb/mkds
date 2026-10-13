/* Decompiled C draft; module arm9; ROM address 0208e490. No matching claim. */
#include "types.h"
#include "deps/0208e490_MaybeRecreateExplosionInstance.h"

int MaybeRecreateExplosionInstance(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = IntrusiveListWrapper_GetAtIndex
                    ((*(uint *)(uRam0208e56c & 0xfffffffc) >> (uRam0208e56c & 3) * 8 |
                     *(uint *)(uRam0208e56c & 0xfffffffc) << (uRam0208e56c & 3) * -8 + 0x20) + 0xc +
                     param_1 * 0xc,0);
  if (iVar1 != 0) {
    IntrusiveListWrapper_RemoveItem
              ((*(uint *)(uRam0208e56c & 0xfffffffc) >> (uRam0208e56c & 3) * 8 |
               *(uint *)(uRam0208e56c & 0xfffffffc) << (uRam0208e56c & 3) * -8 + 0x20) + 0xc +
               param_1 * 0xc,iVar1);
    *(undefined4 *)(iVar1 + 0x88) = 0;
    uVar3 = param_2[1];
    uVar4 = param_2[2];
    *(undefined4 *)(iVar1 + 0x74) = *param_2;
    *(undefined4 *)(iVar1 + 0x78) = uVar3;
    *(undefined4 *)(iVar1 + 0x7c) = uVar4;
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    uVar2 = uRam0208e56c;
    *(undefined4 *)(iVar1 + 0xac) = 0;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    *(undefined2 *)(iVar1 + 0xb0) =
         *(undefined2 *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x5c);
    *(undefined4 *)(iVar1 + 0xb4) = 1;
    uVar5 = iVar1 + 0x80U & 3;
    uVar2 = *(uint *)(iVar1 + 0x80U & 0xfffffffc);
    (*(code *)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20))(iVar1,param_3);
    IntrusiveListWrapper_InsertLast
              (*(uint *)(uRam0208e56c & 0xfffffffc) >> (uRam0208e56c & 3) * 8 |
               *(uint *)(uRam0208e56c & 0xfffffffc) << (uRam0208e56c & 3) * -8 + 0x20,iVar1);
    uVar2 = uRam0208e56c;
    uVar5 = *(uint *)(uRam0208e56c & 0xfffffffc) >> (uRam0208e56c & 3) * 8 |
            *(uint *)(uRam0208e56c & 0xfffffffc) << (uRam0208e56c & 3) * -8 + 0x20;
    *(short *)(uVar5 + 0x5c) = *(short *)(uVar5 + 0x5c) + 1;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    if (0xd < *(ushort *)(uVar5 + 0x5c)) {
      *(undefined2 *)(uVar5 + 0x5c) = 10;
    }
  }
  return iVar1;
}

