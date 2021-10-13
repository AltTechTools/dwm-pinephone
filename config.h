/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 8;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 120;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const double defaultopacity  = 0.75;
static const char *fonts[]          = { "monospace:size=22" };
static const char dmenufont[]       = "monospace:size=22";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_red[]	    = "#FF0000";
static const char col_white[]	    = "#FFFFFF";
static const char col_black[]	    = "#000000";
static const char col_lightred[]    = "#FF7A7E";
static const char col_blue[]	    = "#0000FF";
static const char col_lightblue[]   = "#99C3FC";
//static const unsigned int baralpha = OPAQUE; //0xd0;
//static const unsigned int baralphainactive = OPAQUE; //0x26; //0x64;
//static const unsigned int borderalpha = OPAQUE;

//colores from enum in dwm.c
//enum { white, black, gray1, gray2, gray3, gray4, red, lightred, blue, lightblue, cyan }; /* colors available */

/*
static const char colorpalette[][7]      = {
	[gray1]		= "#222222",
	[gray2]		= "#444444",
	[gray3]		= "#bbbbbb",
	[gray4]		= "#eeeeee",
	[white] 	= "#FFFFFF",
	[black] 	= "#000000",
	[lightred] 	= "#FF7A7E",
	[red] 		= "#FF0000",
	[lightblue]	= "#99C3FC",
	[blue]		= "#0000FF",
	[cyan]		= "#005577",
};
*/


//static const char *col_NormFG2   		= colorpalette[black];

static const char col_NormFG[]   		= "#FFFFFF";
static const char col_NormBG[]   		= "#99C3FC";
static const char col_NormBorder[]		= "#FF7A7E";

static const char col_SelFG[]   		= "#FFFFFF";
static const char col_SelBG[]   		= "#FF7A7E";
static const char col_SelBorder[]		= "#FF0000";


static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_NormFG,  col_NormBG,  col_NormBorder },
	[SchemeSel]  =  { col_SelFG,  col_SelBG,  col_SelBorder },
};

	//[SchemeNorm] = { col_white, col_lightblue, col_lightred },
	//[SchemeSel]  = { col_black, col_lightred,  col_red  },

	//[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	//[SchemeSel]  = { col_gray4, col_cyan,  col_red  },

//static const unsigned int alphas[][3]      = {
//	/*               fg      bg        border     */
//	[SchemeNorm] = { OPAQUE, baralphainactive, borderalpha },
//	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
//};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
//	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
//	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	/* class      instance    title       tags mask     isfloating	 opacity	monitor 
	{ "Gimp",     NULL,       NULL,       0,            1,           1.0,		-1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           0.75,		-1 },
	{ "gnome-terminal",  NULL,       NULL,0,	    0,           0.5,		-1 },
*/
	{ "St",	      NULL,       NULL,       0,            0,           -1},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const float hfact     = 0.55; /* factor of master area hight size [0.05..0.95] */
static const int nmaster     = 2;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
//#define MODKEY Mod1Mask
#define MODKEY Mod4Mask //windows key
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
  	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */ //wokrdir is $HOME
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_red, "-nf", col_white, "-sb", col_lightblue, "-sf", col_black, NULL };
//static const char *termcmd[]  = { "st", NULL };
static const char *termcmd[]  = { "kgx", NULL };
//static const char *customcmd[] = { "xsetroot", "-name", "HelloWorld", NULL};
//static const char *customcmd[] = { "cd", "$HOME", "&&","./.dwm/customcommand.sh", NULL};
static const char *customcmd[] = { "./.dwm/customcommand.sh","&", NULL};
static const char *testcmd[] = { "xsetroot", "-name", "Test", NULL};
//static const char *testcmd2[] = { "xsetroot", "-name", "TstPowerBtn", NULL};
static const char *volumeUPcmd[] = { "./.dwm/audioctr/audio_volup.sh", NULL};
static const char *volumeDwncmd[] = { "./.dwm/audioctr/audio_voldwn.sh", NULL};
static const char *volumeMuteTglcmd[] = { "./.dwm/audioctr/audio_mutetoggle.sh", NULL};
static const char *testcmd2[] = { "xdotool", "key", "Return", NULL};

//also see: /usr/include/X11/XF86keysym.h
/*
XF86XK_PowerOff oder XF86XK_PowerDown oder XF86XK_WakeUp oder XF86XK_Sleep oder XF86XK_Hibernate
XF86XK_AudioMute
XF86XK_AudioPause
XF86XK_AudioMedia
(XF86XK_Launch0 - F)
..XF86XK_WheelButton == button2?
XF86XK_WebCam 
XF86XK_Music
XF86XK_Bluetooth
XF86XK_Keyboard
*/
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
/*	{ 0,				XF86XK_AudioRaiseVolume,	spawn,	{.v = volumeUPcmd } },
	{ 0,				XF86XK_AudioLowerVolume,	spawn,	{.v = volumeDwncmd } },
	{ 0,				XF86XK_AudioPause,		spawn,	{.v = testcmd } },
	{ 0,				XF86XK_AudioMute,		spawn,	{.v = volumeMuteTglcmd } },

	{ 0,				XF86XK_PowerOff,		spawn,	{.v = testcmd2 } },
	{ 0,				XF86XK_PowerDown,		spawn,	{.v = testcmd2 } },
	{ 0,				XF86XK_Hibernate,		spawn,	{.v = testcmd2 } },
	{ 0,				XF86XK_Sleep,			spawn,	{.v = testcmd2 } },
	{ 0,				XF86XK_WakeUp,			spawn,	{.v = testcmd2 } },
*/

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.10} }, //0.05
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.10} }, //0.05
	//--custom
	{ MODKEY|ShiftMask,             XK_h,      sethfact,       {.f = -0.05} }, //0.05
	{ MODKEY|ShiftMask,             XK_l,      sethfact,       {.f = +0.05} }, //0.05
	//++custom
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} }, //orig 0 (i switched the list order and the default by that)
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} }, //orig 1
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[0]} }, //orig 2
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
//	{ MODKEY|ShiftMask,		XK_KP_Add, changeopacity,	{.f = +0.1}},
//	{ MODKEY|ShiftMask,		XK_KP_Subtract, changeopacity,  {.f = -0.1}},
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
//	{ ClkRootWin,           MODKEY,         Button1,        togglefloating, {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = customcmd } },
};
