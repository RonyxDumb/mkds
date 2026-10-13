/* Decompiled C draft; module arm9_ov000; ROM address 0218e5e4. No matching claim. */
#include "types.h"
#include "deps/0218e5e4_FUN_0218e5e4.h"

undefined4 * FUN_0218e5e4(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = DAT_0218e634;
  *DAT_0218e634 = DAT_0218e630;
  puVar1[1] = DAT_0218e638;
  *(undefined2 *)(puVar1 + 2) = 2;
  *(undefined2 *)((int)puVar1 + 10) = 0;
  puVar1[3] = DAT_0218e63c;
  *DAT_0218e640 = 0;
  uVar2 = FUN_021a8830();
  FUN_021a8bb0(uVar2,(undefined1 *)(void *)(DAT_0218e640));
  puVar1 = DAT_0218e63c;
  if (*DAT_0218e640 == 0) {
    return (undefined4 *)0x0;
  }
  *DAT_0218e63c = DAT_0218e640;
  puVar3 = DAT_0218e634;
  *(undefined2 *)((int)DAT_0218e634 + 10) = 4;
  puVar1[1] = 0;
  return puVar3;
}

