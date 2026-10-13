/* Decompiled C draft; module arm9; ROM address 0208d978. No matching claim. */
#include "types.h"
#include "deps/0208d978_func_0208d978.h"

void func_0208d978(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  if (*(short *)(iRam0208da88 + 0x58) != 0) {
    uVar6 = 0;
    if ((param_2 != 0) &&
       (iVar1 = IntrusiveListWrapper_GetAtIndex
                          ((*(uint *)(uRam0208da8c & 0xfffffffc) >> (uRam0208da8c & 3) * 8 |
                           *(uint *)(uRam0208da8c & 0xfffffffc) << (uRam0208da8c & 3) * -8 + 0x20) +
                           0x24,0), iVar1 != 0)) {
      IntrusiveListWrapper_RemoveItem
                ((uint *)(uintptr_t)((*(uint *)(uRam0208da8c & 0xfffffffc) >> (uRam0208da8c & 3) * 8 |
                 *(uint *)(uRam0208da8c & 0xfffffffc) << (uRam0208da8c & 3) * -8 + 0x20) + 0x24),
                 iVar1);
      *(undefined4 *)(iVar1 + 0x88) = 0;
      uVar3 = param_1[1];
      uVar4 = param_1[2];
      *(undefined4 *)(iVar1 + 0x74) = *param_1;
      *(undefined4 *)(iVar1 + 0x78) = uVar3;
      *(undefined4 *)(iVar1 + 0x7c) = uVar4;
      *(undefined4 *)(iVar1 + 0xa8) = 0;
      uVar2 = uRam0208da8c;
      *(undefined4 *)(iVar1 + 0xac) = 0;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      *(undefined2 *)(iVar1 + 0xb0) =
           *(undefined2 *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x5c);
      *(undefined4 *)(iVar1 + 0xb4) = 1;
      uVar5 = iVar1 + 0x80U & 3;
      uVar2 = *(uint *)(iVar1 + 0x80U & 0xfffffffc);
      (*(code *)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20))(iVar1,0);
      IntrusiveListWrapper_InsertLast
                (*(uint *)(uRam0208da8c & 0xfffffffc) >> (uRam0208da8c & 3) * 8 |
                 *(uint *)(uRam0208da8c & 0xfffffffc) << (uRam0208da8c & 3) * -8 + 0x20,iVar1);
      uVar2 = uRam0208da8c;
      uVar5 = *(uint *)(uRam0208da8c & 0xfffffffc) >> (uRam0208da8c & 3) * 8 |
              *(uint *)(uRam0208da8c & 0xfffffffc) << (uRam0208da8c & 3) * -8 + 0x20;
      *(short *)(uVar5 + 0x5c) = *(short *)(uVar5 + 0x5c) + 1;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
      if (0xd < *(ushort *)(uVar5 + 0x5c)) {
        *(undefined2 *)(uVar5 + 0x5c) = 10;
      }
    }
    do {
      uVar5 = iRam0208da90 + uVar6 * 4;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      if (-1 < (int)uVar5) {
        func_0208b7bc(uVar5,(uint)(uintptr_t)(param_1));
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 2);
    return;
  }
  return;
}

