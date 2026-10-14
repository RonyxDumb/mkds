/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */

extern void Mem_CpuFastMemorySet(void *dst, int val);

void Maybe_call_Mem_CpuFastMemorySet(int val, void *dst) {
    void *volatile d = dst;
    Mem_CpuFastMemorySet(d, val);
}
