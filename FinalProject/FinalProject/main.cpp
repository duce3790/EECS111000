#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>

int main(){
    ALLEGRO_DISPLAY *display;

    if(!al_init()){
        al_show_native_message_box(NULL,NULL,NULL,"Could't initialize!",NULL,NULL);
    }

    display = al_create_display(800,600);

    if(!display){
        al_show_native_message_box(NULL,NULL,NULL,"Could't create Window!",NULL,NULL);
    }

    al_rest(5.0);
    return 0;
}
