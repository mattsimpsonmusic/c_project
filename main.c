/* a simple two-player projectile game */

 #include <graphics_lib.h>
 #include <time.h>
 #include <math.h>
 #include <stdio.h>

/*------------ Defining Function Prototypes ------------*/
int button_x;
int button_y;
char button_colour[10];
char text[20];

void start_screen();
void ad();
void draw_button(button_x, button_y, button_colour, text);
void play_game_button();
void leaderboard_button();
void start_screen_commands();

void display_leaderboard();
void game();




/*------------ Main Function ------------*/
int main(void)
{

 /* initialise window and font*/
    GFX_InitWindow(700, 400);
    GFX_InitFont();

    /* create event queue for commands */
    GFX_CreateEventQueue();

    /* initialise mouse */
    GFX_InitMouse();
    GFX_RegisterMouseEvents();

    /* initialise keyboard */
    GFX_InitKeyboard();
    GFX_RegisterKeyboardEvents();


start_screen();

return 0;
}

/*------------ Other Functions ------------*/

/*----- inital screen function -----*/
void start_screen()
{

    /* set background colour blue */
    GFX_SetBackgroundColour(LIGHTCYAN);

    /* make sure window is cleared */
    GFX_ClearWindow();

    /* wet pen colour to green */
    GFX_SetColour(DARKGRAY);

    /* write welcome message */
    GFX_DrawText(35, 30, ("Hello! Thanks for waiting, one of our staff members will be with you"));
    GFX_DrawText(35, 40, ("shortly. In the meantime, please click below to play a game while you wait!"));

    /* put in ads at bottom of screen */
    ad();

    /* add play game button */
    play_game_button();

    /*add leaderboard button */
    leaderboard_button();

    /* write message to display */
    GFX_UpdateDisplay();

    start_screen_commands();



}

/* ad function */
void ad()
{

/* draw background for ads */
GFX_DrawFilledRectangle(0, 300, 700, 400, WHITE);

/* divide the ads into 2 */
GFX_DrawLine(350, 300, 350, 400, 2);

/* wrtie ad 1 */
GFX_DrawText(70, 340, "Your advertisment here!");

/* write ad 2 */
GFX_DrawText(430, 340, "Your advertisment here!");
}

/* button function */
void draw_button(button_x, button_y, button_colour, text)
{


/* draw circle of a certain colour */
GFX_DrawFilledCircle(button_x, button_y, 80, button_colour);

/* write text in middle of circle */
GFX_DrawText(button_x-40, button_y-10, text);

}

/* play game button function */
void play_game_button()
{

/* draw play game button */
draw_button(210, 170, LIGHTGRAY, "Play game");

}

/* leaderboard button function */
void leaderboard_button()
{

/* draw leaderboard button */
draw_button(500, 170, LIGHTRED, "Leaderboard");

}

/* function for user responses */
void start_screen_commands()
{

    int button_press;
    int mouse_x;
    int mouse_y;
    int key;
    int done;


    done = 0;
    while (!done)
    {
        GFX_WaitForEvent();

        if (GFX_IsEventMouseButton())
        {
            GFX_GetMouseButton(&button_press);
            if (button_press == MOUSE_BUTTON_LEFT)
            {
                GFX_GetMouseCoordinates(&mouse_x, &mouse_y);
                GFX_UpdateDisplay();
                if (mouse_x > 160 && mouse_x < 260 && mouse_y >110 && mouse_y < 230)
                {
                game();
                }
                else if (mouse_x > 440 && mouse_x < 560 && mouse_y >110 && mouse_y < 230)
                {
                display_leaderboard();
                }
            }
        }
    }

    /* shut down welcome screen */
    GFX_CloseWindow();

    return 0;
}


void display_leaderboard()
{

int button_press;
int mouse_x;
int mouse_y;
int go_back;

GFX_ClearWindow();
GFX_DrawFilledRectangle(160, 50, 510, 250, LIGHTGRAY);


GFX_SetColour(DARKGRAY);
GFX_DrawLine(160, 100, 510, 100, 3);
GFX_DrawLine(250, 50, 250, 250, 3);
GFX_DrawLine(390, 50, 390, 250, 3);


GFX_DrawText(188, 70, "Rank");
GFX_DrawText(285, 70, "Username");
GFX_DrawText(425, 70, "Score");

GFX_DrawText(200, 110, "1");
GFX_DrawText(200, 140, "2");
GFX_DrawText(200, 170, "3");
GFX_DrawText(200, 200, "4");
GFX_DrawText(200, 230, "5");



GFX_DrawFilledRectangle(20, 20, 90, 50, WHITE);
GFX_DrawText(35, 27, "Back");


go_back = 0;

    while (!go_back)
    {
        GFX_WaitForEvent();

        if (GFX_IsEventMouseButton())
        {
            GFX_GetMouseButton(&button_press);
            if (button_press == MOUSE_BUTTON_LEFT)
            {
                GFX_GetMouseCoordinates(&mouse_x, &mouse_y);
                GFX_UpdateDisplay();
                if (mouse_x > 20 && mouse_x < 90 && mouse_y >20 && mouse_y < 50)
                {
                GFX_ClearWindow();
                start_screen();
                go_back = 1;
                }
            }
        }
    }
}

void game()
{
GFX_ClearWindow();
GFX_InitWindow(10, 10);
}
