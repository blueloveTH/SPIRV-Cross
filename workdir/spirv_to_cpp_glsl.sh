set -e

../build/spirv-cross CoreKeeperWorld.spv --output CoreKeeperWorld.cpp --cpp
../build/spirv-cross CoreKeeperWorld.spv --output CoreKeeperWorld.glsl --version 450 --no-es