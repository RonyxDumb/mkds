/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_ov001_021a9b8c data_ov001_021a9b8c
#define func_020c092c SDK_data_020c092c
extern void *data_ov001_021a9b8c;
extern void func_020c092c(void *a0, void *a1, int a2);

void func_ov001_021813f4(void *a0) {
    func_020c092c(a0, data_ov001_021a9b8c, 0);
}
