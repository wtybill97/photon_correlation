#include "run.h"
#include "options.h"
#include "channels.h"

int main(int argc, char *argv[]) {
	program_options_t program_options = {
"This program performs some basic manipulations of tttr data. This includes\n"
"suppression of channel data (removal of all such photons from a stream)\n"
"and addition of a constant offset to particular channels.\n",
		{OPT_VERBOSE, OPT_HELP, OPT_VERSION,
			OPT_FILE_IN, OPT_FILE_OUT,
			OPT_MODE,
			OPT_TIME_OFFSETS, OPT_PULSE_OFFSETS,
			OPT_SUPPRESS, OPT_EOF}};

	return(run(&program_options, channels_dispatch, argc, argv));
}
