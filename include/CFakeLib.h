#ifndef CFAKE_LIB_H
#define CFAKE_LIB_H

/* #include <pulse/operation.h> */
/* #include <pulse/pulseaudio.h> */
/* #include <stdio.h> */
/* #include <string.h> */
/* #include <time.h> */
/* #include <unistd.h> */

/* #include <array> */
/* #include <exception> */
/* #include <functional> */
/* #include <string> */
/* #include <variant> */
/* #include <vector> */
#include <FakeLib/common.h>
#include <pulse/subscribe.h>

typedef void(*fake_user_subscribe_callback_t)(pa_subscription_event_type_t event);

#ifdef __cplusplus
extern "C" {
#endif //cplusplus
	void fake_move_source_output_port(uint32_t index, uint32_t sourceIndex);
	void fake_move_sink_input_port(uint32_t index, uint32_t sinkIndex);
	void fake_load_module(const char* name, 
						 const char* arguments,
						 const char* description);
	void fake_unload_module(uint32_t index);
	void fake_set_sink_volume(uint32_t index, double volume); // volume in percentage
	void fake_set_sink_input_volume(uint32_t index, double volume); // volume in percentage
	void fake_get_module_list();
	void fake_get_sink_list();
	void fake_get_sink_input_list();
	void fake_get_source_list();
	void fake_get_source_output_list();
	void fake_get_module(uint32_t index);
	void fake_get_sink(uint32_t index);
	void fake_get_sink_input(uint32_t index);
	void fake_get_source(uint32_t index);
	void fake_get_source_output(uint32_t index);
	void fake_enable_subscription(pa_subscription_mask_t mask);
	void fake_run_commands();
	void fake_clear_commands();
	void fake_init_subscribtion(pa_subscription_mask_t mask, fake_user_subscribe_callback_t callback);
	void fake_iterate_subscribtion_loop();
	void fake_clean_subscribtion_loop();

	size_t fake_extract_sink_input_list (sink_input_infos_t** list);
	size_t fake_extract_sink_list (sink_infos_t** list);
	size_t fake_extract_source_list (source_infos_t** list);
	size_t fake_extract_source_output_list (source_output_infos_t** list);
#ifdef __cplusplus
}
#endif //cplusplus


#endif // CFAKE_LIB_H
