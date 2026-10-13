/* Decompiled C draft; module arm9; ROM address 0208ec64. No matching claim. */
#include "types.h"
#include "deps/0208ec64_func_0208ec64.h"

int func_0208ec64(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = IntrusiveListWrapper_GetAtIndex
                    ((*(uint *)(uRam0208ecd4 & 0xfffffffc) >> (uRam0208ecd4 & 3) * 8 |
                     *(uint *)(uRam0208ecd4 & 0xfffffffc) << (uRam0208ecd4 & 3) * -8 + 0x20) + 0xc,0
                    );
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x14) = param_1;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    uVar3 = uRam0208ecd4;
    *(undefined4 *)(iVar2 + 0x1c) = 0x400;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0xc),iVar2);
    IntrusiveListWrapper_InsertLast
              (*(uint *)(uRam0208ecd4 & 0xfffffffc) >> (uRam0208ecd4 & 3) * 8 |
               *(uint *)(uRam0208ecd4 & 0xfffffffc) << (uRam0208ecd4 & 3) * -8 + 0x20,iVar2);
  }
  return iVar2;
}

