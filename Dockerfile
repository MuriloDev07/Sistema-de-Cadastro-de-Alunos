FROM gcc:latest
WORKDIR /usr/src/myapp
COPY . .
RUN make
CMD ["./sistema"]