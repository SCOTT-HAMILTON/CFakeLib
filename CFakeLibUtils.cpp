#include "CFakeLibUtils.h"

#include <iostream>

extern "C" {
void print_sink_input_info_list(sink_input_infos_t* list, size_t size) {
	for (size_t ctr = 0; ctr < size; ++ctr) {
		std::cerr << "=======[ Sink Input info #" << ctr + 1 << " ]=======\n";
		std::cerr << "Name: " << 
				list[ctr].name << '\n';
		std::cerr << "Index: " << 
				list[ctr].index << '\n';
		std::cerr << "Owner Module: " << 
				list[ctr].owner_module << '\n';
		std::cerr << "Client: " << 
				list[ctr].client << '\n';
		std::cerr << "Sink: " << 
				list[ctr].sink << '\n';
		std::cerr << "Process Binary: " << 
				list[ctr].process_binary << '\n';
		std::cerr << '\n';
	}
}
void print_sink_info_list(sink_infos_t* list, size_t size) {
	for (size_t ctr = 0; ctr < size; ++ctr) {
		std::cerr << "=======[ Sink list[ctr] #" << ctr + 1 << " ]=======\n";
		std::cerr << "Name: " << 
				list[ctr].name << '\n';
		std::cerr << "Index: " << 
				list[ctr].index << '\n';
		std::cerr << "Description: " << 
				list[ctr].description << '\n';
		std::cerr << '\n';
	}
}
void print_source_info_list(source_infos_t* list, size_t size) {
	for (size_t ctr = 0; ctr < size; ++ctr) {
		std::cerr << "=======[ Source info #" << ctr + 1 << " ]=======\n";
		std::cerr << "Name: " << 
				list[ctr].name << '\n';
		std::cerr << "Index: " << 
				list[ctr].index << '\n';
		std::cerr << "Description: " << 
				list[ctr].description << '\n';
		std::cerr << '\n';
	}
}
void print_source_output_info_list(source_output_infos_t* list, size_t size) {
	for (size_t ctr = 0; ctr < size; ++ctr) {
		std::cerr << "=======[ Source Output info #" << ctr + 1 << " ]=======\n";
		std::cerr << "Name: " << 
				list[ctr].name << '\n';
		std::cerr << "Source: " << 
				list[ctr].source << '\n';
		std::cerr << "Index: " << 
				list[ctr].index << '\n';
		std::cerr << "Process Binary: " << 
				list[ctr].process_binary << '\n';
		std::cerr << '\n';
	}
}

}
