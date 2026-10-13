/* Decompiled C draft; module arm9; ROM address 0208fd8c. No matching claim. */
#include "types.h"
#include "deps/0208fd8c_func_0208fd8c.h"

void func_0208fd8c(int param_1,int param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = pcRam0208fdc8;
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam0208fdc0 & 0xfffffffc) >> (uRam0208fdc0 & 3) * 8 |
          *(uint *)(uRam0208fdc0 & 0xfffffffc) << (uRam0208fdc0 & 3) * -8 + 0x20) + 0x58;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xc +
       (*(uint *)(uRam0208fdc4 & 0xfffffffc) >> (uRam0208fdc4 & 3) * 8 |
       *(uint *)(uRam0208fdc4 & 0xfffffffc) << (uRam0208fdc4 & 3) * -8 + 0x20);
                    /* WARNING: Could not recover jumptable at 0x0208fdbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

