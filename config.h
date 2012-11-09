/* JokerBoy - http://hg.punctweb.ro */

/* appearance */
static const char font[]            = "DejaVu Sans Mono:Book:size=8:antialias=true:autohint=true";
static const char colors[MAXCOLORS][ColLast][8] = {
	/* border     fg         bg       */
	{ "#222222", "#666666", "#1A1A1A" }, /* 0 = normal */
	{ "#876CBE", "#DDDDDD", "#1A1A1A" }, /* 1 = selected */
	{ "#FF2882", "#FFFFFF", "#FF2882" }, /* 2 = urgent */
	{ "#222222", "#53A6A6", "#1A1A1A" }, /* 3 = green */
	{ "#222222", "#BF85CC", "#1A1A1A" }, /* 4 = yellow */
	{ "#222222", "#6096BF", "#1A1A1A" }, /* 5 = cyan */
	{ "#222222", "#7E62B3", "#1A1A1A" }, /* 6 = magenta */
	{ "#222222", "#899CA1", "#1A1A1A" }, /* 7 = grey */
};
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 8;        /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus      = True;     /* Change focus only on click */
static const Bool viewontag         = True;     /* Switch view on tag switch */

static const Rule rules[] = {
	/* class          instance     title       tags mask     isfloating   iscentred   monitor */
	{ "Gimp",         NULL,        NULL,       0,            True,        False,      -1 },
	{ "MPlayer",      NULL,        NULL,       0,            True,        True,       -1 },
	{ "mplayer2",     NULL,        NULL,       0,            True,        True,       -1 },
	{ "Vlc",          NULL,        NULL,       0,            True,        True,       -1 },
	{ "XFontSel",     NULL,        NULL,       0,            True,        True,       -1 },
	{ "Kcalc",        NULL,        NULL,       0,            True,        True,       -1 },
	{ "Komodo Edit",  NULL,        NULL,       0,            True,        True,       -1 },
	{ "Komodo Edit",  "Komodo",    NULL,       0,            False,       False,      -1 },
	{ "Komodo Edit",  NULL,        "Find",     0,            True,        True,       -1 },
	{ "Chromium",     NULL,        NULL,       1 << 2,       False,       False,      -1 },
	{ "Firefox",      NULL,        NULL,       1 << 2,       True,        True,       -1 },
	{ "Firefox",      "Navigator", NULL,       1 << 2,       False,       False,      -1 },
	{ "Ktorrent",     NULL,        NULL,       1 << 4,       False,       False,      -1 },
	{ "VirtualBox",   NULL,        NULL,       1 << 5,       False,       False,      -1 },
	{ "VBoxSDL",      NULL,        NULL,       1 << 5,       False,       False,      -1 },
	{ "Wine",         NULL,        NULL,       1 << 5,       False,       True,       -1 },
	{ "Xephyr",       NULL,        NULL,       0,            False,       False,      -1 },
	{ "Opera",        NULL,        NULL,       1 << 2,       False,       False,      -1 },
	{ "Pidgin",       NULL,        NULL,       1 << 3,       False,       False,      -1 },
	{ "Pidgin",       NULL,        "Pidgin",   1 << 3,       True,        True,       -1 },
	{ "Gyachi",       NULL,        NULL,       1 << 3,       False,       False,      -1 },
	{ "Skype",        NULL,        NULL,       1 << 3,       False,       False,      -1 },
};

/* layout(s) */
static const float mfact      = 0.5;   /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },        /* first entry is default */
	{ "[M]",      monocle },
	{ "[F]",      NULL },        /* no layout function means floating behavior */
	{ "[B]",      bstack },
	{ "[G]",      gaplessgrid },
	{ "[P]",      pidgin },
};

/* tagging */
static const Tag tags[] = {
	/* name       layout           mfact    nmaster */
	{ "main",     &layouts[4],     -1,      -1 },
	{ "term",     &layouts[4],     -1,      -1 },
	{ "web",      &layouts[1],     -1,      -1 },
	{ "im",       &layouts[5],     0.83,    -1 },
	{ "dld",      &layouts[4],     -1,      -1 },
	{ "misc",     &layouts[4],     -1,      -1 },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static const char terminal[]       = "urxvtcd";
static const char scratchpadname[] = "scratchy";
static const char *dmenucmd[]      = { "dmenu_run", "-i", "-p", "Run command:", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG],"-sb", colors[1][ColBG], "-sf", colors[1][ColFG], NULL };
static const char *termcmd[]       = { terminal, NULL };
static const char *tmuxcmd[]       = { terminal, "-e", "tmuxa", NULL };
static const char *musiccmd[]      = { terminal, "-e", "ncmpcpp", NULL };
static const char *scratchpadcmd[] = { terminal, "-name", scratchpadname, "-geometry", "150x40", NULL };
static const char *filemancmd[]    = { "dolphin", NULL };
static const char *browserfcmd[]   = { "firefox", "-p", "default", NULL };
static const char *browserwcmd[]   = { "firefox", "-p", "work", NULL };
static const char *browsergcmd[]   = { "firefox", "-p", "games", NULL };
static const char *altbrowsercmd[] = { "chromium", NULL };
static const char *secbrowsercmd[] = { "opera", NULL };
static const char *editorcmd[]     = { "komodoedit", NULL };
static const char *imcmd[]         = { "pidgin", NULL };
static const char *vboxcmd[]       = { "VirtualBox", NULL };
static const char *volmcmd[]       = { "amixer", "-q", "sset", "Master", "toggle", NULL };
static const char *voldcmd[]       = { "amixer", "-q", "sset", "Master", "1-", "unmute", NULL };
static const char *volucmd[]       = { "amixer", "-q", "sset", "Master", "1+", "unmute", NULL };
static const char *mpdvoldcmd[]    = { "ncmpcpp", "volume", "-2", NULL };
static const char *mpdvolucmd[]    = { "ncmpcpp", "volume", "+2", NULL };
static const char *mpdtogglecmd[]  = { "ncmpcpp", "toggle", NULL };
static const char *mpdstopcmd[]    = { "ncmpcpp", "stop", NULL };
static const char *mpdprevcmd[]    = { "ncmpcpp", "prev", NULL };
static const char *mpdnextcmd[]    = { "ncmpcpp", "next", NULL };
static const char *screenshotcmd[] = { "printscreen", NULL };
static const char *lockcmd[]       = { "slock", NULL };
static const char *suspendcmd[]    = { "systemctl", "suspend", NULL };
static const char *hibernatecmd[]  = { "systemctl", "hibernate", NULL };
static const char *rebootcmd[]     = { "systemctl", "reboot", NULL };
static const char *shutdowncmd[]   = { "systemctl", "poweroff", NULL };

static Key keys[] = {
	/* modifier                     key         function        argument */
	{ ALTKEY,                       XK_F2,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,  spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_Return,  spawn,          {.v = tmuxcmd } },
	{ MODKEY,                       XK_n,       spawn,          {.v = musiccmd } },
	{ MODKEY,                       XK_x,       togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_t,       spawn,          {.v = filemancmd } },
	{ MODKEY,                       XK_f,       spawn,          {.v = browserfcmd } },
	{ MODKEY,                       XK_w,       spawn,          {.v = browserwcmd } },
	{ MODKEY,                       XK_g,       spawn,          {.v = browsergcmd } },
	{ MODKEY,                       XK_c,       spawn,          {.v = altbrowsercmd } },
	{ MODKEY,                       XK_o,       spawn,          {.v = secbrowsercmd } },
	{ MODKEY,                       XK_e,       spawn,          {.v = editorcmd } },
	{ MODKEY,                       XK_p,       spawn,          {.v = imcmd } },
	{ MODKEY,                       XK_v,       spawn,          {.v = vboxcmd } },
	{ 0,                            0x1008ff12, spawn,          {.v = volmcmd } },
	{ 0,                            0x1008ff11, spawn,          {.v = voldcmd } },
	{ 0,                            0x1008ff13, spawn,          {.v = volucmd } },
	{ MODKEY,                       0x1008ff11, spawn,          {.v = mpdvoldcmd } },
	{ MODKEY,                       0x1008ff13, spawn,          {.v = mpdvolucmd } },
	{ 0,                            0x1008ff14, spawn,          {.v = mpdtogglecmd } },
	{ 0,                            0x1008ff15, spawn,          {.v = mpdstopcmd } },
	{ 0,                            0x1008ff16, spawn,          {.v = mpdprevcmd } },
	{ 0,                            0x1008ff17, spawn,          {.v = mpdnextcmd } },
	{ 0,                            XK_Print,   spawn,          {.v = screenshotcmd } },
	{ MODKEY|ShiftMask,             XK_m,       togglemax,      {0} },
	{ MODKEY|ShiftMask,             XK_b,       togglebar,      {0} },
	{ MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,       pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,       pushup,         {0} },
	{ MODKEY,                       XK_a,       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_z,       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,       setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_l,       setmfact,       {.f = +0.01} },
	{ ALTKEY,                       XK_Return,  zoom,           {0} },
	{ ALTKEY,                       XK_Tab,     view,           {0} },
	{ MODKEY,                       XK_Tab,     focusurgent,    {0} },
	{ MODKEY,                       XK_Escape,  killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_c,       centerwindow,   {0} },
	{ MODKEY|ControlMask,           XK_n,       setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_m,       setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_f,       setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_b,       setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_g,       setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ControlMask,           XK_p,       setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
	{ MODKEY,                       XK_0,       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_Left,    cycle,          {.i = -1 } },
	{ MODKEY,                       XK_Right,   cycle,          {.i = +1 } },
	{ MODKEY|ControlMask,           XK_Left,    tagcycle,       {.i = -1 } },
	{ MODKEY|ControlMask,           XK_Right,   tagcycle,       {.i = +1 } },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	{ 0,                            XK_Pause,   spawn,          {.v = lockcmd } },
	{ ALTKEY|ControlMask,           XK_s,       spawn,          {.v = suspendcmd } },
	{ ALTKEY|ControlMask,           XK_h,       spawn,          {.v = hibernatecmd } },
	{ ALTKEY|ControlMask,           XK_r,       spawn,          {.v = rebootcmd } },
	{ ALTKEY|ControlMask,           XK_q,       spawn,          {.v = shutdowncmd } },
	{ MODKEY|ShiftMask,             XK_Escape,  quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkWinTitle,          0,              Button4,        focusstack,     {.i = +1} },
	{ ClkWinTitle,          0,              Button5,        focusstack,     {.i = -1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        cycle,          {.i = -1} },
	{ ClkTagBar,            0,              Button5,        cycle,          {.i = +1} },
};
