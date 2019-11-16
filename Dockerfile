FROM python:3.6

WORKDIR /root/cpython-examples/cpython
COPY cpython/* ./
RUN apt-get update && apt-get -y install gcc python3-dev meson ninja-build
RUN meson setup . build
WORKDIR build
RUN ninja && mv libspam.so spam.so
CMD python3 -c "import spam; print(spam.divide(1, 2));"

