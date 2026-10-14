/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0217d130 SDK_data_0217b130
#define Sound_LoadGroup SDK_data_0209bbd0
#define LoadGroupById Maybe_get_17b130
extern void *data_0217d130;
extern void Sound_LoadGroup(void *a0, void *a1);
void LoadGroupById(void *a0) {
    Sound_LoadGroup(a0, data_0217d130);
}
