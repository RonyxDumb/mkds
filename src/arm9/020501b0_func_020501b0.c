/* Decompiled C draft; module arm9; ROM address 020501b0. No matching claim. */
#include "types.h"
#include "deps/020501b0_func_020501b0.h"

undefined4 func_020501b0(uint param_1)

{
  undefined1 uVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar4 = uRam020502f8;
  uVar3 = 0;
  if (param_1 < 4) {
    uVar5 = *(uint *)(uRam020502f8 & 0xfffffffc) >> (uRam020502f8 & 3) * 8 |
            *(uint *)(uRam020502f8 & 0xfffffffc) << (uRam020502f8 & 3) * -8 + 0x20;
    if ((*(ushort *)(uVar5 + 0x454) & 0x40) == 0) {
      *(undefined1 *)(uVar5 + 0x43b) = 0;
      *(undefined1 *)
       ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
        *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x438) = 0;
      uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      iVar6 = param_1 * 0xe0 + uVar5 + 0xac;
      *(ushort *)(uVar5 + 0x436) = *(ushort *)(uVar5 + 0x436) & 0xfffe;
      if ((int)((uint)*(byte *)(iVar6 + 0xdc) << 0x1f) < 0) {
        uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x24;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        Mem_CpuCopy8((ushort *)(uintptr_t)(iVar6),(uint *)(uintptr_t)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20),0xc0);
        uVar4 = (*(uint *)(uRam020502f8 & 0xfffffffc) >> (uRam020502f8 & 3) * 8 |
                *(uint *)(uRam020502f8 & 0xfffffffc) << (uRam020502f8 & 3) * -8 + 0x20) + 0x24;
        uVar5 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        DC_SomeClean(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,0xc0);
        uVar1 = *(undefined1 *)(iVar6 + 0xc1);
        uVar4 = *(uint *)(uRam020502f8 & 0xfffffffc) >> (uRam020502f8 & 3) * 8 |
                *(uint *)(uRam020502f8 & 0xfffffffc) << (uRam020502f8 & 3) * -8 + 0x20;
        uVar3 = 1;
        *(undefined1 *)(uVar4 + 0x42c) = *(undefined1 *)(iVar6 + 0xc0);
        *(undefined1 *)(uVar4 + 0x42d) = uVar1;
        uVar1 = *(undefined1 *)(iVar6 + 0xc3);
        *(undefined1 *)(uVar4 + 0x42e) = *(undefined1 *)(iVar6 + 0xc2);
        *(undefined1 *)(uVar4 + 0x42f) = uVar1;
        uVar1 = *(undefined1 *)(iVar6 + 0xc5);
        *(undefined1 *)(uVar4 + 0x430) = *(undefined1 *)(iVar6 + 0xc4);
        *(undefined1 *)(uVar4 + 0x431) = uVar1;
        *(byte *)(uVar4 + 0x43c) = (byte)(((uint)*(byte *)(iVar6 + 0xdc) << 0x1b) >> 0x1c);
      }
    }
    else {
      if (uVar5 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      }
      bVar2 = false;
      if (((uVar4 == 2) && (bVar2 = false, *psRam020502fc != 2)) &&
         ((int)((uint)*(byte *)(param_1 * 0xe0 + uVar5 + 0x188) << 0x1f) < 0)) {
        bVar2 = true;
      }
      if (bVar2) {
        func_0204e074();
        uVar3 = 1;
      }
    }
    return uVar3;
  }
  return 0;
}

