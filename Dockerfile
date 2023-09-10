FROM debian:bookworm
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=America/Sao_Paulo
# Update and install cross-platform build dependencies
RUN apt update && apt install -y \
    gcc \
    g++ \
    gcc-multilib \
    g++-multilib \
    build-essential \
    xutils-dev \
    libreadline6-dev \
    libncurses5-dev \
    mingw-w64 \
    mingw-w64-tools \
    libwebp-dev \
    libgsl-dev \
    libsdl2-gfx-dev \
    cmake
    # libsdl2-image-dev \
    # libsdl2-mixer-dev \
    # libsdl2-net-dev \
    # libsdl2-ttf-dev \
    # libsdl2-dev \

# Install other dependencies
RUN apt install -y make xterm sudo build-essential git curl valgrind clang-format

# https://github.com/libsdl-org/SDL/releases/download/release-2.28.3/SDL2-2.28.3.tar.gz
ARG SDL_VERSION=2.28.3
RUN curl -skL https://github.com/libsdl-org/SDL/releases/download/release-${SDL_VERSION}/SDL2-${SDL_VERSION}.tar.gz -o SDL2-${SDL_VERSION}.tar.gz \
  && tar xf SDL2-${SDL_VERSION}.tar.gz \
  && cd /SDL2-${SDL_VERSION} && ./configure && make && make install \
  && cd / && rm -rf /SDL2-${SDL_VERSION} SDL2-${SDL_VERSION}.tar.gz

# https://github.com/libsdl-org/SDL_ttf/releases/download/release-2.20.2/SDL2_ttf-2.20.2.tar.gz
ARG SDL_TTF_VERSION=2.20.2
RUN curl -skL https://github.com/libsdl-org/SDL_ttf/releases/download/release-${SDL_TTF_VERSION}/SDL2_ttf-${SDL_TTF_VERSION}.tar.gz -o SDL2_ttf-${SDL_TTF_VERSION}.tar.gz \
  && tar xf SDL2_ttf-${SDL_TTF_VERSION}.tar.gz \
  && cd /SDL2_ttf-${SDL_TTF_VERSION} && ./configure && make && make install \
  && cd / && rm -rf /SDL2_ttf-${SDL_TTF_VERSION} SDL2_ttf-${SDL_TTF_VERSION}.tar.gz

# https://github.com/libsdl-org/SDL_image/releases/download/release-2.6.3/SDL2_image-2.6.3.tar.gz
ARG SDL_IMAGE_VERSION=2.6.3
RUN curl -skL https://github.com/libsdl-org/SDL_image/releases/download/release-${SDL_IMAGE_VERSION}/SDL2_image-${SDL_IMAGE_VERSION}.tar.gz -o SDL2_image-${SDL_IMAGE_VERSION}.tar.gz \
  && tar xf SDL2_image-${SDL_IMAGE_VERSION}.tar.gz \
  && cd /SDL2_image-${SDL_IMAGE_VERSION} && ./configure && make && make install \
  && cd / && rm -rf /SDL2_image-${SDL_IMAGE_VERSION} SDL2_image-${SDL_IMAGE_VERSION}.tar.gz

# https://github.com/libsdl-org/SDL_mixer/releases/download/release-2.6.3/SDL2_mixer-2.6.3.tar.gz
ARG SDL_MIXER_VERSION=2.6.3
RUN curl -skL https://github.com/libsdl-org/SDL_mixer/releases/download/release-${SDL_MIXER_VERSION}/SDL2_mixer-${SDL_MIXER_VERSION}.tar.gz -o SDL2_mixer-${SDL_MIXER_VERSION}.tar.gz \
  && tar xf SDL2_mixer-${SDL_MIXER_VERSION}.tar.gz \
  && cd /SDL2_mixer-${SDL_MIXER_VERSION} && ./configure && make && make install \
  && cd / && rm -rf /SDL2_mixer-${SDL_MIXER_VERSION} SDL2_mixer-${SDL_MIXER_VERSION}.tar.gz

ARG USER=docker
ARG UID=9999
ARG GID=9999
# default password for user
ARG PW=docker

# Option1: Using unencrypted password/ specifying password
RUN useradd -m ${USER} --uid=${UID} && echo "${USER}:${PW}" | chpasswd && adduser docker sudo
RUN echo "${USER} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

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


# Setup default user, when enter docker container
USER ${UID}:${GID}
WORKDIR /home/${USER}


# Activate PATH and other environment variables in the current terminal
#source ./emsdk_env.sh
RUN echo "source /opt/emsdk/emsdk_env.sh" >> /home/${USER}/.bashrc

EXPOSE 8080