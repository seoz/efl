/*
   gcc event.c -o event `pkg-config --cflags --libs elementary` && ./event
 */

#include <Elementary.h>

static void
_mouse_down_cb(void *data, Evas *e, Evas_Object *obj, void *event_info)
{
   Evas_Event_Mouse_Down *ev = event_info;
   printf("down\n");
}

static void
_mouse_up_cb(void *data, Evas *e, Evas_Object *obj, void *event_info)
{
   Evas_Event_Mouse_Up *ev = event_info;
   printf("up\n");
}

void
app_init(void)
{
   Evas_Object *win, *o;

   win = elm_win_util_standard_add("win", "Win");
   evas_object_resize(win, 400, 300);
   evas_object_show(win);

   o = evas_object_rectangle_add(evas_object_evas_get(win));
   evas_object_repeat_events_set(o, EINA_TRUE);
   evas_object_color_set(o, 0, 0, 0, 0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_win_resize_object_add(win, o);
   evas_object_show(o);

   evas_object_event_callback_add(o, EVAS_CALLBACK_MOUSE_DOWN, _mouse_down_cb, NULL);
   evas_object_event_callback_add(o, EVAS_CALLBACK_MOUSE_UP, _mouse_up_cb, NULL);

   o = elm_bg_add(win);
   //elm_bg_color_set(o, 100, 0, 0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   elm_win_resize_object_add(win, o);
   evas_object_show(o);
}

EAPI_MAIN int
elm_main(int argc, char **argv)
{
   app_init();
   elm_run();
   elm_shutdown();
   return 0;
}
ELM_MAIN()
