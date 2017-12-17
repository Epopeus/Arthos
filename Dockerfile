FROM debian:latest

ENV ProjectName Arthos
ENV ProjectRootDir /home/${ProjectName}

ARG version=master

RUN useradd -m ${ProjectName} && su - ${ProjectName}
WORKDIR ${ProjectRootDir}

#Install necessary libs
RUN apt-get update
RUN apt-get install -y python wget git cmake gcc g++
RUN wget https://bootstrap.pypa.io/get-pip.py && python get-pip.py
RUN pip install conan
RUN conan remote add conan-community https://api.bintray.com/conan/conan-community/conan 

#Checkout current source code at required version. Avoid unnecessary downloads with --depth 1.
RUN git clone --branch $version --depth 1 https://github.com/Toinouze/${ProjectName}

#Build the server
ENV CC /usr/bin/gcc
ENV CXX /usr/bin/g++
RUN cmake -DCMAKE_BUILD_TYPE=Debug ${ProjectName}/server
RUN cmake --build ${ProjectName}/server/cmake-build-debug --target ${ProjectName}Logind -j4

#Expose Login daemon port
EXPOSE 3724

#Run !
ENTRYPOINT ${ProjectName}/server/cmake-build-debug/bin
