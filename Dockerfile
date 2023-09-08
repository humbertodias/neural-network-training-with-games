FROM ubuntu:20.04


ENV TZ=America/Sao_Paulo
RUN apt update && DEBIAN_FRONTEND=noninteractive apt install -y make xterm sudo build-essential \
libsdl2-dev libsdl2-ttf-dev libsdl2-image-dev libwebp-dev libgsl-dev valgrind


ARG USER=docker
ARG UID=1000
ARG GID=1000
# default password for user
ARG PW=docker

# Option1: Using unencrypted password/ specifying password
RUN useradd -m ${USER} --uid=${UID} && echo "${USER}:${PW}" | chpasswd && adduser docker sudo

# Setup default user, when enter docker container
USER ${UID}:${GID}
WORKDIR /home/${USER}
