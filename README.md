# CFake Lib - C binding of FakeLib

 > See [FakeLib](https://github.com/SCOTT-HAMILTON/FakeLib)

![powered by Pulseaudio](https://www.freedesktop.org/software/pulseaudio/logo.png)

![Powered by Pulseaudio](icons/powered_by_pulseaudio.png)


![Build Passing](https://travis-ci.org/SCOTT-HAMILTON/CFakeLib.svg?branch=master)

C binding of FakeLib.
FakeLib is a pulseaudio wrapper library written in c++.

# Meson Building 
  To build it, run : 
  ```sh
  meson setup build
  ninja -C build
  ninja -C install
  ```

# Usage
 CFakeLib can run multiple pulseaudio commands at once. The structure used runs the commands in the same server connection. 
 The basic usage consists of four steps : 
  1. Stacking commands that you want to run.
  2. Running them.
  4. Extracting the resuts you're interesed in.
  5. Using the extracted results.

In code, this would translate to
```c
fake_clear_commands();
fake_get_sink_input_list();
fake_get_sink_list();
fake_get_source_list();
fake_get_source_output_list();
fake_run_commands();

sink_input_infos_t* sink_input_list = null;
size_t size = fake_extract_sink_input_list(&sink_input_list);
fprintf(stderr, "size : %ld\n", size);
print_sink_input_info_list(sink_input_list, size);

sink_infos_t* sink_list = null;
size = fake_extract_sink_list(&sink_list);
fprintf(stderr, "size : %ld\n", size);
print_sink_info_list(sink_list, size);

source_infos_t* source_list = null;
size = fake_extract_source_list(&source_list);
fprintf(stderr, "size : %ld\n", size);
print_source_info_list(source_list, size);

source_output_infos_t* source_output_list = null;
size = fake_extract_source_output_list(&source_output_list);
fprintf(stderr, "size : %ld\n", size);
print_source_output_info_list(source_output_list, size);

// don't forget to free it
free(sink_input_list);
free(sink_list);
free(source_list);
free(source_output_list);
```

This code outputs this on my laptop : 

```
=======[ Module info #1 ]=======
Name: module-device-restore
Index: 0

=======[ Module info #2 ]=======
Name: module-stream-restore
Index: 1

[...]

=======[ Module info #15 ]=======
Name: module-rescue-streams
Index: 14

=======[ Module info #16 ]=======
Name: module-always-sink
Index: 15

=======[ Sink info #1 ]=======
Name: alsa_output.pci-0000_00_1f.3.analog-stereo
Index: 0
Description: Audio interne Stéréo analogique

=======[ Source info #1 ]=======
Name: alsa_output.pci-0000_00_1f.3.analog-stereo.monitor
Index: 0
Description: Monitor of Audio interne Stéréo analogique

=======[ Source info #2 ]=======
Name: alsa_input.pci-0000_00_1f.3.analog-stereo
Index: 1
Description: Audio interne Stéréo analogique

=======[ Source Output info #1 ]=======
Name: recStream
Source: 1
Index: 0
Source Process Binary Name: .Discord-wrapped
```

## Integration

CFakeLib provides a pkg-config file.

### Requirements

Fake requires libpulse

### Help

CFakeLib is just a little project, but feel free to fork, change, extend or correct the code.


License
----
CFakeLib is delivered as it is under the well known MIT License


**References that helped**
 - [pulseaudio IRC] : <#pulseaudio>
 - [pulseaudio under the hood] : <https://gavv.github.io/articles/pulseaudio-under-the-hood/>
 - [pulseaudio documentation] : <https://freedesktop.org/software/pulseaudio/doxygen/>
 - [pulseaudio introspect API interface] :
   <https://freedesktop.org/software/pulseaudio/doxygen/introspect_8h.html>

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)



   [pulseaudio IRC]: <#pulseaudio>
   [pulseaudio under the hood]: <https://gavv.github.io/articles/pulseaudio-under-the-hood/>
   [pulseaudio documentation]: <https://freedesktop.org/software/pulseaudio/doxygen/>
   [pulseaudio introspect API interface]:
   <https://freedesktop.org/software/pulseaudio/doxygen/introspect_8h.html>
