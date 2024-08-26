# Inmoov ROS 2 Project: Dockerized System Setup

This project provides a Dockerized setup for a ROS 2 project, using `docker-compose` for orchestration. The `Makefile` included helps automate common tasks such as building images, running containers, linting code, and running tests.

## Prerequisites

### Linux

Before you begin, ensure you have the following installed:

1. **Docker**: [Installation Guide](https://docs.docker.com/engine/install/)
2. **Docker Compose**: [Installation Guide](https://docs.docker.com/compose/install/)
3. **GNU Make**:
    - On Ubuntu/Debian:
      ```bash
      sudo apt-get install make
      ```
    - On Fedora:
      ```bash
      sudo dnf install make
      ```

### Windows

For Windows users, ensure the following are installed:

1. **Docker Desktop**:
    - Includes both Docker and Docker Compose. [Installation Guide](https://docs.docker.com/desktop/install/windows-install/)

2. **Windows Subsystem for Linux (WSL 2)**:
    - Required for running Docker on Windows. [WSL 2 Installation Guide](https://docs.microsoft.com/en-us/windows/wsl/install)

3. **GNU Make**:
    - Install via [Chocolatey](https://chocolatey.org/):
      ```powershell
      choco install make
      ```
    - Alternatively, you can use `make` from within WSL.

## Project Structure

Here’s a brief overview of the project structure:

- **`src/`**: Contains the source code for various components of the robot system.
    - **`description/`**: URDF files, mesh files, and robot configuration.
    - **`firmware/`**: Arduino firmware code for the robot.
    - **`navigation/`**: ROS 2 navigation node and path planner.
    - **`robot_control/`**: ROS 2 control node and actuator control.
    - **`robot_sensors/`**: ROS 2 sensor node and data processing.
- **`tests/`**: Unit tests for different components.
- **`config/`**: Configuration files.
- **`launch/`**: Launch files for ROS 2 nodes.
- **`scripts/`**: Utility scripts for starting and stopping the robot.
- **`doc/`**: Documentation files.

## Makefile Rules

The `Makefile` included in this project provides several rules to help you manage your Docker environment. Here's a summary of the available rules:

### `make help`

Displays the help message with a list of available `Makefile` targets and their descriptions. This is the default target, so running `make` without any arguments will display this help.

```sh
make help
```

### `make build`

Builds the Docker images defined in the `docker-compose.yml` file.

```sh
make build
```

### `make up`

Starts the Docker containers in detached mode, using `docker-compose up -d`.

```sh
make up
```

### `make down`

Stops and removes the Docker containers, using `docker-compose down`.

```sh
make down
```

### `make logs`

Follows the logs from the running Docker containers. This is useful for debugging and monitoring.

```sh
make logs
```

### `make lint_cpp`

Runs C++ linting on all `.cpp` and `.hpp` files in your project using `cpplint`. The linting is performed inside the Docker container.

```sh
make lint_cpp
```

### `make lint_py`

Runs Python linting on all Python files in your project using `flake8`. The linting is performed inside the Docker container.

```sh
make lint_py
```

### `make test`

Runs tests defined in your project using `colcon test` inside the Docker container.

```sh
make test
```

### `make clean`

Stops and removes all Docker containers and images associated with the project. This is useful for cleaning up your environment.

```sh
make clean
```

## How to Use

1. Clone this repository:

   ```sh
   git clone git@github.com:charlesmadjeri/inmoov-ros2-system.git
   cd inmoov-ros2-system
   ```

2. Review the `docker-compose.yml` file to ensure it meets your project’s requirements.

3. Use the `Makefile` commands listed above to build, run, and manage your Docker environment.

## License

This project is licensed under the MIT License with Non-Commercial Use. See the LICENSE.md file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Contact

For questions or support, please send a mail [here](mailto:inmoovros2contributi.numerate191@passmail.net).
