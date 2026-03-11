# Используем Ubuntu 22.04
FROM ubuntu:22.04

# Устанавливаем gcc, make и ncurses
RUN apt-get update && \
    apt-get install -y build-essential libncurses5-dev libncursesw5-dev && \
    rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию внутри контейнера
WORKDIR /app

# Копируем весь проект внутрь контейнера
COPY . .

# Запускаем make для сборки проекта
RUN make

# Команда по умолчанию для запуска контейнера
CMD ["./build/main"]