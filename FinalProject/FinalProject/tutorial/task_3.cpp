#include <stdio.h>
#include <allegro5/allegro.h>

#define GAME_TERMINATE 666


#define AL_INIT_FAILED -1
#define DESPLAY_INIT_FAILED -2

ALLEGRO_DISPLAY* display = NULL;

/*
 * TODO: Declare your event_queue and event.
 */
ALLEGRO_EVENT_QUEUE* event_queue=NULL;
ALLEGRO_EVENT event;


const int width = 800;
const int height = 600;

void show_err_msg(int msg);
void game_init();
void game_begin();
int process_event();
int game_run();
void game_destroy();


int main(int argc, char *argv[]) {
    int msg = 0;

    game_init();
    game_begin();
    printf("Hello world!!!\n");
    printf("Close window to terminate.\n");

    while (msg != GAME_TERMINATE) {
        msg = game_run();
        if (msg == GAME_TERMINATE)
            printf("See you, world\n");
    }
    game_destroy();
    return 0;
}

void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d", msg);
    game_destroy();
    exit(9);
}

void game_init() {
    if (!al_init()) {
        show_err_msg(AL_INIT_FAILED);
    }

    display = al_create_display(width, height);
    event_queue=al_create_event_queue();
    if (display == NULL) {
        show_err_msg(DESPLAY_INIT_FAILED);
    }

    /*
     * TODO: initial display and event queue, and register specific event into event queue.
     */
     al_init_user_event_source(event_queue);
     al_register_event_source(event_queue,al_get_display_event_source(display));
}

void game_begin() {
    al_clear_to_color(al_map_rgb(0,0,0));
    al_flip_display();
}

int process_event() {
    /*
     * TODO: Get the earliest event from event_queue and judge whether it represents the closing of window.
     *       If so, return GAME_TERMINATE.
     * Hint: using event.type == ALLEGRO_EVENT_DISPLAY_CLOSE to judge whether the display is closed just now.
     */
     al_wait_for_event(event_queue,&event);
     if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return GAME_TERMINATE;
        }
    else show_err_msg(-1);
}

int game_run() {
    /*
     * TODO: Judge whether there's any event in the queue; if so, call process_event() to process it.
     */
     int error=0;
     if(!al_is_event_queue_empty(event_queue)) error=process_event();
     return error;
}

void game_destroy() {
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
}










#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

const int width = 800;
const int height = 600;

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_FONT *font = NULL;
ALLEGRO_COLOR color;
ALLEGRO_BITMAP *img = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_EVENT event;

void show_err_msg(int msg);
void game_init();
void game_load();
void game_destroy();
void set_color(int, int, int);

int main(int argc, char argv[]) {
    //int msg = 0;
    printf("Hello world!!!\n");
    game_init();
    game_load();

    al_clear_to_color(al_map_rgb(0, 255, 180));
    al_draw_text(font, al_map_rgb(255, 255, 255), width/2, (height/4), ALLEGRO_ALIGN_CENTER, "TAIWAN");
    al_draw_rectangle(200, 200, 300, 300, al_map_rgb(255, 255, 255), 3);
    al_draw_bitmap(img, 0, 0, 0);
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_flip_display();

    //al_rest(3);
    while (1) {
        if (al_is_event_queue_empty(event_queue)) {
            al_wait_for_event(event_queue, &event);
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            game_destroy();
            printf("See you, world!!\n");
        }
    }


    //al_destroy_font(font);
    al_rest(3);
    game_destroy();
    printf("See you, world!!\n");

    return 0;
}

void show_err_msg(int msg) {
    fprintf(stderr, "unexpected msg: %d", msg);
    game_destroy();
    exit(9);
    /
     The function above aims to show the error message and terminate the game.
     You may use it in any function need to deal with some error message.
     The program would not get any error if you don't utilize it,
     But you may get a tough debugging time when some mistakes happen.
     You can modify it to fit for your habit.
     /
}
void game_init() {
    if (!al_init()) {
        al_show_native_message_box(NULL, NULL, NULL, "Couldn't initialize!", NULL, NULL);
    }
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_image_addon();
}
void game_load() {
    display =  al_create_display(width, height);
    if (!display) {
        al_show_native_message_box(NULL, NULL, NULL, "Couldn't create Window!", NULL, NULL);
        show_err_msg(10);
    }

    font = al_load_ttf_font("pirulen.ttf", 72, 0);
    if(!font) {
        fprintf(stderr, "fuxx");
        show_err_msg(11);
    }

    img = al_load_bitmap("htchen.jpg");
    if(!img) {
        fprintf(stderr, "fuimg");
        show_err_msg(12);
    }

    event_queue = al_create_event_queue();
}
void game_destroy() {
    /
     TODO: Destroy everything you have initialized or created.
     */
    al_destroy_display(display);
}
void set_color(int r, int g, int b) {
    color = al_map_rgb(r, g, b);
    al_clear_to_color(color);
    //al_flip_display();
}
