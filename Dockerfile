#docker build -t callcenterimage -f Dockerfile .
#docker run --dns=8.8.8.8 --network bridge -d -p 127.0.0.1:2222:22 --name callcentercontainer callcenterimage

#if you wanna connect to container via SSH you should use following command: ssh userLinux@127.0.0.1 -p 2222
#if you wanna send a file or directory from host to container you should you following command: docker cp hostDirectoryName/ CallCenterContainer:/home/userLinux/

#Instructions to create SSH-key for GitHub account:
#ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
#cat PublicKey_file
#eval "$(ssh-agent -s)"
#ssh-add PrivateKey_file
#ssh -T git@github.com

FROM ubuntu:22.04

RUN apt-get update && apt-get upgrade -y \
    && apt-get install -y build-essential \
    libboost-all-dev \
    cmake \
    curl \
    g++ \
    git \
    ninja-build \
    pip \
    python3 \
    ssh \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

RUN pip install conan==1.61.0

RUN useradd -m userLinux && echo "userLinux:password" | chpasswd
RUN usermod -s /bin/bash userLinux
RUN usermod -aG sudo userLinux

RUN git clone https://github.com/GavrilovMS/it-leti-2024-patterns-demo /home/userLinux/it-leti-2024-patterns-demo
WORKDIR /home/userLinux/it-leti-2024-patterns-demo

RUN mkdir /tmp/starship
RUN curl -sS https://starship.rs/install.sh > /tmp/starship/install.sh
RUN sh /tmp/starship/install.sh -y
RUN mkdir ~/.config
RUN touch ~/.config/starship.toml
RUN starship preset no-runtime-versions -o ~/.config/starship.toml
RUN echo 'eval "$(starship init bash)"' >>  ~/.bashrc
RUN rm -rf /tmp/starship

RUN ( \
   echo 'LogLevel DEBUG2'; \
   echo 'PermitRootLogin yes'; \
   echo 'PasswordAuthentication yes'; \
   echo 'Subsystem sftp /usr/lib/openssh/sftp-server'; \
   ) > /etc/ssh/sshd_config \
   && mkdir /run/sshd

ENTRYPOINT ["/usr/sbin/sshd"]
CMD ["-D", "-e", "-f", "/etc/ssh/sshd_config"]