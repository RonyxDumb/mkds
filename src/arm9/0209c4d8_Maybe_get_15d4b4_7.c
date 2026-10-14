/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0215d4b4 SDK_data_0215d4b4
#define Maybe_get_15d4b4 Maybe_get_15d4b4_7
typedef short s16;

extern const s16 data_0215d4b4[];

s16 Maybe_get_15d4b4(int idx) {
    return data_0215d4b4[(idx >> 4) << 1];
}
