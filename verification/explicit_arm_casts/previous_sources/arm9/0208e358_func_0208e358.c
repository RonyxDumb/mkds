/* Decompiled C draft; module arm9; ROM address 0208e358. No matching claim. */
#include "types.h"
#include "deps/0208e358_func_0208e358.h"

void func_0208e358(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_40 [36];
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  Matrix4x3_Identity(auStack_40);
  iVar3 = IntrusiveListWrapper_NextItem
                    (*(uint *)(uRam0208e3fc & 0xfffffffc) >> (uRam0208e3fc & 3) * 8 |
                     *(uint *)(uRam0208e3fc & 0xfffffffc) << (uRam0208e3fc & 3) * -8 + 0x20,0);
  uVar2 = uRam0208e3fc;
  if (iVar3 == 0) {
    return;
  }
  do {
    uVar1 = iVar3 + 0xb4U & 3;
    uVar4 = *(uint *)(iVar3 + 0xb4U & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
      uVar1 = iVar3 + 0x74U & 3;
      uVar4 = *(uint *)(iVar3 + 0x74U & 0xfffffffc);
      iStack_1c = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
      uVar1 = iVar3 + 0x78U & 3;
      uVar4 = *(uint *)(iVar3 + 0x78U & 0xfffffffc);
      iStack_18 = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
      uVar1 = iVar3 + 0x7cU & 3;
      uVar4 = *(uint *)(iVar3 + 0x7cU & 0xfffffffc);
      iStack_14 = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
      Model_Render(iVar3 + 8,*(undefined2 *)(iVar3 + 0xb0));
      func_020849f8(iVar3 + 8,auStack_40,iVar3 + 0x9c);
    }
    uVar1 = uVar2 & 3;
    uVar4 = *(uint *)(uVar2 & 0xfffffffc);
    iVar3 = IntrusiveListWrapper_NextItem(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,iVar3);
  } while (iVar3 != 0);
  return;
}

