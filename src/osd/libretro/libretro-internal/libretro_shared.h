#ifndef _LIBRETRO_SHARED_H
#define _LIBRETRO_SHARED_H

#include "libretro.h"

#ifndef USE_XINPUT
#define USE_XINPUT 0
#endif

#define HAVE_RGB32
//FIXME: re-add way to handle 16/32 bit
#if (!defined(HAVE_OPENGL) && !defined(HAVE_RGB32)) || (!defined(HAVE_OPENGLES) && !defined(HAVE_RGB32))

#ifndef M16B
#define M16B
#endif

#endif

#ifndef M16B
#define PIXEL_TYPE UINT32
#else
#define PIXEL_TYPE UINT16
#endif

#define CORE_NAME "mame"
#define RETRO_PATH_MAX 512

enum
{
   RETROPAD_B,
   RETROPAD_Y,
   RETROPAD_SELECT,
   RETROPAD_START,
   RETROPAD_PAD_UP,
   RETROPAD_PAD_DOWN,
   RETROPAD_PAD_LEFT,
   RETROPAD_PAD_RIGHT,
   RETROPAD_A,
   RETROPAD_X,
   RETROPAD_L,
   RETROPAD_R,
   RETROPAD_L2,
   RETROPAD_R2,
   RETROPAD_L3,
   RETROPAD_R3,
   RETROPAD_TOTAL
};

enum
{
   RETRO_SETTING_LIGHTGUN_MODE_DISABLED,
   RETRO_SETTING_LIGHTGUN_MODE_POINTER,
   RETRO_SETTING_LIGHTGUN_MODE_LIGHTGUN
};

enum
{
   RETRO_SETTING_LIGHTGUN_OFFSCREEN_MODE_FREE,
   RETRO_SETTING_LIGHTGUN_OFFSCREEN_MODE_TOP_LEFT,
   RETRO_SETTING_LIGHTGUN_OFFSCREEN_MODE_BOTTOM_RIGHT,
};

enum
{
   ROTATION_MODE_NONE,
   ROTATION_MODE_LIBRETRO,
   ROTATION_MODE_INTERNAL,
   ROTATION_MODE_TATE_ROL,
   ROTATION_MODE_TATE_ROR
};

extern bool retro_load_ok;
extern int video_changed;
extern int retro_pause;
extern int mame_reset;
extern char g_rom_dir[RETRO_PATH_MAX];
extern char mediaType[10];
extern const char *retro_save_directory;
extern const char *retro_system_directory;
extern const char *retro_content_directory;

extern int  lightgun_mode;
extern int  lightgun_offscreen_mode;
extern bool mouse_enable;
extern bool cheats_enable;
extern bool alternate_renderer;
extern bool boot_to_osd_enable;
extern bool boot_to_bios_enable;
extern bool softlist_enable;
extern bool softlist_auto;
extern bool autoloadfastforward;
extern bool write_config_enable;
extern bool read_config_enable;
extern bool throttle_enable;
extern bool auto_save_enable;
extern bool game_specific_saves_enable;
extern bool buttons_profiles;
extern bool mame_paths_enable;
extern bool mame_4way_enable;
extern char mame_4way_map[256];
extern char joystick_deadzone[8];
extern char joystick_saturation[8];
extern char joystick_threshold[8];

extern int fb_width;
extern int fb_height;
extern float retro_aspect;
extern float view_aspect;
extern float retro_fps;
extern float sound_timer;
extern int rotation_mode;
extern int thread_mode;
extern int screen_configured;

extern const char *slash_str;

/* libretro callbacks */
extern retro_log_printf_t log_cb;
extern retro_environment_t environ_cb;
extern retro_input_state_t input_state_cb;
extern retro_input_poll_t input_poll_cb;

extern void retro_keyboard_event(bool, unsigned, uint32_t, uint16_t);

extern bool fexists(std::string path);
extern int mmain2(int argc, const char *argv[]);
extern void extract_basename(char *buf, const char *path, size_t size);
extern void extract_directory(char *buf, const char *path, size_t size);

void retro_frame_draw_enable(bool enable);

void *retro_get_fb_ptr(void);

#ifdef __cplusplus
extern "C" {
#endif

int mmain2(int argc, const char *argv);
int mmain(int argc, char *argv[]);

#ifdef __cplusplus
}
#endif

#endif
