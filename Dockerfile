FROM ubuntu:23.04

ENV TZ=America/Sao_Paulo
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y make xterm sudo build-essential git mingw-w64 mingw-w64-tools \
libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libwebp-dev libgsl-dev valgrind clang-format

# emcc
RUN \
cd /opt && \
# Get the emsdk repo
git clone https://github.com/emscripten-core/emsdk.git && \
# Enter that directory
cd emsdk && \
# Fetch the latest version of the emsdk (not needed the first time you clone)
git pull && \
# Download and install the latest SDK tools.
./emsdk install latest && \
# Make the "latest" SDK "active" for the current user. (writes .emscripten file)
./emsdk activate latest

# Activate PATH and other environment variables in the current terminal
RUN echo "source /opt/emsdk/emsdk_env.sh" >> /root/.bashrc

EXPOSE 8080