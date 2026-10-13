/* Decompiled C draft; module arm9; ROM address 0208e400. No matching claim. */
#include "types.h"
#include "deps/0208e400_UpdateExplosionInstances.h"

void UpdateExplosionInstances(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = IntrusiveListWrapper_NextItem
                    (*(uint *)(uRam0208e48c & 0xfffffffc) >> (uRam0208e48c & 3) * 8 |
                     *(uint *)(uRam0208e48c & 0xfffffffc) << (uRam0208e48c & 3) * -8 + 0x20,0);
  uVar2 = uRam0208e48c;
  if (iVar3 == 0) {
    return;
  }
  do {
    uVar1 = iVar3 + 0x84U & 3;
    uVar4 = *(uint *)(iVar3 + 0x84U & 0xfffffffc);
    (*(code *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))(iVar3);
    uVar1 = iVar3 + 0xa8U & 3;
    uVar4 = *(uint *)(iVar3 + 0xa8U & 0xfffffffc);
    *(uint *)(iVar3 + 0xa8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 1;
    uVar1 = iVar3 + 0x88U & 3;
    uVar4 = *(uint *)(iVar3 + 0x88U & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 1) {
      IntrusiveListWrapper_RemoveItem
                ((uint *)(uintptr_t)(*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20),iVar3);
      uVar1 = iVar3 + 0x8cU & 3;
      uVar4 = *(uint *)(iVar3 + 0x8cU & 0xfffffffc);
      IntrusiveListWrapper_InsertLast
                ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * 0xc +
                 (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xc,iVar3);
    }
    iVar3 = IntrusiveListWrapper_NextItem
                      (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                       *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20,iVar3);
  } while (iVar3 != 0);
  return;
}

