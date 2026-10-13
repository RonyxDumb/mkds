/* Decompiled C draft; module arm9; ROM address 02079f70. No matching claim. */
#include "types.h"
#include "deps/02079f70_CharacterKartContext_SomeFn_1_0.h"

void CharacterKartContext_SomeFn_1_0(int param_1,int param_2,int param_3,int param_4)

{
  *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x6a) & 0x1f;
  *(ushort *)(param_1 + 0x76) = ((ushort)param_2 & 0x1f) - *(short *)(param_1 + 0x70);
  *(ushort *)(param_1 + 0x72) = (ushort)((int)(uint)*(ushort *)(param_1 + 0x6a) >> 5) & 0x1f;
  *(ushort *)(param_1 + 0x78) = ((ushort)(param_2 >> 5) & 0x1f) - *(short *)(param_1 + 0x72);
  *(ushort *)(param_1 + 0x74) = (ushort)((int)(uint)*(ushort *)(param_1 + 0x6a) >> 10) & 0x1f;
  *(ushort *)(param_1 + 0x7a) = ((ushort)(param_2 >> 10) & 0x1f) - *(short *)(param_1 + 0x74);
  *(ushort *)(param_1 + 0x7c) = *(ushort *)(param_1 + 0x6c) & 0x1f;
  *(ushort *)(param_1 + 0x82) = ((ushort)param_3 & 0x1f) - *(short *)(param_1 + 0x7c);
  *(ushort *)(param_1 + 0x7e) = (ushort)((int)(uint)*(ushort *)(param_1 + 0x6c) >> 5) & 0x1f;
  *(ushort *)(param_1 + 0x84) = ((ushort)(param_3 >> 5) & 0x1f) - *(short *)(param_1 + 0x7e);
  *(ushort *)(param_1 + 0x80) = (ushort)((int)(uint)*(ushort *)(param_1 + 0x6c) >> 10) & 0x1f;
  *(ushort *)(param_1 + 0x86) = ((ushort)(param_3 >> 10) & 0x1f) - *(short *)(param_1 + 0x80);
  *(ushort *)(param_1 + 0x88) = *(ushort *)(param_1 + 0x6e) & 0x1f;
  *(ushort *)(param_1 + 0x8e) = ((ushort)param_4 & 0x1f) - *(short *)(param_1 + 0x88);
  *(ushort *)(param_1 + 0x8a) = (ushort)((int)(uint)*(ushort *)(param_1 + 0x6e) >> 5) & 0x1f;
  *(ushort *)(param_1 + 0x90) = ((ushort)(param_4 >> 5) & 0x1f) - *(short *)(param_1 + 0x8a);
  *(ushort *)(param_1 + 0x8c) = (ushort)((int)(uint)*(ushort *)(param_1 + 0x6e) >> 10) & 0x1f;
  *(ushort *)(param_1 + 0x92) = ((ushort)(param_4 >> 10) & 0x1f) - *(short *)(param_1 + 0x8c);
  *(undefined2 *)(param_1 + 0x94) = 0;
  return;
}

