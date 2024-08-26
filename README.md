# Inmoov ROS 2 Project: Dockerized System Setup

This project provides a Dockerized setup for a ROS 2 project, using `docker-compose` for orchestration. The `Makefile` included helps automate common tasks such as building images, running containers, linting code, running tests, and deploying to a NUC (Next Unit of Computing, aka an embedded computer in the robot).

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

## Environment Configuration

The project uses a `.env` file to manage environment-specific variables. Create a `.env` file in the root directory of the project with the following format:

```env
# .env

# Docker Compose file
DOCKER_COMPOSE_FILE=docker-compose.yml

# Project name
PROJECT_NAME=my_ros2_project

# Deployment path on NUC
NUC_DEPLOY_PATH=/path/to/deployment
# NUC user and address
NUC_USER=user
NUC_HOST=robot-nuc

# ROS 2 workspace setup path on NUC
ROS2_WORKSPACE_SETUP_PATH=/path/to/deployment/install/setup.bash
```

## Makefile Rules

The `Makefile` included in this project provides several rules to help you manage your Docker environment and deploy to the NUC. Here’s a summary of the available rules:

### `make help`

Displays the help message with a list of available `Makefile` targets and their descriptions. This is the default target, so running `make` without any arguments will display this help.

```sh
make help
```

### Development Rules
- **`make dc-build`**: Builds the Docker containers defined in the `docker-compose.yml` file.

  ```sh
  make dc-build
  ```

- **`make dc-up`**: Starts the Docker containers in detached mode.

  ```sh
  make dc-up
  ```

- **`make dc-down`**: Stops and removes the Docker containers.

  ```sh
  make dc-down
  ```

- **`make dc-logs`**: Follows the logs from the running Docker containers.

  ```sh
  make dc-logs
  ```

- **`make dc-test`**: Runs tests inside Docker.

  ```sh
  make dc-test
  ```

- **`make dc-clean`**: Cleans up Docker images and containers.

  ```sh
  make dc-clean
  ```

### Local Linting Rules
- **`make lint-cpp`**: Runs local C++ linting on `.cpp` and `.hpp` files.

  ```sh
  make lint-cpp
  ```

- **`make lint-py`**: Runs local Python linting on `.py` files.

  ```sh
  make lint-py
  ```

### CI/CD Docker Linting Rules
- **`make dc-lint-cpp`**: Runs C++ linting inside Docker.

  ```sh
  make dc-lint-cpp
  ```

- **`make dc-lint-py`**: Runs Python linting inside Docker.

  ```sh
  make dc-lint-py
  ```

### NUC Rules
- **`make nuc-deploy`**: Deploys files to NUC and runs the deployment script.

  ```sh
  make nuc-deploy
  ```

- **`make nuc-build`**: Builds the ROS 2 project on the NUC.

  ```sh
  make nuc-build
  ```

- **`make nuc-start`**: Starts the ROS 2 project on the NUC.

  ```sh
  make nuc-start
  ```

- **`make nuc-stop`**: Stops the ROS 2 project on the NUC.

  ```sh
  make nuc-stop
  ```

## How to Use

1. Clone this repository:

   ```sh
   git clone git@github.com:charlesmadjeri/inmoov-ros2-system.git
   cd inmoov-ros2-system
   ```

2. From the `.env.example` file, create and configure your local `.env` file in the root directory with the required variables. Never push your `.env`.

3. Review the `docker-compose.yml` file to ensure it meets your project’s requirements.

4. Use the `Makefile` commands listed above to build, run, and manage your Docker environment, and deploy to the NUC.

## License

This project is licensed under the MIT License with Non-Commercial Use. See the [LICENSE.md](LICENSE.md) file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## Contact

For questions or support, please email [us](mailto:inmoovros2contributi.numerate191@passmail.net).
