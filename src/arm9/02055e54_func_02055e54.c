/* Decompiled C draft; module arm9; ROM address 02055e54. No matching claim. */
#include "types.h"
#include "deps/02055e54_func_02055e54.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_02055e54(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  func_02148fc8();
  func_02148fb4();
  bVar4 = (*(ushort *)
            ((*(uint *)(uRam02055f54 & 0xfffffffc) >> (uRam02055f54 & 3) * 8 |
             *(uint *)(uRam02055f54 & 0xfffffffc) << (uRam02055f54 & 3) * -8 + 0x20) + 8) & 1) == 0;
  if (bVar4) {
    _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | 0x300;
    *puRam02055f58 =
         (*(uint *)((uint)puRam02055f58 & 0xfffffffc) >> ((uint)puRam02055f58 & 3) * 8 |
         *(uint *)((uint)puRam02055f58 & 0xfffffffc) << ((uint)puRam02055f58 & 3) * -8 + 0x20) &
         0xffffe0ff | 0x400;
    func_0214922c(4);
    GX_SetBankForLCDC(8);
    iVar3 = 3;
    uVar2 = *(uint *)(uRam02055f54 & 0xfffffffc) >> (uRam02055f54 & 3) * 8 |
            *(uint *)(uRam02055f54 & 0xfffffffc) << (uRam02055f54 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 8) = *(ushort *)(uVar2 + 8) | 1;
  }
  else {
    _DAT_04000000 = _DAT_04000000 & 0xffffe0ff | 0x300;
    *puRam02055f58 =
         (*(uint *)((uint)puRam02055f58 & 0xfffffffc) >> ((uint)puRam02055f58 & 3) * 8 |
         *(uint *)((uint)puRam02055f58 & 0xfffffffc) << ((uint)puRam02055f58 & 3) * -8 + 0x20) &
         0xffffe0ff | 0x1000;
    GX_SetBankForLCDC(4);
    func_021491b0(8);
    iVar3 = 2;
    uVar2 = *(uint *)(uRam02055f54 & 0xfffffffc) >> (uRam02055f54 & 3) * 8 |
            *(uint *)(uRam02055f54 & 0xfffffffc) << (uRam02055f54 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 8) = *(ushort *)(uVar2 + 8) & 0xfffe;
  }
  puVar1 = puRam02055f64;
  uVar2 = uRam02055f60 | iVar3 << 0x10;
  *puRam02055f5c = *puRam02055f5c & 0x7fff | (ushort)!bVar4 << 0xf;
  *puVar1 = uVar2;
  return;
}

