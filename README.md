# Эмулятор для языка оболочки ОС

## Общее описание
Эмулятор для языка оболочки ОС предназначен для имитации работы командной строки в UNIX-подобной ОС. Эмулятор запускается из реальной командной строки и принимает образ виртуальной файловой системы в виде файла формата zip. Эмулятор работает в режиме CLI и поддерживает команды `ls`, `cd`, `exit`, `whoami`, и `tac`.

## Описание всех функций и настроек

### Функции:
- **ls**: Выводит список файлов и директорий в текущем каталоге.
- **cd**: Изменяет текущий каталог.
- **exit**: Завершает работу эмулятора.
- **whoami**: Выводит имя текущего пользователя.
- **tac**: Выводит содержимое файла в обратном порядке.

### Настройки:
- **Имя пользователя**: Используется для отображения в приглашении к вводу.
- **Имя компьютера**: Используется для отображения в приглашении к вводу.
- **Путь к архиву виртуальной файловой системы**: Путь к файлу формата zip, содержащему виртуальную файловую систему.
- **Путь к лог-файлу**: Путь к файлу формата csv, в который записываются все действия во время сеанса работы с эмулятором.
- **Путь к стартовому скрипту**: Путь к файлу, содержащему список команд для начального выполнения.

## Описание команд для сборки проекта
Для сборки проекта используется файл-скрипт `build.sh`. Команды для сборки проекта:
```sh
./build.sh
