#!/bin/sh

cd $(dirname "$(readlink -f "$0")")

#Only for mesa, doesn't hurt anyone else
#Only works for radeon, not for intel. Why?
export MESA_GL_VERSION_OVERRIDE=4.1 MESA_GLSL_VERSION_OVERRIDE=410

./hellovr "$@"
