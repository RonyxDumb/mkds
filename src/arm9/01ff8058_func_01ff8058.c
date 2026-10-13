/* Decompiled C draft; module arm9; ROM address 01ff8058. No matching claim. */
#include "types.h"
#include "deps/01ff8058_func_01ff8058.h"

/* WARNING: Control flow encountered bad instruction data */

void func_01ff8058(uint param_1)

{
  short *psVar1;
  uint uVar2;
  undefined4 *puVar4;
  undefined4 *puVar5;
  code *pcVar6;
  uint uVar7;
  undefined4 uVar8;
  code *UNRECOVERED_JUMPTABLE_00;
  undefined4 in_stack_00000004;
  undefined4 in_stack_00000008;
  uint uVar3;
  
  uVar8 = 0;
  uVar7 = *(uint *)((uint)puRam01ff81a4 & 0xfffffffc) >> ((uint)puRam01ff81a4 & 3) * 8 |
          *(uint *)((uint)puRam01ff81a4 & 0xfffffffc) << ((uint)puRam01ff81a4 & 3) * -8 + 0x20;
  if (uVar7 != 0) {
    do {
      *(undefined4 *)(uVar7 + 100) = 1;
      *(undefined4 *)(uVar7 + 0x78) = 0;
      *(undefined4 *)(uVar7 + 0x7c) = 0;
      uVar3 = uVar7 + 0x80 & 3;
      uVar2 = *(uint *)(uVar7 + 0x80 & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      *(undefined4 *)(uVar7 + 0x80) = 0;
      puVar5 = puRam01ff81a4;
      uVar7 = uVar3;
    } while (uVar3 != 0);
    *puRam01ff81a4 = 0;
    puVar5[1] = 0;
    *psRam01ff81a8 = 1;
    param_1 = 0;
  }
  psVar1 = psRam01ff81a8;
                    /* WARNING: Could not recover jumptable at 0x01ff80b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  if (*psRam01ff81a8 != 0) {
    *psRam01ff81a8 = 0;
    uVar7 = (uint)(psVar1 + 4) & 3;
    uVar3 = *(uint *)((uint)(psVar1 + 4) & 0xfffffffc);
    puVar5 = (undefined4 *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
    while( true ) {
      if (puVar5 != (undefined4 *)0x0) {
        param_1 = (uint)*(ushort *)(puVar5 + 0x19);
      }
      if (puVar5 == (undefined4 *)0x0 || param_1 == 1) break;
      uVar7 = (uint)(puVar5 + 0x1a) & 3;
      uVar3 = *(uint *)((uint)(puVar5 + 0x1a) & 0xfffffffc);
      puVar5 = (undefined4 *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
    }
    if ((puVar5 != (undefined4 *)0x0) &&
       (uVar7 = (uint)(psVar1 + 2) & 3, uVar3 = *(uint *)((uint)(psVar1 + 2) & 0xfffffffc),
       puVar4 = (undefined4 *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20), puVar5 != puVar4))
    {
      uVar7 = (uint)(psVar1 + 6) & 3;
      uVar3 = *(uint *)((uint)(psVar1 + 6) & 0xfffffffc);
      pcVar6 = (code *)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20);
      if (pcVar6 != (code *)0x0) {
        (*pcVar6)();
      }
      *(undefined4 **)(psVar1 + 2) = puVar5;
      *puVar4 = uVar8;
      (*pcRam01ff81ac)(puVar4 + 0x12);
      puVar4[1] = in_stack_00000004;
      puVar4[2] = in_stack_00000008;
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
                    /* WARNING: Could not recover jumptable at 0x01ff80f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)();
    return;
  }
  (*UNRECOVERED_JUMPTABLE_00)();
  return;
}

