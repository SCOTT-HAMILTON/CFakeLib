#include <CFakeLib.h>
#include <CFakeLibUtils.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	fake_clear_commands();
	fake_get_sink_input_list();
	fake_get_sink_list();
	fake_get_source_list();
	fake_get_source_output_list();
	fake_run_commands();
	
	sink_input_infos_t* sink_input_list = NULL;
	size_t size = fake_extract_sink_input_list(&sink_input_list);
	fprintf(stderr, "size : %ld\n", size);
	fake_utils_print_sink_input_info_list(sink_input_list, size);

	sink_infos_t* sink_list = NULL;
	size = fake_extract_sink_list(&sink_list);
	fprintf(stderr, "size : %ld\n", size);
	fake_utils_print_sink_info_list(sink_list, size);

	source_infos_t* source_list = NULL;
	size = fake_extract_source_list(&source_list);
	fprintf(stderr, "size : %ld\n", size);
	fake_utils_print_source_info_list(source_list, size);

	source_output_infos_t* source_output_list = NULL;
	size = fake_extract_source_output_list(&source_output_list);
	fprintf(stderr, "size : %ld\n", size);
	fake_utils_print_source_output_info_list(source_output_list, size);

	// don't forget to free it
	free(sink_input_list);
	free(sink_list);
	free(source_list);
	free(source_output_list);

	return 0;
}
