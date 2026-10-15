/* C reconstructed from reference ARM instructions; full local bytes verified.
 * No whole-ROM or global ABI equivalence claim. */
struct EmblemNameEntry {
    unsigned name;
    unsigned other[2];
};
extern struct EmblemNameEntry Menu_EmblemNamesCustom[];
extern struct EmblemNameEntry Menu_EmblemNamesCharacter[];

unsigned FormatCharacterEmblemName(int i, int which)
{
    if (which)
        return Menu_EmblemNamesCustom[i].name;
    else
        return Menu_EmblemNamesCharacter[i].name;
}
