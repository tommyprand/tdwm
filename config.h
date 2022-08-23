/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int barspacing					= 4;				/* px of spacing on y axis for the bar */
static const char *fonts[]          = { "Iosevka Nerd Font:size=14:style=Bold" };
static const char dmenufont[]       = "Iosevka Nerd Font:size=14:style=Bold";
// catppuccin mocha
static const char rosewater_mocha[] = "#f5e0dc";
static const char flamingo_mocha[]  = "#f2cdcd";
static const char pink_mocha[]      = "#f5c2e7";
static const char mauve_mocha[]     = "#cba6f7";
static const char red_mocha[]       = "#f38ba8";
static const char maroon_mocha[]    = "#eba0ac";
static const char peach_mocha[]     = "#fab387";
static const char yellow_mocha[]    = "#f9e2af";
static const char green_mocha[]     = "#a6e3a1";
static const char teal_mocha[]      = "#94e2d5";
static const char sky_mocha[]       = "#89dceb";
static const char sapphire_mocha[]  = "#74c7ec";
static const char blue_mocha[]      = "#89b4fa";
static const char lavender_mocha[]  = "#b4befe";
static const char text_mocha[]      = "#cdd6f4";
static const char subtext_mocha[]   = "#a6adc8";
static const char crust_mocha[]     = "#11111b";
static const char base_mocha[]      = "#1e1e2e";
// catppuccin latte
static const char rosewater_latte[] = "#dc8a78";
static const char flamingo_latte[]  = "#dd7878";
static const char pink_latte[]      = "#ea76cb";
static const char mauve_latte[]     = "#8839ef";
static const char red_latte[]       = "#d20f39";
static const char maroon_latte[]    = "#e64553";
static const char peach_latte[]     = "#fe640b";
static const char yellow_latte[]    = "#df8e1d";
static const char green_latte[]     = "#40a02b";
static const char teal_latte[]      = "#179299";
static const char sky_latte[]       = "#04a5e5";
static const char sapphire_latte[]  = "#209fb5";
static const char blue_latte[]      = "#1e66f5";
static const char lavender_latte[]  = "#7287fd";
static const char text_latte[]      = "#4c4f69";
static const char subtext_latte[]   = "#5c5f77";
static const char crust_latte[]     = "#dce0e8";
static const char base_latte[]      = "#eff1f5";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	// dark color scheme
	[SchemeNormDark] = { text_mocha, base_mocha, subtext_mocha },
	[SchemeSelDark]  = { subtext_mocha, crust_mocha, sky_mocha},
	// status bar color scheme
	[SchemeStatusDark] = {text_latte, sky_mocha, sky_mocha},
	// colors when tag selected
	[SchemeTag1Dark] = { pink_mocha, crust_mocha, crust_mocha },
	{ mauve_mocha, crust_mocha, crust_mocha },
	{ red_mocha, crust_mocha, crust_mocha },
	{ peach_mocha, crust_mocha, crust_mocha },
	{ yellow_mocha, crust_mocha, crust_mocha },
	{ green_mocha, crust_mocha, crust_mocha },
	{ sapphire_mocha, crust_mocha, crust_mocha },
	{ blue_mocha, crust_mocha, crust_mocha },
	{ lavender_mocha, crust_mocha, crust_mocha },
	
	[15] = { "#000000", "#000000", "#000000" },
	// light color scheme
	[SchemeNormLight] = { text_latte, base_latte, subtext_latte },
	[SchemeSelLight]  = { subtext_latte, crust_latte, sky_latte},
	// status bar color scheme
	[SchemeStatusLight] = {text_latte, sky_latte, sky_latte},
	// colors when tag selected
	[SchemeTag1Light] = { pink_latte, crust_latte, crust_latte },
	{ mauve_latte, crust_latte, crust_latte },
	{ red_latte, crust_latte, crust_latte },
	{ peach_latte, crust_latte, crust_latte },
	{ yellow_latte, crust_latte, crust_latte },
	{ green_latte, crust_latte, crust_latte },
	{ sapphire_latte, crust_latte, crust_latte },
	{ blue_latte, crust_latte, crust_latte },
	{ lavender_latte, crust_latte, crust_latte },

	[31] = { "#000000", "#000000", "#000000" },
};

/* tagging */
static const char *tags[] = { "dev", "web", "sys", "mus", "vid", "soc", "vir" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating    center   monitor */
	{ "St",       NULL,       NULL,       0,            0,            1,       -1 },
	{ "Firefox",  NULL,       NULL,       0,       0,            1,       -1 }
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", base_mocha, "-nf", text_mocha, "-sb", crust_mocha, "-sf", subtext_mocha, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *browsercmd[]  = { "firefox", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_s,			 togglescheme,   {0} },
	{ MODKEY|ShiftMask,             XK_d,			 setdark,        {0} },
	{ MODKEY|ShiftMask,             XK_l,			 setlight,       {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

