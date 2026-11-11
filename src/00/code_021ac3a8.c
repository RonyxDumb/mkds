#include "00/code_021ac3a8.h"

u32 ComputeSha1ScheduleWord(u32 index, u32 *words) {
    u32 mixed;
    mixed = words[index] ^ (words[(index + 2) & 0xf] ^ (words[(index + 13) & 0xf] ^ words[index ^ 8]));
    words[index] = (mixed << 1) | (mixed >> 31);
    return words[index];
}
