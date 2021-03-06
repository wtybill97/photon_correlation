/*
 * Copyright (c) 2011-2015, Thomas Bischof
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, 
 *    this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, 
 *    this list of conditions and the following disclaimer in the documentation 
 *    and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of the Massachusetts Institute of Technology nor the 
 *    names of its contributors may be used to endorse or promote products 
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "run.h"
#include "options.h"
#include "photon/photons.h"

int main(int argc, char *argv[]) {
	program_options_t program_options = {
"This program reads and writes photons. It also provides tools for conversion\n"
"between photon types:\n"
"    1. t3 to t2, or t2 to t3: Use the excitation repetition rate and time\n"
"       origin to translate absolute time to pulse-clocked time.\n"
"    2. t3 as t2: Remove the time component of t3 data, to retain only the\n"
"       pulse information.\n"
"\n"
"You can also copy photons from all channels to a single target channel, \n"
"by passing an argument to --copy-to-channel. Use this to create a channel \n"
"containing all photons for calculating the intensity autocorrelation of the\n"
"full signal.\n",
		{OPT_VERBOSE, OPT_HELP, OPT_VERSION,
			OPT_FILE_IN, OPT_FILE_OUT,
			OPT_MODE, OPT_CONVERT, OPT_TIME_ORIGIN,
			OPT_REPETITION_TIME, OPT_COPY_TO_CHANNEL,
			OPT_EOF}};

	return(run(&program_options, photons, argc, argv));
}
