/* Decompiled C draft; module arm9_ov000; ROM address 021aec84. No matching claim. */
#include "types.h"
#include "deps/021aec84_FUN_021aec84.h"

void FUN_021aec84(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_021af090();
  if ((puVar1 != (undefined4 *)0x0) && (*(char *)(puVar1 + 2) == '\x02')) {
    func_0x0200dd94();
    puVar1[9] = (((int)(uint)*(ushort *)(param_2 + 4) >> 8 | (*(ushort *)(param_2 + 4) & 0xff) << 8)
                 << 0x10 |
                (int)(uint)*(ushort *)(param_2 + 6) >> 8 | (*(ushort *)(param_2 + 6) & 0xff) << 8) +
                1;
    puVar1[0xc] = ((int)(uint)*(ushort *)(param_2 + 8) >> 8 | (*(ushort *)(param_2 + 8) & 0xff) << 8
                  ) << 0x10 |
                  (int)(uint)*(ushort *)(param_2 + 10) >> 8 |
                  (*(ushort *)(param_2 + 10) & 0xff) << 8;
    *(ushort *)(puVar1 + 0xb) = *(ushort *)(param_2 + 0xe) >> 8 | *(ushort *)(param_2 + 0xe) << 8;
    FUN_021af030(param_2,(int)(uintptr_t)(puVar1));
    FUN_021aefb4((undefined4)(uintptr_t)(puVar1),(ushort)*(byte *)(param_1 + 5) * 0x100 + 6);
    *(undefined1 *)(puVar1 + 2) = 4;
    if (puVar1[1] == 1) {
      puVar1[1] = 0;
      func_0x0200df68(*puVar1);
    }
    return;
  }
  FUN_021aeed8(param_1,(ushort *)(uintptr_t)(param_2),param_3,(ushort)*(byte *)(param_1 + 5) * 0x100 + 5);
  return;
}

