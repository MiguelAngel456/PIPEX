# Pipex 🔗

## Descripción

**Pipex** es un proyecto de la escuela 42 que consiste en replicar el comportamiento básico de los pipes en Unix, permitiendo encadenar comandos a través de tuberías. El programa recibe comandos, crea procesos hijos, redirige la entrada/salida y simula el funcionamiento de `cmd1 | cmd2`.

Este proyecto se desarrolló en macOS y puede que requiera adaptaciones para otros sistemas operativos.

---

## Tecnologías

- Lenguaje: C  
- Sistema operativo: macOS  
- Uso de pipes, fork, execve y dup2 para la gestión de procesos y redirecciones.

---

## Instalación y uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/tu_usuario/pipex.git
   cd pipex

2. Compilar el repositorio:
   ```bash
   make

3. Ejecutar el proyecto:
   ```bash
   ./pipex file1 "cmd1" "cmd2" file2

3.5. Ejemplo
   ```bash
   ./pipex infile "grep hola" "wc -l" outfile
