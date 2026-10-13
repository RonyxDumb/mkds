/* Decompiled C draft; module arm9_ov000; ROM address 021ae3a4. No matching claim. */
#include "types.h"
#include "deps/021ae3a4_FUN_021ae3a4.h"

void FUN_021ae3a4(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_18 [2];
  
  uVar2 = DAT_021ae3ec;
  uVar1 = DAT_021ae3e8;
  do {
    iVar3 = FUN_021afdcc(local_18);
    if (0x22 < local_18[0]) {
      uVar4 = (int)(uint)*(ushort *)(iVar3 + 0xc) >> 8 | (*(ushort *)(iVar3 + 0xc) & 0xff) << 8;
      if (uVar4 == uVar1) {
        FUN_021ae3f0((byte *)(uintptr_t)(iVar3 + 0xe),local_18[0] - 0xe);
      }
      else if (uVar4 == uVar2) {
        FUN_021af3e8((ushort *)(uintptr_t)(iVar3 + 0xe),local_18[0] - 0xe);
      }
    }
    FUN_021afd8c();
  } while( true );
}

