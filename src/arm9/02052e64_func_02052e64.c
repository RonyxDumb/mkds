/* Decompiled C draft; module arm9; ROM address 02052e64. No matching claim. */
#include "types.h"
#include "deps/02052e64_func_02052e64.h"

void func_02052e64(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam02052ec8 & 0xfffffffc) >> (uRam02052ec8 & 3) * 8 |
          *(uint *)(uRam02052ec8 & 0xfffffffc) << (uRam02052ec8 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 0x24) {
    *(undefined4 *)(uVar4 + 0x10) = 0;
    return;
  }
  iVar3 = func_0204bcdc();
  if (iVar3 == 2) {
    *(undefined4 *)
     ((*(uint *)(uRam02052ec8 & 0xfffffffc) >> (uRam02052ec8 & 3) * 8 |
      *(uint *)(uRam02052ec8 & 0xfffffffc) << (uRam02052ec8 & 3) * -8 + 0x20) + 0x10) = 0;
    func_0204f5e4();
    return;
  }
  return;
}

