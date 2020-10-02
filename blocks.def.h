//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	10,		0},
    {"Vol: ", "echo $(pamixer --get-volume)%", 10, 10},
    {"Bat: ", "echo $(cat /sys/class/power_supply/BAT0/capacity)% $(if [ \"$(cat /sys/class/power_supply/BAT0/status)\" != \"Discharging\" ]; then echo \"⚡\"; fi;)" , 10, 0},
	{"", "date '+%b %d %H:%M'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
