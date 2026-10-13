/* Decompiled C draft; module arm9; ROM address 020458cc. No matching claim. */
#include "types.h"
#include "deps/020458cc_func_020458cc.h"

void func_020458cc(void)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = pcRam0204590c;
  uVar2 = (*(uint *)(uRam02045908 & 0xfffffffc) >> (uRam02045908 & 3) * 8 |
          *(uint *)(uRam02045908 & 0xfffffffc) << (uRam02045908 & 3) * -8 + 0x20) + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1d) < 0) {
    *(undefined4 *)
     ((*(uint *)(uRam02045910 & 0xfffffffc) >> (uRam02045910 & 3) * 8 |
      *(uint *)(uRam02045910 & 0xfffffffc) << (uRam02045910 & 3) * -8 + 0x20) + 500) = 0;
  }
  else {
    *(undefined4 *)
     ((*(uint *)(uRam02045910 & 0xfffffffc) >> (uRam02045910 & 3) * 8 |
      *(uint *)(uRam02045910 & 0xfffffffc) << (uRam02045910 & 3) * -8 + 0x20) + 500) = 4;
  }
                    /* WARNING: Could not recover jumptable at 0x02045904. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

