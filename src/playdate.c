#include "pd_api.h"

#include "playdate_gfx.h"
#include "playdate_input.h"
#include "playdate_sfx.h"
#include "playdate_sys.h"

PlaydateAPI* playdate;

#define SHOW_FPS 0

static int update(void* userdata);

int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
    (void)arg;

    if ( event == kEventInit )
    {
        playdate = pd;

        registerPlaydateSysFunctions(playdate);
        initPlaydateGraphics(playdate);
        initPlaydateSoundSource(playdate);

        doom_init(1, NULL, 0);

        playdate->system->setUpdateCallback(update, playdate);
    }

    return 0;
}

static int update(void* userdata)
{
    handleInputs(playdate);
    doom_update();
    refreshScreen();
#if SHOW_FPS
    playdate->system->drawFPS(0, 0);
#endif
    return 1;
}
