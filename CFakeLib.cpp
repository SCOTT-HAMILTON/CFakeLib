#include "CFakeLib.h"

/* #include <stdio.h> */
/* #include <string.h> */
/* #include <time.h> */
/* #include <unistd.h> */

/* #include <iostream> */
/* #include <string> */
/* #include <utility> */
/* #include <variant> */
#include <FakeLibUtils.hpp>
#include <vector>
#include <iostream>

static std::vector<ObjectVariant> commandObjects;
static std::vector<ObjectVariant> results;

template<typename user_type>
size_t get_info_list_size(const info_list<user_type>& list) {
	size_t size = 0;
	for (const auto& info : list) {
		if (!info.initialized)
			break;
		++size;
	}
	return size;
}

template<typename user_type>
size_t fake_extract (user_type** list) {
	info_list<user_type> foundList;
	bool found = false;
	for (auto& variant : results) {
		try {
			foundList = std::get<info_list<user_type>>(variant);
			found = true;
			break;
		} catch (const std::bad_variant_access&) {}
	}
	assert(found);
	size_t size = get_info_list_size(foundList);
	assert ((*list) == NULL);
	*list = static_cast<user_type*>(malloc(size*sizeof(user_type)));
	assert((*list) != NULL);
	std::copy_n(std::begin(foundList), size, *list);
	return size;
}

extern "C" {
void fake_move_source_output_port(uint32_t index, uint32_t sourceIndex) {
	move_source_output_port_t infos {
		.success = 0,
		.index = index,
		.sourceIndex = sourceIndex
	};
	ObjectVariant variant(infos);
	commandObjects.push_back(variant);
}
void fake_move_sink_input_port(uint32_t index, uint32_t sinkIndex) {
	move_sink_input_port_t infos {
		.success = 0,
		.index = index,
		.sinkIndex = sinkIndex
	};
	commandObjects.emplace_back(infos);
}
void fake_load_module(const char* name, 
					 const char* arguments,
					 const char* description){
	load_module_t infos = {
		.success = 0
	};
	strcpy(infos.description, description);
	strcpy(infos.arguments, arguments);
	strcpy(infos.name, name);
	commandObjects.emplace_back(infos);
}
void fake_unload_module(uint32_t index) {
	unload_module_t infos = {
		.success = 0,
		.index = index
	};
	commandObjects.emplace_back(infos);
}
void fake_set_sink_volume(uint32_t index, double volume) {
	set_sink_volume_t infos = {
		.success = 0,
		.index = index,
		.volume = volume
	};
	commandObjects.emplace_back(infos);
}
void fake_set_sink_input_volume(uint32_t index, double volume) {
	set_sink_input_volume_t infos = {
		.success = 0,
		.index = index,
		.volume = volume
	};
	commandObjects.emplace_back(infos);
}
void fake_get_module_list() {
	info_list<module_infos_t> infos;
	FakeLibUtils::reset_info_list(infos);
	commandObjects.emplace_back(infos);
}
void fake_get_sink_list() {
	info_list<sink_infos_t> infos;
	FakeLibUtils::reset_info_list(infos);
	commandObjects.emplace_back(infos);
}
void fake_get_sink_input_list() {
	info_list<sink_input_infos_t> infos;
	FakeLibUtils::reset_info_list(infos);
	commandObjects.emplace_back(infos);
}
void fake_get_source_list() {
	info_list<source_infos_t> infos;
	FakeLibUtils::reset_info_list(infos);
	commandObjects.emplace_back(infos);
}
void fake_get_source_output_list() {
	info_list<source_output_infos_t> infos;
	FakeLibUtils::reset_info_list(infos);
	commandObjects.emplace_back(infos);
}
void fake_get_module(uint32_t index) {
	module_infos_t infos = {
		.initialized = false,
		.index  = index
	};
	commandObjects.emplace_back(infos);
}
void fake_get_sink(uint32_t index) {
	sink_infos_t infos = {
		.initialized = false,
		.index  = index
	};
	commandObjects.emplace_back(infos);
}
void fake_get_sink_input(uint32_t index) {
	sink_input_infos_t infos = {
		.initialized = false,
		.index  = index
	};
	commandObjects.emplace_back(infos);
}
void fake_get_source(uint32_t index) {
	source_infos_t infos = {
		.initialized = false,
		.index  = index
	};
	commandObjects.emplace_back(infos);
}
void fake_get_source_output(uint32_t index) {
	source_output_infos_t infos = {
		.initialized = false,
		.index  = index
	};
	commandObjects.emplace_back(infos);
}
void fake_enable_subscription(pa_subscription_mask_t mask) {
	{
		set_subscribe_callback_info_t info = {};
		commandObjects.emplace_back(info);
	}
	{
		subscribe_info_t info = {
			.mask = mask
		};
		commandObjects.emplace_back(info);
	}
}
void fake_run_commands() {
	results = FakeLibImplementation::run_pa_commands(commandObjects);
}
void fake_clear_commands() {
	commandObjects.clear();
}
void fake_init_subscribtion(pa_subscription_mask_t mask, fake_user_subscribe_callback_t user_callback) {
	user_callback(PA_SUBSCRIPTION_EVENT_SINK);
	FakeLibImplementation::init_subscribtion(mask, user_callback);
}
void fake_iterate_subscribtion_loop() {
	FakeLibImplementation::iterate_subscribtion_loop();
}
void fake_clean_subscribtion_loop() {
	FakeLibImplementation::clean_subscribtion_loop();
}

size_t fake_extract_sink_input_list (sink_input_infos_t** list) {
	return fake_extract(list);
}
size_t fake_extract_sink_list (sink_infos_t** list) {
	return fake_extract(list);
}
size_t fake_extract_source_list (source_infos_t** list) {
	return fake_extract(list);
}
size_t fake_extract_source_output_list (source_output_infos_t** list) {
	return fake_extract(list);
}

void sink_infos_copy(sink_infos_t* a, sink_infos_t* b) {
	b->initialized = a->initialized;
	strcpy(b->name, a->name);
	b->index = a->index;
	strcpy(b->description, a->description);
}
void sink_input_infos_copy(sink_input_infos_t* a, sink_input_infos_t* b) {
	b->initialized = a->initialized;
	strcpy(b->name, a->name);
	b->index = a->index;
	b->owner_module = a->owner_module;
	b->client = a->client;
	b->sink = a->sink;
	strcpy(b->process_binary, a->process_binary);
}
void source_infos_copy(source_infos_t* a, source_infos_t* b) {
	b->initialized = a->initialized;
	strcpy(b->name, a->name);
	b->index = a->index;
	strcpy(b->description, a->description);
}
void source_output_infos_copy(source_output_infos_t* a, source_output_infos_t* b) {
	b->initialized = a->initialized;
	strcpy(b->name, a->name);
	b->index = a->index;
	b->source = a->source;
	strcpy(b->process_binary, a->process_binary);
}

}
