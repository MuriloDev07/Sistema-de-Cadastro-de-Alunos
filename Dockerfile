# Stage 1 - Build
FROM gcc:latest AS builder
WORKDIR /usr/src/myapp
COPY . .
RUN make

# Stage 2 - Production
FROM debian:stable-slim
WORKDIR /app
COPY --from=builder /usr/src/myapp/sistema .
CMD ["./sistema"]