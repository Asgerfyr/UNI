FROM debian:12-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        openssh-server \
        sudo \
        bash \
        ca-certificates \
        iproute2 \
        net-tools \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir /var/run/sshd

RUN useradd -m -s /bin/bash dev && \
    echo 'dev:password123' | chpasswd && \
    usermod -aG sudo dev && \
    echo 'dev ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

RUN sed -i 's/^#\?PermitRootLogin.*/PermitRootLogin no/' /etc/ssh/sshd_config && \
    sed -i 's/^#\?PasswordAuthentication.*/PasswordAuthentication yes/' /etc/ssh/sshd_config && \
    sed -i 's/^#\?PubkeyAuthentication.*/PubkeyAuthentication yes/' /etc/ssh/sshd_config && \
    sed -i 's/^#\?ChallengeResponseAuthentication.*/ChallengeResponseAuthentication no/' /etc/ssh/sshd_config && \
    sed -i 's/^#\?UsePAM.*/UsePAM yes/' /etc/ssh/sshd_config

COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 22

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["bash"]
