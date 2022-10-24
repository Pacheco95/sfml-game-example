FROM conanio/gcc9:latest

RUN sudo apt update -y
RUN sudo apt upgrade -y

RUN sudo apt install -y \
    libudev-dev \
    libgl1-mesa-dev \
    libfontenc-dev \
    libice-dev \
    libsm-dev \
    libxaw7-dev \
    libxcomposite-dev \
    libxcursor-dev \
    libxi-dev \
    libxinerama-dev \
    libxkbfile-dev \
    libxmu-dev \
    libxmuu-dev \
    libxpm-dev \
    libxrandr-dev \
    libxrender-dev \
    libxres-dev \
    libxss-dev \
    libxt-dev \
    libxtst-dev \
    libxv-dev \
    libxvmc-dev \
    libxcb-render-util0-dev \
    libxcb-xkb-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-xinerama0-dev \
    uuid-dev \
    libxcb-util-dev

COPY . ./app

WORKDIR ./app/build

RUN sudo chown -R conan:conan-1001 ..

RUN cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
RUN make tests

ENTRYPOINT ["./bin/tests"]