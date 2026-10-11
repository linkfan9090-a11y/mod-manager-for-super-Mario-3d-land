
#include <3ds.h>
#include <stdio.h>

int main(void)
{
    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    int selected = 0;

    const char *menu[] = {
        "Browse mods",
        "Enable / disable",
        "Back up files",
        "Exit"
    };

    while (aptMainLoop()) {
        hidScanInput();
        u32 keys = hidKeysDown();

        if (keys & KEY_UP)
            selected = (selected + 3) % 4;

        if (keys & KEY_DOWN)
            selected = (selected + 1) % 4;

        if ((keys & KEY_A) && selected == 3)
            break;

        consoleClear();

        printf("SM3DL MOD MANAGER\n");
        printf("--------------------\n\n");

        for (int i = 0; i < 4; i++) {
            printf("%s %s\n",
                   i == selected ? ">" : " ",
                   menu[i]);
        }

        printf("\nD-pad: Navigate");
        printf("\nA: Select");
        printf("\n\nPrototype v0.1");
    }

    gfxExit();
    return 0;
}
