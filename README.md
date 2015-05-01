OpenVR is an API and runtime that allows access to VR hardware from multiple 
vendors without requiring that applications have specific knowledge of the 
hardware they are targeting. This repository is an SDK that contains the API 
and samples. The runtime is under SteamVR in Tools on Steam. 

Documentation for the API is available in the wiki: https://github.com/ValveSoftware/openvr/wiki/API-Documentation

More information on OpenVR and SteamVR can be found on http://steamvr.com

Building with cmake:

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release /path/to/openvr # add -DARCH=32 for 32 bit. -DARCH=64 is default
make
```

hellovr will be in samples/hellovr_opengl/hellovr

On old mesa versions hellovr should be run with `MESA_GL_VERSION_OVERRIDE=4.1 MESA_GLSL_VERSION_OVERRIDE=410 samples/hellovr_opengl/hellovr` for now.
For convenience samples/hellovr_opengl/run_hellovr.sh is provided.

For building helloworldoverlay:

```bash
cd samples/helloworldoverlay/
qmake helloworldoverlay.pro
make
```

This will build `samples/bin/win32/HelloWorldOverlay` (yes, really). Start it with

```bash
cd samples/bin/win32
LD_LIBRARY_PATH=../../../lib/linux64 ./HelloWorldOverlay
```

