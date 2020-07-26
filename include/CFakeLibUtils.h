#ifndef CFAKE_LIB_UTILS_H
#define CFAKE_LIB_UTILS_H

/* #include "FakeLibImplementation.h" */
#include <FakeLib/common.h>

#ifdef __cplusplus
extern "C" {
#endif

void fake_utils_print_sink_input_info_list(sink_input_infos_t* list, size_t size);
void fake_utils_print_sink_info_list(sink_infos_t* list, size_t size);
void fake_utils_print_source_info_list(source_infos_t* list, size_t size);
void fake_utils_print_source_output_info_list(source_output_infos_t* list, size_t size);

#ifdef __cplusplus
}
#endif

#endif //CFAKE_LIB_UTILS_H
