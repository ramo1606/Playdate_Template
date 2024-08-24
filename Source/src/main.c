#include <stdio.h>
#include "pd_api.h"

static int update(void* userdata);

int eventHandler(PlaydateAPI* pd, PDSystemEvent event, uint32_t arg)
{
    (void)arg; // unused

    if (event == kEventInit)
    {
        pd->system->setUpdateCallback(update, pd);
    }

    return 0;
}

static int update(void* userdata)
{
    PlaydateAPI* pd = userdata;
    pd->graphics->clear(kColorWhite);
    pd->graphics->drawText("Hello World!", strlen("Hello World!"), kASCIIEncoding, 10, 10);
    pd->system->drawFPS(0,0);

    return 1;
}