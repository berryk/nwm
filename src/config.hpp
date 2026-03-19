#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <X11/keysym.h>
#include "nwm.hpp"

using namespace nwm;

#define ANIMATIONS_ENABLED          true

#define ANIM_SCROLL_ENABLED         true
#define ANIM_WINDOW_MOVE_ENABLED    false
#define ANIM_WINDOW_RESIZE_ENABLED  false
#define ANIM_OPACITY_ENABLED        false
#define ANIM_MASTER_FACTOR_ENABLED  false
#define ANIM_WINDOW_OPEN_ENABLED    false
#define ANIM_WINDOW_CLOSE_ENABLED   false
#define ANIM_WORKSPACE_SWITCH_ENABLED false
#define ANIM_BORDER_COLOR_ENABLED   false

#define ANIM_SCROLL_DURATION        300
#define ANIM_WINDOW_MOVE_DURATION   200
#define ANIM_WINDOW_RESIZE_DURATION 200
#define ANIM_OPACITY_DURATION       150
#define ANIM_MASTER_FACTOR_DURATION 250
#define ANIM_WINDOW_OPEN_DURATION   199
#define ANIM_WINDOW_CLOSE_DURATION  200
#define ANIM_WORKSPACE_SWITCH_DURATION 300
#define ANIM_BORDER_COLOR_DURATION  150
#define ANIM_SCROLL_EASING          nwm::EasingType::EASE_OUT_CUBIC
#define ANIM_WINDOW_MOVE_EASING     nwm::EasingType::EASE_OUT_QUAD
#define ANIM_WINDOW_RESIZE_EASING   nwm::EasingType::EASE_OUT_QUAD
#define ANIM_OPACITY_EASING         nwm::EasingType::EASE_IN_OUT_QUAD
#define ANIM_MASTER_FACTOR_EASING   nwm::EasingType::EASE_OUT_CUBIC
#define ANIM_WINDOW_OPEN_EASING     nwm::EasingType::EASE_OUT_CUBIC
#define ANIM_WINDOW_CLOSE_EASING    nwm::EasingType::EASE_IN_CUBIC
#define ANIM_WORKSPACE_SWITCH_EASING nwm::EasingType::EASE_IN_OUT_CUBIC
#define ANIM_BORDER_COLOR_EASING    nwm::EasingType::EASE_OUT_QUAD

// Window open/close animation styles
// Open styles: FADE, SCALE, SLIDE_FROM_TOP, SLIDE_FROM_BOTTOM, SLIDE_FROM_LEFT, SLIDE_FROM_RIGHT
// Close styles: FADE_OUT, SCALE_DOWN, SLIDE_TO_TOP, SLIDE_TO_BOTTOM, SLIDE_TO_LEFT, SLIDE_TO_RIGHT
#define WINDOW_OPEN_STYLE           nwm::AnimationManager::SCALE
#define WINDOW_CLOSE_STYLE          nwm::AnimationManager::SCALE_DOWN

#define BORDER_WIDTH        3
#define BORDER_COLOR        0x45475a   // Catppuccin Surface 1
#define FOCUS_COLOR         0x89b4fa   // Catppuccin Blue
#define GAP_SIZE            6

#define BAR_POSITION        0
#define BAR_HEIGHT          28
#define BAR_BG_COLOR        0x1e1e2e   // Catppuccin Base
#define BAR_FG_COLOR        0xcdd6f4   // Catppuccin Text
#define BAR_ACTIVE_COLOR    0x89b4fa   // Catppuccin Blue
#define BAR_ACCENT_COLOR    0x89b4fa   // Catppuccin Blue
#define BAR_INACTIVE_COLOR  0x6c7086   // Catppuccin Overlay 0
#define BAR_INDICATOR_COLOR 0xa6e3a1   // Catppuccin Green
#define USE_BUILTIN_BAR     1
#define SHOW_BAR_TITLE      0

#define SHOW_WINDOW_TITLES  0
#define TITLE_BAR_HEIGHT    20
#define TITLE_BAR_BG        0x313244   // Catppuccin Surface 0
#define TITLE_BAR_FG        0xcdd6f4   // Catppuccin Text
#define TITLE_BAR_FOCUS_BG  0x89b4fa   // Catppuccin Blue
#define TITLE_BAR_FOCUS_FG  0x1e1e2e   // Catppuccin Base

#define USE_XINERAMA        1
#define SCROLL_WINDOWS_VISIBLE 2

#define FONT                "Ubuntu Mono:size=12"

static const std::vector<std::string> WIDGET = {
    "1","2","3","4","5","6","7","8","9"
};

#define RESIZE_STEP         60

#define SCROLL_STEP         550

#define MODKEY Mod1Mask
#define MODKEY2 Mod4Mask

static const char *termcmd[]    = { "alacritty",        NULL };
static const char *dmenucmd[]   = { "dmenu_run", NULL };
static const char *browser[]    = { "zen-browser",   NULL };
static const char *filemanager[] = { "thunar",   NULL };
static const char *editor[]     = { "alacritty", "-e", "nvim", NULL };
static const char *sysmon[]     = { "alacritty", "-e", "btop", NULL };
static const char *keybinds[]   = { "bash", "-c", "/usr/local/bin/keybinds-overlay", NULL };

static const int ws0 = 0;
static const int ws1 = 1;
static const int ws2 = 2;
static const int ws3 = 3;
static const int ws4 = 4;
static const int ws5 = 5;
static const int ws6 = 6;
static const int ws7 = 7;
static const int ws8 = 8;

static const int mon0 = 0;
static const int mon1 = 1;
static const int mon2 = 2;

static const int scroll_visible_1 = 1;
static const int scroll_visible_2 = 2;
static const int scroll_visible_3 = 3;
static const int scroll_visible_4 = 4;
static const int scroll_visible_5 = 5;

inline __attribute__((unused)) const struct {
    unsigned int mod;
    KeySym keysym;
    void (*func)(void*, nwm::Base&);
    const void *arg;
} keys[] = {
    // ── App Launching (Omarchy-style) ────────────────────────────
    { MODKEY,             XK_Return,          spawn,          termcmd },
    { MODKEY,             XK_space,           spawn,          dmenucmd },
    { MODKEY,             XK_b,               spawn,          browser },
    { MODKEY|ShiftMask,   XK_f,               spawn,          filemanager },
    { MODKEY,             XK_n,               spawn,          editor },
    { MODKEY,             XK_t,               spawn,          sysmon },

    // ── Window Management ─────────────────────────────────────
    { MODKEY,             XK_w,               close_window,   NULL },
    { MODKEY,             XK_f,               toggle_fullscreen, NULL },
    { MODKEY|ShiftMask,   XK_v,               toggle_float,   NULL },
    { MODKEY,             XK_g,               toggle_gap,     NULL },
    { MODKEY,             XK_r,               toggle_bar,     NULL },

    // ── Focus ────────────────────────────────────────────────────
    { MODKEY,             XK_j,               focus_next,     NULL },
    { MODKEY,             XK_k,               focus_prev,     NULL },
    { MODKEY,             XK_Down,            focus_next,     NULL },
    { MODKEY,             XK_Up,              focus_prev,     NULL },
    { MODKEY,             XK_period,          focus_next,     NULL },
    { MODKEY,             XK_comma,           focus_prev,     NULL },

    // ── Swap / Move windows ───────────────────────────────────
    { MODKEY | ShiftMask, XK_h,               swap_prev,      NULL },
    { MODKEY | ShiftMask, XK_l,               swap_next,      NULL },
    { MODKEY | ShiftMask, XK_Left,            swap_prev,      NULL },
    { MODKEY | ShiftMask, XK_Right,           swap_next,      NULL },

    // ── Master area resize ────────────────────────────────────
    { MODKEY,             XK_h,               resize_master,  (void*)-RESIZE_STEP },
    { MODKEY,             XK_l,               resize_master,  (void*)RESIZE_STEP },

    // ── Scroll (nwm feature) ──────────────────────────────────
    { MODKEY,             XK_Left,            scroll_left,    NULL },
    { MODKEY,             XK_Right,           scroll_right,   NULL },
    { MODKEY,             XK_equal,           increment_scroll_visible, NULL },
    { MODKEY,             XK_minus,           decrement_scroll_visible, NULL },

    // ── Layout toggle ─────────────────────────────────────────
    { MODKEY | ShiftMask, XK_t,               toggle_layout,  NULL },

    // ── Scroll visible windows ──────────────────────────────────
    { MODKEY|ShiftMask,   XK_comma,           set_scroll_visible, (void*)&scroll_visible_2 },
    { MODKEY|ShiftMask,   XK_period,          set_scroll_visible, (void*)&scroll_visible_3 },
    { MODKEY|ShiftMask,   XK_slash,           set_scroll_visible, (void*)&scroll_visible_4 },

    // ── Workspaces ────────────────────────────────────────────
    { MODKEY,             XK_1,               switch_workspace, (void*)&ws0 },
    { MODKEY,             XK_2,               switch_workspace, (void*)&ws1 },
    { MODKEY,             XK_3,               switch_workspace, (void*)&ws2 },
    { MODKEY,             XK_4,               switch_workspace, (void*)&ws3 },
    { MODKEY,             XK_5,               switch_workspace, (void*)&ws4 },
    { MODKEY,             XK_6,               switch_workspace, (void*)&ws5 },
    { MODKEY,             XK_7,               switch_workspace, (void*)&ws6 },
    { MODKEY,             XK_8,               switch_workspace, (void*)&ws7 },
    { MODKEY,             XK_9,               switch_workspace, (void*)&ws8 },

    { MODKEY | ShiftMask, XK_1,               move_to_workspace, (void*)&ws0 },
    { MODKEY | ShiftMask, XK_2,               move_to_workspace, (void*)&ws1 },
    { MODKEY | ShiftMask, XK_3,               move_to_workspace, (void*)&ws2 },
    { MODKEY | ShiftMask, XK_4,               move_to_workspace, (void*)&ws3 },
    { MODKEY | ShiftMask, XK_5,               move_to_workspace, (void*)&ws4 },
    { MODKEY | ShiftMask, XK_6,               move_to_workspace, (void*)&ws5 },
    { MODKEY | ShiftMask, XK_7,               move_to_workspace, (void*)&ws6 },
    { MODKEY | ShiftMask, XK_8,               move_to_workspace, (void*)&ws7 },
    { MODKEY | ShiftMask, XK_9,               move_to_workspace, (void*)&ws8 },

    // ── Help ──────────────────────────────────────────────────
    { MODKEY,             XK_slash,           spawn,          keybinds },

    // ── Session ───────────────────────────────────────────────
    { MODKEY | ShiftMask, XK_q,               quit_wm,        NULL },
    { MODKEY | ShiftMask, XK_r,               quit_wm,        (void*)1 },

    // ── Mac Cmd key (KasmVNC maps Cmd to Control in combos) ──
    // Ctrl+Shift bindings — pass through browser/KasmVNC reliably
    #define CSKEY (ControlMask | ShiftMask)

    { CSKEY,               XK_Return,          spawn,          termcmd },
    { CSKEY,               XK_space,           spawn,          dmenucmd },
    { CSKEY,               XK_b,               spawn,          browser },
    { CSKEY,               XK_n,               spawn,          editor },
    { CSKEY,               XK_t,               spawn,          sysmon },

    { CSKEY,               XK_w,               close_window,   NULL },
    { CSKEY,               XK_f,               toggle_float,   NULL },
    { CSKEY,               XK_g,               toggle_gap,     NULL },
    { CSKEY,               XK_r,               toggle_bar,     NULL },

    { CSKEY,               XK_j,               focus_next,     NULL },
    { CSKEY,               XK_k,               focus_prev,     NULL },
    { CSKEY,               XK_Down,            focus_next,     NULL },
    { CSKEY,               XK_Up,              focus_prev,     NULL },

    { CSKEY,               XK_h,               swap_prev,      NULL },
    { CSKEY,               XK_l,               swap_next,      NULL },
    { CSKEY,               XK_Left,            swap_prev,      NULL },
    { CSKEY,               XK_Right,           swap_next,      NULL },
    { CSKEY,               XK_d,               spawn,          filemanager },
    { CSKEY,               XK_x,               toggle_layout,  NULL },

    { CSKEY,               XK_bracketleft,     resize_master,  (void*)-RESIZE_STEP },
    { CSKEY,               XK_bracketright,    resize_master,  (void*)RESIZE_STEP },

    { CSKEY,               XK_comma,           scroll_left,    NULL },
    { CSKEY,               XK_period,          scroll_right,   NULL },
    { CSKEY,               XK_equal,           increment_scroll_visible, NULL },
    { CSKEY,               XK_minus,           decrement_scroll_visible, NULL },

    { CSKEY,               XK_1,               switch_workspace, (void*)&ws0 },
    { CSKEY,               XK_2,               switch_workspace, (void*)&ws1 },
    { CSKEY,               XK_3,               switch_workspace, (void*)&ws2 },
    { CSKEY,               XK_4,               switch_workspace, (void*)&ws3 },
    { CSKEY,               XK_5,               switch_workspace, (void*)&ws4 },
    { CSKEY,               XK_6,               switch_workspace, (void*)&ws5 },
    { CSKEY,               XK_7,               switch_workspace, (void*)&ws6 },
    { CSKEY,               XK_8,               switch_workspace, (void*)&ws7 },
    { CSKEY,               XK_9,               switch_workspace, (void*)&ws8 },

    // Ctrl+Shift+Alt for move-to-workspace
    { CSKEY | Mod1Mask,    XK_1,               move_to_workspace, (void*)&ws0 },
    { CSKEY | Mod1Mask,    XK_2,               move_to_workspace, (void*)&ws1 },
    { CSKEY | Mod1Mask,    XK_3,               move_to_workspace, (void*)&ws2 },
    { CSKEY | Mod1Mask,    XK_4,               move_to_workspace, (void*)&ws3 },
    { CSKEY | Mod1Mask,    XK_5,               move_to_workspace, (void*)&ws4 },
    { CSKEY | Mod1Mask,    XK_6,               move_to_workspace, (void*)&ws5 },
    { CSKEY | Mod1Mask,    XK_7,               move_to_workspace, (void*)&ws6 },
    { CSKEY | Mod1Mask,    XK_8,               move_to_workspace, (void*)&ws7 },
    { CSKEY | Mod1Mask,    XK_9,               move_to_workspace, (void*)&ws8 },

    { CSKEY,               XK_slash,           spawn,          keybinds },

    { CSKEY,               XK_q,               quit_wm,        NULL },
    { CSKEY | Mod1Mask,    XK_r,               quit_wm,        (void*)1 },
};

#endif //CONFIG_HPP
